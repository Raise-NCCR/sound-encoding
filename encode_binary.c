#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input_fp = fopen("a.wav", "r");
    FILE *output_fp = fopen("binary_encoded", "w");
    unsigned char chunk[44];
    size_t data_length = 10100;
    size_t data_idx = 0;
    size_t input_length;
    unsigned char input_data[50000];
    unsigned char *data = calloc(data_length, 90000);
    fread(chunk, 1, 44, input_fp);
    fwrite(chunk, 1, 44, output_fp);
    while (input_length = fread(input_data, 1, 10000, input_fp))
    {
        for (int i = 0; i < input_length; i++)
        {
            for (unsigned char binary_length = 0; binary_length < input_data[i]; binary_length++)
            {
                data[binary_length] = 1;
            }
            data[input_data[i]] = 0;
            fwrite(data, 1, input_data[i] + 1, output_fp);
        }
    }
    return 0;
}