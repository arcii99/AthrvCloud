//FormAI DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <string.h>

//Function to encrypt the input message using a simple cipher
void encrypt(char message[], int key){
    int i;
    char c;
    for(i = 0; message[i] != '\0'; ++i){
        c = message[i];
        if(c >= 'a' && c <= 'z'){
            c += key;
            if(c > 'z'){
                c = c - 'z' + 'a' - 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z'){
            c += key;
            if(c > 'Z'){
                c = c - 'Z' + 'A' - 1;
            }
            message[i] = c;
        }
    }
}

int main(){
    char message[1000];
    int key;
    
    //Ask for user input to obtain message and key
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    
    //Call the encrypt function to encrypt the input message using the given key
    encrypt(message, key);
    
    //Print the encrypted message
    printf("Encrypted message: %s", message);
    
    return 0;
}