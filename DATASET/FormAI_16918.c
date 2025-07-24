//FormAI DATASET v1.0 Category: Spell checking ; Style: configurable
#include<stdio.h>
#include<ctype.h>
#include<string.h>

//Function for changing all characters to lowercase
void toLowerCase(char *s){
    while(*s!='\0'){
        *s = tolower(*s);
        s++;
    }
}

//Function for removing non-alphabets from string
void removeNonAlphabetic(char *s){
    char *pos = s;
    while(*s!='\0'){
        if(isalpha(*s)){
            *pos = *s;
            pos++;
        }
        s++;
    }
    *pos = '\0';
}

//Function for checking spelling
void checkSpelling(char *dictionary[], int dict_size, char *word){
    char temp_word[50];
    strcpy(temp_word,word);
    toLowerCase(temp_word);
    removeNonAlphabetic(temp_word);

    for(int i=0;i<dict_size;i++){
        if(strcmp(temp_word,dictionary[i])==0){
            printf("%s is spelled correctly.\n",word);
            return;
        }
    }

    printf("%s is not spelled correctly.\n",word);
}

int main(){

    char *dictionary[] = {"cryptography","algorithm","programming","computer","software","database"};
    int dict_size = sizeof(dictionary)/sizeof(char*);

    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence,100,stdin);

    char *word = strtok(sentence," \n");

    while(word!=NULL){
        checkSpelling(dictionary,dict_size,word);
        word = strtok(NULL," \n");
    }

    return 0;
}