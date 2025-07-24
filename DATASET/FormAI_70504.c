//FormAI DATASET v1.0 Category: Weather simulation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TEMP_MIN 0       //minimum temperature in degree Celsius.
#define TEMP_MAX 50      //maximum temperature in degree Celsius.
#define PRESSURE_MIN 900 //minimum pressure in millibars.
#define PRESSURE_MAX 1100//maximum pressure in millibars.
#define HUMIDITY_MIN 0   //minimum humidity in percentage.
#define HUMIDITY_MAX 100 //maximum humidity in percentage.

typedef struct weather{
    float temperature;   //temperature in degree Celsius.
    int pressure;        //pressure in millibars.
    float humidity;      //humidity in percentage.
}Weather;

//generates a random temperature between TEMP_MIN and TEMP_MAX.
float generateTemperature(){
    return ( (float)rand() / RAND_MAX ) * (TEMP_MAX - TEMP_MIN) + TEMP_MIN;
}

//generates a random pressure between PRESSURE_MIN and PRESSURE_MAX.
int generatePressure(){
    return rand() % (PRESSURE_MAX - PRESSURE_MIN + 1) + PRESSURE_MIN;
}

//generates a random humidity between HUMIDITY_MIN and HUMIDITY_MAX.
float generateHumidity(){
    return ( (float)rand() / RAND_MAX ) * (HUMIDITY_MAX - HUMIDITY_MIN) + HUMIDITY_MIN;
}

//generates a random weather data.
void generateWeather(Weather *w){
    w->temperature = generateTemperature();
    w->pressure = generatePressure();
    w->humidity = generateHumidity();
}

int main(){
    srand(time(NULL));  //seeding the random number generator.

    Weather w;

    //generating the weather data.
    generateWeather(&w);

    //displaying the generated weather data.
    printf("Temperature: %.2f\u00b0C\n", w.temperature);
    printf("Pressure: %d millibars\n", w.pressure);
    printf("Humidity: %.2f%%\n", w.humidity);

    return 0;
}