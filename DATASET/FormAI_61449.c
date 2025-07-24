//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>

int main(){
    char input[100];
    char output[100];
    printf("Enter the C Cat Language: ");
    fgets(input, 100, stdin);
    int len = strlen(input);
    for(int i = 0; i < len; i++){
        if(input[i] == 'c' || input[i] == 'C'){
            output[i] = 'm';
        }
        else if(input[i] == 'a' || input[i] == 'A'){
            output[i] = 'e';
        }
        else if(input[i] == 't' || input[i] == 'T'){
            output[i] = 'o';
        }
        else if(input[i] == ' '){
            output[i] = ' ';
        }
        else{
            output[i] = input[i] + 1;
        }
    }
    printf("Translated to Linus Torvalds Style: %s\n", output);
    return 0;
}