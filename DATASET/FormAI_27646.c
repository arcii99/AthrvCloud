//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main() {
    char alphabet[62] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // characters to choose from
    char password[PASSWORD_LENGTH + 1]; // +1 for string null character
    int i, rand_index;
    
    srand(time(NULL)); // seed the random number generator with current time
    
    printf("Your secure password is: ");
    
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        rand_index = rand() % 62; // generate a random index within the range of alphabet
        
        password[i] = alphabet[rand_index]; // add the randomly chosen character to password
    }
    
    password[PASSWORD_LENGTH] = '\0'; // adds null character to end the string
    
    printf("%s\n", password); // print the generated password
    
    return 0;
}