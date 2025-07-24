//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>

/* Function to check if a given string contains spam keywords */
int checkSpam(char* str){
    char spamWords[10][20] = {"free", "offer", "click here", "earn money", "make money", "subscribe", "download", "buy now", "limited time offer", "discount"};
    int spamCount = 0;  // Counter variable to keep track of number of spam keywords found

    // Convert string to lower case
    for(int i=0; i<strlen(str); i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i] = str[i] + ('a'-'A');
        }
    }

    // Check if the string contains any spam keywords
    for(int i=0; i<10; i++){
        char* p = strstr(str, spamWords[i]);  /* Check if spamWords[i] is a substring of str */
        if(p != NULL){
            spamCount++;
            str = p + strlen(spamWords[i]);  /* Update str to start searching from the next character after the spam keyword */
        }
    }

    return spamCount;
}

int main(){
    char msg[100];
    int spamScore;

    printf("Enter your message:\n");
    fgets(msg, 100, stdin);  // Read input string

    spamScore = checkSpam(msg);

    if(spamScore > 0){
        printf("This message contains %d spam keywords. It might be a spam!", spamScore);
    }else{
        printf("This message doesn't contain any spam keywords. It's safe to proceed with it.");
    }

    return 0;
}