//FormAI DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key){
    // a unique encryption algorithm
    int length = strlen(message);
    char* output = (char*) malloc(sizeof(char)*(length+1));
    for(int i=0; i<length; i++){
        output[i] = message[i] ^ key;
    }
    output[length] = '\0';
    return output;
}

int main(){
    printf("Welcome to the Puzzle C Encryption Program!\n");
    // prompt user for message
    printf("Please enter your message to be encrypted: ");
    char message[100];
    fgets(message, 100, stdin);
    // prompt user for encryption key
    printf("Please enter a value for your encryption key (1-255): ");
    int key;
    scanf("%d", &key);
    getchar(); // remove newline from buffer
    // encrypt message
    char* encrypted = encrypt(message, key);
    // print out encrypted message
    printf("Your encrypted message is: \n%s", encrypted);
    // clean up memory
    free(encrypted);
    printf("\nThank you for using the Puzzle C Encryption Program!\n");
    return 0;
}