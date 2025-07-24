//FormAI DATASET v1.0 Category: Browser Plugin ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to store website information
typedef struct {
    char name[50];
    char url[100];
    bool isSecure;
    int visits;
} Website;

// Function to print website information
void printWebsiteInfo(Website site) {
    printf("Name: %s\n", site.name);
    printf("URL: %s\n", site.url);
    printf("Secure: %s\n", site.isSecure ? "Yes" : "No");
    printf("Visits: %d\n", site.visits);
}

// Function to add a website to the browser history
void addWebsiteToHistory(char name[], char url[], bool isSecure) {
    FILE *file;
    Website site;

    // Copy website information to struct
    strcpy(site.name, name);
    strcpy(site.url, url);
    site.isSecure = isSecure;

    // Open file in append mode and write website information
    file = fopen("history.txt", "a");
    fprintf(file, "%s,%s,%d\n", site.name, site.url, site.isSecure);
    fclose(file);
}

// Function to retrieve browser history
void retrieveBrowserHistory() {
    FILE *file;
    char line[200];
    Website site;

    // Open file in read mode and loop through each line
    file = fopen("history.txt", "r");
    while (fgets(line, sizeof(line), file) != NULL) {
        // Parse line into website information
        sscanf(line, "%[^,],%[^,],%d", site.name, site.url, &site.isSecure);
        site.visits = 1; // Start with 1 visit

        // Loop through file again to find additional visits to the same website
        rewind(file);
        while (fgets(line, sizeof(line), file) != NULL) {
            // Parse line into website information and check if it matches current site
            Website tempSite;
            sscanf(line, "%[^,],%[^,],%d", tempSite.name, tempSite.url, &tempSite.isSecure);
            if (strcmp(tempSite.url, site.url) == 0) {
                site.visits++; // Increment visit count if URLs match
            }
        }

        // Print website information and reset cursor to beginning of file
        printWebsiteInfo(site);
        rewind(file);
    }
    fclose(file);
}

int main() {
    addWebsiteToHistory("Google", "http://www.google.com", true);
    addWebsiteToHistory("Facebook", "http://www.facebook.com", true);
    addWebsiteToHistory("Amazon", "http://www.amazon.com", true);
    addWebsiteToHistory("YouTube", "http://www.youtube.com", true);
    retrieveBrowserHistory();

    return 0;
}