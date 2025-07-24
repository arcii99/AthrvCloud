//FormAI DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

int main() {
    struct Book c_ebook; // Creating the structure
    strcpy(c_ebook.title, "The C Programming Language"); // Adding values to the structure
    strcpy(c_ebook.author, "Brian Kernighan and Dennis Ritchie");
    c_ebook.pages = 272;
    c_ebook.price = 29.99;

    FILE *fp = fopen("c_ebook.txt", "w"); // Opening a file to write the Ebook details
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "Title: %s\n", c_ebook.title); // Writing the structure details to the file
    fprintf(fp, "Author: %s\n", c_ebook.author);
    fprintf(fp, "Pages: %d\n", c_ebook.pages);
    fprintf(fp, "Price: $%.2f\n", c_ebook.price);

    fclose(fp); // Closing the file
    
    fp = fopen("c_ebook.txt", "r"); // Opening the file to read Ebook details
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    char line[100];

    while(fgets(line, 100, fp) != NULL){ // Reading file line by line and printing it out
        printf("%s", line);
    }

    fclose(fp); // Closing the file

    return 0;
}