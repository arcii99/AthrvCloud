//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare functions
char randomChar();
int randomNum(int lower_bound, int upper_bound);

int main() {
    // Declare variables
    char password[9];
    int i;

    // Initialize random number generator
    srand(time(0));

    // Generate password
    for (i=0; i<9; i++) {
        if (i%3 == 0) {
            password[i] = randomChar();
        } else {
            password[i] = (char) randomNum(0, 9) + '0';
        }
    }

    // Print password
    printf("My love, behold the password for our secret rendezvous:\n");
    for (i=0; i<9; i++) {
        printf("%c", password[i]);
        if (i == 2 || i == 5) {
            printf("-");
        }
    }
    printf("\n");

    return 0;
}

char randomChar() {
    // Generate random uppercase letter
    return (char) randomNum(65, 90);
}

int randomNum(int lower_bound, int upper_bound) {
    // Generate random integer between lower_bound and upper_bound (inclusive)
    return (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
}