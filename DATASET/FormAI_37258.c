//FormAI DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <string.h>

int main()
{
    char email[50], keyword[10], *pos;

    printf("Enter email: ");
    fgets(email, 50, stdin);

    printf("Enter keyword: ");
    fgets(keyword, 10, stdin);

    // remove newline character
    email[strcspn(email, "\n")] = 0;
    keyword[strcspn(keyword, "\n")] = 0;

    pos = strstr(email, keyword);

    if (pos != NULL)
    {
        printf("This email may contain spam.");
    }
    else
    {
        printf("This email is safe.");
    }

    return 0;
}