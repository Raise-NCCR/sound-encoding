base16: base16_encode base16_decode
	./base16_encode.out && ./base16_decode.out

base16-all: clean base16

base16_encode:
	gcc -g base16_encode.c -o base16_encode.out

base16_decode:
	gcc -g base16_decode.c -o base16_decode.out

clean:
	rm *.out *decoded.wav *encoded