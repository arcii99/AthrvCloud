//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 1024 // maximum size for recovered data in bytes

int main() {
    char* data = (char*) malloc(MAX_DATA_SIZE * sizeof(char)); // allocate memory for recovered data
    if (data == NULL) {
        printf("Failed to allocate memory for recovered data\n");
        return 1;
    }

    FILE* fp = fopen("backup.bin", "rb"); // attempt to open backup file
    if (fp == NULL) {
        printf("Failed to open backup file\n");
        free(data);
        return 1;
    }

    int fileSize;
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp); // get filesize
    rewind(fp);

    if (fileSize > MAX_DATA_SIZE) { // make sure recovered data will fit in buffer
        printf("File too large to recover\n");
        free(data);
        fclose(fp);
        return 1;
    }

    int bytesRead = 0;
    while (!feof(fp)) { // read file into buffer
        bytesRead += fread(data+bytesRead, 1, MAX_DATA_SIZE-bytesRead, fp);
    }

    fclose(fp);

    printf("Recovered data:\n");
    for (int i = 0; i < bytesRead; i++) { // print recovered data as ASCII characters
        printf("%c", *(data+i));
    }

    free(data); // free allocated memory
    return 0;
}