//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LEN 256
#define MAX_TIME_STR_LEN 30

typedef struct {
    char urls[MAX_URL_LEN][MAX_URL_LEN];
    int num_urls;
    int delay;
} Config;

Config read_config(const char* filename);
void monitor_urls(Config config);
void log_event(const char* url, bool is_up);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <config file>\n", argv[0]);
        return 1;
    }

    Config config = read_config(argv[1]);
    monitor_urls(config);

    return 0;
}

Config read_config(const char* filename) {
    FILE* fp = fopen(filename, "r");

    Config config;
    memset(&config, 0, sizeof(Config));
    
    if (fp != NULL) {
        char buf[MAX_URL_LEN];
        int line_num = 0;

        while (fgets(buf, sizeof(buf), fp) != NULL) {
            line_num++;

            // Ignore blank lines and comments
            if (strlen(buf) <= 1 || buf[0] == '#') {
                continue;
            }

            // Remove newline from end of string
            buf[strcspn(buf, "\n")] = 0;

            if (line_num == 1) {
                config.delay = atoi(buf);
            } else {
                strcpy(config.urls[config.num_urls], buf);
                config.num_urls++;
            }
        }

        fclose(fp);
    } else {
        printf("Failed to read config file '%s'\n", filename);
        exit(1);
    }

    return config;
}

void monitor_urls(Config config) {
    while (true) {
        // Check each URL
        for (int i = 0; i < config.num_urls; i++) {
            CURL* curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, config.urls[i]);
                curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
                curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 2L);
                curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3L);

                CURLcode res = curl_easy_perform(curl);
                if (res == CURLE_OK) {
                    long response_code;
                    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                    
                    if (response_code / 100 == 2) {
                        log_event(config.urls[i], true);
                    } else {
                        log_event(config.urls[i], false);
                    }
                } else {
                    log_event(config.urls[i], false);
                }

                curl_easy_cleanup(curl);
            }
        }

        // Wait before checking again
        printf("Waiting %d seconds...\n", config.delay);
        sleep(config.delay);
    }
}

void log_event(const char* url, bool is_up) {
    FILE* fp = fopen("uptime.log", "a");

    if (fp != NULL) {
        char time_str[MAX_TIME_STR_LEN];
        time_t t = time(NULL);
        struct tm* tm_info = localtime(&t);

        strftime(time_str, MAX_TIME_STR_LEN, "%Y-%m-%d %H:%M:%S", tm_info);
        fprintf(fp, "%s %s %s\n", time_str, url, is_up ? "UP" : "DOWN");

        fclose(fp);
    }
}