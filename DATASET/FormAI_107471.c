//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <pthread.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

typedef struct {
    char* password;
    int length;
    bool uppercase;
    bool lowercase;
    bool digit;
    bool symbol;
} Password;

typedef struct {
    Password* passwords;
    int numPasswords;
    int* strengths;
} PasswordInput;

void* checkPasswordStrength(void* arg) {
    PasswordInput* input = (PasswordInput*)arg;
    for(int i=0; i<input->numPasswords; i++) {
        int strength = 0;
        Password p = input->passwords[i];
        if(p.length >= MIN_LENGTH && p.length <= MAX_LENGTH) {
            strength += 1;
        }
        if(p.uppercase) {
            strength += 1;
        }
        if(p.lowercase) {
            strength += 1;
        }
        if(p.digit) {
            strength += 1;
        }
        if(p.symbol) {
            strength += 1;
        }
        input->strengths[i] = strength;
    }
    pthread_exit(NULL);
}

int main() {
    const int numPasswords = 5;
    PasswordInput input;
    Password passwords[numPasswords];
    int strengths[numPasswords];
    input.passwords = passwords;
    input.numPasswords = numPasswords;
    input.strengths = strengths;
    passwords[0] = (Password){"pAssword", 8, true, true, true, false};
    passwords[1] = (Password){"123456", 6, false, false, true, false};
    passwords[2] = (Password){"Password12345!", 16, true, true, true, true};
    passwords[3] = (Password){"password", 8, false, true, false, false};
    passwords[4] = (Password){"PaSsWoRd", 8, true, true, false, false};

    pthread_t threads[numPasswords];
    int rc;
    long t;
    for(t=0; t<numPasswords; t++) {
        rc = pthread_create(&threads[t], NULL, checkPasswordStrength, (void*)&input);
    }

    for(int i=0; i<numPasswords; i++) {
        rc = pthread_join(threads[i], NULL);
        printf("Password %d:\n", i);
        printf("Length: %d\n", input.passwords[i].length);
        printf("Uppercase: %s\n", input.passwords[i].uppercase ? "true" : "false");
        printf("Lowercase: %s\n", input.passwords[i].lowercase ? "true" : "false");
        printf("Digit: %s\n", input.passwords[i].digit ? "true" : "false");
        printf("Symbol: %s\n", input.passwords[i].symbol ? "true" : "false");
        printf("Strength: %d\n", input.strengths[i]);
    }

    pthread_exit(NULL);
    return 0;
}