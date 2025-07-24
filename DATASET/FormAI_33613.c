//FormAI DATASET v1.0 Category: Unit converter ; Style: Alan Touring
#include <stdio.h>

int main() {
    double miles, kilometers;
    
    printf("Enter distance in miles: ");
    scanf("%lf", &miles);

    //convert miles to kilometers
    kilometers = miles * 1.60934;
  
    printf("%.2lf miles is equal to %.2lf kilometers\n", miles, kilometers);

    return 0;
}