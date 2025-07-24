//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>

//function to encrypt the given string
void encrypt(char str[], int key) {
    int len = strlen(str);
    int newKey = key % 26; //for handling keys greater than 26
    
    for(int i=0; i<len; i++) {
        char ch = str[i];
        if(ch>='a' && ch<='z') {
            ch = ((ch-'a')+newKey)%26 + 'a'; //encrypting small letters
        }
        else if(ch>='A' && ch<='Z') {
            ch = ((ch-'A')+newKey)%26 + 'A'; //encrypting capital letters
        }
        str[i] = ch;
    }
}

int main() {
    char str[100];
    int key;
    
    //taking input from user
    printf("Enter the string to encrypt: ");
    fgets(str, 100, stdin);
    printf("Enter the key (integer): ");
    scanf("%d", &key);
    
    encrypt(str, key);
    
    printf("The encrypted string is: %s\n", str);
    
    return 0;
}