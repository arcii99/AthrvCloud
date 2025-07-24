//FormAI DATASET v1.0 Category: File handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("dream_world.txt", "w+");
    char *dreams[10] = {"I was a tree, swaying in the wind.\n",
                        "I was a bird, soaring through the clouds.\n",
                        "I was a fish, swimming in the depths of the ocean.\n",
                        "I was a flame, flickering in the darkness.\n",
                        "I was a star, shining brightly in the night sky.\n",
                        "I was a cloud, drifting across the horizon.\n",
                        "I was a rock, standing tall and strong.\n",
                        "I was a wave, crashing against the shore.\n",
                        "I was a flower, blooming in the sun.\n",
                        "I was a rainbow, painting the sky with color.\n"};

    if (file == NULL) 
    {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Welcome to the Dream World!\n");

    for (int i = 0; i < 10; i++)
    {
        fputs(dreams[i], file);
    }

    rewind(file);

    printf("Here are some of the dreams you can choose to experience:\n");

    char line[100];

    while (fgets(line, 100, file) != NULL)
    {
        printf("%s", line);
    }

    printf("Which dream would you like to experience?\n");

    char choice[2];

    scanf("%s", choice);

    int index = atoi(choice);

    if (index >= 0 && index < 10)
    {
        printf("You are now experiencing the dream: %s", dreams[index]);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    fclose(file);

    return 0;
}