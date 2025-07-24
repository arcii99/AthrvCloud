//FormAI DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int calculate_time_diff(char *start_time, char *end_time, int log_type) {
    int start_hour, start_min, start_sec, start_ms, end_hour, end_min, end_sec, end_ms;
    sscanf(start_time, "[%d:%d:%d.%d]", &start_hour, &start_min, &start_sec, &start_ms);
    sscanf(end_time, "[%d:%d:%d.%d]", &end_hour, &end_min, &end_sec, &end_ms);
    int time_diff = (end_hour - start_hour) * 3600000 + (end_min - start_min) * 60000 + (end_sec - start_sec) * 1000 + (end_ms - start_ms);
    if(log_type == 0) {
        printf("Time taken for function call: %d ms\n", time_diff);
    }
    else if(log_type == 1) {
        printf("Time taken for HTTP request: %d ms\n", time_diff);
    }
    return time_diff;
}

int main() {
    FILE *log_file = fopen("app.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }
    char log_line[250];
    char *start_time, *end_time, *log_message;
    int total_time = 0, num_calls = 0, max_time = -1, min_time = 1000000000;
    int total_requests = 0, num_success = 0, num_failure = 0;
    while (fgets(log_line, sizeof(log_line), log_file) != NULL) {
        if (strstr(log_line, "[CALL]") != NULL) {
            // function call log
            start_time = strtok(log_line, " ");
            end_time = strtok(NULL, " ");
            log_message = strtok(NULL, "");
            int time_diff_ms = calculate_time_diff(start_time, end_time, 0);
            total_time += time_diff_ms;
            num_calls++;
            if (time_diff_ms > max_time) {
                max_time = time_diff_ms;
            }
            if (time_diff_ms < min_time) {
                min_time = time_diff_ms;
            }
        } else if (strstr(log_line, "[HTTP]") != NULL) {
            // HTTP request log
            start_time = strtok(log_line, " ");
            end_time = strtok(NULL, " ");
            log_message = strtok(NULL, "");
            int time_diff_ms = calculate_time_diff(start_time, end_time, 1);
            total_time += time_diff_ms;
            total_requests++;
            if (strstr(log_message, "200 OK") != NULL) {
                num_success++;
            } else {
                num_failure++;
            }
        }
    }
    fclose(log_file);
    printf("\n--- Function call log statistics ---\n");
    printf("Total number of calls: %d\n", num_calls);
    printf("Total time taken: %d ms\n", total_time);
    printf("Average time per call: %d ms\n", total_time / num_calls);
    printf("Maximum time taken for a single call: %d ms\n", max_time);
    printf("Minimum time taken for a single call: %d ms\n", min_time);
    printf("\n--- HTTP request log statistics ---\n");
    printf("Total number of requests: %d\n", total_requests);
    printf("Number of successful requests: %d (%.2f%%)\n", num_success, (float)num_success / total_requests * 100);
    printf("Number of failed requests: %d (%.2f%%)\n", num_failure, (float)num_failure / total_requests * 100);
    return 0;
}