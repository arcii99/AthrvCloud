//FormAI DATASET v1.0 Category: Email Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that splits the email address into username and domain
void splitEmail(char email[], char *username, char *domain) {
    int i = 0, j = 0;
    while (email[i] != '@') {
        username[i] = email[i];
        i++;
    }
    username[i] = '\0';
    i++;
    while (email[i] != '\0') {
        domain[j] = email[i];
        i++;
        j++;
    }
    domain[j] = '\0';
}

// Main function
int main() {
    char email[50], username[30], domain[20];
    printf("Enter your email: ");
    scanf("%s", email);
    splitEmail(email, username, domain);
    printf("Username: %s\n", username);
    printf("Domain: %s\n", domain);
    return 0;
}