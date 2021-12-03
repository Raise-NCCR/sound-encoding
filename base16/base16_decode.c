#include <stdio.h>
#include <stdlib.h>

unsigned char index_of(char c)
{
    unsigned char index = 0;
    unsigned char *base16 = "0123456789ABCDEF";
    while(base16[index] != c)
    {
        index++;
    }
    return index;
}

int main(int argc, char *argv[])
{
    FILE *input_fp = fopen("base16_encoded", "r");
    FILE *output_fp = fopen("base16_decoded.wav", "wb");
    unsigned char chunk[44];
    size_t data_length = 10100;
    size_t data_idx = 0;
    size_t input_length;
    unsigned char input_data[10000];
    unsigned char *data = calloc(data_length, 90000);
    fread(chunk, 1, 44, input_fp);
    fwrite(chunk, 1, 44, output_fp);
    while (input_length = fread(input_data, 1, 10000, input_fp))
    {
        for (int i = 0; i < input_length; i++)
        {
            data[data_idx] = 16 * index_of(input_data[i]);
            i++;
            data[data_idx] += index_of(input_data[i]);
            data_idx++;
        }
    }
    fwrite(data, 1, data_idx, output_fp);
    return 0;
}