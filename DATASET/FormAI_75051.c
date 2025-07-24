//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* morse_code(char letter){
    char* code;
    switch(toupper(letter)){
        case 'A': code = ".-";break;
        case 'B': code = "-...";break;
        case 'C': code = "-.-.";break;
        case 'D': code = "-..";break;
        case 'E': code = ".";break;
        case 'F': code = "..-.";break;
        case 'G': code = "--.";break;
        case 'H': code = "....";break;
        case 'I': code = "..";break;
        case 'J': code = ".---";break;
        case 'K': code = "-.-";break;
        case 'L': code = ".-..";break;
        case 'M': code = "--";break;
        case 'N': code = "-.";break;
        case 'O': code = "---";break;
        case 'P': code = ".--.";break;
        case 'Q': code = "--.-";break;
        case 'R': code = ".-.";break;
        case 'S': code = "...";break;
        case 'T': code = "-";break;
        case 'U': code = "..-";break;
        case 'V': code = "...-";break;
        case 'W': code = ".--";break;
        case 'X': code = "-..-";break;
        case 'Y': code = "-.--";break;
        case 'Z': code = "--..";break;
        default:
            return "";
    }
    return code;
}

void morse_encrypt(char* message){
    char* letter;
    char ciphertext[1000] = "";
    for(int i=0;i<strlen(message);i++){
        letter = morse_code(message[i]);
        if(strcmp(letter, "") == 0){
            continue;
        }
        strcat(ciphertext, letter);
        strcat(ciphertext, " ");
    }
    printf("Morse Code:\n%s\n", ciphertext);
}

void morse_decrypt(char* code){
    char plaintext[1000] = "";
    char letter;
    char buffer[10];
    int j=0;
    for(int i=0;code[i] != '\0';i++){
        if(code[i] == ' '){
        letter = 0;
            for(int k=0;k<j;k++){
                buffer[k] = buffer[k] == '.' ? 1 : 0;
                letter += buffer[j-k-1] << k;
            }
            j = 0;
            strncat(plaintext, &letter, 1);
        }else{
            buffer[j++] = (code[i] == '.') ? '.' : '-';
        }
    }
    printf("Original Text:\n%s\n", plaintext);
}

int main(){
    int choice;
    char message[1000];
    char code[1000];
    printf("Enter Message:\n> ");
    fgets(message,1000,stdin);
    do{
        printf("\n---------------------------------------\n");
        printf("Choose an option:\n");
        printf("1. Encrypt message to Morse Code\n");
        printf("2. Decrypt Morse Code to message\n");
        printf("3. Exit\n");
        printf("> ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                morse_encrypt(message);
                break;
            case 2:
                printf("Enter Morse Code:\n> ");
                fflush(stdin);
                fgets(code,1000,stdin);
                morse_decrypt(code);
                break;
            case 3:
                printf("Good Bye!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    }while(choice != 3);

    return 0;
}