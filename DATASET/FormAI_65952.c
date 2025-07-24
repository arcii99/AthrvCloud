//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main() {
    CURL *curl;
    CURLcode res;
    char url[100] = "http://api.openweathermap.org/data/2.5/weather?q=New+York&appid=APIKEY";
    char weather[50];

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            return 1;
        }
        else {
            char *data;
            long http_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

            if(http_code == 200) {
                curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &data);

                if(data)
                    printf("Content-Type: %s\n", data);

                printf("\nHere's the current weather in New York: ");
                sscanf(weather, "%50[^,]", data);
                printf("%s! Don't forget to wear sunscreen :)", data);
            }
            else {
                printf("HTTP Error: %ld\n", http_code);
            }
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}