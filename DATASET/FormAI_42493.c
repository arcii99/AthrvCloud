//FormAI DATASET v1.0 Category: Date and time ; Style: lively
#include<stdio.h>
#include<time.h>

int main(){

    // get current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // print date and time
    printf("Today's date is %02d/%02d/%d\n", tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900);
    printf("The current time is %02d:%02d:%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);

    // prompt user to enter new date and time
    printf("\nEnter a new date and time (DD/MM/YYYY HH:MM:SS): ");
    char input[20];
    fgets(input, 20, stdin);

    // parse new date and time
    int day, month, year, hour, min, sec;
    sscanf(input, "%d/%d/%d %d:%d:%d", &day, &month, &year, &hour, &min, &sec);
    struct tm new_tm = { .tm_year = year - 1900, .tm_mon = month - 1, .tm_mday = day, .tm_hour = hour, .tm_min = min, .tm_sec = sec };
    time_t new_t = mktime(&new_tm);

    // calculate difference between new and old time
    double diff = difftime(new_t, t);

    if(diff == 0){
        printf("\nThe new date and time is the same as the current date and time.\n");
    }
    else if(diff > 0){
        printf("\nThe new date and time is %d seconds ahead of the current date and time.\n", (int)diff);
    }
    else{
        printf("\nThe new date and time is %d seconds behind the current date and time.\n", (int)(-diff));
    }

    return 0;
}