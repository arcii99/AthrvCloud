//FormAI DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>

#define BLOCK_SIZE 512
#define FILENAME_SIZE 100

int main(){
    FILE *input_file;
    char filename[FILENAME_SIZE];
    char block[BLOCK_SIZE];
    int block_number = 0;

    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    input_file = fopen(filename, "rb");

    if(input_file == NULL) {
        printf("File not found!\n");
        return 0;
    }

    while(fread(block, sizeof(char), BLOCK_SIZE, input_file) == BLOCK_SIZE) {
        block_number++;
    }

    printf("File recovered successfully! It had %d blocks.\n", block_number);

    fclose(input_file);
    return 0;
}