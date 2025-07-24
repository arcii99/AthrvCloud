//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char name[30];
    int age;
    char date[15];
    char time[10];
    printf("Welcome to Our Clinic!\n");
    printf("Please enter your name: ");
    fgets(name, 30, stdin);
    printf("Please enter your age: ");
    scanf("%d", &age);
    getchar(); //to clear the input buffer
    printf("Please enter the date of your appointment (mm/dd/yyyy): ");
    fgets(date, 15, stdin);
    printf("Please enter the time of your appointment (hh:mm): ");
    fgets(time, 10, stdin);
    printf("\n\nThank you for making an appointment with us!\n");
    printf("Appointment Details:\n");
    printf("Name: %s", name);
    printf("Age: %d\n", age);
    printf("Date: %s\n", date);
    printf("Time: %s\n", time);
    return 0;
}