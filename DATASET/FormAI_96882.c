//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_INPUT_SIZE 1024

// Structure to hold the IP address and port number
typedef struct {
    char ip_address[16];
    int port;
} Address;

// Node of the linked list that holds the IP address and port number
typedef struct Node {
    Address address;
    struct Node *next;
} Node;

// Function to insert a new node into the linked list
void insert_node(Node **head, Address address)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->address = address;
    new_node->next = *head;
    *head = new_node;
}

// Function to check if the given IP address and port number is present in the linked list
int check_address(Node *head, Address address)
{
    Node *current = head;
    while(current != NULL) {
        if(strcmp(current->address.ip_address, address.ip_address) == 0 && current->address.port == address.port) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main()
{
    char input[MAX_INPUT_SIZE];
    Node *head = NULL;
    
    // Loop to read the input lines
    while(fgets(input, MAX_LINE_SIZE, stdin)) {
        
        // Removing the newline character from the end
        input[strlen(input)-1] = '\0';
        
        // Parsing the input line to get the IP address and port number
        char *pch = strtok(input, ":");
        Address address;
        strcpy(address.ip_address, pch);
        
        pch = strtok(NULL, ":");
        address.port = atoi(pch);
        
        // Checking if the IP address and port number is already present in the linked list
        if(check_address(head, address) == 1) {
            printf("Intrusion detected: %s:%d\n", address.ip_address, address.port);
        } else {
            // Inserting the IP address and port number into the linked list
            insert_node(&head, address);
        }
    }
    
    return 0;
}