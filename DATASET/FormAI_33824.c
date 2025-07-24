//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include<stdio.h>

int main() {
    char sentence[100];
    int i;

    // Taking input from user
    printf("Enter a sentence in C Cat Language:\n");
    gets(sentence);

    // Loop to translate each word
    for(i=0; sentence[i]!='\0'; i++) {
        if(sentence[i] == 'm' && sentence[i+1] == 'e') {
            printf("I ");
            i++;
        }
        else if(sentence[i] == 'h' && sentence[i+1] == 'a') {
            printf("am ");
            i++;
        }
        // Add more cases to translate other words
        else {
            printf("%c", sentence[i]);
        }
    }

    printf("\n");

    return 0;
}