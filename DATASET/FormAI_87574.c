//FormAI DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

void logEvent(char* message){
    time_t now;
    char time_str[25];
    now = time(NULL);
    strftime(time_str, 25, "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf("%s | %s\n", time_str, message);
}

int main(){
    char message[100];
    printf("Enter an event to log: ");
    fgets(message, 100, stdin);
    logEvent(message);
    return 0;
}