//FormAI DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int is_spam(char msg[]){
    char spam_words[10][20] = {"buy now", "refinance", "dating", "make money", "amazing offer", "guaranteed", "limited time", "click here", "opportunity", "discount"};
    int i, j, count=0;
    int len = strlen(msg);
  
    for(i=0;i<10;i++){
        for(j=0;j<len-strlen(spam_words[i])+1;j++){
            if(strncmp(spam_words[i], &msg[j], strlen(spam_words[i]))==0){
                count++;
                j+=strlen(spam_words[i]) - 1;
            }
        }
    }

    if(count>=2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char message[500];
    printf("Enter your message: ");
    fgets(message, 500, stdin);
  
    if(is_spam(message)){
        printf("This message is spam.");
    }
    else{
        printf("This message is not spam.");
    }

    return 0;
}