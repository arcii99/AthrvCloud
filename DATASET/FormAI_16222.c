//FormAI DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 100
#define MAX_COMMAND_LENGTH 100

// Configurable options (can be modified by the user)
int brightness = 0;
int contrast = 0;
int saturation = 0;

// Function to read the image file
void read_image(FILE *fp) {
    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
}

// Function to write the image file
void write_image(FILE *fp, char* content) {
    fprintf(fp, "%s", content);
}

// Function to adjust the brightness of the image
void adjust_brightness(char* image) {
    int len = strlen(image);
    for (int i = 0; i < len; i++) {
        if (isdigit(image[i])) {
            int num = image[i] - '0';
            num += brightness;
            if (num < 0) {
                num = 0;
            }
            if (num > 9) {
                num = 9;
            }
            image[i] = num + '0';
        }
    }
}

// Function to adjust the contrast of the image
void adjust_contrast(char* image) {
    int len = strlen(image);
    int min_val = 9;
    int max_val = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(image[i])) {
            int num = image[i] - '0';
            if (num < min_val) {
                min_val = num;
            }
            if (num > max_val) {
                max_val = num;
            }
        }
    }
    int diff = max_val - min_val;
    if (diff == 0) {
        return;
    }
    for (int i = 0; i < len; i++) {
        if (isdigit(image[i])) {
            int num = image[i] - '0';
            num -= min_val;
            num *= (10 / diff);
            num += contrast;
            if (num < 0) {
                num = 0;
            }
            if (num > 9) {
                num = 9;
            }
            image[i] = num + '0';
        }
    }
}

// Function to adjust the saturation of the image
void adjust_saturation(char* image) {
    int len = strlen(image);
    int avg_val = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(image[i])) {
            avg_val += (image[i] - '0');
        }
    }
    avg_val /= len;
    for (int i = 0; i < len; i++) {
        if (isdigit(image[i])) {
            int num = image[i] - '0';
            num += (num - avg_val) * (saturation / 100.0);
            if (num < 0) {
                num = 0;
            }
            if (num > 9) {
                num = 9;
            }
            image[i] = num + '0';
        }
    }
}

int main()
{
    char file_name[MAX_FILE_NAME];
    char command[MAX_COMMAND_LENGTH];
    FILE *fp;

    printf("Enter the image file name: ");
    fgets(file_name, MAX_FILE_NAME, stdin);
    strtok(file_name, "\n");
    
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    read_image(fp);

    while (1) {
        printf("\nEnter command (brightness, contrast, saturation, save, exit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(command, "brightness\n") == 0) {
            printf("Enter brightness value (-100 to 100): ");
            scanf("%d", &brightness);
            getchar(); // clear buffer
            char* image = malloc(MAX_FILE_NAME * sizeof(char));
            fseek(fp, 0, SEEK_SET);
            fgets(image, MAX_FILE_NAME, fp);
            adjust_brightness(image);
            printf("Brightness adjusted.\n");
            printf("%s", image);
            free(image);
        } else if (strcmp(command, "contrast\n") == 0) {
            printf("Enter contrast value (-100 to 100): ");
            scanf("%d", &contrast);
            getchar(); // clear buffer
            char* image = malloc(MAX_FILE_NAME * sizeof(char));
            fseek(fp, 0, SEEK_SET);
            fgets(image, MAX_FILE_NAME, fp);
            adjust_contrast(image);
            printf("Contrast adjusted.\n");
            printf("%s", image);
            free(image);
        } else if (strcmp(command, "saturation\n") == 0) {
            printf("Enter saturation value (-100 to 100): ");
            scanf("%d", &saturation);
            getchar(); // clear buffer
            char* image = malloc(MAX_FILE_NAME * sizeof(char));
            fseek(fp, 0, SEEK_SET);
            fgets(image, MAX_FILE_NAME, fp);
            adjust_saturation(image);
            printf("Saturation adjusted.\n");
            printf("%s", image);
            free(image);
        } else if (strcmp(command, "save\n") == 0) {
            printf("Enter new file name: ");
            fgets(file_name, MAX_FILE_NAME, stdin);
            strtok(file_name, "\n");
            FILE *new_fp = fopen(file_name, "w");
            if (new_fp == NULL) {
                printf("Error creating file\n");
            }
            char* image = malloc(MAX_FILE_NAME * sizeof(char));
            fseek(fp, 0, SEEK_SET);
            fgets(image, MAX_FILE_NAME, fp);
            adjust_brightness(image);
            adjust_contrast(image);
            adjust_saturation(image);
            write_image(new_fp, image);
            fclose(new_fp);
            printf("File saved as %s\n", file_name);
            free(image);
        } else if (strcmp(command, "exit\n") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    fclose(fp);

    return 0;
}