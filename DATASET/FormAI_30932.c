//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./data_recovery <memory_card_image>\n");
        return 1;
    }

    // Opening file for reading
    FILE *card = fopen(argv[1], "r");
    if(card == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Creating output file
    FILE *recovered_file = NULL;
    char filename[8], buffer[BLOCK_SIZE];
    int file_count = 0;
    while(fread(buffer, BLOCK_SIZE, 1, card) == 1) {
        // Check if block starts with jpeg signature
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            if(recovered_file != NULL) {
                fclose(recovered_file);
            }
            sprintf(filename, "%03i.jpg", file_count++);
            recovered_file = fopen(filename, "w");
        }
        if(recovered_file != NULL) {
            fwrite(buffer, BLOCK_SIZE, 1, recovered_file);
        }
    }

    // Closing files
    if(recovered_file != NULL) {
        fclose(recovered_file);
    }
    fclose(card);

    printf("Data recovery completed successfully!\n");

    return 0;
}