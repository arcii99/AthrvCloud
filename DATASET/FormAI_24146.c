//FormAI DATASET v1.0 Category: Weather simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int temp[7][24];
    srand(time(0)); // seeding the random number generator
    
    // Generating random temperature for the week
    for(int i=0; i<7; i++){
        for(int j=0; j<24; j++){
            temp[i][j] = (rand() % 21) + 10; // range from 10 to 30 degrees Celsius
        }
    }
    
    // Printing the temperature for the week in a tabular format
    printf("***************************\n");
    printf("* WEEKLY WEATHER FORECAST *\n");
    printf("***************************\n");
    printf("Day\t|\tTemperature\n");
    printf("---------------------------\n");
    for(int i=0; i<7; i++){
        printf("%d\t|\t", i+1);
        for(int j=0; j<24; j++){
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------\n");
    
    // Finding the average temperature for the week
    int sum = 0;
    for(int i=0; i<7; i++){
        for(int j=0; j<24; j++){
            sum += temp[i][j];
        }
    }
    float avg = (float)sum / (7*24);
    printf("Average temperature for the week: %.2f degrees Celsius\n", avg);
    
    // Finding the highest temperature for the week
    int max = temp[0][0];
    for(int i=0; i<7; i++){
        for(int j=0; j<24; j++){
            if(temp[i][j] > max){
                max = temp[i][j];
            }
        }
    }
    printf("Highest temperature for the week: %d degrees Celsius\n", max);
    
    // Finding the lowest temperature for the week
    int min = temp[0][0];
    for(int i=0; i<7; i++){
        for(int j=0; j<24; j++){
            if(temp[i][j] < min){
                min = temp[i][j];
            }
        }
    }
    printf("Lowest temperature for the week: %d degrees Celsius\n", min);
    
    return 0;
}