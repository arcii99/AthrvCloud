//FormAI DATASET v1.0 Category: Log analysis ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, count = 0, success = 0, failure = 0;
    double total_time = 0.0;
    char buffer[1024];
    FILE *fp;

    if (argc < 2) {
        printf("Usage: %s < logfile1 > [logfile2] ... [logfileN]\n", argv[0]);
        return 0;
    }

    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("Failed to open file %s\n", argv[i]);
            continue;
        }
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            char *pos = strchr(buffer, ' ');
            if (pos == NULL) {
                continue;
            }
            pos++;
            count++;
            if (strstr(pos, "200") != NULL) {
                success++;
                char *time_pos = strchr(pos, '\"');
                if (time_pos != NULL) {
                    time_pos++;
                    char *end_pos = strchr(time_pos, '\"');
                    if (end_pos != NULL) {
                        *end_pos = '\0';
                        total_time += atof(time_pos);
                        *end_pos = '\"';
                    }
                }
            } else {
                failure++;
            }
        }
        fclose(fp);
    }

    printf("Total requests: %d\n", count);
    printf("Successful requests: %d (%.2f%%)\n", success, (double)success / count * 100.0);
    printf("Failed requests: %d (%.2f%%)\n", failure, (double)failure / count * 100.0);
    printf("Average response time: %.2f seconds\n", total_time / success);

    return 0;
}