//FormAI DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
    char spam[] = "Viagra";
    char message[50];
    printf("Please enter your message: ");
    scanf("%s", message);
    int len = strlen(spam);
    int flag = 0;

    for(int i=0; i<strlen(message)-len+1; i++)
    {
        // Compare substring with spam string
        if(strncmp(message+i, spam, len) == 0)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        printf("Warning! Spam detected in your message.\n");
    else
        printf("Your message is safe.\n");

    return 0;
}