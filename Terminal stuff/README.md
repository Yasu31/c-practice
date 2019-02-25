# Terminal stuff
## shell
a command-line interpreter(computer programs designed to interpret a sequence of lines of text which may be entered by a user, read from a file or another kind of data stream.) or shell(UI for accessing OS services. Can be either CUI or GUI).

### screen
Terminal multiplexers can multiplex separate login sessions inside a single terminal display. Useful for separating programs from session of Unix shells, so that the process can continue after user is disconnected.

So [`screen` can be used in a similar way to `nohup`](https://qiita.com/IshitaTakeshi/items/531e4c9c1782a7549a62)- to continue processes even after exiting shell.

ctrl+a c : new screen
exit: kill current screen
screen -ls : view current screens
screen -r [Process ID] ; attach screen
## `which` command
shows location of a program
> In theory, all programs should run from the /usr/bin folder but in reality, this is not the case.

`which -a ???` to display all the places where a program is installed (eg, with the `less` program)
```
$ which -a less
/usr/bin/less
/bin/less
$ ls -lt /usr/bin/less
/usr/bin/less -> /bin/less
```
The `->` indicates a symbolic link.

* [Example Uses of the Linux Which Command- lifewire](https://www.lifewire.com/linux-which-command-4062680)

## symbolic links
### hard links
> Each file in your file system is identified by a number called an inode.
A hard link lets you assign a different name to a file in a different location but essentially it is exactly the same file. The key that links the files together is the inode number.

### soft links (symbolic links)
>A symbolic link is like a shortcut from one file to another. The contents of a symbolic link are the address of the actual file or folder that is being linked to.

* [How To Create Symbolic Links Using The ln Command -lifewire](https://www.lifewire.com/create-symbolic-links-ln-command-4059723)

## folders
>UNIX系統のOSは、オリジナルであるSystem 7のディレクトリ構成をベースに、時代の要請を取り入れながら徐々に変わってきました。そのため、さまざまなシステムで似たり寄ったりの構成になっていますが、やはり細かい違いはあります。これを統一すべく策定されたのがFilesystem Hierarchy Standard（FHS）で、2001年8月時点ではバージョン2.2がリリースされています

The command locations are in the $PATH variable.
```
yasu@yasu-ThinkPad-T440s:~$ echo $PATH
/opt/ros/kinetic/bin:/home/yasu/bin:/home/yasu/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin

```
### /bin
>binとは、Binary codeのことでようするに実行可能プログラム置き場ということ。バイナリということはコンパイル型の言語により作られたプログラムが置かれるのだろう。

> ここには、システム管理者と一般ユーザーの両方が使う、極めて基本的なコマンドが入っています。ほかのファイルシステムがマウントされていない、シングルユーザーモードでも一通りの作業が行えるコマンド群です。
　FHS 2.2では、ここに収めるべきコマンドをRequirements（必須）とOptions（オプション）の2種類に分けて定義しています。
### /usr/bin
>ユーザーが一般的に使用するコマンドで、
緊急時のシステム保守に必須ではないコマンドが配置されます。

### /dev
>/devにはデバイスファイルが配置されています。コンソール画面に何かを出力するなら、/dev/consoleに書き込めばいいわけです。
Linuxの特徴として、「各種のデバイスもファイルとして扱う」ということがよくいわれます。もっとも、これはUNIXの特徴だったのですが、現代のOSは大なり小なりUNIXの影響を受けているためか、割と一般的な機能です。

* [Linuxのディレクトリ構造（一覧）を理解する](http://www.linuxmaster.jp/linux_skill/2010/02/06linux.html)
* [The Linux Information Project](http://www.linfo.org/index.html)
* [Linuxの/bin、/usr/bin、$HOME/binのそれぞれの役割 -Qiita](https://qiita.com/totzyuta/items/84d610f56129a186f0c5)
* [各ディレクトリの役割を知ろう（ルートディレクトリ編）](http://www.atmarkit.co.jp/ait/articles/0108/07/news002.html)
* [自作のコマンドを作成した -Qiita](https://qiita.com/yoshiken/items/2b8e6c24d6b95e65b625)

## chmod (change mode)
```
$ chmod a+x <file>
```

* r 4 : read
* w 2 : write
* x 1 : execute
* 0 : no permission

* digit 1 : user
* digit 2 : group
* digit 3 : others

* a : all users

so, `a+x` means giving permission to execute for all users

view a file's permissions with the `ls -l <file>` command
* [Linux chmod command -ComputerHope](https://www.computerhope.com/unix/uchmod.htm)
