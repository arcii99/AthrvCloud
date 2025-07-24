//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mathematical
#include <stdio.h>

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    int bootTime, optimizeTime, gcdTime;
    printf("Enter the boot time in seconds: ");
    scanf("%d", &bootTime);
    printf("Enter the optimization time in seconds: ");
    scanf("%d", &optimizeTime);
    
    // Calculate the greatest common divisor between the boot time and the optimization time
    gcdTime = gcd(bootTime, optimizeTime);
    
    // Calculate the percentage reduction in boot time achieved through optimization
    int reduction = ((bootTime - gcdTime) * 100) / bootTime;
    printf("The boot time can be reduced by %d%% through optimization.\n", reduction);
    
    // Calculate the new boot time after optimization
    int newBootTime = bootTime - gcdTime;
    printf("The new boot time would be %d seconds.\n", newBootTime);
    
    // Calculate the percentage of time saved through optimization
    int timeSaved = ((bootTime - newBootTime) * 100) / bootTime;
    printf("The optimization would save %d%% of the boot time.\n", timeSaved);
    
    return 0;
}