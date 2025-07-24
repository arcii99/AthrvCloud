//FormAI DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

void encryption(char input_string[], char encrypted_string[]);
void decryption(char encrypted_string[], char decrypted_string[]);

int main(){
    printf("Welcome to the encryption and decryption program, Mr. Holmes.\n");
    printf("Please enter the message you want to encrypt: ");
    char input_string[1000];
    fgets(input_string, sizeof(input_string), stdin);

    char encrypted_string[1000];
    encryption(input_string, encrypted_string);

    printf("The encrypted message is: %s", encrypted_string);

    printf("\nWould you like to decrypt the message? (y/n): ");
    char response;
    scanf("%c", &response);

    if(response == 'y' || response == 'Y'){
        char decrypted_string[1000];
        decryption(encrypted_string, decrypted_string);
        printf("The decrypted message is: %s", decrypted_string);
    }
    else{
        printf("Alright, Mr. Holmes, the game is afoot! Goodbye!");
    }
    return 0;
}

void encryption(char input_string[], char encrypted_string[]){
    int key = 5;
    for(int i = 0; i < strlen(input_string); i++){
        encrypted_string[i] = input_string[i] + key;
    }
}

void decryption(char encrypted_string[], char decrypted_string[]){
    int key = 5;
    for(int i = 0; i < strlen(encrypted_string); i++){
        decrypted_string[i] = encrypted_string[i] - key;
    }
}