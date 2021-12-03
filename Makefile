variable_bit_length: variable_bit_length-encode variable_bit_length-decode
	./variable_bit_length_encode.out && ./variable_bit_length_decode.out

variable_bit_length-all: clean variable_bit_length

variable_bit_length-encode:
	gcc -g variable_bit_length_encode.c -o variable_bit_length_encode.out

variable_bit_length-decode:
	gcc -g variable_bit_length_decode.c -o variable_bit_length_decode.out

normal: encode decode
	./encode.out && ./decode.out

normal-all: clean normal

encode:
	gcc -g encode.c -o encode.out

decode:
	gcc -g decode.c -o decode.out

clean:
	rm *.out *decoded.wav *encoded