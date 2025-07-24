//FormAI DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// function to check if the word is valid or not
int isValid(char *word){
    int len=strlen(word);
    // check if the word contains only alphabets
    for(int i=0;i<len;i++){
        if(!isalpha(word[i]))
            return 0;
    }
    return 1;
}

int main(){

    FILE *fp;
    char word[100], ch;
    int i=0;

    // open the file in read mode
    fp=fopen("textFile.txt", "r");

    // check if the file exists or not
    if(fp==NULL){
        printf("File does not exist\n");
        return 1;
    }

    // read word by word from the file
    while((ch=fgetc(fp))!=EOF){
        if(isalpha(ch)){
            word[i]=tolower(ch);
            i++;
        }
        // if a non-alphabet character is found
        else{
            word[i]='\0';
            // check if the word is valid
            if(isValid(word)){
                // code to check if the word is spelled correctly or not
                // add your code here
            }
            // reset the index for next word
            i=0;
        }
    }

    // close the file
    fclose(fp);

    return 0;
}