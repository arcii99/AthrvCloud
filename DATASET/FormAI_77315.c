//FormAI DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void addUser(char* username, char* password) {
    /* Add user code here */
}

int main() {
    char username[50];
    char password[50];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    addUser(username, password);
    
    printf("User added successfully!");
    
    return 0;
}