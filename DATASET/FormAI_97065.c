//FormAI DATASET v1.0 Category: System event logger ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    time_t t = time(NULL);
    struct tm * current_time = localtime(&t);
    
    char event[100];
    
    printf("Welcome to the C System event logger!\n\n");
    printf("Please enter the event you wish to log:\n");
    scanf("%[^\n]%*c", event);
    
    FILE * fp;
    fp = fopen("events.log", "a+");
    
    if(fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    
    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d : %s\n",
            current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday,
            current_time->tm_hour, current_time->tm_min, current_time->tm_sec, event);
    
    printf("\nEvent logged successfully!\n\n");
    printf("Do you wish to log another event?\n");
    printf("Press Y/y for Yes or N/n for No:\n");
    
    char choice;
    scanf("%c", &choice);
    
    if(choice == 'Y' || choice == 'y') {
        main();
    }
    else {
        printf("\nThank you for using the C System event logger. Have a nice day!\n");
    }
    
    fclose(fp);
    return 0;
}