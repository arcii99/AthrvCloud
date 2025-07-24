//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: careful
#include <stdio.h>
#include <string.h>

// function declarations
void extractMetadata(char *fileContent);

int main() {
    // sample file content
    char fileContent[] = "Title: The Great Gatsby\nAuthor: F. Scott Fitzgerald\nYear: 1925\nGenre: Novel\nPublisher: Charles Scribner's Sons\n";

    // call function to extract metadata
    extractMetadata(fileContent);

    return 0;
}

void extractMetadata(char *fileContent) {
    // declare variables
    char *token, *string, *delimiter = "\n";

    // split file content by delimiter
    string = strtok(fileContent, delimiter);

    // loop through each line and extract metadata
    while (string != NULL) {
        // split line by colon
        token = strtok(string, ":");

        // check if token is not NULL and print metadata
        if (token != NULL) {
            printf("%s: ", token);

            // get value of metadata
            token = strtok(NULL, ":");

            // remove any leading/trailing space from value
            char *value = token;
            while (*value == ' ') {
                value++;
            }
            int len = strlen(value) - 1;
            while (value[len] == ' ') {
                value[len--] = 0;
            }

            // print value of metadata
            printf("%s\n", value);
        }

        // split next line by delimiter
        string = strtok(NULL, delimiter);
    }
}