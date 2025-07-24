//FormAI DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char file_name[50];
    printf("Enter File Name: ");
    scanf("%s",file_name);

    FILE *fp_in, *fp_out;
    fp_in = fopen(file_name,"rb");   

    if(fp_in == NULL)
    {
        printf("\nSorry, Cannot open file!");
        exit(0);
    }

    char new_file[60] = "encrypted_";
    strcat(new_file, file_name);
    fp_out = fopen(new_file,"wb");

    if(fp_out == NULL)
    {
        printf("\nSorry, Cannot create file!");
        exit(1);
    }

    char ch;
    int key = 5;  // Encryption key

    while(1)
    {
        ch = fgetc(fp_in);

        if(ch == EOF)
            break;

        ch = ch + key;  //Encryption process

        fputc(ch,fp_out);
    }

    printf("\nEncryption successful!");

    fclose(fp_in);
    fclose(fp_out);
}