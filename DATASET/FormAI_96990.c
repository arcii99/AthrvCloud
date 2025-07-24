//FormAI DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(FILE *fpin, FILE *fpout, char *password)
{
    int c;
    int i = 0;
    int pw_len = strlen(password);
    while ((c = fgetc(fpin)) != EOF)
    {
        fputc(c ^ password[i], fpout);
        i = (i + 1) % pw_len;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s [input file] [output file] [password]\n", argv[0]);
        return 1;
    }

    FILE *fpin = fopen(argv[1], "r");
    if (!fpin)
    {
        printf("Could not open %s for reading\n", argv[1]);
        return 1;
    }

    FILE *fpout = fopen(argv[2], "w");
    if (!fpout)
    {
        printf("Could not open %s for writing\n", argv[2]);
        return 1;
    }

    encrypt(fpin, fpout, argv[3]);

    fclose(fpin);
    fclose(fpout);

    return 0;
}