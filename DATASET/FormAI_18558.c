//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recoverData(char* filename, char* recoveredFilename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Input file does not exist.\n");
        return;
    }
    FILE *recoveredFptr = fopen(recoveredFilename, "w");
    if (recoveredFptr == NULL) {
        printf("Could not create output file.\n");
        fclose(fptr);
        return;
    }
    fseek(fptr, 0, SEEK_END);
    long numBytes = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    char* data = (char*)malloc(numBytes * sizeof(char));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fptr);
        fclose(recoveredFptr);
        return;
    }
    fread(data, 1, numBytes, fptr);
    for (long i = 0; i < numBytes; i++) {
        if (data[i] == 's') {
            data[i] = 'S';
        } else if (data[i] == 'h') {
            data[i] = 'H';
        } else if (data[i] == 'i') {
            data[i] = 'I';
        } else if (data[i] == 'f') {
            data[i] = 'F';
        } else if (data[i] == 't') {
            data[i] = 'T';
        } else if (data[i] == ' ') {
            data[i] = '_';
        }
    }
    fwrite(data, 1, numBytes, recoveredFptr);
    free(data);
    fclose(fptr);
    fclose(recoveredFptr);
}

int main() {
    char* filename = "input.txt";
    char* recoveredFilename = "recovered.txt";
    recoverData(filename, recoveredFilename);
    return 0;
}