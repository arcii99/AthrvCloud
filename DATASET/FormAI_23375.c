//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min; 
}

// function to generate a secure password
void secure_password_generator(int length) {
    char password[length+1]; // create a character array to store the password
    
    // define the range of characters available to be used in the password
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[],.<>?";
    
    srand(time(NULL)); // set the seed for the random number generator
    
    for(int i=0; i<length; i++) {
        password[i] = charset[rand_num(0, sizeof(charset)-1)]; // add a random character from the charset to the password array
    }
    
    password[length] = '\0'; // add null character to the end of the password array
    
    printf("Your secure password is: %s\n", password);
}

// main function
int main() {
    int password_length; // variable to store the desired length of the password
    
    printf("Secure Password Generator\n");
    printf("Enter the length of the password: ");
    scanf("%d", &password_length); // get the desired length of the password from the user
    
    secure_password_generator(password_length); // generate a secure password of the desired length
    
    return 0;
}