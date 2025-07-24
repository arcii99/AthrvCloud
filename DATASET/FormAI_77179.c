//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include<stdio.h>
#include<string.h>

int main(){
    char message[1000];
    int i=0, j=0, count=0;
    printf("Enter message: ");
    fgets(message, 1000, stdin); //Reads message from user
    int len=strlen(message);
    for(i=0; i<len; i++){ //Loop to count number of characters
        if(message[i]!=' ' && message[i]!='\n'){ //If character is not space or new line
            count++;
        }
    }
    float ratio=(float)count/len; //Calculating ratio
    if(ratio>0.3){ //If ratio is greater than 0.3
        printf("Warning: Possible spam detected!"); 
    }
    else{
        printf("Message is not spam."); //If ratio is <=0.3
    }
    return 0;
}