//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int temperature;
    int hours = 24;
    srand(time(NULL));

    for(int i = 0; i<hours; i++){
        temperature = rand()%20 + 15;

        if(temperature < 20){
            printf("Temperature is %d C. It's freezing outside. Better wear your cyberpunk jacket!\n", temperature);
        }
        else if(temperature >= 20 && temperature < 25){
            printf("Temperature is %d C. It's cool outside. You can wear your cyberpunk hoodie!\n", temperature);
        }
        else if(temperature >= 25 && temperature < 30){
            printf("Temperature is %d C. It's getting hot outside. Time to show off your cyberpunk tank top!\n", temperature);
        }
        else{
            printf("Temperature is %d C. It's scorching outside. Better stay indoors and adjust your cyberpunk AC unit!\n", temperature);
        }
    } 

    return 0;
}