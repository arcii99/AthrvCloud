//FormAI DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secretkey"
#define KEY_LEN 9

int main(int argc, char *argv[]) 
{
    if (argc < 3) 
    {
        printf("Usage: %s [input file] [output file]\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    FILE *infile, *outfile;
    char key[KEY_LEN + 1];
    strncpy(key, KEY, KEY_LEN);

    infile = fopen(input_filename, "rb");
    if (infile == NULL) 
    {
        printf("Error opening input file.\n");
        return 1;
    }

    outfile = fopen(output_filename, "wb");
    if (outfile == NULL) 
    {
        printf("Error opening output file.\n");
        fclose(infile);
        return 1;
    }

    int ch, keypos = 0;
    while ((ch = fgetc(infile)) != EOF) 
    {
        fputc(ch ^ key[keypos], outfile);
        keypos = (keypos + 1) % KEY_LEN;
    }

    fclose(infile);
    fclose(outfile);
    printf("Encryption complete.\n");
    return 0;
}