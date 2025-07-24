//FormAI DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h> // for atof function
#include <string.h>

#define MAX_LINE_LENGTH 100 // maximum length of each line in CSV file
#define MAX_LINES 1000 // maximum number of lines in CSV file

typedef struct {
    char date[11];
    float open;
    float close;
    float high;
    float low;
} StockData;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s file.csv\n", argv[0]);
        exit(1);
    }

    StockData stocks[MAX_LINES];
    int numLines = 0;

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open %s\n", argv[1]);
        exit(1);
    }
    
    // read each line of CSV file and store data in array of StockData structs
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file); // discard header line
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && numLines < MAX_LINES) {
        char *token;
        int fieldCount = 0;
        for (token=strtok(line, ",\n"); token != NULL && fieldCount < 5; token=strtok(NULL, ",\n")) {
            switch (fieldCount) {
                case 0:
                    strcpy(stocks[numLines].date, token);
                    break;
                case 1:
                    stocks[numLines].open = atof(token);
                    break;
                case 2:
                    stocks[numLines].close = atof(token);
                    break;
                case 3:
                    stocks[numLines].high = atof(token);
                    break;
                case 4:
                    stocks[numLines].low = atof(token);
                    break;
            }
            fieldCount++;
        }
        numLines++;
    }
    
    fclose(file);
    
    // calculate average closing price and print summary statistics
    float sum = 0.0;
    float maxDiff = 0.0;
    int maxDiffIdx = 0;
    for (int i = 0; i < numLines; i++) {
        sum += stocks[i].close;
        float diff = stocks[i].high - stocks[i].low;
        if (diff > maxDiff) {
            maxDiff = diff;
            maxDiffIdx = i;
        }
    }
    float avg = sum / numLines;
    printf("Average closing price: $%.2f\n", avg);
    printf("Maximum daily difference: $%.2f on %s\n", maxDiff, stocks[maxDiffIdx].date);
    
    return 0;
}