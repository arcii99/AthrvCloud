//FormAI DATASET v1.0 Category: Spam Detection System ; Style: thriller
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char msg[1000];
    int count = 0;

    printf("Enter the message:\n");
    scanf("%[^\n]%*c", msg);
    //Checking messages for spam keywords/codes
    if(strstr(msg,"buy now")) {
        count++;
    }
    if(strstr(msg,"make money fast")) {
        count++;
    }
    if(strstr(msg,"cash prize")) {
        count++;
    }
    //if spam count is more than 2 then message is spam
    if(count > 2) {
        printf("\nSPAM MESSAGE DETECTED!\n");
    }
    else {
        printf("\nMESSAGE IS NOT SPAM.\n");
    }

    return 0;
}