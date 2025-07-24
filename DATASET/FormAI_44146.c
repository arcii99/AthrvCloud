//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int password_length, i, ascii_value;
    char password[101];
    srand(time(0)); // use current time as seed for random generator

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired length of your password (max. 100): ");
    scanf("%d", &password_length);

    if (password_length < 1 || password_length > 100) {
        printf("Invalid password length. Please enter a positive integer between 1 and 100.\n");
        return 1;
    }

    printf("\nYour secure password is: ");

    for (i=0; i < password_length; i++) {
        ascii_value = rand() % 94 + 33; // generate random ASCII value between 33 and 126
        password[i] = (char) ascii_value;
        printf("%c", password[i]);
    }

    printf("\n\nThank you for using the Secure Password Generator!\n");

    return 0;
}