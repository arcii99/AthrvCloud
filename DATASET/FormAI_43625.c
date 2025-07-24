//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: irregular
#include<stdio.h>
#include<string.h>
// Initializing the C Cat Language Dictionary
char dictionary[15][10]={"meow","purr","hiss","scratch","claw","whisker","tail","nap","litter","kitten","mouse","bowl","milk","yawn","pounce"};
char meaning[15][20]={"Hello","Happy","Angry","Trouble","Attack","Curiosity","Angry","Sleep","Waste","Baby","Food","Eat","Drink","Tired","Jump"};

// Function to Translate C Cat Language to English
void ccat_to_english(char sentence[100]){
    char *words[100];
    int i=0, j=0;

    // Storing words in sentence in an array of pointers
    words[i] = strtok(sentence, " ");
    while(words[i] != NULL){
        words[++i] = strtok(NULL, " ");
    }
    // Iterating through each word and translating it using the C Cat Language Dictionary
    for(int k=0; k<i; k++){
        for(j=0; j<15; j++){
            if(strcmp(dictionary[j], words[k]) == 0){
                printf("%s ",meaning[j]);
                break;
            }
        }
        // If the word is not present in the dictionary, then it is printed as it is
        if(j==15){
            printf("%s ", words[k]);
        }
    }
}

// Sample Main Function
int main(){
    char sentence[100];
    printf("Enter a sentence in C Cat language: ");
    gets(sentence);
    printf("The English translation of the sentence is: ");
    ccat_to_english(sentence);
    return 0;
}