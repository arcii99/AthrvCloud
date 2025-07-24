//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include<stdio.h>
#include<ctype.h>
#include<string.h>

//Function to count words in a given text 
int wordCount(char *text){
    int count=0;
    int flag=0; //flag to indicate start of new word
    for(int i=0;i<strlen(text);i++){
        if(isalpha(text[i]) && flag==0){ //check if character is alphabet and flag is not set
            count++; //increment the count of words
            flag=1; //set the flag to indicate start of new word
        }
        else if(!isalpha(text[i])){ //check if character is not alphabet
            flag=0; //reset the flag
        }
    }
    return count;
}

int main(){
    char text[1000];
    printf("Enter some text (less than 1000 characters): ");
    fgets(text,1000,stdin);
    printf("Number of words in the text: %d",wordCount(text));
    return 0;
}