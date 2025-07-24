//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2000

// Array of websites to monitor
char* websites[] = {
    "https://www.google.com",
    "https://www.facebook.com",
    "https://www.apple.com",
    "https://www.microsoft.com",
    "https://www.amazon.com"
};
int numWebsites = 5;

// Struct for holding website status information
struct websiteStatus {
    char name[MAX_URL_LENGTH];
    double uptimeRatio;
    int numChecks;
    int numFailures;
    time_t lastChecked;
};

// Function for calculating website uptime ratio
double calcUptimeRatio(struct websiteStatus website) {
    if (website.numChecks == 0) {
        return 0.0;
    }
    return (double)(website.numChecks - website.numFailures) / website.numChecks;
}

// Function for performing website check
int performCheck(char* url) {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("%s is down.\n", url);
            curl_easy_cleanup(curl);
            return 0;
        }
        curl_easy_cleanup(curl);
        return 1;
    }
    else {
        printf("Error initializing curl.\n");
        return -1;
    }
}

int main() {
    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Initialize array of websiteStatus structs
    struct websiteStatus websiteStats[numWebsites];
    for (int i = 0; i < numWebsites; i++) {
        strcpy(websiteStats[i].name, websites[i]);
        websiteStats[i].uptimeRatio = 0.0;
        websiteStats[i].numChecks = 0;
        websiteStats[i].numFailures = 0;
        websiteStats[i].lastChecked = 0;
    }

    // Start monitoring loop
    while (1) {
        printf("Checking websites...\n");

        // Loop through websites and perform checks
        for (int i = 0; i < numWebsites; i++) {
            char* url = websiteStats[i].name;

            // Make sure we don't check a website too frequently
            time_t currentTime = time(NULL);
            double elapsedTime = difftime(currentTime, websiteStats[i].lastChecked);
            if (elapsedTime < 10.0) {
                continue;
            }

            // Perform website check
            int checkResult = performCheck(url);
            websiteStats[i].lastChecked = currentTime;
            websiteStats[i].numChecks++;
            if (checkResult == 0) {
                websiteStats[i].numFailures++;
            }

            // Calculate uptime ratio
            websiteStats[i].uptimeRatio = calcUptimeRatio(websiteStats[i]);

            // Print out website status
            printf("%s: Uptime ratio=%.2f%%, Num checks=%d, Num failures=%d\n",
                websiteStats[i].name, websiteStats[i].uptimeRatio * 100,
                websiteStats[i].numChecks, websiteStats[i].numFailures);
        }

        // Wait 5 seconds before next check
        printf("Sleeping...\n");
        sleep(5);
    }

    // Clean up curl
    curl_global_cleanup();

    return 0;
}