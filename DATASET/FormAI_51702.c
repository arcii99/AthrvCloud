//FormAI DATASET v1.0 Category: Browser Plugin ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main function
int main() {
    char url[50];
    char plugin[20];
    
    // Get the URL from the user
    printf("Enter the URL you want to visit:\n");
    scanf("%s", url);
    
    // Check if the URL contains "facebook.com"
    if (strstr(url, "facebook.com") != NULL) {
        strcpy(plugin, "Facebook Plugin");
    } else if (strstr(url, "youtube.com") != NULL) {
        strcpy(plugin, "YouTube Plugin");
    } else {
        strcpy(plugin, "No Plugin Available");
    }
    
    // Display the URL and the plugin
    printf("You are visiting %s, and the recommended plugin is %s\n", url, plugin);
    
    return 0;
}