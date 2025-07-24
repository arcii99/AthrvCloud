//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include<stdio.h>
#include<string.h>

// Function to encrypt the string using Caesar Cipher
char* encrypt(char* input, int key){
    // Create a char array the same length as the input string
    char* output = (char*)malloc(sizeof(char)*(strlen(input)+1));
    
    // Loop through each character in the input string
    for(int i=0; i<strlen(input); i++){
        // If the character is an uppercase letter
        if(input[i]>='A' && input[i]<='Z'){
            output[i] = ((input[i] - 'A' + key) % 26) + 'A';
        }
        // If the character is a lowercase letter
        else if(input[i]>='a' && input[i]<='z'){
            output[i] = ((input[i] - 'a' + key) % 26) + 'a';
        }
        // If the character is a non-alphabetic character
        else{
            output[i] = input[i];
        }
    }
    // Set the last character in the output array to be a null terminator
    output[strlen(input)] = '\0';
    
    return output;
}

int main(){
    // Define a string to be encrypted
    char input[50] = "Hello, world!";
    // Define the encryption key
    int key = 3;
    
    // Encrypt the input string
    char* output = encrypt(input, key);
    
    // Display the input string and the encrypted output string
    printf("Input string: %s\n", input);
    printf("Output string: %s\n", output);
    
    // Free the memory allocated for the output string
    free(output);
    
    // Exit the program with a successful status code
    return 0;
}