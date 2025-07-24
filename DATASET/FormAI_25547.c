//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Oh my god! I can't believe what I'm seeing... \n");
    printf("The RAM usage is through the roof! \n");

    while (1)
    {
        FILE *fp;
        char path[1035];
        
        // Open the command for reading
        fp = popen("free -m | awk 'NR==2{printf \"%s/%sMB (%.2f%%)\", $3,$2,$3*100/$2 }'", "r");
        
        if (fp == NULL)
        {
            printf("Oh no, something went wrong while trying to monitor the RAM usage!\n");
            exit(1);
        }

        // Read the output of the command
        while (fgets(path, sizeof(path), fp) != NULL)
        {
            printf("%s", path);
        }

        // Close the connection to the command
        pclose(fp);
        
        sleep(1);
        system("clear");
    }
    return 0;
}