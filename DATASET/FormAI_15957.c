//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include<stdio.h>
#include<string.h>

char* english_words[] = {"Hello", "World", "How", "Are", "You"};

char* cat_language_words[] = {"Meow", "Purr", "Hiss", "Paws", "Tail"};

char* translate_to_cat_language(char *english_word) {
    int i, n=5;
    for(i=0; i<n; i++) {
        if(strcmp(english_word, english_words[i]) == 0) {
            return cat_language_words[i];
        }
    }
    return english_word;
}

int main() {
    char input_str[100], *word;
    printf("Enter sentence to translate to cat language:\n");
    fgets(input_str, 100, stdin);
    printf("Cat language translation:  ");
    word = strtok(input_str, " ");
    while(word != NULL) {
        printf("%s ", translate_to_cat_language(word));
        word = strtok(NULL, " ");
    }
    return 0;
}