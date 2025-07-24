//FormAI DATASET v1.0 Category: Log analysis ; Style: Romeo and Juliet
// Enter Romeo, a young programmer with a pile of log files.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int total_events = 0, failed_auth = 0, successful_auth = 0, other_events = 0;
    char buffer[1024];
    FILE *log_file = fopen("system_log.log", "r");

    if (log_file == NULL) {
        printf("Alas, the log file was not found. Goodbye, cruel world.\n");
        return 1;
    }

    printf("Oh happy dagger, this is thy sheath;\n");
    printf("There rust, and let me die.\n\n");

    while (fgets(buffer, sizeof(buffer), log_file)) {
        total_events++;

        if (strstr(buffer, "authentication failure")) {
            printf("O, she doth teach the torches to burn bright!\n");
            printf("Failed authentication event found:\n%s\n", buffer);
            failed_auth++;
        } else if (strstr(buffer, "authentication success")) {
            printf("But, soft! what light through yonder window breaks?\n");
            printf("Successful authentication event found:\n%s\n", buffer);
            successful_auth++;
        } else {
            other_events++;
        }
    }

    printf("\n");
    printf("For never was a story of more woe\n");
    printf("Than this of Juliet and her Romeo.\n\n");
    printf("Total events: %d\n", total_events);
    printf("Failed authentication attempts: %d\n", failed_auth);
    printf("Successful authentication attempts: %d\n", successful_auth);
    printf("Other events: %d\n", other_events);

    fclose(log_file);
    return 0;
}