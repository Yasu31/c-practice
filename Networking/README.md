# [Asio](https://www.boost.org/doc/libs/1_69_0/doc/html/boost_asio/overview.html)

# BSD sockets
ネットワークの抽象化インタフェースとしてのデファクトスタンダードとなっている。

run the tcpd.c program as `tcpd 80`, then try to connect to *localhost:80*! 
Run `netstat -tln` 

* [C言語で学ぶソケットAPI入門 第1回 サーバ編](https://qiita.com/tajima_taso/items/2f0606db7764580cf295)
* [ 第2回 クライアント編](https://qiita.com/tajima_taso/items/fb5669ddca6e4d022c15)
* [ 第3回 サーバ/クライアント編 #1](https://qiita.com/tajima_taso/items/13b5662aca1f68fc6e8e)
* [第4回 UDPサーバ/クライアント編 #1](https://qiita.com/tajima_taso/items/fdfed88c1e735ffb41e8)
* [C言語で学ぶモダンなソケットAPI入門](https://qiita.com/tajima_taso/items/b8f2ee3eb84880778cad)

UDP and TCP are separate protocols but on the same layer, UDP is more unreliable, they are both one step higher level than IP.

## 3-way handshake
in TCP
1. client sends connection request (SYN)
1. server sends back SYN and ACK
1. client sends back ACK
