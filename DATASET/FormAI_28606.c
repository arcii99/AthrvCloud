//FormAI DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if correct number of arguments
    if(argc != 2) {
        printf("Please specify input file.\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    // Check if file exists
    if(file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // Count words in file
    int count = 0;
    int inword = 0;
    char c;

    while((c = getc(file)) != EOF) {
        if(isspace(c)) {
            inword = 0;
        } else if(!inword) {
            inword = 1;
            count++;
        }
    }

    // Print word count
    printf("The file \"%s\" contains %d words.\n", filename, count);

    // Close file
    fclose(file);

    return 0;
}