//FormAI DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int main() {
    char password[MAX];
    char confirm[MAX];

    printf("Enter new password: ");
    fgets(password, MAX, stdin);
    
    printf("Confirm password: ");
    fgets(confirm, MAX, stdin);

    if (strcmp(password, confirm) == 0) {
        printf("Password set successfully!\n");
    } else {
        printf("Passwords do not match. Please try again.\n");
    }

    return 0;
}