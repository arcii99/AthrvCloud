//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* getPassword(int length) {
    char* password = (char*)malloc((length+1)*sizeof(char));
    static const char characters[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "!@#$%^&*()_+=-[]{}\\|;:'\",.<>/?`~";
    int num_chars = sizeof(characters) - 1;
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % num_chars];
    }
    password[length] = '\0';
    return password;
}

int main() {
    int length;
    printf("How long would you like your password to be?: ");
    scanf("%d", &length);

    char* password = getPassword(length);
    printf("Your new password is: %s\n", password);

    // Clearing password from memory to prevent it from being cached in memory
    memset(password, 0, strlen(password));
    free(password);
  
    return 0;
}