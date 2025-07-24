//FormAI DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random temperature between -20 and 40 Celsius */
float generateTemperature(){

    float temperature = ((float)(rand() % 601 - 200))/10;
    return temperature;
}

/* Function to generate random humidity between 0 and 100% */
int generateHumidity(){
    
    int humidity = rand() % 101;
    return humidity;
}

/* Function to generate random wind speed between 0 and 100 km/h */
int generateWindSpeed(){
    
    int windSpeed = rand() % 101;
    return windSpeed;
}

/* Function to print a message based on the temperature */
void checkTemperature(float temperature){
    if(temperature <= 5.0f){
        printf("It's really cold outside! Make sure to wear a coat.\n");
    }
    else if(temperature <= 20.0f){
        printf("It's a nice day outside. Enjoy it!\n");
    }
    else{
        printf("It's hot outside! Stay hydrated.\n");
    }
}

/* Function to print a message based on the humidity */
void checkHumidity(int humidity){
    if(humidity < 30){
        printf("It's very dry outside. Make sure to drink water.\n");
    }
    else if(humidity < 60){
        printf("Humidity is at a comfortable level.\n");
    }
    else{
        printf("It's quite humid outside. Stay cool.\n");
    }
}

/* Function to print a message based on the wind speed */
void checkWindSpeed(int windSpeed){
    if(windSpeed < 20){
        printf("It's a calm day. Enjoy the weather.\n");
    }
    else if(windSpeed < 50){
        printf("It's a bit windy outside. Hold on to your hat.\n");
    }
    else{
        printf("It's very windy! Stay indoors if possible.\n");
    }
}

int main(){
    
    /* Seed random number generator with current time */
    srand(time(NULL));
    
    /* Generate weather conditions and store in variables */
    float temperature = generateTemperature();
    int humidity = generateHumidity();
    int windSpeed = generateWindSpeed();
    
    /* Print out weather conditions */
    printf("Current weather conditions:\n");
    printf("Temperature: %.2fC\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind speed: %dkm/h\n", windSpeed);
    
    /* Check weather conditions */
    checkTemperature(temperature);
    checkHumidity(humidity);
    checkWindSpeed(windSpeed);
    
    return 0;
}