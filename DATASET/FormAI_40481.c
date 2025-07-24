//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

// Define a struct to store website information
typedef struct website {
    char *url;
    int refresh_rate;
    bool is_up;
} Website;

// Function to check if a website is up
bool check_website(Website *site) {
    CURL *curl;
    CURLcode res;
    bool result = false;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, true);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            int response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                result = true;
            }
        }
        curl_easy_cleanup(curl);
    }
    return result;
}

// Function to update website status
void update_status(Website *site) {
    site->is_up = check_website(site);
}

int main() {
    // Define website information
    Website google = {"https://www.google.com", 30, false};
    Website facebook = {"https://www.facebook.com", 60, false};
    Website twitter = {"https://www.twitter.com", 45, false};
    Website websites[] = {google, facebook, twitter};

    // Check website status every refresh rate
    while (true) {
        for (int i = 0; i < sizeof(websites) / sizeof(websites[0]); i++) {
            update_status(&websites[i]);
            printf("%s is %s\n", websites[i].url, websites[i].is_up ? "up" : "down");
        }
        sleep(1);
    }

    return 0;
}