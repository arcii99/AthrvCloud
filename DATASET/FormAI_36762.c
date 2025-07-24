//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to store stock information */
typedef struct {
    char symbol[10];
    float price;
    float change;
    float percentage_change;
} Stock;

/* Define a struct to store linked list nodes */
typedef struct Node {
    Stock stock;
    struct Node* next;
} Node;

/* Function to add a new stock to linked list */
void add_stock(Node** head, Stock stock) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->stock = stock;
    new_node->next = *head;
    *head = new_node;
}

/* Function to print all stocks in linked list */
void print_stocks(Node* head) {
    printf("%-10s %-10s %-10s %s\n", "Symbol", "Price", "Change", "% Change");
    while (head != NULL) {
        printf("%-10s $%-9.2f $%-9.2f %0.2f%%\n", head->stock.symbol, head->stock.price, head->stock.change, head->stock.percentage_change);
        head = head->next;
    }
}

int main() {
    /* Create a linked list of sample stocks */
    Node* head = NULL;
    add_stock(&head, (Stock){"AAPL", 127.90, 1.23, 0.97});
    add_stock(&head, (Stock){"GOOG", 2365.08, -5.43, -0.23});
    add_stock(&head, (Stock){"TSLA", 676.88, 12.34, 1.85});
    add_stock(&head, (Stock){"AMZN", 3312.53, -8.09, -0.24});

    /* Print all stocks */
    print_stocks(head);

    return 0;
}