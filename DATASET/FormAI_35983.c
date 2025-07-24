//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int count = 0;

    while(1)
    {
        FILE *fp;
        char buffer[1000];

        fp = popen("free -m | grep Mem | awk '{print $3}'", "r");
        fgets(buffer, sizeof(buffer), fp);
        int memUsage = atoi(buffer);
        pclose(fp);

        printf("Current RAM usage is %d MB\n", memUsage);

        if(memUsage > 500)
        {
            printf("High RAM usage detected! Killing processes...\n");
            system("killall chrome");
            system("killall firefox");
            system("killall java");

            printf("Processes killed successfully!\n");
        }

        count++;
        if(count == 60)
        {
            printf("Checking for critical system errors...\n");
            system("fsck -y /dev/sda1");
            printf("Filesystem check complete.\n");

            count = 0;
        }

        sleep(5);
    }

    return 0;
}