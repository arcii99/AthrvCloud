//FormAI DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_sys_info() {
    printf("System Information:\n");
    printf("OS: Linux\n");
    printf("Kernel Release: ");
    system("uname -r");
    printf("Architecture: ");
    system("uname -m");
}

void display_time_date() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Time and Date:\n");
    printf("%02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("%04d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void run_command() {
    char command[50];
    printf("Enter command to run:\n");
    scanf("%s", command);
    system(command);
}

int main() {
    display_sys_info();
    printf("\n");
    display_time_date();
    printf("\n");
    run_command();
    return 0;
}