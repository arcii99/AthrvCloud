//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include<stdio.h>
#include<string.h>
#define MAX 1000

int wordCount(char sentence[MAX]){
    int i, count=1;
    for(i=0;sentence[i]!='\0';i++){
        if(sentence[i]==' ' && sentence[i+1]!=' '){
            count++;
        }
    }
    return count;
}

int main(){
    char sentence[MAX];
    printf("Enter a sentence: ");
    gets(sentence);
    printf("Word count: %d\n", wordCount(sentence));
    return 0;
}