//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Welcome to the Unique C Metadata Extractor!\n");

    // Initialize example metadata
    char *file_name = "example.c";
    char *author_name = "Joe Smith";
    int num_lines = 42;
    int num_functions = 3;
    char *last_modified = "2022-01-01";
    
    // Print metadata to console
    printf("\nFile Name: %s\n", file_name);
    printf("Author Name: %s\n", author_name);
    printf("Number of Lines: %d\n", num_lines);
    printf("Number of Functions: %d\n", num_functions);
    printf("Last Modified Date: %s\n", last_modified);
    
    // Write metadata to file
    FILE *fp;
    fp = fopen("metadata.txt", "w");
    fprintf(fp, "File Name: %s\n", file_name);
    fprintf(fp, "Author Name: %s\n", author_name);
    fprintf(fp, "Number of Lines: %d\n", num_lines);
    fprintf(fp, "Number of Functions: %d\n", num_functions);
    fprintf(fp, "Last Modified Date: %s\n", last_modified);
    fclose(fp);

    // Exit message
    printf("\nMetadata has been successfully extracted and saved to metadata.txt!\n");

    return 0;
}