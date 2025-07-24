//FormAI DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 50
#define MAX_CHARS_PER_COL 20

int main()
{
    // Declare variables for CSV parsing
    char filename[] = "data.csv";
    char buffer[MAX_ROW * MAX_COL * MAX_CHARS_PER_COL];
    char *tokens[MAX_ROW][MAX_COL];

    // Read the CSV file and parse the data
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }
    fgets(buffer, MAX_ROW * MAX_COL * MAX_CHARS_PER_COL, file);
    int row = 0;
    while(fgets(buffer, MAX_ROW * MAX_COL * MAX_CHARS_PER_COL, file))
    {
        char *token = strtok(buffer, ",");
        int col = 0;
        while(token != NULL)
        {
            tokens[row][col] = token;
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }
    fclose(file);

    // Extract and process the data
    float prices[MAX_ROW], total = 0;
    int quantity[MAX_ROW], count = 0;
    for(int i = 0; i < row; i++)
    {
        prices[i] = atof(tokens[i][1]); // Convert the price to float
        quantity[i] = atoi(tokens[i][2]); // Convert the quantity to integer
        total += prices[i] * quantity[i]; // Calculate the total cost
        if(prices[i] > 10) // Find expensive items
        {
            printf("Warning: Item '%s' is expensive!\n", tokens[i][0]);
            count++;
        }
    }
    printf("Total cost: $%.2f\n", total);
    printf("%d items are expensive.\n", count);

    return 0;
}