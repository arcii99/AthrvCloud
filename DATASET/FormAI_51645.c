//FormAI DATASET v1.0 Category: File Encyptor ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY "mysecretkey" //Change this to your own secret key

void encrypt(char* input_file, char* output_file){
    FILE *fpin, *fpout;
    char ch, k;
    int keylen, i = 0;
    keylen = strlen(KEY);
    fpin = fopen(input_file, "r");
    if(fpin == NULL){
        printf("File %s not found.\nExiting...", input_file);
        exit(1);
    }
    fpout = fopen(output_file, "w");
    while((ch = fgetc(fpin)) != EOF){
        k = KEY[i++ % keylen];
        fputc(ch^k, fpout); //XOR Encryption
    }
    fclose(fpin);
    fclose(fpout);
    printf("\nFile encoded successfully!");
}

int main(){
    char input_file[50], output_file[50];
    printf("Enter name of file to encrypt: ");
    scanf("%s", input_file);
    printf("Enter name of output file: ");
    scanf("%s", output_file);
    encrypt(input_file, output_file);
    return 0;
}