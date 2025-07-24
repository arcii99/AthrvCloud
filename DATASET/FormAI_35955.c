//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* password = malloc(sizeof(char)*16);
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=";
    srand(time(NULL));
    for(int i=0; i<15; i++) {
        password[i] = characters[rand()%74];
    }
    password[15] = '\0';
    printf("Your secure password is: %s\n", password);
    free(password);
    return 0;
}