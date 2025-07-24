//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
#include<stdio.h>
#include<string.h>

//function to encrypt the input string
void encrypt(char* str) {
    int len = strlen(str);
    
    //loop through all characters in the string
    for(int i = 0; i < len; i++) {
        //perform custom encryption operation on each character
        str[i] = str[i] + 3;
    }
}

int main() {
    char input[100]; //array to store input string
    
    //get input from user
    printf("Enter the string you want to encrypt: ");
    scanf("%[^\n]s", input);
    
    //call encryption function and print the encrypted string
    encrypt(input);
    printf("Encrypted string: %s", input);
    
    return 0;
}