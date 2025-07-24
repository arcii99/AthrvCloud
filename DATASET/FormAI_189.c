//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scientific
#include<stdio.h>
#include<math.h>

int main(){
    int signal_strength;
    printf("Enter the signal strength in dBm: ");
    scanf("%d", &signal_strength);
    
    if(signal_strength >= -30){
        printf("Signal Strength: Excellent\n");
    }
    else if(signal_strength >= -67 && signal_strength < -30){
        printf("Signal Strength: Good\n");
    }
    else if(signal_strength >= -70 && signal_strength < -67){
        printf("Signal Strength: Fair\n");
    }
    else if(signal_strength >= -80 && signal_strength < -70){
        printf("Signal Strength: Weak\n");
    }
    else if(signal_strength < -80){
        printf("Signal Strength: Very Weak\n");
    }
    
    double distance, frequency, distance_m, signal_strength_mW, signal_strength_W;
    
    printf("\nEnter the frequency in GHz: ");
    scanf("%lf", &frequency);
    
    distance = pow(10, ((27.55 - (20 * log10(frequency)) + fabs(signal_strength))/20));
    distance_m = distance * 1000;
    signal_strength_mW = pow(10, signal_strength/10);
    signal_strength_W = signal_strength_mW/1000;
    
    printf("\nDistance in meters: %.2f m", distance_m);
    printf("\nSignal Strength in mW: %.2f mW", signal_strength_mW);
    printf("\nSignal Strength in W: %.9f W", signal_strength_W);
    
    return 0;
}