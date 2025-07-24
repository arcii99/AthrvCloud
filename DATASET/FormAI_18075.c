//FormAI DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include<stdio.h>

//function to generate random temperature
float generateTemp(){
    float temp = (float)(rand() % 50 + 1);
    return temp;
}

//function to check if current temperature is within normal range
int isNormal(float temp){
    if(temp>0 && temp<37)
        return 1;
    else
        return 0;
}

int main(){

    printf("\tWelcome to Temperature Monitor Program\n");

    //initial temperature check
    printf("\nCurrent Temperature: ");
    float temp = generateTemp();
    printf("%.2f", temp);
    if(isNormal(temp))
        printf(" (Normal)\n");
    else
        printf(" (Abnormal)\n");

    //continuously monitor temperature every 5 seconds
    while(1){
        sleep(5);
        printf("\nCurrent Temperature: ");
        temp = generateTemp();
        printf("%.2f", temp);
        if(isNormal(temp))
            printf(" (Normal)\n");
        else
            printf(" (Abnormal)\n");
    }

    return 0;
}