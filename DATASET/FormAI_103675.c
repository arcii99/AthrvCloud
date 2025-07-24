//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    
    FILE* fp;
    char filename[50], c;
    char* buffer;
    long size;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    buffer = (char*)malloc((size+1)*sizeof(char));
    memset(buffer, 0, size+1);

    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(fp);
        exit(1);
    }

    fread(buffer, sizeof(char), size, fp);
    fclose(fp);

    printf("Recovered data from file %s: %s", filename, buffer);

    free(buffer);
    return 0;
}