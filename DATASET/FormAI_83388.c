//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include<stdio.h>
#include<math.h>

int main(){

    int signalStrength;

    printf("Enter signal strength (in dbm):");
    scanf("%d", &signalStrength);

    if(signalStrength > -50){
        printf("Signal strength: Excellent\n");
    }else if(signalStrength <= -50 && signalStrength > -60){
        printf("Signal strength: Good\n");
    }else if(signalStrength <= -60 && signalStrength > -70){
        printf("Signal strength: Fair\n");
    }else if(signalStrength <= -70 && signalStrength > -80){
        printf("Signal strength: Weak\n");
    }else{
        printf("Signal strength: Poor\n");
    }

    return 0;
}