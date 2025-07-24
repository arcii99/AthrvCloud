//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function to encrypt the string
void encrypt(char str[]) {

    int len = strlen(str);

    // iterate through each character of the string
    for(int i=0;i<len;i++) {
        
        // if the character is a space or non-alphabetical, skip it
        if(str[i] == ' ' || !isalpha(str[i]))
            continue;

        // encrypt uppercase letter
        if(isupper(str[i])) {
            str[i] = (((str[i] - 'A') + 13) % 26) + 'A';
        }

        // encrypt lowercase letter
        if(islower(str[i])) {
            str[i] = (((str[i] - 'a') + 13) % 26) + 'a';
        }
    }

}

int main() {
    
    char plain_text[100];
    
    printf("Enter the string you want to encrypt: ");
    fgets(plain_text, 100, stdin);

    // remove the newline character at the end of the input string
    plain_text[strcspn(plain_text, "\n")] = '\0';

    // encrypt the input string
    encrypt(plain_text);

    printf("The encrypted string is: %s", plain_text);

    return 0;
}