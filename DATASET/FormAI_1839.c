//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ken Thompson
//This is a spam detection system program written in Ken Thompson style.

#include <stdio.h>
#include <string.h>
#define SPAM "best deal"
#define PHISHING "please confirm your account information"

int main(void){

    char email[100];
    int spam_count, phishing_count;
    char *spam_test, *phishing_test = NULL;

    printf("Enter your email: ");
    scanf("%s", email);

    //testing for spam messages using strstr() function
    spam_test = strstr(email, SPAM);
    if(spam_test != NULL){
        spam_count++;
        printf("Detected spam message: %s\n", spam_test);
    }

    //testing for phishing messages
    phishing_test = strstr(email, PHISHING);
    if(phishing_test != NULL){
        phishing_count++;
        printf("Detected phishing message: %s\n", phishing_test);
    }

    //printing results
    if(spam_count > 0){
        printf("Received %d spam messages. Please delete them.\n", spam_count);
    }

    if(phishing_count > 0){
        printf("Received %d phishing messages. Please do not reply to them.\n", phishing_count);
    }

    return 0;
}