//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    int char_set_size = 74;
    int password_length = 12;
    char password[password_length+1];
    int i;

    srand(time(NULL)); // Seed the random generator with the current time

    for (i = 0; i < password_length; i++) {
        password[i] = char_set[rand() % char_set_size];
    }
    password[password_length] = '\0';

    printf("Your secure password is: %s\n", password);

    return 0;
}