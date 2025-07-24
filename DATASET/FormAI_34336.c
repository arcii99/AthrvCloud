//FormAI DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct file {
    char name[50];
    int size;
    struct node *head;
};

struct ebook {
    char title[50];
    int pages;
    struct file file_data;
};

int main() {
    int n, i, j, choice;
    printf("How many ebooks do you want to store? ");
    scanf("%d", &n);
    struct ebook books[n]; // dynamic allocation of array of ebooks
    for(i=0; i<n; i++) {
        // inputting book data
        printf("Enter title of book %d: ", i+1);
        scanf(" %[^\n]", &books[i].title);
        printf("Enter number of pages in %s: ", books[i].title);
        scanf("%d", &books[i].pages);
        printf("Enter name of the file for %s: ", books[i].title);
        scanf(" %[^\n]", &books[i].file_data.name);
        printf("Enter size of the file for %s (in KB): ", books[i].title);
        scanf("%d", &books[i].file_data.size);
        // dynamic memory allocation of linked list to store page locations
        books[i].file_data.head = (struct node*) malloc(sizeof(struct node));
        struct node *current = books[i].file_data.head;
        for(j=1; j<=books[i].pages; j++) {
            current->data = j;
            if(j != books[i].pages) {
                current->next = (struct node*) malloc(sizeof(struct node));
                current = current->next;
            }
        }
        current->next = NULL;
    }
    // reading an ebook
    printf("\nWhich book do you want to read?\n");
    for(i=0; i<n; i++) {
        printf("%d. %s\n", i+1, books[i].title);
    }
    scanf("%d", &choice);
    struct node *current_page = books[choice-1].file_data.head; // current page initialized to first page
    printf("\nYou are reading %s.\n", books[choice-1].title);
    printf("You are on page %d of %d.\n\n", current_page->data, books[choice-1].pages);
    while(1) {
        printf("Menu:\n");
        printf("1. Go to next page\n");
        printf("2. Go to previous page\n");
        printf("3. Go to a specific page\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(current_page->next) { // go to next page if not on last page
                    current_page = current_page->next;
                    printf("\nYou are on page %d of %d.\n\n", current_page->data, books[choice-1].pages);
                }
                else {
                    printf("\nYou are already on the last page.\n\n");
                }
                break;
            case 2:
                if(current_page != books[choice-1].file_data.head) { // go to previous page if not on first page
                    struct node *temp = books[choice-1].file_data.head;
                    while(temp->next != current_page) { // find the previous page
                        temp = temp->next;
                    }
                    current_page = temp;
                    printf("\nYou are on page %d of %d.\n\n", current_page->data, books[choice-1].pages);
                }
                else {
                    printf("\nYou are already on the first page.\n\n");
                }
                break;
            case 3:
                printf("Enter the page number you want to go to: ");
                scanf("%d", &choice);
                if(choice >= 1 && choice <= books[i-1].pages) { // go to specified page if it exists
                    struct node *temp = books[choice-1].file_data.head;
                    while(temp->data != choice) { // find the specified page
                        temp = temp->next;
                    }
                    current_page = temp;
                    printf("\nYou are on page %d of %d.\n\n", current_page->data, books[choice-1].pages);
                }
                else {
                    printf("\nInvalid page number.\n\n");
                }
                break;
            case 4:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n\n");
                break;
        }
    }
    return 0;
}