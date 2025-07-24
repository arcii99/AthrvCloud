//FormAI DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>

int main(){
    float temp, total = 0;
    int i;

    printf("Enter the number of temperature readings you want to take: ");
    int num;
    scanf("%d", &num);

    for(i = 1; i <= num; i++){
        printf("Enter the temperature reading in Celsius for reading %d: ", i);
        scanf("%f", &temp);

        //Add all readings to total
        total += temp;
    }
    //Find the average temperature reading
    float avg = total / num;
    
    //Print the average temperature reading
    printf("\nThe average temperature reading is %.2f degrees Celsius\n", avg);

    //Display status based on the average temperature reading
    if(avg <= 0){
        printf("It's freezing outside. Stay warm!\n");
    }
    else if(avg >= 1 && avg <= 10){
        printf("It's very cold outside. Wear a jacket!\n");
    }
    else if(avg >= 11 && avg <= 20){
        printf("It's chilly outside. Bring a sweater!\n");
    }
    else if(avg >= 21 && avg <= 30){
        printf("It's warm outside. Enjoy the sunshine!\n");
    }
    else{
        printf("It's hot outside. Stay cool!\n");
    }

    return 0;
}