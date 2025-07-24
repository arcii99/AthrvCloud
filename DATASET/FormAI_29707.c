//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define THRESHOLD 10

bool checkLength(char password[]) {
    int length = strlen(password);
    return length >= 8 && length <= 20;
}

bool checkUpperCase(char password[]) {
    for(int i = 0; i < strlen(password); i++) {
        if(isupper(password[i]))
            return true;
    }
    return false;
}

bool checkLowerCase(char password[]) {
    for(int i = 0; i < strlen(password); i++) {
        if(islower(password[i]))
            return true;
    }
    return false;
}

bool checkNumeric(char password[]) {
    for(int i = 0; i < strlen(password); i++) {
        if(isdigit(password[i]))
            return true;
    }
    return false;
}

bool checkSpecial(char password[]) {
    for(int i = 0; i < strlen(password); i++) {
        if(!isalnum(password[i]))
            return true;
    }
    return false;
}

void* threadFunc(void* arg) {
    char* password = (char *) arg;
    bool length = checkLength(password);
    bool upperCase = checkUpperCase(password);
    bool lowerCase = checkLowerCase(password);
    bool numeric = checkNumeric(password);
    bool special = checkSpecial(password);
    int score = length + upperCase + lowerCase + numeric + special;
    char* strength;
    if(score <= 2)
        strength = "Weak";
    else if(score <= 4)
        strength = "Moderate";
    else if(score <= THRESHOLD)
        strength = "Strong";
    else
        strength = "Very Strong";
    printf("Password strength: %s\n", strength);
    return NULL;
}

int main() {
    char passwords[5][20] = {"abcd1234", "Pa$$word#1", "securepassword", "1234", "Aa1@"};
    pthread_t threads[5];
    for(int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadFunc, (void *) passwords[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}