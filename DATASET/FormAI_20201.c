//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int pfd, cfd;
    int pnum, cnum;
    char *pname = "/proc/stat";
    char *cname = "cpuinfo";

    while(1)
    {
        pfd = open(pname, O_RDONLY);
        if (pfd < 0)
        {
            printf("Cannot open %s file.\n", pname);
            continue;
        }

        char buf[4096];
        int size = read(pfd, buf, sizeof(buf));
        if (size <= 0)
        {
            printf("Cannot read %s file.\n", pname);
            continue;
        }

        close(pfd);

        pnum = -1; cnum = 0;

        char *ptr = strtok(buf,"\n");

        while(ptr != NULL)
        {
            if (strncmp(ptr,"cpu ",4) == 0)
            {
                ptr += 5;

                while(*ptr != ' ')
                {
                    pnum++;
                    ptr++;
                }

                ptr += 2;

                while(*ptr != ' ')
                    ptr++;

                ptr += 1;

                while(*ptr != ' ')
                {
                    cnum++;
                    ptr++;
                }

                break;
            }

            ptr = strtok(NULL,"\n");
        }

        cfd = open(cname, O_WRONLY|O_CREAT|O_TRUNC, 0644);
        if (cfd < 0)
        {
            printf("Cannot create %s file.\n", cname);
            continue;
        }

        dprintf(cfd,"Total CPUs: %d\n",pnum+1);
        dprintf(cfd,"Used CPUs: %d\n",cnum);

        close(cfd);

        sleep(5); // Check every 5 seconds
    }

    return 0;
}