//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *filename) {
    FILE *fp;
    fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = malloc(sizeof(char)*size);
    fread(buffer, size, 1, fp);
    fclose(fp);
    fp = fopen(filename, "wb");
    int key = 42; // the answer to life, the universe, and everything
    for(int i=0; i<size; i++) {
        char c = buffer[i] ^ key;
        fprintf(fp, "%c", c);
    }
    fclose(fp);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide a file name to encrypt\n");
        return -1;
    }
    char *filename = argv[1];

    printf("Encrypting file '%s'...\n", filename);
    encrypt(filename);
    printf("Done! Your file has been encrypted with the utmost of security measures!\n");
    return 0;
}