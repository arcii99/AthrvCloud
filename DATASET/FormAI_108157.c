//FormAI DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_CITIES 10
#define MAX_WEATHER_TYPES 5
#define MAX_TEMP_DIFFERENCE 20

typedef struct {
    char name[20];
    int temperature;
    char weather_type[10];
} City;

char* weather_types[MAX_WEATHER_TYPES] = {"Sunny", "Rainy", "Cloudy", "Foggy", "Snowy"};

City cities[MAX_CITIES] = {
    {"New York", 20, "Sunny"},
    {"Chicago", 10, "Rainy"},
    {"Los Angeles", 25, "Cloudy"},
    {"Atlanta", 15, "Foggy"},
    {"Seattle", 5, "Snowy"},
    {"Dallas", 18, "Sunny"},
    {"Denver", 12, "Rainy"},
    {"Houston", 22, "Cloudy"},
    {"Miami", 23, "Foggy"},
    {"San Francisco", 16, "Snowy"}
};

int get_random_temp() {
    return (rand() % (MAX_TEMP_DIFFERENCE * 2 + 1)) - MAX_TEMP_DIFFERENCE;
}

char* get_random_weather_type() {
    int index = rand() % MAX_WEATHER_TYPES;
    return weather_types[index];
}

void update_weather(City* city) {
    int temp_change = get_random_temp();
    char* new_weather = get_random_weather_type();
    
    city->temperature += temp_change;
    strcpy(city->weather_type, new_weather);
}

void display_cities() {
    printf("-----------------------------\n");
    printf("| %-15s | %-5s | %-10s |\n", "City", "Temp", "Weather");
    printf("-----------------------------\n");
    for (int i = 0; i < MAX_CITIES; i++) {
        printf("| %-15s | %-5d | %-10s |\n", cities[i].name, cities[i].temperature, cities[i].weather_type);
    }
    printf("-----------------------------\n");
}

void simulate_weather() {
    printf("Starting weather simulation...\n");
    while (1) {
        for (int i = 0; i < MAX_CITIES; i++) {
            update_weather(&cities[i]);
        }
        display_cities();
        sleep(1);
    }
}

int main() {
    srand(time(0));
    simulate_weather();
    return 0;
}