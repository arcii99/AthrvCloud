//FormAI DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining the size of blocks for reading file
#define BLOCK_SIZE 512

//function to recover the file
void recover_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    //search for files in blocks of BLOCK_SIZE
    unsigned char buffer[BLOCK_SIZE];
    int counter = 0;
    char file_name[100];
    FILE* new_file = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, file)) {
        //checking if the block is the start of a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0)) {
            //if a new file is already opened, close it
            if (new_file != NULL) {
                fclose(new_file);
            }
            //generating a new filename
            sprintf(file_name, "%03i.jpg", counter++);
            
            //creating a new file and writing the block into it
            new_file = fopen(file_name, "w");
            fwrite(buffer, BLOCK_SIZE, 1, new_file);
        } else {
            //if the current block is not the start of a new file, just append it to the current file
            if (new_file != NULL) {
                fwrite(buffer, BLOCK_SIZE, 1, new_file);
            }
        }
    }
    //closing the last opened file
    if (new_file != NULL) {
        fclose(new_file);
    }
    fclose(file);
}

int main(int argc, char** argv) {
    //checking if the argument with the filename is provided
    if (argc != 2) {
        printf("Usage: ./recover filename.raw\n");
        return 1;
    }
    recover_file(argv[1]);
    
    printf("File recovery completed successfully\n");
    
    return 0;
}