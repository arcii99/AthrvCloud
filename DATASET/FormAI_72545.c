//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include<stdio.h>
#include<string.h>

int main(){
    //define variables
    char str[100];
    int i, word_count, vowel_count, consonant_count;

    //ask for user input
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    //initialize counting variables
    word_count = 1;
    vowel_count = 0;
    consonant_count = 0;

    //count number of words
    for(i=0; str[i]!='\0'; i++){
        if(str[i] == ' '){
            word_count++;
        }
    }

    //count number of vowels and consonants
    for(i=0; str[i]!='\0'; i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
            vowel_count++;
        }
        else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            consonant_count++;
        }
    }

    //print the results
    printf("\nString processing result:\n");
    printf("Number of words in the string: %d\n", word_count);
    printf("Number of vowels in the string: %d\n", vowel_count);
    printf("Number of consonants in the string: %d\n", consonant_count);

    return 0;
}