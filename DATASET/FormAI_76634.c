//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scientific
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h> 

// Define constants 
#define MAX 100 
#define MIN -100 
#define SIZE 20 

// #define statement to get distance 
#define DISTANCE(level) pow(10, ((-59 - level)/20)) 

int main() 
{ 
    // Declare variables 
    int i, j, k, n; 
    char ssid[MAX][SIZE], ch; 
    int level[MAX]; 
    float dist[MAX]; 

    // Ask user for number of Wi-Fi networks 
    printf("Enter the number of Wi-Fi networks: "); 
    scanf("%d", &n); 

    // Ask user to enter ESSID and signal strength 
    printf("\nEnter the ESSID and signal strength for each network:\n"); 
    for(i = 0; i < n; i++)
    { 
        // Flush buffer 
        fflush(stdin); 

        // Ask user to enter ESSID 
        printf("%d. ESSID: ", i+1); 
        fgets(ssid[i], SIZE, stdin); 

        // Ask user to enter signal strength 
        printf("   Strength (dBm): "); 
        scanf("%d", &level[i]); 

        // calculate distance 
        dist[i] = DISTANCE(level[i]); 
    } 

    // Provide a table of Wi-Fi networks with their signal strengths and distances 
    printf("\n----------------------------------------------------------------------------------------------------------"); 
    printf("\n| %20s | %20s | %20s |", "ESSID", "Signal Strength (dBm)", "Distance (m)"); 
    printf("\n----------------------------------------------------------------------------------------------------------"); 
    for(i = 0; i < n; i++) 
    { 
        printf("\n| %20s | %20d | %20.2f |", ssid[i], level[i], dist[i]); 
        printf("\n----------------------------------------------------------------------------------------------------------"); 
    }

    return 0; 
}