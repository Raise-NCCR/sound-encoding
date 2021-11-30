all: clean encode decode
	./encode && ./decode

encode:
	gcc -g encode.c -o encode

decode:
	gcc -g decode.c -o decode

clean:
	rm encode decode encoded decoded.wav