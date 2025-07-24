//FormAI DATASET v1.0 Category: Stock market tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define API_KEY "YOUR_API_KEY"
#define API_URL "https://www.alphavantage.co/query?"

typedef struct {
    char symbol[16];
    double price;
    double change;
    double pct_change;
} Stock;

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    strncpy(userdata, ptr, size * nmemb);
    return size * nmemb;
}

void get_stock(Stock *s) {
    CURL *curl;
    CURLcode res;
    char url[128];
    char data[1024];

    sprintf(url, "%sfunction=GLOBAL_QUOTE&symbol=%s&apikey=%s", API_URL, s->symbol, API_KEY);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            exit(EXIT_FAILURE);
        }

        // parse the JSON response and extract the stock price, change, and percent change
        char *price_str = strstr(data, "\"05. price\": \"");
        if (price_str == NULL) {
            fprintf(stderr, "Error: unable to parse stock price\n");
            exit(EXIT_FAILURE);
        }
        sscanf(price_str, "\"05. price\": \"%lf", &s->price);

        char *change_str = strstr(data, "\"09. change\": \"");
        if (change_str == NULL) {
            fprintf(stderr, "Error: unable to parse stock change\n");
            exit(EXIT_FAILURE);
        }
        sscanf(change_str, "\"09. change\": \"%lf", &s->change);

        char *pct_change_str = strstr(data, "\"10. change percent\": \"");
        if (pct_change_str == NULL) {
            fprintf(stderr, "Error: unable to parse stock percent change\n");
            exit(EXIT_FAILURE);
        }
        sscanf(pct_change_str, "\"10. change percent\": \"%lf%%", &s->pct_change);

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void print_stock(Stock *s) {
    printf("%-6s | Price: %-15.2lf | Change: %-15.2lf | Pct Change: %-15.2lf%%\n",
           s->symbol, s->price, s->change, s->pct_change);
}

int main() {
    Stock stocks[] = {
        {"AAPL", 0, 0, 0},
        {"MSFT", 0, 0, 0},
        {"GOOG", 0, 0, 0},
        {"AMZN", 0, 0, 0},
        {"FB", 0, 0, 0},
        {"TSLA", 0, 0, 0},
        {"NVDA", 0, 0, 0},
        {"NFLX", 0, 0, 0},
        {"BABA", 0, 0, 0},
        {"JPM", 0, 0, 0}
    };
    int num_stocks = sizeof(stocks) / sizeof(Stock);

    // get the current stock prices and print them out
    for (int i = 0; i < num_stocks; i++) {
        get_stock(&stocks[i]);
        print_stock(&stocks[i]);
    }

    return EXIT_SUCCESS;
}