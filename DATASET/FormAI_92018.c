//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Alan Touring
/* Alan Turing Style C Browser Plugin Example */

#include <stdio.h>

int main() {

    // Print Welcome Message
    printf("Welcome to the Browser Plugin Example Program!\n");
    
    // User Input
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);
    
    // Print Greeting
    printf("Hello, %s!\n", name);
    
    // Browser Plugin Functionality
    printf("This browser plugin allows you to search Google.\n");
    printf("Please enter your search query: ");
    char query[100];
    scanf("%s", query);
    printf("Redirecting to Google search results for \"%s\"...\n", query);
    
    // Exit Message
    printf("Thank you for using the Browser Plugin Example Program!\n");
    return 0;
}