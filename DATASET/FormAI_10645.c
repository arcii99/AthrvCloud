//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello there! I am your C RAM usage monitor program! Let's get started!\n");

    while(1)
    {
        char cmd[100];
        FILE* fp = popen("free -m | awk 'FNR == 2 {print $3}'", "r");

        fgets(cmd, sizeof(cmd), fp);
        int ram_usage = atoi(cmd);

        printf("Your current RAM usage is: %d MB\n", ram_usage);

        pclose(fp);
        sleep(5);
    }
    return 0;
}