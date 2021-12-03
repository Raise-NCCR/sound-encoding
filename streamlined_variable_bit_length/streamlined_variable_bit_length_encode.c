#include <stdio.h>
#include <stdlib.h>

struct Num_count
{
    unsigned char num;
    int count;
};
typedef struct Num_count Num_count;

unsigned char index_of(unsigned char order[], unsigned char c)
{
    unsigned char index = 0;
    while(order[index] != c)
    {
        index++;
    }
    return index;
}


int main(int argc, char *argv[])
{
    FILE *input_fp = fopen("a.wav", "r");
    FILE *output_fp = fopen("streamlined_variable_bit_length_encoded", "w");
    unsigned char chunk[44];
    size_t data_length = 10100;
    size_t data_idx = 0;
    size_t midway_data_idx = 0;
    size_t encoded_data_idx = 0;
    size_t input_length;
    Num_count count[256];
    unsigned char order[256];
    unsigned char input_data[50000];
    unsigned char *data = calloc(data_length, 100000);
    unsigned char *midway_data = calloc(data_length, 1000000);
    unsigned char *encoded_data = calloc(data_length, 100000);
    for (int i = 0; i < 256; i++)
    {
        count[i].num = i;
        count[i].count = 0;
    }
    fread(chunk, 1, 44, input_fp);
    fwrite(chunk, 1, 44, output_fp);
    while (input_length = fread(input_data, 1, 10000, input_fp))
    {
        for (int i = 0; i < input_length; i++)
        {
            count[input_data[i]].count++;
            data[data_idx++] = input_data[i];
        }
    }
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            if (count[j].count < count[j + 1].count)
            {
                Num_count tmp = count[j];
                count[j] = count[j + 1];
                count[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 256; i++)
    {
        order[i] = count[i].num;
    }
    for (int i = 0; i < data_idx; i++)
    {
        for (unsigned char binary_length = 0; binary_length < index_of(order, data[i]); binary_length++)
        {
            midway_data[midway_data_idx++] = 1;
        }
        midway_data[midway_data_idx++] = 0;
    }
    for (int i = 0; i < midway_data_idx; i++)
    {
        unsigned char num = 0;
        for (int j = 0; j < 8; j++)
        {
            if (i + j >= midway_data_idx)
            {
                num = num * 2;
                continue;
            }
            num = num * 2 + midway_data[i + j];
        }
        encoded_data[encoded_data_idx++] = num;
        i += 7;
    }
    fwrite(order, 1, 256, output_fp);
    fwrite(encoded_data, 1, encoded_data_idx, output_fp);
    return 0;
}