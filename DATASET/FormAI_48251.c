//FormAI DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    char f_name[20], ext[5];
    printf("Enter file name: ");
    scanf("%s", f_name);
    printf("Enter file type (jpg/png/bmp): ");
    scanf("%s", ext);

    char f_fullname[30];
    sprintf(f_fullname, "%s.%s", f_name, ext);

    FILE *fptr = fopen(f_fullname, "rb");
    if (!fptr) {
        printf("Error opening file!\n");
        return 1;
    }

    unsigned char header[54]; // bitmap header
    fread(header, sizeof(unsigned char), 54, fptr);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int row_padding = (4 - (width * sizeof(pixel)) % 4) % 4; // to pad each row to 4 bytes

    int row_size = width * sizeof(pixel) + row_padding;
    int pixel_buf_size = row_size * height;

    pixel *pixel_buf = malloc(pixel_buf_size);
    fread(pixel_buf, sizeof(pixel), width * height, fptr);
    fclose(fptr);

    while (1) {
        printf("\n1. Invert colors");
        printf("\n2. Grayscale");
        printf("\n3. Rotate right");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < width * height; i++) {
                    pixel_buf[i].r = ~pixel_buf[i].r;
                    pixel_buf[i].g = ~pixel_buf[i].g;
                    pixel_buf[i].b = ~pixel_buf[i].b;
                }
                break;
            case 2:
                for (int i = 0; i < width * height; i++) {
                    unsigned char gray = (pixel_buf[i].r + pixel_buf[i].g + pixel_buf[i].b) / 3;
                    pixel_buf[i].r = gray;
                    pixel_buf[i].g = gray;
                    pixel_buf[i].b = gray;
                }
                break;
            case 3:
                pixel *new_pixel_buf = malloc(pixel_buf_size);
                for (int y = 0; y < height; y++) {
                    for (int x = 0; x < width; x++) {
                        int old_idx = y * row_size + x * sizeof(pixel);
                        int new_idx = (width - x - 1) * row_size + y * sizeof(pixel);
                        new_pixel_buf[new_idx] = pixel_buf[old_idx];
                    }
                }
                memcpy(pixel_buf, new_pixel_buf, pixel_buf_size); // replace old buffer with new buffer
                free(new_pixel_buf);
                int temp = width;
                width = height;
                height = temp;
                break;
            case 4:
                free(pixel_buf);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // save modified image to file
        char output_name[30];
        sprintf(output_name, "output_%d.%s", choice, ext);
        FILE *out = fopen(output_name, "wb");
        fwrite(header, sizeof(unsigned char), 54, out);
        fwrite(pixel_buf, sizeof(pixel), width * height, out);
        fclose(out);
    }
}