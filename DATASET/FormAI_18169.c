//FormAI DATASET v1.0 Category: Word Count Tool ; Style: funny
#include<stdio.h>
#include<string.h>

int count_words(char *str);
void tell_joke();

int main(){
    char sentence[100];
    int words;

    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter a sentence or phrase: ");
    fgets(sentence, 100, stdin);
    
    //check if user input is a joke
    if(strcmp(sentence,"Why did the programmer quit his job? Because he didn't get arrays!") == 0){
        tell_joke();
    } else {
        words = count_words(sentence);
        printf("The sentence contains %d words!\n", words);
    }
    
    return 0;
}

int count_words(char *str){
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            count++;
        }
    }

    return count+1;
}

void tell_joke(){
    printf("\nHa! That's a good one!\n");
    printf("Here's another for you: What do you call an alligator that works on Wall Street? An investi-gator!\n");
    printf("Thanks for using the C Word Count Tool, come back soon!\n");
}