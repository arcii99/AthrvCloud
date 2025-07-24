//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASS_LENGTH 10

char* generate_password(int length);

int main() {
    char* password = generate_password(PASS_LENGTH);

    printf("Your generated password is: %s\n", password);

    free(password);

    return 0;
}

char* generate_password(int length) {
    char* password = (char*) malloc((length + 1) * sizeof(char)); // allocate memory for password

    // create an array of all possible characters for the password
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";

    srand(time(NULL)); // seed the random number generator with the current time
    
    for (int i = 0; i < length; i++) {
        int index = rand() % (sizeof(charset) - 1); // get a random index from the charset array
        password[i] = charset[index]; // add the character at that index to the password
    }
    
    password[length] = '\0'; // add null terminator to the end of the password string
    
    return password;
}