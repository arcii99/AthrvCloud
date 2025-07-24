//FormAI DATASET v1.0 Category: Browser Plugin ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Struct to hold user data */
typedef struct {
    char name[50];
    int age;
} User;

/* Function to parse user data from string */
User parseUserData(char* userData) {
    User user;
    char* token = strtok(userData, ",");
    strcpy(user.name, token);
    token = strtok(NULL, ",");
    user.age = atoi(token);
    return user;
}

/* Function to print user data */
void printUserData(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
}

/* Main function */
int main() {
    // Assume we have a user profile page loaded in the browser
    char* userData = "John Doe,35";
    User user = parseUserData(userData);
    printUserData(user);
    
    return 0;
}