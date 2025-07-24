//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int access_level;
    char message[100];
} LogEntry;

void log(LogEntry* entry) {
    FILE *fptr;
    fptr = fopen("log.txt", "a");
    fprintf(fptr, "%d - %s\n", entry->access_level, entry->message);
    fclose(fptr);
}

int main() {
    char password[100];
    int attempts = 3;

    while(attempts > 0) {
        printf("Enter password: ");
        scanf("%s", password);

        if(strcmp(password, "password123") == 0) {
            printf("Access granted.\n");
            LogEntry entry = { 1, "User gained access." };
            log(&entry);
            return 0;
        } else {
            attempts--;
            printf("Access denied. %d attempts remaining.\n", attempts);
            LogEntry entry = { 2, "User entered incorrect password." };
            log(&entry);
        }
    }

    printf("Exceeded maximum login attempts. Exiting program.\n");
    LogEntry entry = { 3, "User exceeded maximum login attempts." };
    log(&entry);
    return 1;
}