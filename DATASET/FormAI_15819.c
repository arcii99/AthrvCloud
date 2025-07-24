//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// Function to check if a string contains a given substring
int contains_substring(char* string, char* substring) {
    if (strstr(string, substring) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char metadata[MAX_LEN] = "// Author: John Smith\n"
                             "// Date: 7/12/2021\n"
                             "// Description: This program extracts metadata from a given file";

    char* author = strstr(metadata, "Author: ");
    char* date = strstr(metadata, "Date: ");
    char* description = strstr(metadata, "Description: ");

    printf("Author: %s\n", &author[8]);
    printf("Date: %s\n", &date[6]);
    printf("Description: %s\n", &description[13]);

    if (contains_substring(metadata, "Version: ")) {
        char* version = strstr(metadata, "Version: ");
        printf("Version: %s\n", &version[9]);
    }

    return 0;
}