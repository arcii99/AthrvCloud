//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

struct word_count{
    char word[MAX_WORD_LENGTH];
    int count;
};

typedef struct word_count word_count;

int main(){
    char buffer[MAX_WORD_LENGTH];
    word_count counts[MAX_WORDS];
    int num_words=0; //number of unique words counted
    int i,j,k;

    //initialize all word counts to 0
    for(i=0;i<MAX_WORDS;i++){
        counts[i].count=0;
    }

    //iterate through each word in the input
    while(scanf("%s",buffer)==1){
        //convert word to lowercase
        for(i=0;i<strlen(buffer);i++){
            buffer[i]=tolower(buffer[i]);
        }

        //if word already exists in counts, increment count
        for(i=0;i<num_words;i++){
            if(strcmp(buffer,counts[i].word)==0){
                counts[i].count++;
                break;
            }
        }

        //if word is not found, add to counts and increment num_words
        if(i==num_words){
            strcpy(counts[num_words].word,buffer);
            counts[num_words].count=1;
            num_words++;
        }
    }

    //sort words in counts by count, highest to lowest
    for(i=0;i<num_words;i++){
        for(j=i+1;j<num_words;j++){
            if(counts[i].count<counts[j].count){
                word_count temp=counts[i];
                counts[i]=counts[j];
                counts[j]=temp;
            }
        }
    }

    //print word frequency table
    for(i=0;i<num_words;i++){
        printf("%-20s%d\n",counts[i].word,counts[i].count);
    }

    return 0;
}