//FormAI DATASET v1.0 Category: Weather simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CITIES 10
#define CITY_NAME_LENGTH 20

typedef struct{
    char name[CITY_NAME_LENGTH];
    int temperature;
    int humidity;
}City;

int random_number(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void update_weather(City* cities, int num_cities){
    for(int i=0; i<num_cities; i++){
        int prev_temperature = cities[i].temperature;

        int temperature_change = random_number(-5, 5);
        cities[i].temperature += temperature_change;

        int humidity_change = random_number(0, 10);
        cities[i].humidity += humidity_change;

        printf("%s: Temperature changed from %d C to %d C, Humidity changed from %d%% to %d%%\n", cities[i].name, prev_temperature, cities[i].temperature, cities[i].humidity - humidity_change, cities[i].humidity);
    }
}

void print_weather(City* cities, int num_cities){
    printf("\nCurrent Weather:\n");
    for(int i=0; i<num_cities; i++){
        printf("%s: %d C, %d%%\n", cities[i].name, cities[i].temperature, cities[i].humidity);
    }
}

int main(){
    srand(time(NULL));

    City cities[MAX_CITIES] = {
        {"New York", random_number(-10, 10), random_number(0, 100)},
        {"London", random_number(-5, 10), random_number(0, 100)},
        {"Paris", random_number(0, 15), random_number(0, 100)},
        {"Tokyo", random_number(5, 25), random_number(0, 100)},
        {"Sydney", random_number(15, 30), random_number(0, 100)},
        {"Dubai", random_number(20, 45), random_number(0, 100)},
        {"Sao Paulo", random_number(10, 25), random_number(0, 100)},
        {"Moscow", random_number(-10, 5), random_number(0, 100)},
        {"Cairo", random_number(10, 35), random_number(0, 100)},
        {"Beijing", random_number(-10, 10), random_number(0, 100)}
    };

    int num_cities = MAX_CITIES;

    print_weather(cities, num_cities);

    for(int i=0; i<5; i++){
        printf("\n\n--Hour %d--\n", i+1);
        update_weather(cities, num_cities);
        print_weather(cities, num_cities);
    }

    return 0;
}