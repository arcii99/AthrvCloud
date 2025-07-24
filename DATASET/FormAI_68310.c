//FormAI DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include<stdio.h>

// Structure to hold information about the Ebook
struct EBook {
    char title[50];
    char author[50];
    char format[10];
    float sizeInMB;
    char* content;
};

// Function to display the information about Ebook
void displayEBook(struct EBook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Format: %s\n", ebook.format);
    printf("Size: %.2f MB\n", ebook.sizeInMB);
}

int main() {
    // Creating a sample Ebook
    struct EBook ebook1 = {"The C Programming Language", "Dennis Ritchie", "PDF", 20.5, "#include<stdio.h>\nint main() {\n    printf(\"Hello, world!\");\n    return 0;\n}"};

    // Displaying the information about Ebook
    displayEBook(ebook1);

    // Displaying the content of Ebook
    printf("\nContent:\n%s", ebook1.content);

    return 0;
}