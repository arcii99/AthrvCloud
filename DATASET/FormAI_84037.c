//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate a random lowercase letter
char getRandomLowercaseLetter(){
    return rand() % 26 + 'a';
}

//Function to generate a random uppercase letter
char getRandomUppercaseLetter(){
    return rand() % 26 + 'A';
}

//Function to generate a random digit
char getRandomDigit(){
    return rand() % 10 + '0';
}

//Function to generate a random symbol
char getRandomSymbol(){
    char symbols[] = {'!', '@', '#', '$', '%', '&', '*'};
    return symbols[rand() % 7];
}

int main(){
    //Seed the random number generator
    srand((unsigned int)time(NULL));
    
    //Initialize the password array
    char password[15];
    
    //Generate 3 lowercase letters
    password[0] = getRandomLowercaseLetter();
    password[1] = getRandomLowercaseLetter();
    password[2] = getRandomLowercaseLetter();
    
    //Generate 3 uppercase letters
    password[3] = getRandomUppercaseLetter();
    password[4] = getRandomUppercaseLetter();
    password[5] = getRandomUppercaseLetter();
    
    //Generate 3 digits
    password[6] = getRandomDigit();
    password[7] = getRandomDigit();
    password[8] = getRandomDigit();
    
    //Generate 3 symbols
    password[9] = getRandomSymbol();
    password[10] = getRandomSymbol();
    password[11] = getRandomSymbol();
    
    //Add a null terminator at the end
    password[12] = '\0';
    
    //Print the generated password
    printf("Generated password: %s", password);
    
    return 0;
}