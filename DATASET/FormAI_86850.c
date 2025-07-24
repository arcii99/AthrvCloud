//FormAI DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include<stdio.h>
#include<string.h>

int main(){
    char message[1000];
    int len, i, spam_count=0;
    printf("Please enter your message: ");
    fgets(message,1000,stdin);
    len = strlen(message);
    for(i=0;i<len;i++){
        if(message[i] == 's' && message[i+1] == 'p' && message[i+2] == 'a' && message[i+3] == 'm'){
            spam_count++;
            i = i+3;
        }
    }
    if(spam_count > 0){
        printf("This message contains %d instances of spam.\n", spam_count);
        printf("Please refrain from spamming.\n");
    } else {
        printf("This message does not contain any spam.");
    }

    return 0;
}