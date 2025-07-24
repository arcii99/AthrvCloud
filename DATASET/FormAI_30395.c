//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned char byte;

unsigned short calculateChecksum(byte *data, int length){
    unsigned int checksum = 0;
    int i;

    for(i = 0; i < length; i++){
        checksum += data[i];
    }
    return ~(checksum % 65536);
}

int main(){

    char inputBuffer[100];
    byte *data;
    int length, i;

    printf("Enter the data to calculate checksum:\n");
    fgets(inputBuffer, 100, stdin);
    length = strlen(inputBuffer) - 1; //remove newline character
    data = (byte*)calloc(length, 1); //allocate memory for data

    //copy input buffer to data array
    for(i=0; i<length; i++){
        data[i] = inputBuffer[i];
    }

    printf("Data: %s", inputBuffer);
    printf("Data size: %d\n", length);
    printf("Checksum: %04X\n", calculateChecksum(data, length));

    free(data); //free allocated memory
    return 0;
}