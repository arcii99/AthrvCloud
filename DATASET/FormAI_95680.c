//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_WORD_LENGTH 50
#define MAX_SUMMARY_LENGTH 1000

//returns the frequency of word in the given sentence.
int get_frequency(char* sentence, char* word){
    int frequency=0;
    char** tokens=NULL;
    char* token=NULL;

    tokens=(char**)malloc(1000*sizeof(char*));
    if(tokens==NULL){
        printf("Error: Memory allocation failed.");
        exit(1);
    }
    token=strtok(sentence, " ,.;:");
    while(token!=NULL){
        tokens[frequency]=token;
        frequency++;
        token=strtok(NULL," ,.;:");
    }
    for(int i=0;i<frequency;i++){
        if(strcmp(tokens[i], word)==0){
            free(tokens);
            return 1;
        }
    }
    free(tokens);
    return 0;
}

//removes all punctuations from the given string.
void remove_punctuations(char* text){
    int len=strlen(text);

    for(int i=0;i<len;i++){
        if(ispunct(text[i])){
            text[i]=' ';
        }
    }
}

//returns the frequency of a given word in the text.
int get_text_frequency(char* text, char* word){
    int frequency=0;
    char** sentences=NULL;
    char* sentence=NULL;

    sentences=(char**)malloc(1000*sizeof(char*));
    if(sentences==NULL){
        printf("Error: Memory allocation failed.");
        exit(1);
    }
    sentence=strtok(text, ".!?");

    while(sentence!=NULL){
        int len=strlen(sentence);
        if(len>0 && sentence[len-1]=='\n'){
            sentence[len-1]='\0';
        }
        sentences[frequency]=sentence;
        frequency++;
        sentence=strtok(NULL,".!?");
    }

    for(int i=0;i<frequency;i++){
        char sentence_copy[MAX_SUMMARY_LENGTH];
        strcpy(sentence_copy, sentences[i]);
        remove_punctuations(sentence_copy);
        if(get_frequency(sentence_copy, word)>0){
            free(sentences);
            return 1;
        }
    }
    free(sentences);
    return 0;
}

//summarizes text using a given keyword.
void generate_summary(char* text, char* keyword){
    char** sentences=NULL;
    char* sentence=NULL;
    int sentence_count=0;
    int summary_count=0;

    sentences=(char**)malloc(1000*sizeof(char*));
    if(sentences==NULL){
        printf("Error: Memory allocation failed.");
        exit(1);
    }
    sentence=strtok(text, ".!?");
    while(sentence!=NULL){
        int len=strlen(sentence);
        if(len>0 && sentence[len-1]=='\n'){
            sentence[len-1]='\0';
        }
        sentences[sentence_count]=sentence;
        sentence_count++;
        sentence=strtok(NULL, ".!?");
    }
    for(int i=0;i<sentence_count;i++){
        char sentence_copy[MAX_SUMMARY_LENGTH];
        strcpy(sentence_copy, sentences[i]);
        if(get_frequency(sentence_copy, keyword)>0 || get_text_frequency(text, keyword)>0){
            printf("%s. ", sentences[i]);
            summary_count++;
            if(summary_count>=5){
                break;
            }
        }
    }
    free(sentences);
}

int main(){
    char text[MAX_SUMMARY_LENGTH];
    char keyword[MAX_WORD_LENGTH];

    printf("Enter the text: \n");
    fgets(text, MAX_SUMMARY_LENGTH, stdin);

    printf("Enter the keyword: \n");
    fgets(keyword, MAX_WORD_LENGTH, stdin);

    generate_summary(text, keyword);

    return 0;
}