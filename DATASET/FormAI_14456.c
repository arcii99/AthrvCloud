//FormAI DATASET v1.0 Category: Email Client ; Style: Donald Knuth
// The following code snippet is a C email client program example written in Donald Knuth style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_EMAIL_SIZE 1000000

char buffer[BUFFER_SIZE];
char email[MAX_EMAIL_SIZE];

void print_menu() {
    printf("\n==== Email Client ====\n");
    printf("1. Compose email\n");
    printf("2. View email\n");
    printf("3. Send email\n");
    printf("4. Exit\n");
}

void compose_email() {
    printf("\n==== Compose Email ====\n");
    printf("Enter recipient email address: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    printf("Enter subject line: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    printf("Enter email message: ");
    fgets(email, MAX_EMAIL_SIZE, stdin);
}

void view_email() {
    printf("\n==== View Email ====\n");
    printf("%s\n", email);
}

void send_email() {
    printf("\n==== Send Email ====\n");
    printf("Email sent!\n");
    memset(email, 0, MAX_EMAIL_SIZE * sizeof(char));
}

int main() {
    int choice = 0;

    while (1) {
        print_menu();
        printf("Enter choice: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Convert input into integer
        choice = atoi(buffer);

        switch(choice) {
            case 1:
                compose_email();
                break;
            case 2:
                view_email();
                break;
            case 3:
                send_email();
                break;
            case 4:
                printf("\n==== Exit Program ====\n");
                exit(0);
            default:
                printf("\nError: Invalid Choice\n");
                break;
        }
    }

    return 0;
}