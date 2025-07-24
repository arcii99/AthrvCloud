//FormAI DATASET v1.0 Category: Encryption ; Style: excited
// Woohoo, time to create an epic C Encryption program!
#include<stdio.h>
#include<string.h>

void encryption(char str[]) {
    int len = strlen(str); // calculate the length of the string
    for(int i=0; i<len; i++) { // iterate through each character of the string
        if(str[i] >= 'a' && str[i] <= 'z') { // check if the character is lowercase letter
            str[i] = 'a' + (str[i] - 'a' + 5) % 26; // convert the character to the new encrypted letter
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') { // check if the character is uppercase letter
            str[i] = 'A' + (str[i] - 'A' + 5) % 26; // convert the character to the new encrypted letter
        }
    }
}

int main() {
    char str[100]; // declare a string variable to store the user input
    printf("Welcome to the Epic C Encryption Program\n");
    printf("Enter a string to be encrypted: ");
    scanf("%[^\n]s", str); // scan the string until user input a new line character
    encryption(str); // call the function to encrypt the string
    printf("Encrypted String: %s", str); // print the encrypted string
    return 0;
}