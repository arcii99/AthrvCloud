//FormAI DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_MENU_ITEMS 5

typedef struct Image
{
    int width;
    int height;
    int** pixels;
} Image;

typedef struct MenuItem
{
    char name[30];
    void (*action)(Image* image);
} MenuItem;

/* Function prototypes */
void load_image(Image* image);
void save_image(Image* image);
void flip_horizontal(Image* image);
void flip_vertical(Image* image);
void grayscale(Image* image);

int main()
{
    Image image;

    // Initialize the image
    image.width = 0;
    image.height = 0;
    image.pixels = NULL;

    // Create menu items
    MenuItem items[MAX_MENU_ITEMS];
    strcpy(items[0].name, "Load image");
    items[0].action = &load_image;

    strcpy(items[1].name, "Save image");
    items[1].action = &save_image;

    strcpy(items[2].name, "Flip horizontal");
    items[2].action = &flip_horizontal;

    strcpy(items[3].name, "Flip vertical");
    items[3].action = &flip_vertical;

    strcpy(items[4].name, "Grayscale");
    items[4].action = &grayscale;

    int option;
    do 
    {
        printf("\nImage Editor\n\n");
        int i;
        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            printf("%d. %s\n", i+1, items[i].name);
        }
        printf("0. Exit\n\n");

        printf("Enter option: ");
        scanf("%d", &option);

        if (option >= 1 && option <= MAX_MENU_ITEMS)
        {
            printf("\n");
            (*items[option-1].action)(&image);
        } 
        else if (option == 0)
        {
            printf("\nExiting program...");
        } 
        else 
        {
            printf("\nInvalid option.");
        }
    } while (option != 0);

    // Free allocated memory before exiting
    int i;
    for (i = 0; i < image.height; i++)
    {
        free(image.pixels[i]);
    }
    free(image.pixels);

    return 0;
}

void load_image(Image* image)
{
    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter file name: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("\nError: could not open file.\n");
        return;
    }

    // Read image dimensions from file
    fscanf(file, "%d %d", &image->width, &image->height);

    // Allocate memory for pixel array
    image->pixels = (int**)malloc(image->height * sizeof(int*));
    int i;
    for (i = 0; i < image->height; i++)
    {
        image->pixels[i] = (int*)malloc(image->width * sizeof(int));
    }

    // Read pixel values from file
    int j;
    for (i = 0; i < image->height; i++)
    {
        for (j = 0; j < image->width; j++)
        {
            fscanf(file, "%d", &image->pixels[i][j]);
        }
    }

    fclose(file);

    printf("\nImage loaded.\n");
}

void save_image(Image* image)
{
    if (image->pixels == NULL)
    {
        printf("\nError: no image loaded.\n");
        return;
    }

    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter file name: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "w");

    // Write image dimensions to file
    fprintf(file, "%d %d\n", image->width, image->height);

    // Write pixel values to file
    int i, j;
    for (i = 0; i < image->height; i++)
    {
        for (j = 0; j < image->width; j++)
        {
            fprintf(file, "%d ", image->pixels[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("\nImage saved.\n");
}

void flip_horizontal(Image* image)
{
    if (image->pixels == NULL)
    {
        printf("\nError: no image loaded.\n");
        return;
    }

    int i, j;
    for (i = 0; i < image->height; i++)
    {
        for (j = 0; j < image->width / 2; j++)
        {
            int temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->width - j - 1];
            image->pixels[i][image->width - j - 1] = temp;
        }
    }

    printf("\nImage flipped horizontally.\n");
}

void flip_vertical(Image* image)
{
    if (image->pixels == NULL)
    {
        printf("\nError: no image loaded.\n");
        return;
    }

    int i, j;
    for (i = 0; i < image->height / 2; i++)
    {
        for (j = 0; j < image->width; j++)
        {
            int temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[image->height - i - 1][j];
            image->pixels[image->height - i - 1][j] = temp;
        }
    }

    printf("\nImage flipped vertically.\n");
}

void grayscale(Image* image)
{
    if (image->pixels == NULL)
    {
        printf("\nError: no image loaded.\n");
        return;
    }

    int i, j;
    for (i = 0; i < image->height; i++)
    {
        for (j = 0; j < image->width; j++)
        {
            int r = (image->pixels[i][j] >> 16) & 0xff;
            int g = (image->pixels[i][j] >> 8) & 0xff;
            int b = image->pixels[i][j] & 0xff;

            int gray = (r + g + b) / 3;

            image->pixels[i][j] = (gray << 16) | (gray << 8) | gray;
        }
    }

    printf("\nImage converted to grayscale.\n");
}