//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

// function to check the website uptime
int websiteUptimeCheck(char *url) {
    CURL *curl;
    CURLcode res;
    int status_code = 0;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
        }
        curl_easy_cleanup(curl);
    }
    return status_code;
}

// function to create a log file for website response time
void createLogFile(int statusCode, double responseTime) {
    FILE *fp;
    fp = fopen("website_log.txt", "a+");
    time_t t;
    time(&t);
    char *timeStamp = asctime(localtime(&t));
    char result[100];
    sprintf(result, "%s : Response Time : %f seconds : Status Code : %d \n", timeStamp, responseTime, statusCode);
    fputs(result, fp);
    fclose(fp);
}

int main() {
    char *url = "https://www.example.com";
    while(1){
        int statusCode = websiteUptimeCheck(url);
        double responseTime;
        if(statusCode == 200) {
            CURL *curl;
            CURLcode res;
            curl = curl_easy_init();
            if(curl){
                curl_easy_setopt(curl, CURLOPT_URL, url);
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
                struct timeval start, end;
                gettimeofday(&start, NULL);
                res = curl_easy_perform(curl);
                gettimeofday(&end, NULL);
                curl_easy_cleanup(curl);
                responseTime = (end.tv_sec + end.tv_usec*0.000001) - (start.tv_sec + start.tv_usec*0.000001);
                createLogFile(statusCode, responseTime);
            }
        } else {
            createLogFile(statusCode, 0.0);
        }
        sleep(300); // sleep for 5 minutes before re-checking the website uptime
    }
    return 0;
}