streamlined_variable: streamlined_variable-encode streamlined_variable-decode
	./streamlined_variable_bit_length_encode.out && ./streamlined_variable_bit_length_decode.out

streamlined_variable-all: clean streamlined_variable_bit_length

streamlined_variable-encode:
	gcc -g streamlined_variable_bit_length_encode.c -o streamlined_variable_bit_length_encode.out

streamlined_variable-decode:
	gcc -g streamlined_variable_bit_length_decode.c -o streamlined_variable_bit_length_decode.out

clean:
	rm *.out *decoded.wav *encoded