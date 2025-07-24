//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_LOWER_LIMIT -20
#define TEMP_UPPER_LIMIT 100
#define TEMP_LIST_LENGTH 10

void generate_temperatures(int *temp_list) {
    srand(time(NULL));
    for(int i=0; i<TEMP_LIST_LENGTH; i++) {
        temp_list[i] = rand()%(TEMP_UPPER_LIMIT-TEMP_LOWER_LIMIT+1) + TEMP_LOWER_LIMIT;
    }
}

int calculate_average_temperature(int *temp_list) {
    int sum = 0;
    for(int i=0; i<TEMP_LIST_LENGTH; i++) {
        sum += temp_list[i];
    }
    return sum/TEMP_LIST_LENGTH;
}

int calculate_highest_temperature(int *temp_list) {
    int highest_temp = TEMP_LOWER_LIMIT - 1;
    for(int i=0; i<TEMP_LIST_LENGTH; i++) {
        if(temp_list[i] > highest_temp) {
            highest_temp = temp_list[i];
        }
    }
    return highest_temp;
}

int calculate_lowest_temperature(int *temp_list) {
    int lowest_temp = TEMP_UPPER_LIMIT + 1;
    for(int i=0; i<TEMP_LIST_LENGTH; i++) {
        if(temp_list[i] < lowest_temp) {
            lowest_temp = temp_list[i];
        }
    }
    return lowest_temp;
}

void print_temp_statistics(int *temp_list, int avg_temp, int highest_temp, int lowest_temp) {
    printf("Temperature List:\n");
    for(int i=0; i<TEMP_LIST_LENGTH; i++) {
        printf("%d ", temp_list[i]);
    }
    printf("\n\nAverage Temperature: %d\n", avg_temp);
    printf("Highest Temperature: %d\n", highest_temp);
    printf("Lowest Temperature: %d\n", lowest_temp);
}

int main() {
    int temp_list[TEMP_LIST_LENGTH];
    generate_temperatures(temp_list);
    int avg_temp = calculate_average_temperature(temp_list);
    int highest_temp = calculate_highest_temperature(temp_list);
    int lowest_temp = calculate_lowest_temperature(temp_list);
    print_temp_statistics(temp_list, avg_temp, highest_temp, lowest_temp);
    return 0;
}