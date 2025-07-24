//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random speed data
double generate_speed_data(){
    double min = 10.0, max = 100.0;
    double speed_data = (double)rand()/RAND_MAX*(max-min) + min;
    return speed_data;
}

//Function to calculate average speed
double calculate_average_speed(double *speeds, int num_tests){
    double sum = 0.0, average_speed;
    int i;
    for(i=0;i<num_tests;i++){
        sum += speeds[i];
    }
    average_speed = sum/num_tests;
    return average_speed;
}

//Function to display internet speed data
void display_speed_data(double *speeds, int num_tests){
    int i;
    printf("\nInternet Speed Test Results:\n");
    for(i=0;i<num_tests;i++){
        printf("Test %d: %.2f Mbps\n", i+1, speeds[i]);
    }
}

int main(){
    int num_tests, i;
    srand(time(NULL));
    printf("Enter the number of tests you want to perform: ");
    scanf("%d", &num_tests);
    double *speeds = (double*)malloc(num_tests*sizeof(double));
    if(speeds == NULL){
        printf("Memory allocation failed.\n");
        return 0;
    }
    for(i=0;i<num_tests;i++){
        speeds[i] = generate_speed_data();
    }
    display_speed_data(speeds, num_tests);
    printf("\nAverage Internet Speed: %.2f Mbps\n", calculate_average_speed(speeds, num_tests));
    free(speeds);
    return 0;
}