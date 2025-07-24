//FormAI DATASET v1.0 Category: QR code reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom struct for storing QR data
typedef struct
{
    int id;
    char code[255];
} QR;

int main()
{
    int n, i, j;
    char temp[255];
    QR data[100];

    // Prompt the user for input
    printf("Enter the number of QR codes you want to process: ");
    scanf("%d", &n);

    // Loop through the input
    for (i = 0; i < n; i++)
    {
        printf("Enter QR code %d: ", i + 1);
        scanf("%s", temp);
        printf("QR code %d is %s\n", i + 1, temp);

        // Store the QR data in our struct
        data[i].id = i + 1;
        strcpy(data[i].code, temp);
    }

    // Display the stored QR data
    printf("-----QR Data-----\n");
    for (j = 0; j < n; j++)
    {
        printf("QR code %d: %s\n", data[j].id, data[j].code);
    }

    return 0;
}