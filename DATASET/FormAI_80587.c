//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count_words(char sentence[]){ 
    int count=0;
    int len=strlen(sentence); 
    if(len==0){ 
        return 0;
    }
    for(int i=0;i<len;i++){ 
        if(sentence[i]==' '){
            count++;
        }
    }
    int words=count+1;
    return words;
}
int main(){ 
    char sentence[50];
    printf("Welcome to the Happy Word Count Tool!\n");
    printf("Enter your sentence (less than 50 chars): ");
    fgets(sentence,50,stdin); 
    int words=count_words(sentence); 
    printf("Your sentence contains %d happy words.\n", words);
    printf("Yaaaay! Your positive vibes will spread all around!\n"); 
    printf("Keep spreading love! Bye!\n");
    return 0;
}