//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

char* generate_password(int length);
void shuffle_characters(char * password, int length);

int main(void) {
    srand(time(NULL));
    int password_length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;
    char * password = generate_password(password_length);
    printf("Generated Password: %s\n", password);
    free(password);
    return 0;
}

char* generate_password(int length) {
    char * password = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        int ascii_code = rand() % 94 + 33; 
        password[i] = (char) ascii_code;
    }
    password[i] = '\0';
    shuffle_characters(password, length);
    return password;
}

void shuffle_characters(char * password, int length) {
    srand(time(NULL));
    int i;
    for (i = 0; i < length - 1; i++) {
        int j = rand() % (length - i) + i;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}