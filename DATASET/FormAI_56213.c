//FormAI DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char* title = "The Elephant in the Room: A Surrealist Tale";
    char* author = "Max Ernst";
    int num_pages = 200;
    int current_page = 1;
    char* book_content = "Once upon a time in a far-off land, there lived an elephant who was taller than the tallest trees and stronger than the strongest men. He had a heart of gold and a spirit that could not be broken. One day, he wandered into a room filled with strange objects and peculiar creatures. As he explored this strange new world, he met a group of people who were unlike anything he had ever seen before. They were chess pieces come to life, and they had a challenge for him...";
    
    printf("Welcome to the Surrealist Ebook Reader!\n");
    printf("Title: %s\n", title);
    printf("Author: %s\n", author);
    printf("Number of pages: %d\n\n", num_pages);
    
    printf("You are currently on page %d.\n", current_page);
    printf("%s\n", book_content);
    
    // Page-turning functionality
    char user_input;
    while (1) {
        printf("\nEnter 'n' to go to the next page or 'p' to go to the previous page.\n");
        scanf(" %c", &user_input);
        
        if (user_input == 'n') {
            if (current_page < num_pages) {
                current_page++;
                printf("\nYou are now on page %d.\n", current_page);
            } else {
                printf("\nYou have reached the end of the book.\n");
                break;
            }
        } else if (user_input == 'p') {
            if (current_page > 1) {
                current_page--;
                printf("\nYou are now on page %d.\n", current_page);
            } else {
                printf("\nYou are already on the first page.\n");
            }
        } else {
            printf("\nSorry, I didn't understand that input. Please enter 'n' or 'p'.\n");
        }
    }
    
    printf("\nThank you for reading The Elephant in the Room!\n");
    
    return 0;
}