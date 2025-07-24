//FormAI DATASET v1.0 Category: Database querying ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Cyberpunk Database Querying System v1.0\n");
    printf("Please enter your query:\n");
    
    char query[100];
    scanf("%s", query);
    
    // Check if query is valid
    if (strcmp(query, "SELECT * FROM hackers WHERE alias='Neo'") == 0) {
        printf("Loading results...\n");
        printf("Alias: Neo\nReal Name: Thomas Anderson\nSkills: Hacking, fighting\nOccupation: Hacker, freedom fighter\n");
    } else if (strcmp(query, "SELECT * FROM corporations WHERE name='Tyrell Corp'") == 0) {
        printf("Loading results...\n");
        printf("Name: Tyrell Corp\nFounder: Eldon Tyrell\nIndustry: Robotics, AI\nLocation: Los Angeles\n");
    } else {
        printf("Error: Invalid query\n");
        printf("Try again or consult the manual for valid queries.\n");
    }
    
    return 0;
}