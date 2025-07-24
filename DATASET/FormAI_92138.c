//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

char* generate_password(int length) {
    char* password = (char*) malloc(length + 1);
    password[length] = '\0';
    for(int i = 0; i < length; i++) {
        int type = rand() % 3;
        if(type == 0) {
            password[i] = rand() % 26 + 'a';
        } else if(type == 1) {
            password[i] = rand() % 26 + 'A';
        } else {
            password[i] = rand() % 10 + '0';
        }
    }
    return password;
}

int main() {
    srand(time(NULL));
    int length;
    printf("Enter desired password length: ");
    scanf("%d", &length);
    if(length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Error: Password length must be between %d and %d\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }
    char* password = generate_password(length);
    printf("Your new password is: %s\n", password);
    free(password);
    return 0;
}