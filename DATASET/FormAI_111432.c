//FormAI DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>

void printBook(char* bookTitle, int chapter, int page){
    printf("You are currently reading \"%s\", Chapter %d, Page %d.\n", bookTitle, chapter, page);
}

int main(){

    char* bookTitle = "A Tale of Two Cities";
    int chapter = 1, page = 1;

    printBook(bookTitle, chapter, page);

    printf("Would you like to go to the next page? (Y/N)");
    char userChoice;
    scanf("%c", &userChoice);

    if(userChoice == 'Y' || userChoice == 'y'){
        page++;
        printf("Page %d\n", page);
    }

    printf("Would you like to go to the next Chapter? (Y/N)");
    scanf(" %c", &userChoice);

    if(userChoice == 'Y' || userChoice == 'y'){
        chapter++;
        page = 1;
        printf("Chapter %d, Page %d\n", chapter, page);
    }

    return 0;
}