//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: careful
// C Intrusion Detection System Example Program
#include<stdio.h>

#define THRESHOLD 30 // Number of Failed Login Attempts Allowed Before Alert

int main(){

    int counter = 0; // Variable to keep track of Failed Login Attempts
    int attempts; // Variable to store User Input for Number of Login Attempts
    int i;

    while(1){ // Infinite Loop to Continuously Monitor Login Attempts
        printf("Enter Number of Login Attempts: ");
        scanf("%d",&attempts);

        if(attempts > THRESHOLD){
            printf("\n!!! Possible Intrusion Detected - Number of Attempts: %d !!!\n", attempts);
            
            // Add logic to trigger Email or SMS Alert Systems for Intrusion Detection
            break;
        }
        else{
            counter += attempts;
            printf("%d Failed Login Attempts Detected. Total Number of Failed Attempts: %d\n\n", attempts, counter);
        }
    }
    return 0;
}