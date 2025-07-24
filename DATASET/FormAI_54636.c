//FormAI DATASET v1.0 Category: Spell checking ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000 //maximum number of words

//function to check spelling of a given word
void check_spelling(char word[]){
    FILE *fp;
    int found = 0;
    char temp[MAX];
    fp = fopen("dictionary.txt","r");
    if(fp == NULL){
        printf("Dictionary file does not exist!");
        exit(1);
    }
    while(fgets(temp,MAX,fp)!= NULL){ //loop to read words from dictionary
        temp[strlen(temp) - 1] = '\0'; //removing extra '\n' character at the end of fgets()
        if(strcmp(temp,word)==0){ //comparing words
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("%s is not found in the dictionary\n",word);
}

//driver function
int main(){
    char input[MAX],ch;
    int i = 0;
    printf("Enter a sentence: ");
    while((ch = getchar())!= '\n'){ //loop to read sentence character by character
        if(ch != ' '){
            input[i++] = ch; //adding character to the word
        }
        else{
            input[i] = '\0'; //adding null character at the end of the word
            check_spelling(input); //calling check_spelling function to check the spelling of the word
            i = 0;
        }
    }
    input[i] = '\0'; //adding null character at the end of the last word
    check_spelling(input); //checking the spelling of the last word
    return 0;
}