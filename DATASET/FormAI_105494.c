//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char* str;
    int freq[26] = {0}; //initialize frequency table with 0's
    int len, i;

    printf("Welcome to Chatbot's C Word Frequency Counter! \n");
    printf("Please enter a string: ");
    fgets(str, 100, stdin);
    
    len = strlen(str);

    //convert all characters to lowercase for easy comparison 
    for(i=0; i<len; i++){
        str[i] = tolower(str[i]); 
    }

    //update frequency table
    for(i=0; i<len; i++){
        if(str[i]>='a' && str[i]<='z'){
            freq[str[i] - 'a']++;
        }
    }

    //print character frequency table
    printf("Character frequency table: \n");
    for(i=0; i<26; i++){
        if(freq[i]!=0){
            printf("%c: %d \n", (i+'a'), freq[i]);
        }
    }

    return 0;
}