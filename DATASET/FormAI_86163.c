//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to count the number of words in a given string
int countWords(char* str){
    int count = 0;
    int flag = 0;

    for(int i=0; i<strlen(str); i++){
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){
            flag = 0;
        }
        else if(flag == 0) {
            flag = 1;
            count++;
        }   
    }
    return count;
}

int main(){
    char str[100];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    printf("The number of words in the given string is %d\n", countWords(str));
    return 0;
}