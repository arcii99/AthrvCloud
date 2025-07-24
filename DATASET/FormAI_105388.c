//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include<stdio.h>
#include<string.h>
#define SIZE 100

char* catToEnglish(char cat[SIZE]){
    // Array of cat words and their English translations
    char catWords[][SIZE] = {"meow", "purr", "hiss", "scratch", "lick", "nap", "play", "eat", "drink"};
    char engWords[][SIZE] = {"Hello", "I am happy", "Stay away", "I need attention", "I love you", "I am sleeping", "Let's have fun", "I am hungry", "I am thirsty"};
    
    static char result[SIZE];
    int i;
    
    // Search for a matching cat word and return its English translation
    for(i=0;i<9;i++){
        if(strcmp(cat, catWords[i]) == 0)
            return strcpy(result, engWords[i]);
    }
    return "Unknown cat phrase";
}

int main(){
    // Accept user input for cat language and translate it to English
    char catInput[SIZE];
    printf("Enter cat phrase: ");
    scanf("%s", catInput);
    printf("%s\n", catToEnglish(catInput));
    return 0;
}