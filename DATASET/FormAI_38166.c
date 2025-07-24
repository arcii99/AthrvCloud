//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input_text[100], original_text[100];
    int i, vowels_count = 0, consonants_count = 0, words_count = 1;

    printf("Enter some text: ");
    fgets(input_text, 100, stdin);
    strcpy(original_text, input_text);

    //Count number of vowels and consonants
    for(i=0; input_text[i]!='\0'; i++){
        if(input_text[i]=='a' || input_text[i]=='e' || input_text[i]=='i' || input_text[i]=='o' || input_text[i]=='u' || input_text[i]=='A' || input_text[i]=='E' || input_text[i]=='I' || input_text[i]=='O' || input_text[i]=='U')
            vowels_count++;
        else if((input_text[i]>='a' && input_text[i]<='z') || (input_text[i]>='A' && input_text[i]<='Z'))
            consonants_count++;
        else if(input_text[i]==' ' && input_text[i-1]!=' ')
            words_count++;
    }

    printf("\nOriginal text: %s\n", original_text);
    printf("Number of vowels: %d\n", vowels_count);
    printf("Number of consonants: %d\n", consonants_count);
    printf("Number of words: %d\n", words_count);

    return 0;
}