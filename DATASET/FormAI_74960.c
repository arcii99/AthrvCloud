//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char fname[20], lname[20], email[50];

    printf("Enter your first name: ");
    scanf("%s", fname);
    printf("Enter your last name: ");
    scanf("%s", lname);
    printf("Enter your email address: ");
    scanf("%s", email);

    // Concatenate fname and lname using strcat
    strcat(fname, " ");
    strcat(fname, lname);

    // Check if email contains ".com" using strstr
    char *p;
    p = strstr(email, ".com");
    if (p == NULL) {
        printf("Invalid email address!\n");
        exit(1);
    }

    // Replace "@" with " at " using strtok
    char *token;
    token = strtok(email, "@");
    sprintf(email, "%s at %s", token, strtok(NULL, ""));

    // Print the processed name and email
    printf("Name: %s\n", fname);
    printf("Email: %s\n", email);

    return 0;
}