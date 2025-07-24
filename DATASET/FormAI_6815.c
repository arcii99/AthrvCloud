//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>

int main()
{
    printf("Welcome to the Checksum Calculator! Let's get started!\n");

    int num, sum = 0, count = 0;

    printf("Enter the number of elements you want to calculate the checksum for: ");
    scanf("%d", &num);

    if(num <= 0)
    {
        printf("Error: Invalid number of elements entered. Goodbye!\n");
        return 0;
    }

    int arr[num];

    // Get elements from user
    for(int i = 0; i < num; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // Calculate checksum
    for(int i = 0; i < num; i++)
    {
        sum += arr[i];
        count++;

        if(count == 5)
        {
            sum += 1;
            count = 0;
        }
    }

    // Display checksum
    printf("The checksum for the given elements is: %d\n", sum);

    printf("Yay! We finished calculating the checksum. Have a nice day!\n");

    return 0;
}