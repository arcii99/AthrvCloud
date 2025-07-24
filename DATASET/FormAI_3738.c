//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define an eBook struct
typedef struct {
    char* author;
    char* title;
    char* filename;
} eBook;

// Define a function to read an eBook file
void read_eBook(char* filename) {
    FILE* file = fopen(filename, "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    eBook myEbook;

    // Set the author, title, and filename of the eBook
    myEbook.author = "Jane Doe";
    myEbook.title = "My Awesome eBook";
    myEbook.filename = "my_ebook.txt";

    // Display the author, title, and prompt the user to read the eBook
    printf("Author: %s\n", myEbook.author);
    printf("Title: %s\n", myEbook.title);
    printf("Would you like to read this book? (y/n): ");

    // Get the user's input
    char choice;
    scanf("%c", &choice);

    // Handle the user's choice
    if (choice == 'y') {
        read_eBook(myEbook.filename);
    } else {
        printf("Maybe next time!\n");
    }

    // Exit the program
    return 0;
}