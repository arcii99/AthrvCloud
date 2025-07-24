//FormAI DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h> //C library for making HTTP requests
#include <string.h>

#define MAX_SYMBOLS 20 //maximum number of symbols that can be tracked at once
#define MAX_URL_LEN 100 //maximum length of URL
#define MAX_RESPONSE_LEN 10000 //maximum length of response from API

typedef struct {
    char symbol[10];
    double price;
} Stock;

Stock stocks[MAX_SYMBOLS];
int num_symbols;

//callback function for writing response from API
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    char *response = (char *) userdata;
    strcat(response, ptr);
    return size * nmemb;
}

//function to get stock market data from Alpha Vantage API and update stock prices
void get_stocks() {
    CURL *curl;
    CURLcode res;
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    response[0] = '\0';

    //construct URL for API request based on symbols to track
    sprintf(url, "https://www.alphavantage.co/query?function=BATCH_STOCK_QUOTES&symbols=%s&apikey=YOUR_API_KEY", stocks[0].symbol);
    for (int i = 1; i < num_symbols; i++) {
        char temp[MAX_URL_LEN];
        sprintf(temp, ",%s", stocks[i].symbol);
        strcat(url, temp);
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            //parse JSON response and update stock prices
            char *token = strtok(response, "[{,\"}");
            while (token != NULL) {
                if (!strcmp(token, "1. symbol")) {
                    char symbol[10];
                    strncpy(symbol, strtok(NULL, "[{,\"}"), 10);
                    //search for stock with this symbol and update its price
                    for (int i = 0; i < num_symbols; i++) {
                        if (!strcmp(symbol, stocks[i].symbol)) {
                            stocks[i].price = atof(strtok(NULL, "[{,\"}"));
                            break;
                        }
                    }
                }
                token = strtok(NULL, "[{,\"}");
            }
        }

        curl_easy_cleanup(curl);
    }
}

int main() {
    //initialize stocks that will be tracked
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 138.44;
    strcpy(stocks[1].symbol, "TSLA");
    stocks[1].price = 589.74;
    num_symbols = 2;

    while (1) {
        //clear console and show current stock prices
        system("clear");
        printf("Stock Market Tracker\n\n");
        for (int i = 0; i < num_symbols; i++) {
            printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
        }

        //get updated stock prices every minute
        sleep(60);
        get_stocks();
    }

    return 0;
}