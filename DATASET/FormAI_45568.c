//FormAI DATASET v1.0 Category: Word Count Tool ; Style: curious
#include<stdio.h>
#include<string.h>

int main(){
    printf("\nEnter a sentence that you want to count: ");
    char sentence[100];
    fgets(sentence,100,stdin);
    int len=strlen(sentence);
    int wordCount=0;
    int inWord=0;
    if(sentence[0]=='\n') printf("Word count: %d",wordCount);
    else{
        for(int i=0;i<len;i++){
            if(sentence[i]==' '||sentence[i]=='\n'||sentence[i]=='\t'){
                inWord=0;
            }
            else if(inWord==0){
                inWord=1;
                wordCount++;
            }
        }
        printf("Word count: %d",wordCount);
    }
    return 0;
}