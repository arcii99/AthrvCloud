//FormAI DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char file_name[50], ch;
    FILE *fp_in, *fp_out;
    int key;

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", file_name);

    fp_in = fopen(file_name, "r");
    if(fp_in == NULL)
    {
        printf("Error opening file %s!\n", file_name);
        exit(1);
    }

    printf("Enter a key for encryption (1-26): ");
    scanf("%d", &key);

    fp_out = fopen("encrypted.txt", "w");
    while((ch = fgetc(fp_in)) != EOF)
    {
        //Encrypt the file content
        if(ch >= 'a' && ch <= 'z')
        {
            ch = (ch + key - 'a') % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = (ch + key - 'A') % 26 + 'A';
        }
        fputc(ch, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("File %s encrypted successfully!\n", file_name);

    return 0;
}