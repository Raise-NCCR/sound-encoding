#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input_fp = fopen("binary_encoded", "r");
    FILE *output_fp = fopen("binary_decoded.wav", "wb");
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
            unsigned char num = 0;
            while(input_data[i] != 0)
            {
                num++;
                i++;
            }
            data[data_idx] = num;
            data_idx++;
        }
    }
    fwrite(data, 1, data_idx, output_fp);
    return 0;
}