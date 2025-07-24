//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "This is a virus"

int main(int argc, char *argv[]) {
    int files_scanned = 0;
    int viruses_found = 0;
    char user_input[256];

    printf("Welcome to C Antivirus Scanner\n");
    printf("Please enter the name of the file you would like to scan: ");
    scanf("%s", user_input);

    FILE *file_pointer = fopen(user_input, "r");
    if (file_pointer == NULL) {
        printf("Error: Could not open file %s\n", user_input);
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, 1024, file_pointer) != NULL) {
        if (strstr(buffer, VIRUS_SIGNATURE) != NULL) {
            printf("\n\n*****VIRUS FOUND!*****\n\n");
            viruses_found++;
        }
        files_scanned++;
    }

    printf("Scanned %d files and found %d viruses\n", files_scanned, viruses_found);
    fclose(file_pointer);
    return 0;
}