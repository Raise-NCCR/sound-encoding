# sound-encoding
データ部分の形を変えて元に戻してみて、ちゃんと元の音の様に鳴るのかというのをやってみたかった  
ファイル名と実態が違ったりしますが、許し亭許して

encode.c: 各要素が1バイトで表現されているwavファイルを16進数で表現されたものに変換(ex. 255 -> FF, 15 -> 0F)する  
binary_encode.c: 0から順にビット長が長くなるような符号化(ex. 0 -> 0(1bit), 1 -> 10(2bit), ..., 255 -> 11...10(256bit)) 
