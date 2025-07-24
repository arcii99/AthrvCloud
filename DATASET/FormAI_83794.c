//FormAI DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
// 'Tis but a simple program, my lord,
// A program for reading eBooks we hoard.
// To compile, just run 'gcc reader.c'
// And execute using './a.out <path_to_ebook>'

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // If arguments are not equal to 2,
    // We must scold the user and exit the program.
    if (argc != 2) {
        printf("Thou must pass the path to thy book!\n");
        return 1;
    }
    
    // Let us open the file passed as argument,
    // And assign it to the variable named 'book'.
    FILE *book = fopen(argv[1], "r");
    
    // If book is still NULL, that means,
    // We couldn't open the file for reading.
    if (book == NULL) {
        printf("Alack! Thy book cannot be opened!\n");
        return 1;
    }
    
    printf("Good morrow! Thou art reading: %s\n", argv[1]);
    
    // Reading line by line until the end of the file
    char line[1000];
    while (fgets(line, sizeof(line), book)) {
        printf("%s", line);
    }
    
    printf("\nFarewell! Keep reading, my lord.\n");
    
    // Finally, we must close the file we opened.
    fclose(book);
    
    return 0;
}