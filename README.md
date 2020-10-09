# tools
Cで書かれたプログラム群

## Documentation
ある程度まとまったらDocumentation書きます。

## How to Build
`make all`で全てのプログラムをコンパイルできます。また、`make <program-name>`で個別にコンパイルすることができます。

## Usage

### sort
ソートするプログラムです。

Usage: `./sort [-bhtv?] [<file>]`

詳しい説明は-hオプションで確認できます。

現時点で実装済みのソートアルゴリズム
- バブルソート
- 挿入ソート

### testarray
対話的に配列を操作することができるプログラムです。[split](./split.c)を利用しています。

コマンドの例
- push \<val\> -- valを末尾に追加する
- i -- ランダムな数(0〜9999)を末尾に追加する
- pop -- 末尾から要素を取り出す
- o -- 同上
- print -- 配列の内容を出力する

### testsplit
プロンプトに入力された文字列をスペースで分割します。[split](./split.c)を利用しています。`exit`で終了します。

### array
### split
C言語用の関数群です。\_\_\_\_を参照。(スタブ)

## License
このリポジトリ内の全てのファイルには[MIT License](./LICENSE)が適用されます。
