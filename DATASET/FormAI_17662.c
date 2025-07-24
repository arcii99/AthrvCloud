//FormAI DATASET v1.0 Category: Log analysis ; Style: Ken Thompson
#include <stdio.h>

int main() {
  FILE *log_file = fopen("server_log.txt", "r");
  if (log_file == NULL) {
    printf("Error: could not open log file.\n");
    return 1;
  }

  char line_buffer[1024];
  int num_lines_processed = 0;
  int num_successful_requests = 0;
  int num_failed_requests = 0;
  int total_request_time = 0;
  int max_request_time = 0;
  int min_request_time = 999999999;

  printf("Processing log file...\n");

  while (fgets(line_buffer, sizeof(line_buffer), log_file)) {
    num_lines_processed++;

    // Parse the line to get the request duration
    int request_duration = 0;
    char *duration_ptr = strstr(line_buffer, "duration=");
    if (duration_ptr != NULL) {
      sscanf(duration_ptr+9, "%d", &request_duration);

      total_request_time += request_duration;
      if (request_duration > max_request_time) {
        max_request_time = request_duration;
      }
      if (request_duration < min_request_time) {
        min_request_time = request_duration;
      }
    }

    // Check if request was successful or failed
    if (strstr(line_buffer, "status=200") != NULL) {
      num_successful_requests++;
    } else if (strstr(line_buffer, "status=") != NULL) {
      num_failed_requests++;
    }
  }

  printf("Finished processing log file.\n");
  printf("Total number of lines processed: %d\n", num_lines_processed);
  printf("Number of successful requests: %d\n", num_successful_requests);
  printf("Number of failed requests: %d\n", num_failed_requests);

  if (num_successful_requests > 0) {
    float avg_request_time = total_request_time / (float)num_successful_requests;
    printf("Average request time: %.2f ms\n", avg_request_time);
    printf("Max request time: %d ms\n", max_request_time);
    printf("Min request time: %d ms\n", min_request_time);
  }

  fclose(log_file);
  return 0;
}