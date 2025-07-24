//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 256

int main() {
    char log_file_name[MAX_LENGTH];
    char line[MAX_LENGTH];
    char *ip_address;
    int count = 0;

    printf("Enter the name of the log file: ");
    scanf("%s", log_file_name);
    
    FILE *log_file = fopen(log_file_name, "r");
    
    if (log_file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    while (fgets(line, MAX_LENGTH, log_file) != NULL) {
        ip_address = strstr(line, "SRC=");
        if (ip_address != NULL) {
            ip_address += 4;
            char *end = strchr(ip_address, ' ');
            if (end != NULL) {
                *end = '\0';
                if (strcmp(ip_address, "10.0.0.1") == 0 || strcmp(ip_address, "192.168.0.1") == 0) {
                    count++;
                }
            }
        }
    }
    
    if (count > 10) {
        printf("Intrusion detected!\n");
    } else {
        printf("No intrusion detected.\n");
    }
    
    fclose(log_file);
    return 0;
}