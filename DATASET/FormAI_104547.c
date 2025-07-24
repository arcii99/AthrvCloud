//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
// Hello! Welcome to my cheerful C Firewall code!
#include <stdio.h>
#include <stdlib.h>

// Declare the function for checking if the IP is approved
int isApproved(char* ip);

int main() {
    // Initialize the IP address
    char* ip = (char*)malloc(sizeof(char) * 16); // assuming IPv4 address
    
    // Greet the user
    printf("Hello there! Let's set up your firewall.\n");
    printf("Please enter your IP address: ");
    scanf("%s", ip);
    
    // Check if the IP is approved
    if (isApproved(ip)) {
        printf("IP Address: %s is approved! Welcome!\n", ip);
    } else {
        printf("Sorry, your IP address: %s is not approved. Access denied.\n", ip);
    }
    
    // Exit the program
    printf("Thank you for using the cheerful C Firewall program, goodbye!");
    return 0;
}

int isApproved(char* ip) {
    // Let's have some fun and randomly approve or reject the IP
    int random = rand() % 2; // 0 or 1
    
    if (random == 0) {
        return 0; // sorry, not approved
    } else {
        return 1; // approved!
    }
}