//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main(){
    float temperature;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &temperature);
    if(temperature < -273.15){
        printf("Are you sure? This temperature is below absolute zero!\n");
    }
    else if(temperature == -273.15){
        printf("This temperature is equal to absolute zero. Congratulations?!?\n");
    }
    else if(temperature > -273.15 && temperature < 0){
        printf("Brrrr! It's freezing in here!\n");
    }
    else if(temperature == 0){
        printf("Water freezes at this temperature. Brrr!\n");
    }
    else if(temperature > 0 && temperature < 100){
        printf("This temperature is within the range of liquid water. It's safe to drink!\n");
    }
    else if(temperature == 100){
        printf("Water boils at this temperature. Careful not to get burned!\n");
    }
    else if(temperature > 100){
        printf("This temperature is above the boiling point of water. Don't touch it or you'll get burned!\n");
    }
    printf("Thank you for using our temperature monitoring program!\n");
    return 0;
}