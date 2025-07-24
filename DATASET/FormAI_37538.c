//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include<stdio.h>
#include<string.h>

void count_frequency(char *str);
void print_word_count();

struct word{
    char str[100];
    int frequency;
};

struct word word_count[1000];
int total_words=0;

int main(){
    char str[1000];
    printf("Enter a sentence : ");
    fgets(str,1000,stdin);
    count_frequency(str);
    print_word_count();
    return 0;
}

void count_frequency(char *str){
    char *token=strtok(str," .,\n");
    int flag;
    while(token!=NULL){
        flag=0;
        for(int i=0;i<total_words;i++){
            if(strcmp(token,word_count[i].str)==0){
                word_count[i].frequency+=1;
                flag=1;
            }
        }
        if(flag==0){
            strcpy(word_count[total_words].str,token);
            word_count[total_words].frequency=1;
            total_words++;
        }
        token=strtok(NULL," .,\n");
    }
}

void print_word_count(){
    printf("\nWORD\tFREQUENCY\n");
    for(int i=0;i<total_words;i++){
        printf("%s\t%d\n",word_count[i].str,word_count[i].frequency);
    }
}