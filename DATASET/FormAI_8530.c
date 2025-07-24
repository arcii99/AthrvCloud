//FormAI DATASET v1.0 Category: File Backup System ; Style: surrealist
#include<stdio.h>

void alienEncrypt(char code[]); // function declaration
void humanDecrypt(char code[]); // function declaration

int main(){

    char code[500];

    // for human
    printf("Enter your C file code here: ");
    fgets(code, 500, stdin); // take input from user
    printf("Your code before backup:\n%s\n", code); // display user's input
    humanDecrypt(code); // call human decryption function
    printf("Your code after encryption by aliens:\n%s\n", code); // display encrypted code

    // for aliens
    printf("Welcome aliens! Please enter your encryption code: ");
    fgets(code, 500, stdin);
    printf("Your decryption code before backup:\n%s\n", code);
    alienEncrypt(code); // call alien encryption function
    printf("Your decryption code after backup:\n%s\n", code);

    // exit
    printf("Program executed successfully. Goodbye!\n");
    return 0;
}

// function to encrypt code as per aliens' language
void alienEncrypt(char code[]){

    // change all alphabets to numbers as per alien's language
    for(int i=0; code[i]!='\0'; i++){
        switch (code[i]){
            case 'a':
                code[i] = '1';
                break;
            case 'b':
                code[i] = '2';
                break;
            case 'c':
                code[i] = '3';
                break;
            case 'd':
                code[i] = '4';
                break;
            case 'e':
                code[i] = '5';
                break;
            case 'f':
                code[i] = '6';
                break;
            case 'g':
                code[i] = '7';
                break;
            case 'h':
                code[i] = '8';
                break;
            case 'i':
                code[i] = '9';
                break;
            case 'j':
                code[i] = '?';
                break;
            default:
                code[i] = '0';
        }
    }

    return;
}

// function to decrypt code as per human language
void humanDecrypt(char code[]){

    // change all numbers as per human's language
    for(int i=0; code[i]!='\0'; i++){
        switch (code[i]){
            case '1':
                code[i] = 'a';
                break;
            case '2':
                code[i] = 'b';
                break;
            case '3':
                code[i] = 'c';
                break;
            case '4':
                code[i] = 'd';
                break;
            case '5':
                code[i] = 'e';
                break;
            case '6':
                code[i] = 'f';
                break;
            case '7':
                code[i] = 'g';
                break;
            case '8':
                code[i] = 'h';
                break;
            case '9':
                code[i] = 'i';
                break;
            case '?':
                code[i] = 'j';
                break;
            default:
                code[i] = '0';
        }
    }

    return;
}