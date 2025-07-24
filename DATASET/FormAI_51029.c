//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Romeo and Juliet
// Romeo and Juliet: A Temperature Monitoring Program 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int temperature = 0;
    srand(time(NULL)); // setting seed for random number generation
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n"); // printing a classic quote
    printf("I, thy faithful servant, am here to monitor the temperature.\n"); // Romeo tells Juliet his duty
    printf("Fair Juliet, pray tell me the temperature that thou seeks to monitor: ");
    scanf("%d", &temperature); // asks Juliet to input the temperature

    if(temperature<0){
        printf("My dear, the temperature is freezing as winters frost.\n"); // code to be executed if temperature is less than 0 degree Celsius
    }
    else if(temperature>=0 && temperature<20){
        printf("The temperature is as cold as sorrowful hearts.\n"); // code to be executed if temperature is between 0 to 19 degree Celsius
    }
    else if(temperature>=20 && temperature<30){
        printf("Fear not, the temperature is moderate as the sun.\n"); // code to be executed if temperature is between 20 to 29 degree Celsius
    }
    else if(temperature>=30 && temperature<40){
        printf("Rejoice! The temperature is warm as a lover's embrace.\n"); // code to be executed if temperature is between 30 to 39 degree Celsius
    }
    else{
        printf("My sweet Juliet, the temperature is hot as the fires of Montagues and Capulets.\n"); // code to be executed if temperature is greater than or equal to 40 degree Celsius
    }
    printf("But wait, I see that the temperature has changed unexpectedly!\n"); // Romeo notices a change in temperature
    temperature = rand()%61 - 15; // generates a random temperature between -15 to 45 degree Celsius
    printf("Fair Juliet, the new temperature is: %d\n", temperature); // Romeo informs Juliet of the new temperature

    // adding some drama to the program
    printf("Oh heavens! The temperature is fluctuating as the passions of our doomed love.\n"); 
    printf("Let us pray to the gods to restore order in the temperature readings.\n");
    printf("But until then, let us bid adieu to each other, for we may not know what fate lies ahead.\n");
    printf("Goodbye my love, may we meet again in another lifetime.\n");

    return 0;
}