//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <curl/curl.h>

static int counter = 0;

typedef struct {
    bool is_down;
    char *url;
} Website;

Website create_website(char *url) {
    Website website = { true, url };
    return website;
}

void check_website(Website *website) {
    CURL *curl = curl_easy_init();
    CURLcode res;
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            printf("%s is up!\n", website->url);
            website->is_down = false;
        } else {
            printf("%s is down!\n", website->url);
            website->is_down = true;
        }
        curl_easy_cleanup(curl);
    } else {
        printf("Could not initialize CURL!\n");
        website->is_down = true;
    }
}

int main() {
    Website website1 = create_website("https://www.google.com");
    Website website2 = create_website("https://www.github.com");
    Website website3 = create_website("https://www.facebook.com");

    while (true) {
        if (counter % 10 == 0) {
            printf("Checking websites...\n");
            check_website(&website1);
            check_website(&website2);
            check_website(&website3);
        }

        counter++;
        sleep(1);
    }
    return 0;
}