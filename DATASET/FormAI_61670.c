//FormAI DATASET v1.0 Category: System administration ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char name[20];
    int age;
    char address[40];
};

int main() {
    // Welcome message
    printf("Welcome to User Management System!\n");

    // Allocate memory for 5 users
    struct user *users = malloc(5 * sizeof(struct user));

    // Get user information
    for (int i = 0; i < 5; i++) {
        printf("\nEnter the name for user %d: ", i+1);
        scanf("%s", users[i].name);
        printf("Enter the age for user %d: ", i+1);
        scanf("%d", &users[i].age);
        printf("Enter the address for user %d: ", i+1);
        scanf("%s", users[i].address);
    }

    // Display user information
    printf("\nUser Information:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nName: %s\nAge: %d\nAddress: %s\n", users[i].name, users[i].age, users[i].address);
    }

    // Free memory
    free(users);
    return 0;
}