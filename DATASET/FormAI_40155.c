//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 25

// Function to generate a random integer between two integers
int generateRandomInt(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random uppercase letter
char generateRandomUppercase(){
    int randInt = generateRandomInt(65, 90);
    return (char) randInt;
}

// Function to generate a random lowercase letter
char generateRandomLowercase(){
    int randInt = generateRandomInt(97, 122);
    return (char) randInt;
}

// Function to generate a random special character
char generateRandomSpecialChar(){
    char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '/', '<', '>', '?'};
    int randIndex = generateRandomInt(0, 22);
    return specialChars[randIndex];
}

// Function to generate a random digit
char generateRandomDigit(){
    int randInt = generateRandomInt(48, 57);
    return (char) randInt;
}

// Function to check if a character is already present in a password
int isCharInPassword(char c, char password[], int passwordLen){
    for(int i=0;i<passwordLen;i++){
        if(password[i] == c){
            return 1;
        }
    }
    return 0;
}

// Function to generate a secure password
int generateSecurePassword(char password[], int passwordLen){
    // Initialize random seed    
    srand(time(NULL));
    // Initialize password string
    memset(password, 0, passwordLen);
    // Generate random uppercase letters
    for(int i=0;i<5;i++){
        char c = generateRandomUppercase();
        while(isCharInPassword(c, password, passwordLen)){
            c = generateRandomUppercase();
        }
        password[i] = c;
    }
    // Generate random lowercase letters
    for(int i=5;i<10;i++){
        char c = generateRandomLowercase();
        while(isCharInPassword(c, password, passwordLen)){
            c = generateRandomLowercase();
    }
        password[i] = c;
    }
    // Generate random special characters
    for(int i=10;i<15;i++){
        char c = generateRandomSpecialChar();
        while(isCharInPassword(c, password, passwordLen)){
            c = generateRandomSpecialChar();
        }
        password[i] = c;
    }
    // Generate random digits
    for(int i=15;i<20;i++){
        char c = generateRandomDigit();
        while(isCharInPassword(c, password, passwordLen)){
            c = generateRandomDigit();
        }
        password[i] = c;
    }
    // Shuffle password string
    for(int i=0;i<passwordLen;i++){
        int randIndex = generateRandomInt(0, passwordLen - 1);
        char temp = password[i];
        password[i] = password[randIndex];
        password[randIndex] = temp;
    }
    return 1;
}

// Function to print password
void printPassword(char password[], int passwordLen){
    printf("Your generated secure password is: ");
    for(int i=0; i<passwordLen; i++){
        printf("%c", password[i]);
    }
    printf("\n");
}

int main(){
    char password[MAX_PASSWORD_LENGTH];
    int passwordLen = MAX_PASSWORD_LENGTH;
    // Generate secure password
    int status = generateSecurePassword(password, passwordLen);
    // Print password
    if(status == 1){
        printPassword(password, passwordLen);
    }
    return 0;
}