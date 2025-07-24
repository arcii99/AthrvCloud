//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ebook {
    char title[50];
    char author[50];
    char publisher[50];
    int year;
    char extension[10];
    float size;
    char filepath[100];
};

void displayEbook(struct Ebook ebook){
    printf("\n");
    printf("=============================\n");
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Publisher: %s\n", ebook.publisher);
    printf("Year: %d\n", ebook.year);
    printf("Extension: %s\n", ebook.extension);
    printf("Size: %.2f MB\n", ebook.size);
    printf("=============================\n");
    printf("\n");
}

int main(){
    char filename[30];
    char extension[10];
    char filepath[100] = "Ebooks/";
    struct Ebook ebooks[5];
    int num_ebooks = sizeof(ebooks)/sizeof(ebooks[0]);

    //initialize ebook data
    strcpy(ebooks[0].title, "Harry Potter and the Sorcerer's Stone");
    strcpy(ebooks[0].author, "J.K. Rowling");
    strcpy(ebooks[0].publisher, "Bloomsbury");
    ebooks[0].year = 1997;
    strcpy(ebooks[0].extension, "PDF");
    ebooks[0].size = 2.1;
    strcpy(ebooks[0].filepath, "harry_potter.pdf");

    strcpy(ebooks[1].title, "To Kill a Mockingbird");
    strcpy(ebooks[1].author, "Harper Lee");
    strcpy(ebooks[1].publisher, "J. B. Lippincott & Co.");
    ebooks[1].year = 1960;
    strcpy(ebooks[1].extension, "ePub");
    ebooks[1].size = 0.53;
    strcpy(ebooks[1].filepath, "mockingbird.epub");

    strcpy(ebooks[2].title, "1984");
    strcpy(ebooks[2].author, "George Orwell");
    strcpy(ebooks[2].publisher, "Secker & Warburg");
    ebooks[2].year = 1949;
    strcpy(ebooks[2].extension, "Mobi");
    ebooks[2].size = 0.84;
    strcpy(ebooks[2].filepath, "1984.mobi");

    strcpy(ebooks[3].title, "Pride and Prejudice");
    strcpy(ebooks[3].author, "Jane Austen");
    strcpy(ebooks[3].publisher, "T. Egerton, Whitehall");
    ebooks[3].year = 1813;
    strcpy(ebooks[3].extension, "PDF");
    ebooks[3].size = 1.5;
    strcpy(ebooks[3].filepath, "pride_and_prejudice.pdf");

    strcpy(ebooks[4].title, "The Catcher in the Rye");
    strcpy(ebooks[4].author, "J.D. Salinger");
    strcpy(ebooks[4].publisher, "Little, Brown and Company");
    ebooks[4].year = 1951;
    strcpy(ebooks[4].extension, "ePub");
    ebooks[4].size = 0.76;
    strcpy(ebooks[4].filepath, "catcher.epub");

    //display all the ebooks
    printf("Welcome to the Ebook Reader!\n");
    printf("The following ebooks are available to read:\n");
    for(int i=0; i<num_ebooks; i++){
        displayEbook(ebooks[i]);
    }

    //ask user to choose an ebook
    int chosen_book;
    printf("Which book would you like to read? (Enter a number)\n");
    scanf("%d", &chosen_book);

    //validate user input
    while(chosen_book < 1 || chosen_book > num_ebooks){
        printf("Please enter a valid number.\n");
        scanf("%d", &chosen_book);
    }

    //use the chosen ebook filepath to open ebook in default program
    strcat(filepath, ebooks[chosen_book-1].filepath);
    printf("Opening %s...\n", ebooks[chosen_book-1].title);
    system(filepath);

    return 0;
}