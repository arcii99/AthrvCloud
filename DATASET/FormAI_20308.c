//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include <stdio.h>

void main() {
    char input[1000], output[1000];
    int i, j=0;
    
    printf("Enter a sentence in C Cat Language:\n");
    fgets(input, 1000, stdin);
    
    // Convert the input string
    for(i=0; input[i]!='\0'; i++) {
        if(input[i]=='m' && input[i+1]=='e' && (input[i+2]=='o' || input[i+2]=='e')) {
            output[j++] = 'I';
            i += 2;
        }
        else if(input[i]=='k' && input[i+1]=='a' && input[i+2]== 't') {
            output[j++] = 'you';
            i += 2;
        }
        else if((input[i]=='w' && input[i+1]=='a' && input[i+2]=='n') || (input[i]=='w' && input[i+1]=='a' && input[i+2]=='n' && input[i+3]=='t')) {
            output[j++] = 'want';
            i += 3;
        }
        else if(input[i]=='m' && input[i+1]=='u' && input[i+2]=='r') {
            output[j++] = 'good';
            i += 2;
        }
        else {
            output[j++] = input[i];
        }
    }
    
    output[j] = '\0';
    printf("\nTranslated Sentence: %s\n", output);
    
}