//FormAI DATASET v1.0 Category: System event logger ; Style: cheerful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to generate random logs
char* generateRandomLog() {
    char *logs[] = {"The sun is shining bright! ☀️", "It's raining cats and dogs today! 🌧️", "I saw a funny cat! 😸", "Feeling great today! 🙌"};
    int n = rand() % 4;
    return logs[n];
}

int main()
{
    FILE *fp;
    fp = fopen("event.log", "w");
    if (fp == NULL) {
        printf("Unable to create file!");
        exit(1);
    }

    fprintf(fp, "***** System Event Log *****\n\n");
    printf("\n***** System Event Log *****\n\n");

    int i;
    for (i = 0; i < 10; i++) {
        time_t t = time(NULL);
        char* log = generateRandomLog();

        fprintf(fp, "[%s] - %s\n", ctime(&t), log);
        printf("[%s] - %s\n", ctime(&t), log);

        // wait for a random time before logging next event
        int wait_time = rand() % 5 + 1;
        sleep(wait_time);
    }
    printf("\n\nEvent log written to file - event.log!\n");
    fprintf(fp, "\n***** End of Event Log *****");
    fclose(fp);
    return 0;
}