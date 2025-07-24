//FormAI DATASET v1.0 Category: Spam Detection System ; Style: paranoid
#include <stdio.h>
#include <string.h>

int main()
{
    char spam_message[1000];
    int i, j, flag;

    printf("Please enter your message: ");
    gets(spam_message);

    char *spam_words[] = {"free", "click here", "make money", "limited time offer", "million dollars", "earn", "cash", "discount", "guaranteed", "exclusive offer"};

    int spam_count = 0;
    for(i=0; i<strlen(spam_message); i++){
        flag = 0;
        for(j=0; j<10; j++){
            if(spam_message[i] == spam_words[j][0]){
                if(strncmp(&spam_message[i], spam_words[j], strlen(spam_words[j])) == 0){
                    spam_count++;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag){
            i += strlen(spam_words[j])-1;
        }
    }

    int ratio = ((float)spam_count / (float)strlen(spam_message)) * 100;

    printf("\n\n************************************************************\n\n");
    printf("SPAM DETECTION RESULTS:\n\n");
    printf("The message you entered is %d%% likely to be spam.\n\n", ratio);
    if(ratio > 10){
        printf("This message contains a high percentage of spam words. Please review your message and try again.\n");
    } else {
        printf("This message is likely acceptable and has no apparent spam words.\n");
    }
    printf("\n\n************************************************************\n\n");

    return 0;
}