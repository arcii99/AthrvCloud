//FormAI DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>

void encrypt(char *text, int shift);

int main(){
    char input[100];
    int shift;

    printf("Enter text : ");
    fgets(input, 100, stdin);
    printf("Enter shift : ");
    scanf("%d", &shift);

    encrypt(input, shift);

    printf("Encrypted text : %s\n", input);

    return 0;
}

void encrypt(char *text, int shift){
    char ch;
    
    for(int i = 0; text[i] != '\0'; i++){
        ch = text[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + shift;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            text[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + shift;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            text[i] = ch;
        }
    }
}