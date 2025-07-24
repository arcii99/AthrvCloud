//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include<stdio.h>

//Function signature for encryption
void encrypt(char data[]);

int main() {
    char data[100];
    printf("Enter the message to encrypt: ");
    gets(data); //Fetching input message from user

    printf("\nEncrypting message...\n");

    encrypt(data);

    printf("Encrypted message: %s", data);
    return 0;
}

//Function to perform encryption according to Claude Shannon's model
void encrypt(char data[]) {
    int key = 3; //Key for encryption
    int i;

    for(i = 0; data[i] != '\0'; ++i) {
        //Performing rotation by key positions anticlockwise
        if(data[i] >= 'a' && data[i] <= 'z') {
            data[i] = data[i] - key;
            
            if(data[i] < 'a') {
                data[i] = data[i] + 'z' - 'a' + 1;
            }
        }
        else if(data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = data[i] - key;
            
            if(data[i] < 'A') {
                data[i] = data[i] + 'Z' - 'A' + 1;
            }
        }
    }
}