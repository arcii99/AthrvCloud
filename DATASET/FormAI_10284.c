//FormAI DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SPAM_THRESHOLD 0.5 //Threshold for determining a message as spam

//Function to calculate the ratio of uppercase letters to total letters in a string
float uppercase_ratio(char *text){
    int count = 0;
    int total_count = 0;
    for(int i=0; i<strlen(text); i++){
        if(text[i]>='A' && text[i]<='Z'){
            count++;
        }
        total_count++;
    }
    return (float)count/(float)total_count;
}

//Main function to check if a message is spam or not
int is_spam(char *text){
    float uppercase_ratio_val = uppercase_ratio(text);
    if(uppercase_ratio_val > SPAM_THRESHOLD){
        return 1; //Message is spam
    }
    return 0; //Message is not spam
}

int main(){
    char message[100];
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0; //Remove newline character from input
    
    if(is_spam(message)){
        printf("SPAM detected!\n");
    }
    else{
        printf("Message is not spam.\n");
    }
    
    return 0;
}