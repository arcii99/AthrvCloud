//FormAI DATASET v1.0 Category: Date and time ; Style: beginner-friendly
#include<stdio.h>
#include<time.h>

int main(){
    time_t now;
    struct tm now_local;

    //get the current time
    now = time(NULL);

    //convert the current time to local time
    localtime_r(&now, &now_local);

    //display the local time in various formats
    printf("Current date and time:\n");
    printf("%02d/%02d/%04d\n", now_local.tm_mday, now_local.tm_mon+1, now_local.tm_year+1900);
    printf("%02d:%02d:%02d\n", now_local.tm_hour, now_local.tm_min, now_local.tm_sec);
    printf("%02d:%02d:%02d %02d/%02d/%04d\n", now_local.tm_hour>12?now_local.tm_hour-12:now_local.tm_hour, now_local.tm_min, now_local.tm_sec, now_local.tm_mday, now_local.tm_mon+1, now_local.tm_year+1900);
    printf("%02d:%02d:%02d %02d/%02d/%04d %s\n", now_local.tm_hour>12?now_local.tm_hour-12:now_local.tm_hour, now_local.tm_min, now_local.tm_sec, now_local.tm_mday, now_local.tm_mon+1, now_local.tm_year+1900, now_local.tm_hour>12?"PM":"AM");

    return 0;
}