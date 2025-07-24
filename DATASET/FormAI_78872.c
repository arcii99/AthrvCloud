//FormAI DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    float kilometers, meters, miles;
    
    printf("Enter length in kilometers: ");
    scanf("%f", &kilometers);
    
    // convert kilometers to meters
    meters = kilometers * 1000;
    
    // convert kilometers to miles
    miles = kilometers / 1.609;
    
    printf("%.2f kilometers is %.2f meters\n", kilometers, meters);
    printf("%.2f kilometers is %.2f miles", kilometers, miles);
    
    return 0;
}