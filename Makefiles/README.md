# Makefiles
[トリビアなmakefile入門](http://www.jsk.t.u-tokyo.ac.jp/~k-okada/makefile/), k-okada
>make/makefileは，大きいプログラムのどの断片が再コンパイルされる必要があるかという事と,それらを再コンパイルする発行コマンドを自動的に決定するユーティリティ／設定ファイルです．
コンピュータサイエンスの基本的な考え方のひとつに冗長性をなくして効率化する構成を追及するというのがあります．
情報理論(bitの理論)，HTMLとブラウザ，高級言語と機械語など，ひとつの仕様（表現）から環境や状況にあわせて実装（記述）をつくりだす構成が好まれます．
ひとつのファイルでさまざまなコマンドを制御するmake/makefileを制することはコンピュータサイエンスを制することになります

```Makefile
<target>: <dependent files>
  <command>
```
don't forget the tab before the command! So, to make an executable test1 from two source files...
```Makefile
test1: main.c hello.c
  gcc main.c hello.c -o test1
```
To build it,`$ make test1`. Use the touch command to re-compile stuff.

## 自動変数
`$@` is target file name, `$^` is dependent file name(s).
```Makefile
test1: main.c hello.c
  gcc $^ -o $@
```
* $@ : ターゲットファイル名
* $% : ターゲットがアーカイブメンバだったときのターゲットメンバ名
* $< : 最初の依存するファイルの名前
* $? : ターゲットより新しいすべての依存するファイル名
* $^ : すべての依存するファイルの名前
* $+ : Makefileと同じ順番の依存するファイルの名前
* $* : サフィックスを除いたターゲットの名前

## suffix rule
When "~~~.o" is required, compiles "~~~.c".
```Makefile
.c.o:
  gcc -c $<
```
