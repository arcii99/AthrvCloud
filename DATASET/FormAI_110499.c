//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include<stdio.h>
#include<time.h>

int main()
{
    //Get current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char str_time[25];
    strftime(str_time, sizeof(str_time), "%d.%m.%Y %H:%M:%S", tm);

    //Create and open log file
    FILE *log_file = fopen("event_log.txt", "a");
    if(log_file == NULL)
    {
        printf("Error opening log file!\n");
        return 1;
    }

    //Log system events
    fprintf(log_file, "[%s] System started\n", str_time);
    fprintf(log_file, "[%s] User logged in\n", str_time);
    fprintf(log_file, "[%s] Program X.XX started\n", str_time);
    fprintf(log_file, "[%s] Program X.XX finished\n", str_time);
    fprintf(log_file, "[%s] User logged off\n", str_time);
    fprintf(log_file, "[%s] System shut down\n", str_time);

    //Close log file and exit
    fclose(log_file);
    return 0;
}