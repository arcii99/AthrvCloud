//FormAI DATASET v1.0 Category: Text Summarizer ; Style: excited
#include<stdio.h>
#include<string.h>

int main(){

    printf("Welcome to the most advanced Text Summarizer ever!\n");
    printf("This program will take in any text and give you a concise summary of it.\n");

    char original_text[1000];
    printf("Please enter the original text:\n");
    fgets(original_text, 1000, stdin);

    char summary[500];
    int num_sentences = 1;

    for(int i = 0; i < strlen(original_text); i++){
        if(original_text[i] == '.' || original_text[i] == '?' || original_text[i] == '!'){
            num_sentences++;
            if(num_sentences > 3){
                break;
            }
        }
        summary[i] = original_text[i];
    }

    printf("Here is your summary:\n%s\n", summary);

    printf("Thank you for using our program!\n");
    return 0;
}