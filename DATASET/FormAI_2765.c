//FormAI DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a line in the log file
#define MAX_LINES 500        // Maximum number of lines in the log file

int main() {
    char filename[100];   // Name of the log file
    char lines[MAX_LINES][MAX_LINE_LENGTH];  // 2D array to store all lines in the log file
    char search_term[MAX_LINE_LENGTH]; // Search term entered by user
    int num_lines = 0;     // Counter for number of lines in the log file
    int i;    // Loop variable

    printf("Enter the name of the log file: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove trailing newline character

    FILE* fp = fopen(filename, "r"); // Open the log file for reading
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'.\n", filename);
        return 1;
    }

    // Read the contents of the log file into the lines array
    while (fgets(lines[num_lines], MAX_LINE_LENGTH, fp) != NULL) {
        num_lines++;
        if (num_lines == MAX_LINES) {
            printf("Warning: Maximum number of lines (%d) exceeded.\n", MAX_LINES);
            break;
        }
    }

    fclose(fp); // Close the log file

    printf("\nEnter a search term: ");
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = '\0'; // Remove trailing newline character

    int num_matches = 0; // Counter for number of lines that match the search term

    // Search the lines array for lines that match the search term
    for (i = 0; i < num_lines; i++) {
        if (strstr(lines[i], search_term) != NULL) {
            printf("%s", lines[i]);
            num_matches++;
        }
    }

    if (num_matches == 0) {
        printf("No matches found.\n");
    } else {
        printf("%d match(es) found.\n", num_matches);
    }

    return 0;
}