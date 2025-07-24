//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* original = "abcdefghijklmnopqrstuvwxyz";
char* key = "qwertyuiopasdfghjklzxcvbnm";

char encrypt(char c){
    char result;
    if (isalpha(c)){
        int index = tolower(c) - 'a';
        if (isupper(c)){
            result = toupper(key[index]);
        } else {
            result = key[index];
        }
    } else {
        result = c;
    }
    return result;
}

char decrypt(char c){
    char result;
    if (isalpha(c)){
        int index = strchr(key, tolower(c)) - key;
        if (isupper(c)){
            result = toupper(original[index]);
        } else {
            result = original[index];
        }
    } else {
        result = c;
    }
    return result;
}

void print_message(char* message, char (*func)(char)){
    while (*message){
        putchar(func(*message++));
    }
}

int main(){
    char message[] = "I love cryptography!";
    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    print_message(message, encrypt);
    printf("\n");
    printf("Decrypted message: ");
    print_message(message, decrypt);
    printf("\n");
    return 0;
}