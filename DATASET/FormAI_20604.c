//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_password(int length, char* password){
    // define a string of allowed characters 
    char valid_chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_', '.', '-'};
    int num_chars = sizeof(valid_chars) / sizeof(char);
    // generate random index to choose the next character from valid_chars
    int r = rand() % num_chars;
    // add selected character to password string
    password[length-1] = valid_chars[r];
    // when we reach the end of the desired password length, exit the function
    if (length == 1){
        return;
    } else {
        // otherwise, recursively call the function to generate the next character
        generate_password(length-1, password);
    }
}

int main(){
    // set up random seed based on current time
    srand(time(NULL));
    // set password length to generate
    int length = 12;
    // allocate memory for the password string
    char* password = malloc(length * sizeof(char));
    // generate the password recursively
    generate_password(length, password);
    // print out the generated password
    printf("Your new secure password is: %s\n", password);
    // free memory allocated for password string
    free(password);
    // return success
    return 0;
}