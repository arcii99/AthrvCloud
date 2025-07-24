//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define THRESHOLD 0.4 // Threshold for spam detection

int main(){
    char message[1000];
    int flag = 0;
    int count = 0;
    float spam_score = 0.0;
    
    printf("Enter the message:\n");
    fgets(message, 1000, stdin); // Taking input from user
    
    // Traversing through the characters of the message and checking for spam words
    
    for(int i=0; i<strlen(message); i++){
        if(message[i] == 'f' && message[i+1] == 'r' && message[i+2] == 'e' && message[i+3] == 'e'){ // Checking for the word "free"
            count++;
        }
        else if(message[i] == 'c' && message[i+1] == 'l' && message[i+2] == 'a' && message[i+3] == 'i' && message[i+4] == 'm'){ // Checking for the word "claim"
            count++;
        }
        else if(message[i] == 'w' && message[i+1] == 'i' && message[i+2] == 'n'){ // Checking for the word "win"
            count++;
        }
        else if(message[i] == 'a' && message[i+1] == 'c' && message[i+2] == 't' && message[i+3] == 'n' && message[i+4] == 'o' && message[i+5] == 'w'){ // Checking for the word "actnow"
            count++;
        }
        else if(message[i] == 'd' && message[i+1] == 'i' && message[i+2] == 's' && message[i+3] == 'c' && message[i+4] == 'o' && message[i+5] == 'u' && message[i+6] == 'n' && message[i+7] == 't'){ // Checking for the word "discount"
            count++;
        }
    }
    
    // Calculating spam score using the count of spam words
    
    spam_score = (float) count/5; // Assuming that there are 5 types of spam words
    
    // Checking the spam score against the threshold
    
    if(spam_score >= THRESHOLD){
        printf("The entered message is a SPAM!\n");
        flag = 1;
    }
    
    // Printing the final result
    
    if(!flag){
        printf("The entered message is NOT a spam.\n");
    }
    
    return 0;
}