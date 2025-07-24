//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define THRESHOLD 10

int main()
{
    char buffer[BUFFER_SIZE];
    int count = 0;
    FILE* file = fopen("log.txt", "r");

    if(!file)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    while(fgets(buffer, BUFFER_SIZE, file))
    {
        char* token = strtok(buffer, " ");
        while(token)
        {
            if(strncmp(token, "nmap", 4) == 0 || strncmp(token, "telnet", 6) == 0 || strncmp(token, "nc", 2) == 0)
            {
                count++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    if(count >= THRESHOLD)
    {
        printf("ALERT! Intrusion detected: %d suspicious network activities\n", count);
        system("mail -s 'Intrusion alert' admin@company.com < log.txt");
    }
    else
    {
        printf("No suspicious network activities detected\n");
    }

    return 0;
}