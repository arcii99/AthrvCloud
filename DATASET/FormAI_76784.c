//FormAI DATASET v1.0 Category: Weather simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_CITIES 5

typedef struct Weather {
    char city[16];
    int temperature;
    int humidity;
    char conditions[16];
} Weather_t;

void rand_weather(Weather_t *w) {
    static const char *cities[] = { "New York", "Los Angeles", "London", "Tokyo", "Sydney" };
    static const char *conditions[] = { "sunny", "cloudy", "rainy", "foggy", "stormy", "snowy" };
    int citynum = sizeof(cities) / sizeof(*cities);
    int conditionnum = sizeof(conditions) / sizeof(*conditions);

    int cityidx = rand() % citynum;
    snprintf(w->city, sizeof(w->city), "%s", cities[cityidx]);
    w->temperature = rand() % 50;
    w->humidity = rand() % 100;
    int conditionidx = rand() % conditionnum;
    snprintf(w->conditions, sizeof(w->conditions), "%s", conditions[conditionidx]);
}

void print_weather(Weather_t *w) {
    printf("Weather for %s:\n", w->city);
    printf("Temperature: %d degrees Celsius\n", w->temperature);
    printf("Humidity: %d%%\n", w->humidity);
    printf("Conditions: %s\n", w->conditions);
}

int main(void) {
    srand(time(NULL));

    for (int i = 0; i < WEATHER_CITIES; ++i) {
        Weather_t weather;
        rand_weather(&weather);
        print_weather(&weather);
        putchar('\n');
    }

    return 0;
}