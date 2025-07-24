//FormAI DATASET v1.0 Category: File Encyptor ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(FILE *in, FILE *out, char *key){
    int c, i = 0;
    int keylen = strlen(key);
    while((c = fgetc(in)) != EOF){
        fputc(c ^ key[i % keylen], out);
        i++;
    }
}

void decrypt(FILE *in, FILE *out, char *key){
    encrypt(in, out, key);
}

int main(int argc, char **argv){
    if(argc < 4){
        fprintf(stderr, "Usage: %s <input file> <output file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *infile = argv[1];
    char *outfile = argv[2];
    char *key = argv[3];

    FILE *in = fopen(infile, "r");
    FILE *out = fopen(outfile, "w");

    if(!in || !out){
        fprintf(stderr, "Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    encrypt(in, out, key);

    fclose(in);
    fclose(out);

    printf("Encryption complete.\n");

    return 0;
}