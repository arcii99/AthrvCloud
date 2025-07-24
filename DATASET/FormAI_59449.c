//FormAI DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char date[11];
    float value;
} StockData;

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    sprintf(userdata, "%s%s", (char *) userdata, ptr);
    return size * nmemb;
}

int main() {
    CURL *curl = curl_easy_init();
    if (!curl) {
        printf("Failed to initialize CURL.\n");
        exit(EXIT_FAILURE);
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://finance.yahoo.com/quote/%5EDJI/history?p=%5EDJI");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    char stock_data[10000];
    memset(stock_data, 0, sizeof(stock_data));

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stock_data);
    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        printf("Failed to fetch data from Yahoo Finance.\n");
        curl_easy_cleanup(curl);
        exit(EXIT_FAILURE);
    }

    curl_easy_cleanup(curl);

    StockData data[365];
    char *line = strtok(stock_data, "\n");
    int i = 0;

    while (line != NULL) {
        if (strstr(line, "<span data-reactid=\"")) {
            char *date = strtok(NULL, ",");
            char *value_string = strtok(NULL, ",");
            char *next_chunk = strtok(NULL, ",");
            float value = atof(value_string);

            strcpy(data[i].date, date);
            data[i].value = value;
            i++;
        }
        line = strtok(NULL, "\n");
    }

    printf("|----------------------------------|\n");
    printf("|  Dow Jones Industrial Average    |\n");
    printf("|----------------------------------|\n");
    printf("|  Date        |  Closing Value   |\n");
    printf("|----------------------------------|\n");

    for (int j = 0; j < i; j++) {
        printf("|  %s  |  $%.2f   |\n", data[j].date, data[j].value);
    }

    printf("|----------------------------------|\n");
    printf("|  End of Daily Closing Prices     |\n");
    printf("|----------------------------------|\n");

    return 0;
}