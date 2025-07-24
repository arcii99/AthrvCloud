//FormAI DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>

int main() {
    FILE *logfile = fopen("log.txt", "r");
    char line[256];
    int count = 0;

    while(fgets(line, sizeof(line), logfile)) {
        if(line[0] == 'E' && line[1] == 'R' && line[2] == 'R' && line[3] == 'O' && line[4] == 'R') {
            count++;
            printf("Count = %d: %s", count, line);
        }
    }

    printf("\nTotal Errors: %d\n", count);

    fclose(logfile);
    return 0;
}