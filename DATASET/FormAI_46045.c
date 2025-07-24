//FormAI DATASET v1.0 Category: Educational ; Style: peaceful
#include <stdio.h>

//Function to calculate the average
float average(int n, int arr[]) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    float avg = (float)sum/n;
    return avg;
}

int main() {
    printf("Welcome to the Peace Calculator!\n");
    printf("Please enter the number of values you want to calculate: ");

    //Taking input for number of values
    int n;
    scanf("%d", &n);

    //Taking input for the values
    int arr[n];
    printf("\nEnter the Values:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    //Calculating the average
    float avg = average(n, arr);

    //Displaying the average
    printf("\nThe average of the given values is: %.2f\n", avg);
    printf("Thank you for using Peace Calculator!\n");
    return 0;
}