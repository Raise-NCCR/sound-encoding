binary: binary-encode binary-decode
	./binary_encode && ./binary_decode

binary-all: clean binary

binary-encode:
	gcc -g binary_encode.c -o binary_encode.out

binary-decode:
	gcc -g binary_decode.c -o binary_decode.out

normal: encode decode
	./encode.out && ./decode.out

normal-all: clean normal

encode:
	gcc -g encode.c -o encode.out

decode:
	gcc -g decode.c -o decode.out

clean:
	rm *.out *decoded.wav *encoded