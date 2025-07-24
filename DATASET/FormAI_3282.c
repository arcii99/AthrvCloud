//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char spamWords[][20] = {"buy", "money", "cash", "win", "prize", "gift", 
                            "sale", "deal", "discount", "offer", "income"};
    int numWords = sizeof(spamWords)/sizeof(spamWords[0]);
    char message[100];
    int spamCount = 0; 
    int messageLen, wordLen, freq;

    printf("Enter message: ");
    fgets(message, 100, stdin); //gets message from user
    messageLen = strlen(message); 

    for(int i=0; i<numWords; i++){ 
        wordLen = strlen(spamWords[i]);  
        freq = 0; //initialize frequency to zero

        for(int j=0; j<messageLen; j++){ 
            if(message[j] == spamWords[i][0]){ 
                if(strncmp(&message[j], spamWords[i], wordLen)==0){ 
                    freq++; //increments frequency if word is found
                }
            }
        }

        if(freq){ //if frequency is not equal to zero, it's spam
            printf("\nSpam word found: %s", spamWords[i]); 
            printf("\nFrequency of word: %d\n", freq); 
            spamCount++;  //increments number of spam words detected
        }
    }

    if(spamCount){
        printf("\nMessage contains %d spam words.\n", spamCount);
    }
    else{
        printf("\nMessage is not spam.\n");
    }

    return 0; 
}