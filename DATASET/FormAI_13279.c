//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int count=0;
    char word[100], str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    printf("\nEnter the word to count: ");
    scanf("%s", word);

    char *temp=strtok(str," ,.!?\n");
    while(temp!=NULL){
        if(strcmp(word,temp)==0)
            count++;
        temp=strtok(NULL," ,.!?\n");
    }

    printf("\nNumber of times '%s' occurs is: %d\n",word,count);
    return 0;
}