//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function that generates a random lowercase letter
char genChar(){
    return rand() % 26 + 97;
}

// Function that generates a random uppercase letter
char genCharUpper(){
    return rand() % 26 + 65;
}

// Function that generates a random digit
char genDigit(){
    return rand() % 10 + 48;
}

int main(){
    char password[16]; // Our password, will have 16 characters
    int i, j, k;
    int upper_count = 0, lower_count = 0, digit_count = 0; // Counters for password requirements
    srand(time(0)); // Seed for random number generator
    printf("Generating Secure Password...\n");
    for (i = 0; i < 16; i++){
        // Generate random type of character
        int type = rand() % 3 + 1;
        char c;
        if (type == 1){ // Lowercase letter
            c = genChar();
            password[i] = c;
            lower_count++;
        } else if (type == 2){ // Uppercase letter
            c = genCharUpper();
            password[i] = c;
            upper_count++;
        } else { // Digit
            c = genDigit();
            password[i] = c;
            digit_count++;
        }
    }
    // Checks to ensure password requirements are met
    if (lower_count < 4){
        for (i = 0; i < 4 - lower_count; i++){
            password[rand() % 16] = genChar();
        }
    }
    if (upper_count < 4){
        for (i = 0; i < 4 - upper_count; i++){
            password[rand() % 16] = genCharUpper();
        }
    }
    if (digit_count < 4){
        for (i = 0; i < 4 - digit_count; i++){
            password[rand() % 16] = genDigit();
        }
    }
    // Randomizes the order of the password
    for (i = 0; i < 16; i++){
        int pos = rand() % 16;
        char temp = password[i];
        password[i] = password[pos];
        password[pos] = temp;
    }
    printf("Generated Password: %s\n", password);
    return 0;
}