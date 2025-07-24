//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include<stdio.h>
#include<string.h>

int main(){
    char sentence[1000], word[100];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); //fgets is used to take a string input with spaces
    sentence[strlen(sentence) - 1] = '\0'; //to remove the newline character at the end of the string

    printf("Enter a word to search: ");
    scanf("%s", word);

    int len_sentence = strlen(sentence), len_word = strlen(word);

    int count=0;
    for(int i=0;i<len_sentence;i++){
        if(sentence[i]==word[0]){
            int j=0, c=0;
            while(sentence[i+j]==word[j] && word[j]!='\0'){ // checking if the word is present
                c++;
                j++;
            }
            if(c==len_word){
                printf("The word %s is present at position %d\n", word, i+1);
                count++;
            }
        }
    }

    if(count==0){
        printf("The word %s is not present in the sentence.\n", word);
    }

    return 0;
}