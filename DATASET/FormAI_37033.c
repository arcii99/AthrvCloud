//FormAI DATASET v1.0 Category: Log analysis ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void parseLog(char *log) {
    char *date = strtok(log, " ");
    char *time = strtok(NULL, " ");
    char *level = strtok(NULL, " ");
    char *message = strtok(NULL, "\n");

    printf("Date: %s\n", date);
    printf("Time: %s\n", time);
    printf("Level: %s\n", level);
    printf("Message: %s\n", message);

    if(strcmp(level, "ERROR") == 0) {
        printf("You had me at Error...\n");
    }
    else if(strcmp(level, "WARNING") == 0) {
        printf("You didn't have to warn me, I am already in love with you...\n");
    }
    else if(strcmp(level, "INFO") == 0) {
        printf("You don't have to tell me, I already know how amazing you are...\n");
    }
    else {
        printf("I am sorry, I didn't understand that level...\n");
    }
}

int main() {
    char log[] = "2022-02-14 14:00:01 ERROR You are the error in my life.\n";

    printf("Analyzing your log...\n\n");
    parseLog(log);

    return 0;
}