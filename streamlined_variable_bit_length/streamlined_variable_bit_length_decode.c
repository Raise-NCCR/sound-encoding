#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input_fp = fopen("streamlined_variable_bit_length_encoded", "r");
    FILE *output_fp = fopen("streamlined_variable_bit_length_decoded.wav", "wb");
    size_t data_length = 10100;
    size_t data_idx = 0;
    size_t input_length;
    unsigned char extra_length;
    unsigned char chunk[44];
    unsigned char order[256];
    unsigned char input_data[10000];
    unsigned char *data = calloc(data_length, 90000);
    unsigned char check_num = 1 << 7;
    fread(chunk, 1, 44, input_fp);
    fwrite(chunk, 1, 44, output_fp);
    fread(order, 1, 256, input_fp);
    while (input_length = fread(input_data, 1, 10000, input_fp))
    {
        int i = 0;
        while (i < input_length)
        {
            unsigned char count = 0;
            while(input_data[i] / check_num != 0)
            {
                count++;
                if (check_num == 1)
                {
                    check_num = 1 << 7;
                    if (i == input_length -1)
                    {
                        if (input_length = fread(input_data, 1, 10000, input_fp))
                        {
                            i = 0;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        i++;
                    }
                    continue;
                }
                input_data[i] %= check_num;
                check_num = check_num >> 1;
            }
            data[data_idx] = order[count];
            data_idx++;
            if (check_num == 1)
            {
                check_num = 1 << 7;
                i++;
                continue;
            }
            check_num = check_num >> 1;
        }
    }
    fwrite(data, 1, data_idx, output_fp);
    return 0;
}