//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node {
    char val[256];
    struct node* next;
};

int main() {

    // Create a linked list to store all the IP addresses that are allowed
    struct node* head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    strcpy(head->val, "127.0.0.1");
    head->next = NULL;

    // Take user input for the IP address
    printf("Enter the IP address: ");
    char input[256];
    scanf("%s", input);

    // Convert the input to lowercase
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Check if the input is in the allowed list
    struct node* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->val, input) == 0) {
            printf("Access Granted\n");
            return 0;
        }
        curr = curr->next;
    }

    // If the input is not in the allowed list, print an error message
    printf("Intrusion Detected\n");
    return 0;
}