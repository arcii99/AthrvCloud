//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_TEMP 20
#define MAX_TEMP 30
#define MAX_ALERT_TEMP 25
#define MAX_HISTORY_RECORDS 10

typedef struct {
    float temp;
    time_t timestamp;
} TemperatureRecord;

typedef struct {
    TemperatureRecord history[MAX_HISTORY_RECORDS];
    int size;
} TemperatureHistory;

float getTemperature() {
    return (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
}

bool isTemperatureAboveThreshold(float temperature, float threshold) {
    return temperature > threshold;
}

TemperatureRecord createTemperatureRecord(float temperature) {
    time_t now = time(NULL);
    TemperatureRecord record;
    record.temp = temperature;
    record.timestamp = now;
    return record;
}

void addTemperatureToHistory(TemperatureHistory *history, float temperature) {
    if (history->size == MAX_HISTORY_RECORDS) {
        for (int i = 0; i < MAX_HISTORY_RECORDS - 1; i++) {
            history->history[i] = history->history[i+1];
        }
        history->size--;
    }
    history->history[history->size] = createTemperatureRecord(temperature);
    history->size++;
}

void printTemperatureHistory(TemperatureHistory *history) {
    printf("Temperature History:\n");
    for (int i = 0; i < history->size; i++) {
        printf("%d. Temperature: %.2f, Timestamp: %s", i+1,
            history->history[i].temp, ctime(&history->history[i].timestamp));
    }
}

int main() {
    srand(time(NULL));
    TemperatureHistory history = { .history = {}, .size = 0 };
    while (true) {
        float temperature = getTemperature();
        printf("Current temperature: %.2f\n", temperature);
        if (isTemperatureAboveThreshold(temperature, MAX_ALERT_TEMP)) {
            printf("*** ALERT: Temperature is above the threshold of %.2f ***\n", MAX_ALERT_TEMP);
        }
        addTemperatureToHistory(&history, temperature);
        printTemperatureHistory(&history);
        printf("------------------\n");
        sleep(1);
    }
    return 0;
}