//FormAI DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* filename = argv[1];
    char* word = argv[2];
    FILE* fptr;
    char str[1000];
    int count = 0;
    
    //check if the user has provided input filename and word.
    if (argc != 3) {
        printf("Usage: %s filename word\n", argv[0]);
        return 1;
    }
    
    //open the file in read mode.
    fptr = fopen(filename, "r");
    
    if (fptr == NULL) {
        printf("Error opening %s\n", filename);
        return 2;
    }
    
    //read lines from the file until the end of file.
    while (fgets(str, 1000, fptr) != NULL) {
        char* p = strstr(str, word);
        while (p != NULL) {
            count++;
            p = strstr(p + 1, word);
        }
    }
    
    printf("The word \"%s\" appears %d times in %s\n", word, count, filename);
    fclose(fptr);
    return 0;
}