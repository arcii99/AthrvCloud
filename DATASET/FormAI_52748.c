//FormAI DATASET v1.0 Category: Image Classification system ; Style: grateful
#include <stdio.h>

// Function to classify images based on color
void colorClassification(int r, int g, int b){
    if(r > (g+b)/2){
        printf("The image is predominantly red.\n");
    }
    else if(g > (r+b)/2){
        printf("The image is predominantly green.\n");
    }
    else if(b > (r+g)/2){
        printf("The image is predominantly blue.\n");
    }
    else{
        printf("The image is a mixture of colors.\n");
    }
}

// Function to classify images based on shape
void shapeClassification(int perimeter, int area){
    if(perimeter > 1000 && area > 5000){
        printf("The image is a circle.\n");
    }
    else if(perimeter > 200 && area > 1000){
        printf("The image is a rectangle.\n");
    }
    else if(perimeter > 500 && area > 1000){
        printf("The image is a triangle.\n");
    }
    else{
        printf("The image is of unknown shape.\n");
    }
}

int main(){
    // Example image data
    int red = 200;
    int green = 100;
    int blue = 50;
    int p = 800;
    int a = 3000;

    // Classify image based on color
    colorClassification(red, green, blue);

    // Classify image based on shape
    shapeClassification(p, a);

    return 0;
}