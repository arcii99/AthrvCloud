//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random internet speed result
int generateInternetSpeed(){
    srand(time(NULL)); //Seed the random number generator
    int internetSpeed = rand() % 101; //Generate a random number between 0 and 100
    return internetSpeed;
}

int main(){
    int internetSpeed = generateInternetSpeed(); //Call the function to generate internet speed result
    printf("Running Internet Speed Test...\n");
    printf("Your internet speed is: %d Mbps\n", internetSpeed);
    if(internetSpeed < 10){
        printf("Your internet speed is very slow. Contact your service provider.\n");
    }else if(internetSpeed < 50){
        printf("Your internet speed is average. Consider upgrading your plan.\n");
    }else{
        printf("Your internet speed is great! Keep enjoying your internet.\n");
    }
    return 0;
}