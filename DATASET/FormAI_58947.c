//FormAI DATASET v1.0 Category: Encryption ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char inputString[100];
    int key, i, j, choice;
    char ch;
    printf("Enter input string to encrypt: ");
    fgets(inputString, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);
    printf("Choose encryption technique: \n1. Caesar cipher \n2. Vigenere cipher\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            for(i = 0; inputString[i] != '\0'; i++){
                ch = inputString[i];
                if(isalpha(ch)){
                    ch = tolower(ch);
                    ch = (ch + key - 97) % 26 + 97;
                }
                inputString[i] = ch;
            }
            printf("Encrypted using Caesar cipher: %s\n", inputString);
            break;
        case 2:
            char keyword[50];
            printf("Enter keyword for Vigenere cipher: ");
            scanf("%s", keyword);
            for(i = 0, j = 0; inputString[i] != '\0'; i++, j++){
                if(j == strlen(keyword)){
                    j = 0;
                }
                ch = inputString[i];
                if(isalpha(ch)){
                    ch = tolower(ch);
                    ch = (ch + keyword[j] - 2 * 97) % 26 + 97;
                    j++;
                }
                inputString[i] = ch;
            }
            printf("Encrypted using Vigenere cipher: %s\n", inputString);
            break;
        default:
            printf("Invalid choice\n");
            exit(EXIT_FAILURE);
    }
    return 0;
}