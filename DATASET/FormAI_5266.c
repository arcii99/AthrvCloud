//FormAI DATASET v1.0 Category: Bitwise operations ; Style: real-life
#include<stdio.h>

// Real-life Bitwise operation Example program
// This program is a simple encryption algorithm for user login/passwords

void encrypt(char* str){
    // bitwise left shift operation on the ASCII value of each character of the string
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = str[i] << 1;
    }
}

void decrypt(char* str){
    // bitwise right shift operation on the ASCII value of each character of the string
    for(int i = 0; str[i] != '\0'; i++){
        str[i] = str[i] >> 1;
    }
}

int main(){
    char username[50], password[50];
    printf("Enter username: ");
    fgets(username, 50, stdin);
    encrypt(username); //encrypt the username
    printf("Enter password: ");
    fgets(password, 50, stdin);
    encrypt(password); //encrypt the password
    printf("User login information encrypted!\n");
    printf("Username: %s\n", username);
    printf("Password: %s\n", password);
    printf("Decrypted:\n");
    decrypt(username); //decrypt the username
    decrypt(password); //decrypt the password
    printf("Username: %s\n", username);
    printf("Password: %s\n", password);
    return 0;
}