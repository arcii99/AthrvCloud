//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printHeader() {
    printf("______________________________________________________\n");
    printf("|                    CYBER STOCK                      |\n");
    printf("|======================================================|\n");
    printf("| Ticker | Market Cap | Price | Change | Time Last Update |\n");
    printf("|======================================================|\n");
}

void printData(char* ticker, double marketCap, double price, double change) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("| %6s | $%9.2f | $%.2f | %.2f%% | %02d:%02d:%02d |\n", ticker, marketCap, price, change, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

double getRandomDouble(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main() {
    char* tickers[] = {"AAPL", "AMZN", "GOOGL", "MSFT", "TSLA"};
    double marketCaps[] = {2.3e12, 1.7e12, 1.4e12, 1.1e12, 6.5e11};
    double prices[] = {126.45, 3028.23, 1871.60, 238.93, 819.15};
    double changes[] = {-0.27, 0.61, 0.73, -0.12, 0.94};

    srand(time(NULL));

    printHeader();

    for (int i = 0; i < 5; i++) {
        double randChange = getRandomDouble(-0.5, 0.5);
        double newPrice = prices[i] + prices[i] * randChange;
        double newMarketCap = marketCaps[i] * (newPrice / prices[i]);
        printData(tickers[i], newMarketCap, newPrice, (randChange + changes[i]) * 100);
    }

    printf("|======================================================|\n");

    return 0;
}