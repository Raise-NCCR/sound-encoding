#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input_fp = fopen("a.wav", "r");
    FILE *output_fp = fopen("variable_bit_length_encoded", "w");
    unsigned char chunk[44];
    size_t data_length = 10100;
    size_t data_idx = 0;
    size_t encoded_data_idx = 0;
    size_t input_length;
    unsigned char input_data[50000];
    unsigned char *data = calloc(data_length, 1000000);
    unsigned char *encoded_data = calloc(data_length, 100000);
    fread(chunk, 1, 44, input_fp);
    fwrite(chunk, 1, 44, output_fp);
    while (input_length = fread(input_data, 1, 10000, input_fp))
    {
        for (int i = 0; i < input_length; i++)
        {
            for (unsigned char binary_length = 0; binary_length < input_data[i]; binary_length++)
            {
                data[data_idx + binary_length] = 1;
            }
            data[data_idx + input_data[i]] = 0;
            data_idx += input_data[i] + 1;
        }
    }
    for (int i = 0; i < data_idx; i++)
    {
        unsigned char num = 0;
        for (int j = 0; j < 8; j++)
        {
            num = num * 2 + data[i + j];
        }
        encoded_data[encoded_data_idx++] = num;
        i += 7;
    }
    fwrite(encoded_data, 1, encoded_data_idx, output_fp);
    return 0;
}