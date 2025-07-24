//FormAI DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char *key = (char*) malloc(sizeof(char)*strlen(argv[2]));
    int i;
    for(i=0; i<strlen(argv[2]); i++) {
        key[i] = argv[2][i] ^ rand()%255;
    }
    FILE *fp_in, *fp_out;
    fp_in = fopen(argv[1], "rb");
    fp_out = fopen("encrypted.bin", "wb");
    if (fp_in == NULL || fp_out == NULL) {
        printf("Error: Unable to open files!");
        exit(1);
    }
    char byte;
    int j=0;
    while(fread(&byte, sizeof(char), 1, fp_in)) {
        byte ^= key[j++ % strlen(argv[2])];
        fwrite(&byte, sizeof(char), 1, fp_out);
    }
    fclose(fp_in);
    fclose(fp_out);
    free(key);
    printf("File encrypted successfully!");
    return 0;
}