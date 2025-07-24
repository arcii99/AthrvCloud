//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libgen.h>
#include <limits.h>
#include <ctype.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 1024
#define MAX_DATA_SIZE 10240

enum { STATE_START, STATE_INQUOTE, STATE_INNORM, STATE_FINISH };

char *data;
int data_len;

// This function reads the CSV file and stores its content in the data string
void *read_csv(void *args)
{
    char *filename = (char *) args;

    printf("Opening file %s\n", filename);
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        pthread_exit(NULL);
    }

    struct stat st;
    fstat(fd, &st);
    data = malloc(st.st_size);
    data_len = st.st_size;

    int pos = 0;
    int state = STATE_START;
    char buffer[BUFFER_SIZE];
    int bytesRead;

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)))
    {
        if (bytesRead == -1)
        {
            perror("Error reading file");
            free(data);
            close(fd);
            pthread_exit(NULL);
        }

        for (int i = 0; i < bytesRead; i++)
        {
            char c = buffer[i];

            if (state == STATE_START)
            {
                if (c == '"')
                {
                    state = STATE_INQUOTE;
                }
                else if (!isspace(c))
                {
                    state = STATE_INNORM;
                    data[pos++] = c;
                }
            }
            else if (state == STATE_INQUOTE)
            {
                if (c == '\\')
                {
                    state = STATE_FINISH;
                }
                else if (c == '"')
                {
                    state = STATE_START;
                }
                else
                {
                    data[pos++] = c;
                }
            }
            else if (state == STATE_INNORM)
            {
                if (c == ',')
                {
                    state = STATE_START;
                    data[pos++] = '\t';
                }
                else if (c == '\n')
                {
                    state = STATE_START;
                    data[pos++] = '\n';
                }
                else
                {
                    data[pos++] = c;
                }
            }
            else if (state == STATE_FINISH)
            {
                state = STATE_INQUOTE;
                data[pos++] = c;
            }

            if (pos >= MAX_DATA_SIZE)
            {
                perror("File too large");
                free(data);
                close(fd);
                pthread_exit(NULL);
            }
        }
    }

    close(fd);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename.csv\n", basename(argv[0]));
        return 0;
    }

    pthread_t thread_id;
    int ret = pthread_create(&thread_id, NULL, read_csv, argv[1]);
    if (ret != 0)
    {
        perror ("Error creating thread");
        return 0;
    }

    ret = pthread_join(thread_id, NULL);
    if (ret != 0)
    {
        perror("Error joining thread");
        return 0;
    }

    printf("%s\n", data);

    free(data);
    return 0;
}