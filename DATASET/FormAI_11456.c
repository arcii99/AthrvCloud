//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 1000

char sentiments[14][10] = {"happy", "joy", "excited", "pleasant", "good", "great", "love", "amazing", "hopeful", "awesome", "satisfied", "grateful", "proud", "confident"};

bool is_punctuation(char c){
    if(c == '!' || c == ',' || c == '.' || c == ';' || c == ':' || c == '?' || c == '-'){
        return true;
    }
    return false;
}

void remove_punctuation(char* s){
    int i, j;
    for(i = 0; s[i] != '\0'; i++){
        if(is_punctuation(s[i])){
            for(j = i; s[j] != '\0'; j++){
                s[j] = s[j+1];
            }
            s[j] = '\0';
        }
    }
}

void to_lowercase(char* s){
    int i;
    for(i = 0; s[i] != '\0'; i++){
        s[i] = tolower(s[i]);
    }
}

int count_words(char* s){
    int count = 0;
    char* p = strtok(s, " ");
    while(p != NULL){
        count++;
        p = strtok(NULL, " ");
    }
    return count;
}

bool contains_sentiment(char* s){
    remove_punctuation(s);
    to_lowercase(s);
    int i, j;
    int word_count = count_words(s);
    char words[MAX_SIZE][MAX_SIZE];
    char* p = strtok(s, " ");
    i = 0;
    while(p != NULL){
        strcpy(words[i], p);
        p = strtok(NULL, " ");
        i++;
    }
    for(i = 0; i < word_count; i++){
        for(j = 0; j < 14; j++){
            if(strcmp(words[i], sentiments[j]) == 0){
                return true;
            }
        }
    }
    return false;
}

int main(){
    char s[MAX_SIZE];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove trailing newline character
    if(contains_sentiment(s)){
        printf("The string contains a positive sentiment.\n");
    }else{
        printf("The string does not contain a positive sentiment.\n");
    }
    return 0;
}