#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>
#include "array.h"

#define SORT_MODE_BUBBLE 1
#define SORT_MODE_INSERTION 2
#define SORT_MODE_SELECTION 3
#define SORT_MODE_HEAP 4
#define SORT_MODE_MERGE 5
#define SORT_MODE_QUICK 6
#define SORT_MODE_BOGO 99

int sort_mode = SORT_MODE_BUBBLE;
int verbose = 0;
int measure = 0;

int main(int argc, char **argv){
	FILE *fp;
	char buf[4096], *p, c;
	array a;
	struct timeval before, after;
	while((c = getopt(argc, argv, "bhtv?")) != -1){
		switch(c){
			case 'b':
				sort_mode = SORT_MODE_BUBBLE;
				break;
			case 't':
				measure = 1;
				break;
			case 'v':
				verbose = 1;
				break;
			case 'h':
			case '?':
				printf("\
sort -- Copyright (c) 2020 medit\n\
\n\
Usage: %s [-bhtv?] [<file>]\n\
Get elements from file, put them in an array, and sort\n\
\n\
Sort mode options:\n\
  -b    do bubble sort\n\
\n\
  Other modes are not implemented yet.\n\
\n\
Output options:\n\
  -t    measure and display execution time\n\
  -v    display contents of the array before and after sorting\n\
\n\
General options:\n\
  -h\n\
  -?    show this help\n\
\n\
\n"
				, argv[0]);
				return 1;
			default:
				fprintf(stderr, "unexpected error\n");
				return 1;
		}
	}
	if(argc - optind <= 0 || !strcmp(argv[optind], "-")){
		fp = stdin;
		fprintf(stderr, "read from stdin\n");
	}else{
		fp = fopen(argv[optind], "r");
		if(fp == NULL){
			fprintf(stderr, "error: %s: %s\n", argv[optind], strerror(errno));
			return 1;
		}
	}
	a = array_new();
	if(a == NULL){
		fprintf(stderr, "error: array_new() failed\n");
		return 1;
	}
	int line = 0;
	while(fgets(buf, sizeof(buf), fp)){
		line++;
		p = strchr(buf, '\n');
		if(p != NULL) *p = '\0';
		else while((c = fgetc(fp)) != '\n' || c != EOF);
		long val = strtol(buf, &p, 10);
		if(buf != p && val >= INT_MIN && val <= INT_MAX){
			if(push(a, val)){
				fprintf(stderr, "error: push failed\n");
				return 1;
			}
		}else{
			fprintf(stderr, "wrong input at line %d\n", line);
		}
	}
	if(verbose){
		printf("Before: ");
		array_print(a);
	}
	if(measure){
		gettimeofday(&before, NULL);
	}
	switch(sort_mode){
		case SORT_MODE_BUBBLE:
			array_sort_bubble(a);
			break;
		default:
			fprintf(stderr, "error: unknown sort mode\n");
			return 1;
	}
	if(measure){
		gettimeofday(&after, NULL);
	}
	if(verbose){
		printf("After: ");
		array_print(a);
	}
	if(measure){
		printf("Time: %10.6f s\n", after.tv_sec - before.tv_sec + (double)(after.tv_usec - before.tv_usec) / 1e6);
	}
	array_free(a);
	fclose(fp);
	return 0;
}
