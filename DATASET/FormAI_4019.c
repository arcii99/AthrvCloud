//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int password_length = 0;
    printf("Enter password length: ");
    scanf("%d", &password_length);

    // List of characters to include in password
    char char_list[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+={}[]\\|;:'\",.<>?`~";

    srand(time(0)); // Seed random generator

    printf("Generated Password: ");

    for(int i=0; i<password_length; i++) {
        int random_index = rand() % (sizeof(char_list) - 1);
        printf("%c", char_list[random_index]);
    }

    printf("\n");
    return 0;
}