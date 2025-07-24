//FormAI DATASET v1.0 Category: Task Scheduler ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to display the current time
void displayTime(){
    time_t t;
    struct tm *currentTime;
    char *timeString;

    // Get the current time
    time(&t);
    currentTime = localtime(&t);

    // Convert time to string
    timeString = asctime(currentTime);

    // Display the current time
    printf("Current time: %s", timeString);
}

// Task to be executed after 5 seconds
void task1(){
    printf("Task 1 executed.\n");
}

// Task to be executed after 10 seconds
void task2(){
    printf("Task 2 executed.\n");
}

// Task to be executed after 15 seconds
void task3(){
    printf("Task 3 executed.\n");
}

int main(){
    printf("Starting task scheduler...\n");

    // Schedule task 1 after 5 seconds
    printf("Scheduling task 1 after 5 seconds...\n");
    sleep(5);
    task1();

    // Schedule task 2 after 10 seconds
    printf("Scheduling task 2 after 10 seconds...\n");
    sleep(5);
    task2();

    // Schedule task 3 after 15 seconds
    printf("Scheduling task 3 after 15 seconds...\n");
    sleep(5);
    task3();

    printf("Exiting task scheduler...\n");
    return 0;
}