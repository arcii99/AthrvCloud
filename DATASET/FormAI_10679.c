//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to simulate intrusion detection */
int detect_intrusion()
{
    srand(time(NULL)); // Seed the random number generator with current time
    int rand_num = rand() % 10; // Generate a random number between 0 and 9
    if (rand_num < 8) // If the random number is less than 8 (80% chance)
    {
        printf("No intrusion detected. False alarm! \n");
        return 0;
    }
    else // If the random number is greater than or equal to 8 (20% chance)
    {
        printf("INTRUSION DETECTED!!! \n");
        return 1;
    }
}

/* Main function */
int main()
{
    int intrusion_detected = detect_intrusion(); // Call the function to detect intrusion
    if (intrusion_detected) // If an intrusion is detected
    {
        printf("Sending email alert to admin. \n");
        printf("Sending SMS alert to landlord. \n");
        printf("Activating security cameras. \n");
        printf("Calling 911. \n");
    }
    else // If no intrusion is detected
    {
        printf("No action required. \n");
    }
    return 0;
}