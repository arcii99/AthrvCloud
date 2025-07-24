//FormAI DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int fd1;
    char *fifo1 = "apocalypse_survivors";
    mkfifo(fifo1, 0666);

    char buff[200];

    fd1 = open(fifo1, O_RDWR);

    while (1)
    {
        memset(buff, 0, sizeof(buff));
        read(fd1, buff, 200);

        if (strlen(buff) == 0)
        {
            break;
        }

        printf("\nSurvivor: %s\n", buff);

        char response[200];
        memset(response, 0, sizeof(response));
        strcat(response, "I am alive and surviving. It's a tough world out here. ");

        if (strstr(buff, "food") || strstr(buff, "hungry"))
        {
            strcat(response, "I have some canned food with me. Do you want to share?");
        }
        else if (strstr(buff, "weapon") || strstr(buff, "danger"))
        {
            strcat(response, "I have a knife, but I can always use some company. Are you nearby?");
        }
        else
        {
            strcat(response, "I hope we both make it out of here alive. Stay safe!");
        }

        write(fd1, response, strlen(response) + 1);
    }

    close(fd1);

    return 0;
}