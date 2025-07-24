//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1000

int main()
{
    FILE *fp;
    char path[MAX_LEN];
    char ch;
    int total_memory, used_memory;

    fp = popen("free -m", "r"); // Run the "free -m" command and read the output

    if (fp == NULL) // Check if the command ran successfully or not
    {
        printf("Failed to run command\n");
        exit(1);
    }

    printf("Current RAM usage:\n");

    fgets(path, MAX_LEN, fp); // Skip the first line of output
    fgets(path, MAX_LEN, fp);

    // Extract the total memory and used memory from the output
    sscanf(path, "%*s %d %*s %d", &total_memory, &used_memory);

    printf("Total memory: %d MB\n", total_memory);
    printf("Used memory: %d MB\n", used_memory);

    // Calculate and print the percentage of used memory
    printf("Used memory percentage: %.2f%%\n", (float)used_memory/total_memory*100);

    pclose(fp);

    return 0;
}