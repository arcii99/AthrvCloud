//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include<stdio.h>
#include<string.h>

char *c_cat_language[] = {"meow", "purr", "hiss", "scratch", "nibble"};
char *english[] = {"hello", "how are you", "goodbye", "please stop", "I'm hungry"};

void translate(char *word) {
    int i;
    for(i=0;i<5;i++){
        if(!strcmp(word,c_cat_language[i])){
            printf("%s", english[i]);
            return;
        }
    }
    printf("Sorry, I don't understand that word.");
}

int main() {
    char word[20];
    printf("Welcome to the C Cat Language Translator\n");
    printf("Please enter a word in c cat language: ");
    scanf("%s", word);
    translate(word);
    return 0;
}