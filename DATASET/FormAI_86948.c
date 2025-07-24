//FormAI DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include<stdio.h>
#include<string.h>
#define MAX 1000

int main(){

    char text[MAX];

    //taking input from the user
    printf("Enter the text to be summarized:\n");
    fgets(text, MAX, stdin);

    //removing punctuation marks from the text
    for(int i=0; text[i]!='\0'; i++){
        if(text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!' || text[i] == ':' || text[i] == ';'){
            text[i] = ' ';
        }
    }

    //splitting the text into individual words
    char* words[MAX];
    int count = 0;
    words[0] = strtok(text, " ");
    count++;
    while(words[count-1] != NULL){
        words[count] = strtok(NULL, " ");
        count++;
    }

    //counting the frequency of each word
    int freq[MAX];
    for(int i=0; i<count-1; i++){
        freq[i] = 1;
        for(int j=i+1; j<count-1; j++){
            if(strcmp(words[i], words[j])==0){
                freq[i]++;
                words[j] = "";
            }
        }
    }

    //finding top 5 most frequent words
    char top_words[5][MAX];
    int top_freq[5] = {0,0,0,0,0};
    for(int i=0; i<count-1; i++){
        if(strlen(words[i]) > 0 && freq[i] > top_freq[0]){
            top_freq[0] = freq[i];
            strcpy(top_words[0], words[i]);
        }
        else if(strlen(words[i]) > 0 && freq[i] > top_freq[1]){
            top_freq[1] = freq[i];
            strcpy(top_words[1], words[i]);
        }
        else if(strlen(words[i]) > 0 && freq[i] > top_freq[2]){
            top_freq[2] = freq[i];
            strcpy(top_words[2], words[i]);
        }
        else if(strlen(words[i]) > 0 && freq[i] > top_freq[3]){
            top_freq[3] = freq[i];
            strcpy(top_words[3], words[i]);
        }
        else if(strlen(words[i]) > 0 && freq[i] > top_freq[4]){
            top_freq[4] = freq[i];
            strcpy(top_words[4], words[i]);
        }
    }

    //printing the summary
    printf("\nSummary:\n");
    for(int i=0; i<5; i++){
        if(strlen(top_words[i]) > 0){
            printf("%s ", top_words[i]);
        }
    }
    
    return 0;
}