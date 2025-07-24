//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate secure password
char* generate_password(int length) {
    char* password = (char*) malloc((length + 1) * sizeof(char));
    const char character_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
    int set_length = sizeof(character_set) - 1;
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int random_index = rand() % set_length;
        password[i] = character_set[random_index];
    }
    password[length] = '\0';
    return password;
}

int main() {
    int password_length;
    printf("Enter the length of the password: ");
    scanf("%d", &password_length);
    char* password = generate_password(password_length);
    printf("Your new secure password is: %s\n", password);
    free(password);
    return 0;
}