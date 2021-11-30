#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input_fp = fopen("a.wav", "r");
    FILE *output_fp = fopen("encoded", "w");
    unsigned char chunk[44];
    size_t data_length = 10100;
    size_t data_idx = 0;
    size_t input_length;
    unsigned char input_data[50000];
    unsigned char *data = calloc(data_length, 90000);
    unsigned char *base16 = "0123456789ABCDEF";
    fread(chunk, 1, 44, input_fp);
    fwrite(chunk, 1, 44, output_fp);
    while (input_length = fread(input_data, 1, 10000, input_fp))
    {
        for (int i = 0; i < input_length; i++)
        {
            data[data_idx] = base16[input_data[i]/16];
            data_idx++;
            data[data_idx] = base16[input_data[i]%16];
            data_idx++;
        }
    }
    fwrite(data, 1, data_idx, output_fp);
    return 0;
}