//FormAI DATASET v1.0 Category: Image Classification system ; Style: minimalist
#include <stdio.h>

typedef struct {
   unsigned char red;
   unsigned char green;
   unsigned char blue;
} Pixel;

int main() {
   Pixel image[4][4] = {{{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}},
                         {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}},
                         {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}},
                         {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}}};
                         
   int red_count = 0;
   int green_count = 0;
   int blue_count = 0;
   
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         if (image[i][j].red > image[i][j].green && image[i][j].red > image[i][j].blue) {
            red_count++;
         } else if (image[i][j].green > image[i][j].red && image[i][j].green > image[i][j].blue) {
            green_count++;
         } else if (image[i][j].blue > image[i][j].red && image[i][j].blue > image[i][j].green) {
            blue_count++;
         }
      }
   }
   
   printf("Red pixel count: %d\n", red_count);
   printf("Green pixel count: %d\n", green_count);
   printf("Blue pixel count: %d\n", blue_count);

   return 0;
}