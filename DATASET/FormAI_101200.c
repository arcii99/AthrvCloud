//FormAI DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 256
#define FLAGGED_THRESHOLD 0.3

int main()
{
    char msg[MAX_MSG_LENGTH];
    double flag_count = 0.0;

    printf("Enter a message: ");
    fgets(msg, MAX_MSG_LENGTH, stdin);

    // Remove newline character at end of message
    msg[strcspn(msg, "\n")] = '\0';

    // Check for spam keywords
    if (strstr(msg, "free") != NULL)
        flag_count += 0.5;
    if (strstr(msg, "loan") != NULL)
        flag_count += 0.4;
    if (strstr(msg, "money") != NULL)
        flag_count += 0.3;
    if (strstr(msg, "discount") != NULL)
        flag_count += 0.2;
    if (strstr(msg, "prize") != NULL)
        flag_count += 0.2;
    if (strstr(msg, "winner") != NULL)
        flag_count += 0.1;

    // Check flag count against threshold
    if (flag_count >= FLAGGED_THRESHOLD)
    {
        printf("Message flagged as spam.\n");
    }
    else
    {
        printf("Message OK.\n");
    }

    return 0;
}