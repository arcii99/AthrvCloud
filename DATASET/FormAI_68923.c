//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

void decimal_binary(int n, char *bin){
    int i = 0, j = 0;
    for(i = 7; i >= 0; i--){
        j = n >> i;
        if(j & 1)
            strcat(bin, "1");
        else
            strcat(bin, "0");
    }
}

void binary_decimal(char *bin, int *p){
    *p = 0;
    int len = strlen(bin) - 1;
    for(int i = 0; i < strlen(bin); i++){
        if(bin[i] == '1')
            *p = *p + pow(2, len);
        len--;
    }
}

void embed(char *input_file, char *output_file, char *r_file, char *watermark){
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");
    FILE *r = fopen(r_file, "r");
    int len = strlen(watermark);

    fseek(in, 0, SEEK_END);
    int length = ftell(in);
    fseek(in, 0, SEEK_SET);

    int n = length / len;
    char buffer[MAX];
    char r_char;
    int k = 0, c = 0;

    while((r_char = fgetc(r)) != EOF){
        char r_binary[9] = {'\0'};
        decimal_binary(r_char, r_binary);

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < n; j++){
                fread(buffer, len, 1, in);
                c++;
                if(k < len){
                    char binary[9] = {'\0'};
                    decimal_binary(buffer[0], binary);
                    binary[7] = r_binary[i];
                    int decimal;
                    binary_decimal(binary, &decimal);
                    fputc(decimal, out);
                    k++;
                }
                else{
                    fwrite(buffer, len, 1, out);
                    memset(buffer, '\0', sizeof(buffer));
                    fread(buffer, len, 1, in);
                    char binary[9] = {'\0'};
                    decimal_binary(buffer[0], binary);
                    binary[7] = r_binary[i];
                    int decimal;
                    binary_decimal(binary, &decimal);
                    fputc(decimal, out);
                    k = 1;
                }
            }
        }
    }
    while(c < length){
        fread(buffer, len, 1, in);
        fwrite(buffer, len, 1, out);
        c++;
    }
    fclose(in);
    fclose(out);
    fclose(r);
}

void extract(char *input_file, char *r_file, int watermark_len){
    FILE *in = fopen(input_file, "rb");
    FILE *r = fopen(r_file, "w");
    char c;
    int k = 0;

    while((c = fgetc(in)) != EOF){
        char binary[9] = {'\0'};
        decimal_binary(c, binary);
        fputc(binary[7], r);
        k++;
        if(k == watermark_len)
            break;
    }
    fclose(in);
    fclose(r);
}

int main(){
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    char r_file[] = "random.txt";
    char watermark[] = "CHATBOT";
    int watermark_len = strlen(watermark);
    embed(input_file, output_file, r_file, watermark);
    extract(output_file, r_file, watermark_len);

    return 0;
}