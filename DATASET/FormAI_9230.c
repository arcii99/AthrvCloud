//FormAI DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int books = 0;
    float price = 0.0;
    char title[50];
    
    printf("Welcome to the Ebook Reader Program!\n\n");
    
    printf("Please enter the number of books you want to read: ");
    scanf("%d", &books);
    
    printf("Please enter the price of each book: ");
    scanf("%f", &price);
    
    printf("Please enter the title of the Ebook: ");
    scanf("%s", title);
    
    float total_price = books * price;
    printf("\nThank you for purchasing %d copies of %s at $%.2f\n", books, title, price);
    printf("Your total is $%.2f. Enjoy your reading experience!\n", total_price);
    
    return 0;
}