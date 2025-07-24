//FormAI DATASET v1.0 Category: Date and time ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#define BUF_SIZE 80

void print_time(char *str);
void print_local_time(struct tm *local);
void print_utc_time(struct tm *utc);

int main(int argc, char *argv[]) 
{
    struct timeval tv;
    time_t current_time;
    char time_buf[BUF_SIZE];
    char *current_time_str;

    gettimeofday(&tv, NULL);

    current_time = tv.tv_sec;
    current_time_str = ctime(&current_time);

    printf("Asynchronous Date/Time Example:\n\n");

    print_time("Current Time:");
    sleep(3);

    printf("\n");

    print_time("Local Time:");
    sleep(3);

    printf("\n");

    print_time("UTC Time:");

    return 0;
}

void print_time(char *str)
{
    struct timeval tv;
    time_t current_time;
    struct tm *local;
    struct tm *utc;

    gettimeofday(&tv, NULL);

    current_time = tv.tv_sec;

    local = localtime(&current_time);
    utc = gmtime(&current_time);

    if(local == NULL)
    {
        printf("Local Time Error!\n");
        exit(EXIT_FAILURE);
    }

    if(utc == NULL)
    {
        printf("UTC Time Error!\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", str);
    printf("Epoch Time: %ld seconds\n", current_time);
    print_local_time(local);
    print_utc_time(utc);
}

void print_local_time(struct tm *local)
{
    char buf[BUF_SIZE];
    size_t buf_len = sizeof(buf);

    strftime(buf, buf_len, "Local Time: %c %Z", local);
    printf("%s\n", buf);
}

void print_utc_time(struct tm *utc)
{
    char buf[BUF_SIZE];
    size_t buf_len = sizeof(buf);

    strftime(buf, buf_len, "UTC Time: %c %Z", utc);
    printf("%s\n", buf);
}