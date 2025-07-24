//FormAI DATASET v1.0 Category: Word Count Tool ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
    char str[100];
    int word_count = 0;
    printf("Welcome to C Word Count Tool\n");
    printf("Please enter a sentence or phrase: ");
    fgets(str, 100, stdin);
    for(int i = 0; i < strlen(str); i++){
        if(isalpha(str[i]) && !isspace(str[i])){
            word_count++;
            while(isalpha(str[i]))
                i++;
        }
    }
    if(word_count == 0)
        printf("Looks like you didn't enter any words.\n");
    else if(word_count == 1)
        printf("You entered one word, and that word is \"%s\"\n", str);
    else
        printf("You entered %d words\n", word_count);
    printf("Thank you for using C Word Count Tool. Don't forget to come back with more words!\n");
    
    return 0;
}