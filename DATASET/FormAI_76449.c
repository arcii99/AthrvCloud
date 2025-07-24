//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    int totalRequests = 0, successfulRequests = 0, clientErrors = 0, serverErrors = 0;
    char line[256];
    
    // Open log file
    FILE *file = fopen("access.log", "r");
    
    // Check if file was successfully opened
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Loop through each line in the log file
    while (fgets(line, sizeof(line), file)) {
        totalRequests++;
        
        // Check if request was successful
        if (strstr(line, "200 OK") != NULL) {
            successfulRequests++;
        }
        
        // Check for client errors (4xx status code)
        if (strstr(line, "4") != NULL) {
            clientErrors++;
        }
        
        // Check for server errors (5xx status code)
        if (strstr(line, "5") != NULL) {
            serverErrors++;
        }
    }
    
    // Print analysis results
    printf("Total requests: %d\n", totalRequests);
    printf("Successful requests: %d (%f%%)\n", successfulRequests, ((float) successfulRequests / totalRequests) * 100);
    printf("Client errors: %d (%f%%)\n", clientErrors, ((float) clientErrors / totalRequests) * 100);
    printf("Server errors: %d (%f%%)\n", serverErrors, ((float) serverErrors / totalRequests) * 100);
    
    // Close file
    fclose(file);

    return 0;
}