//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkFile(const char *filename);
void logEvent(const char *event);

int main() {
    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please enter the name of the file you would like to monitor: ");
    char filename[20];
    scanf("%s", filename);
    checkFile(filename);
    return 0;
}

void checkFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "malware") || strstr(line, "virus")) {
            logEvent("Malware detected in file!");
            system("shutdown -s -t 60");
        }
        if (strstr(line, "hack") || strstr(line, "hacking")) {
            logEvent("Hacking attempt detected!");
            printf("Enter your password to secure the system: ");
            char password[20];
            scanf("%s", password);
            if (strcmp(password, "password") == 0) {
                printf("Password accepted. System secured.\n");
            } else {
                logEvent("Password incorrect. Shutting down system.");
                system("shutdown -s -t 0");
            }
        }
    }
    fclose(file);
}

void logEvent(const char *event) {
    FILE *file = fopen("log.txt", "a");
    fprintf(file, "%s\n", event);
    fclose(file);
}