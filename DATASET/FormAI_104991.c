//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate a random character
char getRandomChar(){
    return (char)((rand() % 94) + 33);
}

int main(){
    int passwordLength, numPasswords;

    printf("Welcome to the Secure Password Generator!\n");
    
    printf("\nEnter the length you want for your password (minimum 8 characters): ");
    scanf("%d", &passwordLength);
    
    //Checking if the entered password length is valid
    while(passwordLength < 8){
        printf("Password length should be at least 8 characters!\n");
        printf("\nEnter the length you want for your password: ");
        scanf("%d", &passwordLength);
    }

    printf("\nHow many passwords do you want? ");
    scanf("%d", &numPasswords);

    srand(time(NULL)); //Using time as the seed for random number generation

    for(int i=1; i<=numPasswords; i++){
        printf("\nPassword %d: ", i);

        for(int j=1; j<=passwordLength; j++){
            printf("%c", getRandomChar());
        }
    }
    
    printf("\n\nThank you for using the Secure Password Generator!\n");

    return 0;
}