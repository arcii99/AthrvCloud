//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to generate a secure password
char * generate_password(int length) {
    // initialize the random seed
    srand(time(NULL));
    
    // declare an array to store the possible characters for the password
    char possible_characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=";
    
    // get the length of the possible characters array
    int num_characters = strlen(possible_characters);
    
    // declare a string to store the password
    char * password = (char*) malloc(length * sizeof(char));
    
    // generate the password
    for(int i=0; i<length; i++) {
        int random_index = rand() % num_characters;
        password[i] = possible_characters[random_index];
    }
    
    // add a null terminating character to the end of the password string
    password[length] = '\0';
    
    // return the password
    return password;
}

int main() {
    // generate and print a secure password with 16 characters
    printf("Secure Password: %s\n", generate_password(16));
    
    // generate and print a secure password with 8 characters
    printf("Secure Password: %s\n", generate_password(8));
    
    // generate and print a secure password with 12 characters
    printf("Secure Password: %s\n", generate_password(12));
    
    return 0;
}