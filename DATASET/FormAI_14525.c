//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>

int main(int argc, char *argv[]) {

    //check if file name is specified
    if (argc < 2) {
        printf("Please specify a file name.\n");
        return 1;
    }

     //open the file in read-only mode 
    FILE *file = fopen(argv[1], "r");

    //check if file exists and can be read
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    int count = 0;
    int in_word = 0;
    char c;

    //read each character in the file
    while ((c = fgetc(file)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        }
        else if (c == '.' || c == ',' || c == '?' || c == '!' || c == ':' || c == ';') {
            if (in_word) {
                count++;
                in_word = 0;
            }
        }
        else {
            in_word = 0;
        }
    }

    printf("Number of words: %d\n", count);

    //close the file
    fclose(file);

    return 0;
}