//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

#define LOGFILE "log.txt"

volatile sig_atomic_t terminate = 0;

void sigint_handler(int sig)
{
    (void)sig;
    terminate = 1;
}

void write_log(const char *msg)
{
    FILE *fp;
    fp = fopen(LOGFILE, "a");

    if (fp != NULL)
    {
        fprintf(fp, "%s\n", msg);
        fclose(fp);
    }
}

void check_logfile()
{
    FILE *fp;
    char ch, last;
    int pos = 0;

    fp = fopen(LOGFILE, "r");

    if (fp != NULL)
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '\n' && last != '\n')
            {
                char line[100];
                memset(line, 0, sizeof(line));
                fseek(fp, pos - sizeof(line), SEEK_SET);
                fgets(line, sizeof(line), fp);

                if (strstr(line, "Access denied") != NULL)
                {
                    printf("[INTRUSION DETECTED] %s\n", line);
                }
            }

            last = ch;
            pos++;
        }

        fclose(fp);
    }
}

int main(int argc, char *argv[])
{
    signal(SIGINT, sigint_handler);

    printf("Starting Intrusion Detection System...\n");

    while (!terminate)
    {
        check_logfile();
        sleep(1);
    }

    printf("Stopping Intrusion Detection System...\n");

    return 0;
}