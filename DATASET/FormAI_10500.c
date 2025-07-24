//FormAI DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>

int main() {
    // Welcome message
    printf("Welcome to the Future E-Book Reader!\n\n");

    // Prompt user to enter book title
    char bookTitle[50];
    printf("Please enter the title of the book: ");
    scanf("%[^\n]s", bookTitle); // read entire line, including spaces

    // Open book file
    FILE* bookFile = fopen(strcat(bookTitle, ".txt"), "r");

    // Check if file was opened successfully
    if (bookFile == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Display book title
    printf("\n\n%s\n\n", bookTitle);

    // Read and display book contents
    char bookContent[1000];
    while (fgets(bookContent, sizeof(bookContent), bookFile) != NULL) {
        printf("%s", bookContent);
    }

    // Close book file
    fclose(bookFile);

    // End program
    return 0;
}