//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int ch, pos=0, bytesread, filesize;
    char filename[40], output[20];

    printf("Enter the name of the file to be recovered: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if(fp == NULL) {
        perror("Error");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);

    printf("Enter the output filename: ");
    scanf("%s", output);

    FILE *out = fopen(output, "wb");
    if(out == NULL) {
        perror("Error");
        exit(1);
    }

    printf("File Recovery in progress...\n");

    while(pos < filesize) {
        ch = fgetc(fp);
        if(ch == EOF) break;
        bytesread = fwrite(&ch, 1, 1, out);
        if(bytesread != 1) {
            printf("Error while recovering the file.\n");
            exit(1);
        }
        pos++;
    }

    printf("File Recovery successful.");
    fclose(fp);
    fclose(out);

    return 0;
}