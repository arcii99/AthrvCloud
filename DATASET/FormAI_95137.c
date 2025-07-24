//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate distance between two points
float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    // Initialize constants
    const int num_networks = 5;
    const int range = 10;
    const int min_x = 0;
    const int max_x = 100;
    const int min_y = 0;
    const int max_y = 100;

    // Initialize variables
    int networks[num_networks][2];
    int device_x, device_y;

    // Generate random coordinates for wireless networks
    for (int i = 0; i < num_networks; i++)
    {
        networks[i][0] = rand() % (max_x - min_x + 1) + min_x;
        networks[i][1] = rand() % (max_y - min_y + 1) + min_y;

        // Print coordinates
        printf("Wireless network %d: (%d, %d)\n", i + 1, networks[i][0], networks[i][1]);
    }

    // Generate random coordinates for device
    device_x = rand() % (max_x - min_x + 1) + min_x;
    device_y = rand() % (max_y - min_y + 1) + min_y;

    // Print device coordinates
    printf("\nDevice coordinates: (%d, %d)\n", device_x, device_y);

    // Check if device is within range of any network
    int num_in_range = 0;
    int in_range[num_networks];
    for (int i = 0; i < num_networks; i++)
    {
        if (distance(device_x, device_y, networks[i][0], networks[i][1]) <= range)
        {
            in_range[num_in_range] = i + 1;
            num_in_range++;
        }
    }

    // Print number of networks in range and their IDs
    printf("\n%d wireless networks in range\n", num_in_range);
    printf("Networks in range:");
    for (int i = 0; i < num_in_range; i++)
    {
        printf(" %d", in_range[i]);
    }
    printf("\n");

    return 0;
}