//FormAI DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000 //Maximum length of input string

int main(){
    char input[MAX_LEN]; //input string
    int shift; //shift required in Caesar Cipher

    //Get input string and shift value from user
    printf("Enter the string to encrypt: ");
    fgets(input, MAX_LEN, stdin);
    printf("Enter the desired shift of Caeser Cipher (numeric): ");
    scanf("%d", &shift);

    //encrypt the input string using Caeser Cipher with given shift
    int i, input_len = strlen(input);
    for(i = 0; i < input_len; i++){
        //encrypt lower-case letters
        if(input[i] >= 'a' && input[i] <= 'z'){
            input[i] = (input[i] + shift - 'a') % 26 + 'a';
        }
        //encrypt upper-case letters
        else if(input[i] >= 'A' && input[i] <= 'Z'){
            input[i] = (input[i] + shift - 'A') % 26 + 'A';
        }
        //do not encrypt other characters
        else{
            input[i] = input[i];
        }
    }

    printf("Encrypted string: %s", input);

    return 0;
}