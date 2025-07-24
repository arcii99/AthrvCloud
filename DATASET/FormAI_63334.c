//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    char* bookTitle = "The Happy Coder";
    bool isEbook = true;
    int pageCount = 120;
    float version = 1.2;
    char* author[] = {"Sunny Sun", "Rainy Rainbow"};

    printf("Welcome to the C Ebook Reader!\n\n");
    printf("Title: %s\n", bookTitle);
    printf("Author(s): %s & %s\n", author[0], author[1]);
    printf("Page Count: %d\n", pageCount);
    printf("Version: %.1f\n\n", version);

    if (isEbook) {
        printf("This book is an ebook!\n");
    } else {
        printf("This book is a physical book!\n");
    }

    char* bookContents = "Once upon a time, there was a happy coder named Sunny. \
    Sunny loved coding and always had a smile on his face when he wrote his programs. \
    One day, he wrote a program that made him so happy that he wanted to share it with everyone!";

    printf("\nWould you like to read the book? (y/n): ");
    char answer = getchar();

    if (answer == 'y' || answer == 'Y') {
        printf("\nGreat! Let's get started.\n\n");

        printf("%s\n\n", bookContents);
        printf("End of book. We hope you enjoyed it!\n");
    } else {
        printf("\nNo problem, maybe next time!\n");
    }

    return 0;
}