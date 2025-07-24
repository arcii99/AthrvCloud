//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12 // Change the length as per your requirement

char generateRandomChar(){
    char randomChar;
    int randomNumber = rand() % 3;
    switch(randomNumber){
        case 0:
            randomChar = rand() % 10 + '0'; // Random digit
            break;
        case 1:
            randomChar = rand() % 26 + 'A'; // Random uppercase letter
            break;
        case 2:
            randomChar = rand() % 26 + 'a'; // Random lowercase letter
            break;
    }
    return randomChar;
}

int main(){
    char password[PASSWORD_LENGTH+1]; // +1 for null terminator
    srand(time(NULL)); // Seed the random number generator with current time
    for(int i=0; i<PASSWORD_LENGTH; i++){
        password[i] = generateRandomChar();
    }
    password[PASSWORD_LENGTH] = '\0'; // Add null terminator to the end
    printf("Generated Password: %s\n", password);
    return 0;
}