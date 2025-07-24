//FormAI DATASET v1.0 Category: Image compression ; Style: sophisticated
#include <stdio.h>
int main()
{
    FILE *fptr_in, *fptr_out;
    int pixel[128][128];
    int i, j, x, y, width, height;
    char file[20];
    printf("Enter the file name to compress: ");
    scanf("%s", file);
    fptr_in = fopen(file, "r");
    if (fptr_in == NULL)
    {
        printf("Error: File not found\n");
        fclose(fptr_in);
        return 0;
    }
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);
    printf("Compressing the image...\n");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fscanf(fptr_in, "%d", &pixel[i][j]);
        }
    }
    fclose(fptr_in);
    fptr_out = fopen("compressed.txt", "w");
    for (i = 0; i < height; i += 2)
    {
        for (j = 0; j < width; j += 2)
        {
            int average = (pixel[i][j] + pixel[i][j + 1] + pixel[i + 1][j] + pixel[i + 1][j + 1]) / 4;
            fprintf(fptr_out, "%d ", average);
        }
        fprintf(fptr_out, "\n");
    }
    fclose(fptr_out);
    printf("Compression complete. Compressed file saved as compressed.txt\n");
    return 0;
}