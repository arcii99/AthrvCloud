//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include<stdio.h>
#include<string.h>

int main()
{
    char key[100];
    int key_length;
    printf("Enter the key for encryption: ");
    scanf("%s",key);
    key_length = strlen(key);

    FILE *in_file = fopen("input.txt","r");
    FILE *out_file = fopen("output.enc","w");

    char ch;
    int i=0;
    while((ch = fgetc(in_file)) != EOF)
    {
        ch = ch ^ key[i++];
        if(i == key_length) i=0;

        fputc(ch,out_file);
    }

    fclose(in_file);
    fclose(out_file);
    printf("File Successfully Encrypted!!");

    return 0;
}