//FormAI DATASET v1.0 Category: Log analysis ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main() {
  // Define file pointer and line variables
  FILE *file;
  char line[SIZE];
  
  // Open log file for reading
  file = fopen("example.log", "r");
  
  if (file == NULL) {
    printf("Error opening log file");
    exit(1);
  }
  
  // Define variables for log analysis
  int totalRequests = 0;
  int successfulRequests = 0;
  int failedRequests = 0;
  double averageResponseTime = 0.0;
  
  // Loop through file line by line
  while (fgets(line, SIZE, file)) {
    totalRequests++;
    
    // Split line into individual parts
    char* timestamp = strtok(line, " ");
    char* requestType = strtok(NULL, " ");
    char* responseTime = strtok(NULL, " ");
    char* status = strtok(NULL, " ");
    
    if (status != NULL) {
      int statusCode = atoi(status);
      
      if (statusCode >= 200 && statusCode < 300) {
        successfulRequests++;
        
        if (responseTime != NULL) {
          double response = atof(responseTime);
          averageResponseTime += response;
        }
      } else {
        failedRequests++;
      }
    }
  }
  
  // Calculate average response time
  if (successfulRequests > 0) {
    averageResponseTime /= successfulRequests;
  }
  
  // Print analysis results
  printf("Total Requests: %d\n", totalRequests);
  printf("Successful Requests: %d\n", successfulRequests);
  printf("Failed Requests: %d\n", failedRequests);
  printf("Average Response Time: %lf\n", averageResponseTime);
  
  // Close log file
  fclose(file);
  
  return 0;
}