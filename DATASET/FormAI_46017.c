//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define constants
#define TIMEOUT 10
#define INTERVAL 5

// Function declaration
void check_website(char* website_url);

int main(int argc, char* argv[]) {
    // Check if website URL is specified as command line argument
    if (argc != 2) {
        printf("Usage: %s <website URL>\n", argv[0]);
        exit(1);
    }
    
    // Continuous loop to check website status
    while (1) {
        check_website(argv[1]);
        
        // Pause for specified interval before checking again
        sleep(INTERVAL);
    }
    
    return 0;
}

void check_website(char* website_url) {
    printf("Checking %s...\n", website_url);
    
    // Form curl command to check website availability
    char* command = malloc(sizeof(char) * (strlen(website_url) + 18));
    sprintf(command, "curl --head %s -m %d >/dev/null 2>&1", website_url, TIMEOUT);
    
    // Execute curl command and get exit status
    int status = system(command);
    
    if (status == 0) {
        printf("%s is up!\n", website_url);
    } else {
        printf("%s is down :(\n", website_url);
    }
    
    // Free memory allocated to command string
    free(command);
}