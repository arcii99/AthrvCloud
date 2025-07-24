//FormAI DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 200
#define MAX_SENTENCE 50

typedef struct sentence{
    char words[MAX_SENTENCE][MAX_LINE];
    int word_count;
    int score;
} sentence;

int get_sentence_score(sentence s){
    // calculate the score of the sentence based on the number of words and other heuristics
    // you can play around with this function to make the summary more or less verbose
    int score = 0;
    if(s.word_count >= 10){
        score += s.word_count;
    }
    else{
        score += s.word_count * 2;
    }
    
    if(strlen(s.words[s.word_count-1]) > 1 && s.words[s.word_count-1][strlen(s.words[s.word_count-1])-1] == '.'){
        score += 5;
    }
    
    return score;
}

void summarize(char *text){
    // split the text into sentences and store each sentence in an array of structs
    sentence sentences[MAX_SENTENCE];
    int sentence_count = 0;
    char *pch = strtok(text, ".!?");
    while(pch != NULL && sentence_count < MAX_SENTENCE){
        sentence s;
        s.word_count = 0;
        char *w = strtok(pch, " ");
        while(w != NULL && s.word_count < MAX_LINE){
            strcpy(s.words[s.word_count], w);
            s.word_count++;
            w = strtok(NULL, " ");
        }
        s.score = get_sentence_score(s);
        sentences[sentence_count] = s;
        sentence_count++;
        pch = strtok(NULL, ".!?");
    }
    
    // sort the sentences based on their score, so we can pick the top ones later
    for(int i=0; i<sentence_count-1; i++){
        for(int j=0; j<sentence_count-i-1; j++){
            if(sentences[j].score < sentences[j+1].score){
                sentence tmp = sentences[j+1];
                sentences[j+1] = sentences[j];
                sentences[j] = tmp;
            }
        }
    }
    
    // print the summary
    printf("SUMMARY:\n");
    for(int i=0; i<sentence_count/3; i++){
        for(int j=0; j<sentences[i].word_count; j++){
            printf("%s ", sentences[i].words[j]);
        }
        printf(". ");
    }
}

int main(){
    char text[] = "Researchers at the University of California, Berkeley, have developed a new generation of robots that are able to build other robots from scratch. This new robot-building technology is based on a process that is similar to the way that embryonic stem cells develop into specialized tissues and organs. The robots are created using a variety of materials including polymers, metals, and electronics. The researchers believe that this new technology could lead to the development of more advanced robots that are able to perform complex tasks and adapt to changing environments.";

    summarize(text);
    
    return 0;
}