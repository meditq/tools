#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

int main(int argc, char **argv){
	FILE *fp;
	char buf[4096], *p, c;
	array a;
	if(argc < 2 || !strcmp(argv[1], "-")){
		fp = stdin;
		fprintf(stderr, "read from stdin\n");
	}else{
		fp = fopen(argv[1], "r");
		if(fp == NULL){
			fprintf(stderr, "error: %s: %s\n", argv[1], strerror(errno));
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
	array_print(a);
	array_free(a);
	fclose(fp);
	return 0;
}
