//FormAI DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

#define NUM_CLASSES 10
#define NUM_FEATURES 784

// Struct to store image data
typedef struct Image{
    int class;
    float features[NUM_FEATURES];
}Image;

// Function to read image data from file (in paranoid style)
int read_image(Image* img, FILE* fp){
    int i, num_features, num_read;
    unsigned char label;

    // Make sure file is not corrupted or tampered with
    if(fread(&label, sizeof(unsigned char), 1, fp) != 1){
        printf("Error reading image label\n");
        return -1;
    }

    // Check sanity of image data
    if((label < 0) || (label >= NUM_CLASSES)){
        printf("Invalid image label\n");
        return -1;
    }

    img->class = (int)label;

    num_features = NUM_FEATURES;
    while(num_features > 0){
        num_read = fread(&(img->features[NUM_FEATURES - num_features]), sizeof(float), num_features, fp);
        num_features -= num_read;
        if(num_read == 0){
            printf("Error reading image features\n");
            return -1;
        }
    }

    return 0;
}

// Function to classify image data
int classify_image(Image* img){
    int i, j, class;
    float max_prob, prob, class_probs[NUM_CLASSES];

    // Compute probabilities for each class using paranoid style algorithm
    for(i = 0; i < NUM_CLASSES; i++){
        class_probs[i] = 1.0;
        for(j = 0; j < NUM_FEATURES; j++){
            // Avoid underflow by taking log of probabilities
            prob = (1.0 + img->features[j]) / 2.0;
            prob = log(prob);
            class_probs[i] += prob;
        }
    }

    // Find class with highest probability
    max_prob = class_probs[0];
    class = 0;
    for(i = 1; i < NUM_CLASSES; i++){
        if(class_probs[i] > max_prob){
            max_prob = class_probs[i];
            class = i;
        }
    }

    // Return predicted class
    return class;
}

int main(){
    FILE* fp;
    Image img;
    int class;

    fp = fopen("image.bin", "rb");

    // Ensure file is not corrupted or tampered with
    if(fp == NULL){
        printf("Error opening image file\n");
        return -1;
    }

    // Read image data from file
    if(read_image(&img, fp) != 0){
        fclose(fp);
        return -1;
    }

    // Classify image data
    class = classify_image(&img);

    // Check if classification is valid
    if((class < 0) || (class >= NUM_CLASSES)){
        printf("Invalid classification\n");
        fclose(fp);
        return -1;
    }

    printf("Image classified as %d.\n", class);

    fclose(fp);
    return 0;
}