//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];
    long int file_size;

    if(argc!=3){
        printf("Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source = fopen(argv[1], "rb");
    destination = fopen(argv[2], "wb");

    if(source == NULL || destination == NULL){
        printf("Error opening files!");
        exit(EXIT_FAILURE);
    }

    fseek(source, 0L, SEEK_END);
    file_size = ftell(source);
    rewind(source);

    printf("Scanning file for recoverable data...\n");

    while(file_size > 0){
        size_t read_size = BUFFER_SIZE;
        if(file_size < BUFFER_SIZE) read_size = file_size;
        fread(buffer, read_size, 1, source);
        fwrite(buffer, read_size, 1, destination);
        file_size -= read_size;
    }

    printf("Data recovery successful!\n");

    fclose(source);
    fclose(destination);

    return 0;
}