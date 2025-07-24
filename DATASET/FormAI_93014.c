//FormAI DATASET v1.0 Category: Browser Plugin ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define function to check if a user is an admin
bool isAdmin(char* username) {
    if (strcmp(username, "admin") == 0) {
        return true;
    } else {
        return false;
    }
}

// Define function to display welcome message
void displayWelcome(char* username) {
    printf("Welcome, %s!\n", username);
}

// Define function to retrieve username from browser cookies
char* getUsernameFromCookies() {
    // Code to retrieve username from browser cookies goes here
    char* username = "johndoe"; // For demonstration purposes only
    return username;
}

// Define main function
int main() {
    char* username = getUsernameFromCookies();
    displayWelcome(username);
    if (isAdmin(username)) {
        printf("You have admin privileges.\n");
    }
    return 0;
}