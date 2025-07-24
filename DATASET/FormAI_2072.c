//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

/* Function to shift the characters by a certain amount */
char shiftCharacter(char c, int shiftAmount){
    /*
    * We will only be shifting upper and lowercase letters, 
    * leaving other characters unmodified
    */
    if(c >= 'a' && c <= 'z'){
        c = ((c - 'a' + shiftAmount) % 26) + 'a';
    }
    else if(c >= 'A' && c <= 'Z'){
        c = ((c - 'A' + shiftAmount) % 26) + 'A';
    }
    return c;
}

/* Function to apply the encryption to the given message */
void encryptMessage(char* message, int shiftAmount){
    int i=0;
    while(message[i] != '\0'){
        message[i] = shiftCharacter(message[i], shiftAmount);
        i++;
    }
}

/* Sample main function */
int main(){
    char message[1000];
    int shiftAmount;
    
    // Take input from user
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter shift amount: ");
    scanf("%d", &shiftAmount);

    // Encrypt the message with the given shift amount
    encryptMessage(message, shiftAmount);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}