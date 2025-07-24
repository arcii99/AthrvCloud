//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void detect_intrusion(char *message)
{
    char *keywords[] = {"hacker", "breach", "compromised", "virus", "attack", "malware", "exploit", "intrusion"};
    int num_keywords = sizeof(keywords) / sizeof(char *);
    int i, j;

    for (i = 0; i < num_keywords; i++)
    {
        if (strstr(message, keywords[i]))
        {
            printf("Intrusion detected: \"%s\"\n", keywords[i]);

            // Take appropriate action here...

            exit(0);
        }
    }
}

int main(void)
{
    char message[256];

    printf("Welcome to the Intrusion Detection System\n\n");

    while (1)
    {
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);

        detect_intrusion(message);
    }

    return 0;
}