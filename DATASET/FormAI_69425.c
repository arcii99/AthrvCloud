//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100   // maximum number of log entries

struct LogEntry {
    double value;
    struct tm* timestamp;
};

double calculateMean(struct LogEntry entries[], int count) {
    double sum = 0;
    
    for (int i = 0; i < count; i++) {
        sum += entries[i].value;
    }
    
    return sum / count;
}

double calculateStandardDeviation(struct LogEntry entries[], int count, double mean) {
    double sum = 0;
    
    for (int i = 0; i < count; i++) {
        sum += pow(entries[i].value - mean, 2);
    }
    
    return sqrt(sum / count);
}

int main() {
    struct LogEntry log[N];
    int count = 0;
    
    // read log entries from file or user input
    
    double mean = calculateMean(log, count);
    double standardDeviation = calculateStandardDeviation(log, count, mean);
    
    printf("The mean of the log entries is %.2lf\n", mean);
    printf("The standard deviation of the log entries is %.2lf\n", standardDeviation);
    
    return 0;
}