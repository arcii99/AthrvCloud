//FormAI DATASET v1.0 Category: Image Editor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME 100
#define MAX_PIXEL_VALUE 255

typedef struct {
  int width;
  int height;
  int** pixels;
} Image;

// Function prototypes
bool is_valid_pixel_value(int pixel_value);
void free_image(Image* image);
void swap_pixel_values(int* p1, int* p2);
Image* create_image(int width, int height, int** pixels);
Image* load_image(const char* file_name);
bool save_image(const char* file_name, Image* image);
Image* grayscale_image(Image* image);
Image* invert_colors(Image* image);
Image* flip_image_horizontally(Image* image);
Image* flip_image_vertically(Image* image);
Image* rotate_image_cw(Image* image);
Image* rotate_image_ccw(Image* image);

int main() {
  printf("Welcome to the C Image Editor!\n");
  printf("Please enter the name of the file you would like to edit:\n");

  char file_name[MAX_FILE_NAME];
  scanf("%s", file_name);

  Image* original_image = load_image(file_name);

  if (original_image == NULL) {
    printf("Error: could not load image from file %s\n", file_name);
    return 1;
  }

  printf("Loaded image successfully!\n");
  printf("Please choose an editing option:\n");
  printf("1. Grayscale\n");
  printf("2. Invert colors\n");
  printf("3. Flip horizontally\n");
  printf("4. Flip vertically\n");
  printf("5. Rotate clockwise\n");
  printf("6. Rotate counterclockwise\n");

  int choice;
  scanf("%d", &choice);

  Image* edited_image;

  switch(choice) {
    case 1:
      edited_image = grayscale_image(original_image);
      break;
    case 2:
      edited_image = invert_colors(original_image);
      break;
    case 3:
      edited_image = flip_image_horizontally(original_image);
      break;
    case 4:
      edited_image = flip_image_vertically(original_image);
      break;
    case 5:
      edited_image = rotate_image_cw(original_image);
      break;
    case 6:
      edited_image = rotate_image_ccw(original_image);
      break;
    default:
      printf("Invalid choice, program will exit.\n");
      free_image(original_image);
      return 1;
  }

  printf("Done editing! Please enter a name for your new file:\n");

  char new_file_name[MAX_FILE_NAME];
  scanf("%s", new_file_name);

  bool saved = save_image(new_file_name, edited_image);

  if (saved) {
    printf("New file saved successfully!\n");
  } else {
    printf("Error: could not save new file, program will exit.\n");
    free_image(original_image);
    free_image(edited_image);
    return 1;
  }

  free_image(original_image);
  free_image(edited_image);
  return 0;
}

bool is_valid_pixel_value(int pixel_value) {
  return pixel_value >= 0 && pixel_value <= MAX_PIXEL_VALUE;
}

void free_image(Image* image) {
  for (int i = 0; i < image->height; i++) {
    free(image->pixels[i]);
  }

  free(image->pixels);
  free(image);
}

void swap_pixel_values(int* p1, int* p2) {
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

Image* create_image(int width, int height, int** pixels) {
  Image* image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = pixels;
  return image;
}

Image* load_image(const char* file_name) {
  FILE* file = fopen(file_name, "r");

  if (file == NULL) {
    return NULL;
  }

  int width, height, max_value;
  fscanf(file, "P2\n%d %d\n%d\n", &width, &height, &max_value);

  int** pixels = malloc(sizeof(int*) * height);

  for (int i = 0; i < height; i++) {
    pixels[i] = malloc(sizeof(int) * width);
    for (int j = 0; j < width; j++) {
      int pixel_value;
      fscanf(file, "%d", &pixel_value);
      if (!is_valid_pixel_value(pixel_value)) {
        return NULL;
      }
      pixels[i][j] = pixel_value;
    }
  }

  fclose(file);
  Image* image = create_image(width, height, pixels);
  return image;
}

bool save_image(const char* file_name, Image* image) {
  FILE* file = fopen(file_name, "w");

  if (file == NULL) {
    return false;
  }

  int max_value = MAX_PIXEL_VALUE;

  fprintf(file, "P2\n%d %d\n%d\n", image->width, image->height, max_value);

  for (int i = 0; i < image->height; i++) {
    for (int j = 0; j < image->width; j++) {
      fprintf(file, "%d ", image->pixels[i][j]);
    }
    fprintf(file, "\n");
  }

  fclose(file);
  return true;
}

Image* grayscale_image(Image* image) {
  int width = image->width;
  int height = image->height;
  int** pixels = malloc(sizeof(int*) * height);

  for (int i = 0; i < height; i++) {
    pixels[i] = malloc(sizeof(int) * width);
    for (int j = 0; j < width; j++) {
      int pixel_value = image->pixels[i][j];
      int grayscale_value = 0.3 * pixel_value + 0.59 * pixel_value + 0.11 * pixel_value;
      pixels[i][j] = grayscale_value;
    }
  }

  Image* new_image = create_image(width, height, pixels);
  return new_image;
}

Image* invert_colors(Image* image) {
  int width = image->width;
  int height = image->height;
  int** pixels = malloc(sizeof(int*) * height);

  for (int i = 0; i < height; i++) {
    pixels[i] = malloc(sizeof(int) * width);
    for (int j = 0; j < width; j++) {
      int pixel_value = image->pixels[i][j];
      int inverted_value = MAX_PIXEL_VALUE - pixel_value;
      pixels[i][j] = inverted_value;
    }
  }

  Image* new_image = create_image(width, height, pixels);
  return new_image;
}

Image* flip_image_horizontally(Image* image) {
  int width = image->width;
  int height = image->height;
  int** pixels = malloc(sizeof(int*) * height);

  for (int i = 0; i < height; i++) {
    pixels[i] = malloc(sizeof(int) * width);
    for (int j = 0; j < width; j++) {
      int pixel_value = image->pixels[i][j];
      pixels[i][width - j - 1] = pixel_value;
    }
  }

  Image* new_image = create_image(width, height, pixels);
  return new_image;
}

Image* flip_image_vertically(Image* image) {
  int width = image->width;
  int height = image->height;
  int** pixels = malloc(sizeof(int*) * height);

  for (int i = 0; i < height; i++) {
    pixels[height - i - 1] = malloc(sizeof(int) * width);
    for (int j = 0; j < width; j++) {
      int pixel_value = image->pixels[i][j];
      pixels[height - i - 1][j] = pixel_value;
    }
  }

  Image* new_image = create_image(width, height, pixels);
  return new_image;
}

Image* rotate_image_cw(Image* image) {
  int width = image->width;
  int height = image->height;
  int** pixels = malloc(sizeof(int*) * width);

  for (int i = 0; i < width; i++) {
    pixels[i] = malloc(sizeof(int) * height);
    for (int j = 0; j < height; j++) {
      int pixel_value = image->pixels[height - j - 1][i];
      pixels[i][j] = pixel_value;
    }
  }

  Image* new_image = create_image(height, width, pixels);
  return new_image;
}

Image* rotate_image_ccw(Image* image) {
  int width = image->width;
  int height = image->height;
  int** pixels = malloc(sizeof(int*) * width);

  for (int i = 0; i < width; i++) {
    pixels[i] = malloc(sizeof(int) * height);
    for (int j = 0; j < height; j++) {
      int pixel_value = image->pixels[j][width - i - 1];
      pixels[i][j] = pixel_value;
    }
  }

  Image* new_image = create_image(height, width, pixels);
  return new_image;
}