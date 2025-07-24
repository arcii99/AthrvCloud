//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    
    FILE *file = fopen("logs.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    time_t current_time;
    char* c_time_string;
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        res = curl_easy_perform(curl);
    
        if(res == CURLE_OK) {
            printf("Website is up and running!\n");
            current_time = time(NULL);
            c_time_string = ctime(&current_time);
            fprintf(file, "Website is up at %s\n", c_time_string);
        } else {
            printf("Website is down!\n");
            current_time = time(NULL);
            c_time_string = ctime(&current_time);
            fprintf(file, "Website is down at %s\n", c_time_string);
        }
        
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();

    fclose(file);
    
    return 0;
}