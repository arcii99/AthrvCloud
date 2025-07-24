//FormAI DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>

int main(){
    char message[100];
    int spam_count = 0;

    printf("My love, please enter your message:\n");
    scanf("%[^\n]s", message);
    getchar(); // to consume the enter button pressed after typing the message

    for(int i=0; i<strlen(message); i++){
        if (message[i] == 'c' && message[i+1] == 's' && message[i+2] == 'p' && message[i+3] == 'a' && message[i+4] == 'm') {
            spam_count++;
        }
    }

    if (spam_count > 0){
        printf("My love, your message contains spam. Please do not send spam in the future.\n");
    } else {
        printf("My love, your message is free from spam. I am glad that it is a romantic message.\n");
    }

    return 0;
}