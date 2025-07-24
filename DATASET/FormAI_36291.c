//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

char generate_random_char() {
    int char_type = generate_random_number(1, 4);

    switch(char_type) {
        case 1:
            return generate_random_number(97, 122);
        case 2:
            return generate_random_number(65, 90);
        case 3:
            return generate_random_number(48, 57);
        case 4:
            return generate_random_number(33, 47);
        default:
            return 0;
    }
}

void generate_password(int password_length, char* password) {
    for(int i = 0; i < password_length; i++) {
        password[i] = generate_random_char();
    }
}

int main() {
    srand(time(NULL));

    int password_length = generate_random_number(MIN_LENGTH, MAX_LENGTH);
    char password[MAX_LENGTH];

    generate_password(password_length, password);

    printf("Your secure password is: %s", password);

    return 0;
}