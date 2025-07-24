//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include<stdio.h>

int main(){
    float cm, meter, feet, inches;
    
    printf("Enter the distance in centimeters: ");
    scanf("%f", &cm);
    
    // Convert centimeters to meter
    meter = cm / 100.0;
    printf("\n%.2f cm is equal to %.2f meters\n", cm, meter);
    
    // Convert meter to feet
    feet = meter * 3.28;
    printf("\n%.2f meters is equal to %.2f feet\n", meter, feet);
    
    // Convert feet to inches
    inches = feet * 12.0;
    printf("\n%.2f feet is equal to %.2f inches\n", feet, inches);
    
    return 0;
}