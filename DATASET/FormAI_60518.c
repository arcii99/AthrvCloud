//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

#define MAX_INPUT_SIZE 1024
#define SHIFT 3

void encrypt(char *message, int shift){
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(ch >= 'a' && ch <= 'z'){
            ch = ch + shift;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + shift;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

int main(){
    char input[MAX_INPUT_SIZE];
    int len;

    printf("Mr. Sherlock Holmes, Kindly input the message you want to encrypt: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    len = strlen(input);
    if(len > 0 && input[len-1] == '\n'){
        input[len-1] = '\0';
    }

    encrypt(input, SHIFT);

    printf("Mr. Sherlock Holmes, the encrypted message is: %s\n", input);

    return 0;
}