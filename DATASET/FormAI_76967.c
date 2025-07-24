//FormAI DATASET v1.0 Category: Spam Detection System ; Style: unmistakable
#include<stdio.h>
#include<string.h>

/* function to detect spam in a given message */
int spam_detection(char *message){
    int count=0, i;
    char *spam_keywords[] = {"buy", "now", "limited", "offer", "money back"};

    /* loop to check for each keyword in the message */
    for(i=0; i<5; i++){
        if(strstr(message, spam_keywords[i]) != NULL){
            count++;
        }
    }

    /* return 1 if number of spam keywords found is greater than or equal to 3, else return 0 */
    if(count >= 3){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char message[1000];

    printf("Enter the message: ");
    fgets(message, 1000, stdin);//reading input from user

    /* check for spam */
    if(spam_detection(message)){
        printf("SPAM DETECTED!\n");
    }
    else{
        printf("Message is not spam.\n");
    }

    return 0;
}