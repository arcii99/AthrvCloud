//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char input[100];
    int count=0, i=0;

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin); //input from user

    while(input[i]!='\n'){ //count number of words in input
        if(input[i]==' '){ 
            count++; //if space encountered, word count increases
        }
        i++;
    }
    count++; //last word is not followed by a space

    printf("Number of words: %d\n",count); //display word count

    return 0; 
}