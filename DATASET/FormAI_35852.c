//FormAI DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Ensure the user has root privileges to run the program
    if(geteuid() != 0) {
        printf("This program must be run with root privileges!\n");
        exit(1);
    }
    
    // Retrieve the current system hostname
    char hostname[50];
    if(gethostname(hostname, sizeof(hostname)) < 0) {
        printf("Error retrieving system hostname!\n");
        exit(1);
    }
    printf("Current system hostname: %s\n", hostname);
    
    // Set a new hostname for the system
    char new_hostname[50];
    printf("Enter a new hostname for the system: ");
    scanf("%s", new_hostname);
    if(sethostname(new_hostname, sizeof(new_hostname)) < 0) {
        printf("Error setting new system hostname!\n");
        exit(1);
    }
    printf("New system hostname has been set!\n");
    
    // Retrieve the current system time
    char time_string[50];
    time_t current_time = time(NULL);
    strftime(time_string, sizeof(time_string), "%c", localtime(&current_time));
    printf("Current system time: %s\n", time_string);
    
    // Set a new system time using the NTP service
    system("ntpdate pool.ntp.org");
    printf("New system time has been set using the NTP service!\n");
    
    // Retrieve the current system uptime
    FILE* uptime_file = fopen("/proc/uptime", "r");
    if(uptime_file == NULL) {
        printf("Error retrieving system uptime!\n");
        exit(1);
    }
    char uptime_string[50];
    fgets(uptime_string, sizeof(uptime_string), uptime_file);
    fclose(uptime_file);
    int uptime_seconds = atoi(uptime_string);
    int uptime_days = uptime_seconds / (24 * 60 * 60);
    int uptime_hours = (uptime_seconds / (60 * 60)) % 24;
    int uptime_minutes = (uptime_seconds / 60) % 60;
    printf("Current system uptime: %d days, %d hours, %d minutes\n", uptime_days, uptime_hours, uptime_minutes);
    
    return 0;
}