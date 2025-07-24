//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main () {
    time_t t;
    struct tm *tm;
    char uptime[100];
    FILE *uptime_file;

    uptime_file = fopen("/proc/uptime", "r");
    fscanf(uptime_file, "%s", uptime);
    fclose(uptime_file);

    t = time(NULL);
    tm = localtime(&t);

    printf("The server has been running for %s medieval hours!\n", uptime);

    printf("The current date and time in medieval style is: %d:%d:%d, %d %d, %d AD\n",
           ((tm->tm_hour + 11) % 12) + 1, tm->tm_min, tm->tm_sec,
           tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1190);

    return 0;
}