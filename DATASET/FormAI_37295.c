//FormAI DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

int main() {

    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename to recover data from: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("File not found.");
        return 0;
    }

    char outputfilename[MAX_FILENAME_LENGTH];
    printf("Enter the filename for the recovered data: ");
    scanf("%s", outputfilename);

    FILE *outfp = fopen(outputfilename, "wb");

    char buffer[MAX_BUFFER_SIZE];
    int bytesRead = 0;
    int bytesWritten = 0;

    while((bytesRead = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {
        for(int i = 0; i < bytesRead; i++) {
            buffer[i] ^= 0xFF;
        }
        bytesWritten = fwrite(buffer, 1, bytesRead, outfp);
        if(bytesWritten != bytesRead) {
            printf("Error writing to output file.");
            return 0;
        }
    }

    fclose(fp);
    fclose(outfp);

    printf("Data recovery successful!");

    return 0;
}