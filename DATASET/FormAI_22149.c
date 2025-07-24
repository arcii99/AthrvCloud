//FormAI DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char input[100];
   printf("Please enter the image filename: ");
   fgets(input,100,stdin);

   if (strstr(input, ".jpg") || strstr(input, ".jpeg") || strstr(input, ".png")) {
        printf("Image format recognized. Starting classification process...\n");
        // more code to process the image and classify here
   }
   else {
        printf("Invalid image format. Please enter a valid .jpg, .jpeg, or .png file.\n");
        main(); // recall the function to prompt the user for a valid file
   }

   return 0;
}