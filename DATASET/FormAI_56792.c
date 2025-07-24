//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: single-threaded
#include<stdio.h>
#include<string.h>

char* translate(char* sentence)
{
    char result[1000] = "";

    for(int i=0;i<strlen(sentence);i++) {
        
        if (sentence[i] == 'C' || sentence[i] == 'c') {
            strcat(result, "Meow ");
        } else if (sentence[i] == 'A' || sentence[i] == 'a') {
            strcat(result, "Purr ");
        } else if (sentence[i] == 'T' || sentence[i] == 't') {
            strcat(result, "Hiss ");
        } else if (sentence[i] == 'G' || sentence[i] == 'g') {
            strcat(result, "Scratch ");
        } else {
            char s[2] = "";
            s[0] = sentence[i];
            strcat(result, s);
            strcat(result, " ");
        }
    }
    return result;    
}

int main() {
    char input[1000];
    printf("Enter a sentence in C Cat Language:\n");
    scanf("%[^\n]s", input);

    char* result = translate(input);
    printf("Translated Sentence:\n%s\n", result);
    return 0;
}