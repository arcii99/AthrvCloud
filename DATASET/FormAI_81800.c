//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 2

bool running = true;
pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* signal_strength_analyzer(void* arg)
{
    char buffer[BUFFER_SIZE];

    while(running)
    {
        FILE* f;
        char* cmd = "iwgetid -r";
        char* mode = "r";
        int signal_strength = 0;
    
        pthread_mutex_lock(&mutex);

        f = popen(cmd, mode);
        if(f == NULL)
        {
            printf("Failed to execute command\n");
        }
        else
        {
            // Read the output of the command
            while(fgets(buffer, BUFFER_SIZE, f))
            {
                // Trim newline character from the output
                char* newline = strchr(buffer, '\n');
                if(newline)
                {
                    *newline = '\0';
                }
            
                char ssid[BUFFER_SIZE];
                strcpy(ssid, buffer);
                strcat(ssid, ": ");

                // Get signal strength using iwconfig command
                cmd = "iwconfig 2>&1 | grep Quality";
                mode = "r";
                FILE* f2 = popen(cmd, mode);
                if(f2 == NULL)
                {
                    printf("Failed to execute command\n");
                }
                else
                {
                    while(fgets(buffer, BUFFER_SIZE, f2))
                    {
                        char* quality_trimmed = strchr(buffer, '=') + 1;
                        signal_strength = atoi(quality_trimmed);
                        break;
                    }
                    pclose(f2);
                }

                printf("%s%d\n", ssid, signal_strength);
            }
        
            pclose(f);
        }

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
}

void signal_handler(int sig)
{
    if(sig == SIGINT)
    {
        running = false;
    }
}

int main(int argc, char* argv[])
{
    signal(SIGINT, signal_handler);

    printf("Wi-Fi Signal Strength Analyzer started. Press Ctrl+C to exit.\n");
    
    // Create threads
    int i;
    for(i = 0; i < NUM_THREADS; i++)
    {
        if(pthread_create(&threads[i], NULL, signal_strength_analyzer, NULL))
        {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for(i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Wi-Fi Signal Strength Analyzer finished.\n");

    return 0;
}