//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generate_password(int length);

int main() {
    int length;
    printf("How many characters would you like your password to be? (minimum 8)\n");
    scanf("%d", &length);

    if (length < 8) {
        printf("Password must be at least 8 characters long!\n");
        return 1;
    }

    srand(time(NULL));
    char* password = generate_password(length);
    
    printf("Generated password: %s", password);

    return 0;
}

char* generate_password(int length) {
    const char* charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}\\|<,>.?/~`\"';:";
    const int charset_length = sizeof(charset) - 1;

    char* password = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0';

    return password;
}