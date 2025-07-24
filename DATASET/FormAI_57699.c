//FormAI DATASET v1.0 Category: Encryption ; Style: high level of detail
//Header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to encrypt a string using Caesar Cipher Algorithm
char* caesarCipher(char* message, int shift){
    int i;
    char *result = malloc(strlen(message) + 1); //Allocate memory for result string
    
    //Iterate over each character in the message
    for(i=0;i<strlen(message);i++){
        //Encrypt alphabets only
        if(message[i]>='A' && message[i]<='Z'){
            result[i] = ((message[i] - 'A' + shift)%26) + 'A'; //Encrypt uppercase alphabets
        }
        else if(message[i]>='a' && message[i]<='z'){
            result[i] = ((message[i] - 'a' + shift)%26) + 'a'; //Encrypt lowercase alphabets
        }
        else{
            result[i] = message[i]; //Don't encrypt non-alphabetic characters
        }
    }
    result[i] = '\0'; //Set ending of the encrypted string
    return result; //Return the encrypted string
}

//Main function
int main(){
    char message[100], *encrypted_message; //Declare variables
    int shift;
    
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin); //Read the message from user
    
    printf("Enter the shift value: ");
    scanf("%d", &shift); //Read the shift value
    
    encrypted_message = caesarCipher(message, shift); //Encrypt the message using Caesar Cipher algorithm
    
    printf("The encrypted message is: %s\n", encrypted_message); //Print the encrypted message
    
    free(encrypted_message); //Free memory allocated for encrypted string
    return 0;
}