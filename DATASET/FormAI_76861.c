//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Cryptic
#include<stdio.h>

int main(){
    char message[] = "Meow meow!!";
    int i, key = 6;

    printf("Original message: %s\n", message);

    for(i = 0; i < strlen(message); i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = 'a' + ((message[i] - 'a' + key) % 26);
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = 'A' + ((message[i] - 'A' + key) % 26);
        }
        else if(message[i] == '!'){
            message[i] = '.';
        }
    }

    printf("Translated message: %s\n", message);

    return 0;
}