//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define BUFFER_SIZE 128

int main()
{
    int fd;
    char buff[BUFFER_SIZE];
    char cpu_usage_str[5];
    float cpu_usage;
    time_t raw_time;
    struct tm * time_info;
    char time_str[80];

    fd = open("/proc/stat", O_RDONLY);

    if(fd < 0) {
        printf("Could not open the file.");
        exit(1);
    }

    while(1) {
        lseek(fd, 0, SEEK_SET);
        read(fd, buff, BUFFER_SIZE-1);
        buff[BUFFER_SIZE-1] = '\0';

        char *line = strtok(buff, "\n"); 

        while(line != NULL && strncmp("cpu ", line, 4) == 0) {
            char *prev_tok;
            char *tok = strtok(line+4, " ");
            int total = 0, user = 0, sys = 0, idle = 0;
            int i = 0;

            while(tok != NULL) {
                int curr_val = atoi(tok);
                total += curr_val;
                if(i == 0) user = curr_val;
                else if(i == 1) sys = curr_val;
                else if(i == 3) idle = curr_val;
                prev_tok = tok;
                tok = strtok(NULL, " ");
                i++;
            }

            cpu_usage = (float)(user+sys)/(float)total;
            snprintf(cpu_usage_str, 5, "%.2f", cpu_usage);

            time(&raw_time);
            time_info = localtime(&raw_time);

            strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

            printf("%s CPU Usage: %s\n", time_str, cpu_usage_str);
            fflush(stdout);

            sleep(1);

            line = strtok(NULL, "\n");
        }
    }

    close(fd);
    return 0;
}