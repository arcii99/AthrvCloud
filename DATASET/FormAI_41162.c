//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define URL_LENGTH 100
#define MAX_URLS 10

typedef struct {
    char url[URL_LENGTH];
    int status_code;
    bool is_up;
} website;

typedef struct {
    website sites[MAX_URLS];
    int count;
} monitor;

bool check_website(website *site) {
    CURL *curl;
    CURLcode res;
    long status_code;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);

            if (status_code == 200) {
                site->is_up = true;
                site->status_code = status_code;
            }
            else {
                site->is_up = false;
                site->status_code = status_code;
            }
        }

        curl_easy_cleanup(curl);
    }

    return site->is_up;
}

void monitor_websites(monitor *mon) {
    for (int i = 0; i < mon->count; i++) {
        bool is_up = check_website(&mon->sites[i]);

        if (is_up) {
            printf("%s is up! Status code: %d\n", mon->sites[i].url, mon->sites[i].status_code);
        }
        else {
            printf("%s is down! Status code: %d\n", mon->sites[i].url, mon->sites[i].status_code);
        }
    }

    time_t now = time(0);
    printf("Last checked at: %s", ctime(&now));
}

int main() {
    monitor mon = {
        .sites = {
            { .url = "https://www.google.com", .status_code = 0, .is_up = false },
            { .url = "https://www.facebook.com", .status_code = 0, .is_up = false }
        },
        .count = 2
    };

    while (true) {
        monitor_websites(&mon);
        sleep(10);
    }

    return 0;
}