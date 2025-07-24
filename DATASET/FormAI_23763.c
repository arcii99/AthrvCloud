//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_WATERMARK_SIZE 32
#define MAX_FILE_NAME_SIZE 100

// Function declarations
void add_watermark_to_file(FILE* source_file, char* watermark);

int main(void) {
    char watermark[MAX_WATERMARK_SIZE];
    char source_file_name[MAX_FILE_NAME_SIZE];
    
    printf("Enter the watermark: \n");
    fgets(watermark, MAX_WATERMARK_SIZE, stdin);
    
    printf("Enter the name of the source file: \n");
    fgets(source_file_name, MAX_FILE_NAME_SIZE, stdin);
    
    // Remove newline character from input strings
    watermark[strcspn(watermark, "\n")] = 0;
    source_file_name[strcspn(source_file_name, "\n")] = 0;
    
    FILE* source_file = fopen(source_file_name, "rb+");
    
    if (source_file == NULL) {
        printf("Error opening source file.\n");
        exit(1);
    }

    add_watermark_to_file(source_file, watermark);
    
    fclose(source_file);
    printf("Watermark added successfully!\n");

    return 0;
}

void add_watermark_to_file(FILE* source_file, char* watermark) {
    fseek(source_file, 0L, SEEK_END);
    long int file_size = ftell(source_file);
    rewind(source_file);
    
    for (int i = 0; i < strlen(watermark); i++) {
        fputc(watermark[i], source_file);
    }
    
    long int watermark_end_position = ftell(source_file);
    
    // Add padding to ensure watermark ends at the end of the file
    for (int i = watermark_end_position; i < file_size; i++) {
        fputc('\0', source_file);
    }
}