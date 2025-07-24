//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    //Clearing terminal window
    system("clear");

    //Initializing variables
    float temperature = 0.0;
    int counter = 0;

    //Infinite loop for temperature monitoring
    while(1){

        //Generating random temperature between 10 and 50 degrees Celsius
        temperature = (rand()%41) + 10;

        //Printing the current temperature
        printf("\nTemperature: %.2f C\n", temperature);

        //Increasing the counter
        counter++;

        //Checking if the temperature is above 40 degrees Celsius
        if(temperature > 40.0){

            //Printing warning message
            printf("\n!!! Warning !!! Temperature above 40 degrees Celsius\n");

            //Pausing the program for 2 seconds
            sleep(2);

            //Clearing terminal window
            system("clear");

            //Printing the temperature 5 times with warning message
            for(int i = 0; i < 5; i++){

                printf("\n!!! WARNING !!! High Temperature: %.2f C\n", temperature);
                sleep(1);
            }
        }

        //Checking if the program has monitored 50 temperatures
        if(counter == 50){

            //Printing completion message
            printf("\n\n>>> Temperature monitoring completed <<<\n\n");

            //Ending program
            return 0;
        }

        //Pausing the program for 1 second
        sleep(1);
    }

    return 0;
}