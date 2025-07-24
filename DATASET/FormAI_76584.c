//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    int signal_strength;
    printf("Enter Signal Strength: "); 
    scanf("%d", &signal_strength); 
  
    if (signal_strength >= -50) 
        printf("Wi-Fi signal is excellent, enjoy browsing!\n"); 
    else if (signal_strength >= -60 && signal_strength < -50) 
        printf("Wi-Fi signal is good, continue browsing!\n"); 
    else if (signal_strength >= -70 && signal_strength < -60) 
        printf("Wi-Fi signal is fair, browsing may be slow!\n"); 
    else if (signal_strength >= -80 && signal_strength < -70) 
        printf("Wi-Fi signal is weak, you may experience connectivity issues!\n"); 
    else 
        printf("Wi-Fi signal is poor, connection lost!\n"); 
  
    return 0; 
}