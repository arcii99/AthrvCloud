//FormAI DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>

int main () {

   int image1[][3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}};
   int image2[][3] = {{255, 255, 0}, {0, 255, 255}, {255, 0, 255}};
   int image3[][3] = {{255, 255, 255}, {0, 0, 0}, {128, 128, 128}};

   int image_class;
   
   // Classify the images based on their color
   if (image1[0][0] == 255 && image1[1][1] == 255 && image1[2][2] == 255) {
      image_class = 1;
   } else if (image2[0][1] == 255 && image2[1][0] == 0 && image2[2][2] == 255) {
      image_class = 2;
   } else if (image3[0][0] == 255 && image3[1][1] == 0 && image3[2][2] == 128) {
      image_class = 3;
   } else {
      image_class = 0;
   }
   
   switch (image_class) {
      case 1 :
         printf("Image 1 is the class of red, green and blue.\n");
         break;
      case 2 :
         printf("Image 2 is the class of yellow, cyan and magenta.\n");
         break;
      case 3 :
         printf("Image 3 is the class of white, black and gray.\n");
         break;
      default :
         printf("Image class not recognized.\n");
   }

   return 0;
}