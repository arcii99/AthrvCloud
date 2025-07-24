//FormAI DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define NUM_IMAGES 100
#define NUM_CLASSES 10

float images[NUM_IMAGES][784] = {0}; // 100 images of size 28x28
int labels[NUM_IMAGES] = {0}; // labels of each image

void extract_features(float image[784], float features[784]) {
    // Paranoid feature extraction function
    // Ensures no malicious code is hidden in the image pixels
    
    for(int i = 0; i < 784; i++) {
        if(image[i] < 0 || image[i] > 1) {
            printf("ERROR: Image pixel out of range!\n");
            exit(1);
        }
        
        if((int)image[i] != 0 && (int)image[i] != 1) {
            printf("ERROR: Image pixel not a binary value!\n");
            exit(1);
        }
        
        features[i] = image[i]; // Copy valid pixels to features array
    }
}

int classify(float features[784], float weights[NUM_CLASSES][784]) {
    // Paranoid classification function
    // Uses machine learning weights to classify image
    // Ensures no tampering with the weights or features array
    
    float scores[NUM_CLASSES] = {0};
    
    for(int i = 0; i < NUM_CLASSES; i++) {
        for(int j = 0; j < 784; j++) {
            if(weights[i][j] < -1 || weights[i][j] > 1) { 
                printf("ERROR: Weight out of range!\n");
                exit(1);
            }
            
            if((int)weights[i][j] != 0 && (int)weights[i][j] != 1) {
                printf("ERROR: Non-binary weight value!\n");
                exit(1);
            }
            
            scores[i] += features[j] * weights[i][j]; // Compute score while checking weight validity
        }
    }
    
    int max_score_index = 0;
    float max_score = scores[0];
    
    for(int i = 1; i < NUM_CLASSES; i++) {
        if(scores[i] > max_score) {
            max_score = scores[i];
            max_score_index = i;
        }
    }
    
    return max_score_index;
}

int main() {
    
    // In a paranoid system, we cannot trust external data sources
    // So we generate our own data for testing
    for(int i = 0; i < NUM_IMAGES; i++) {
        for(int j = 0; j < 784; j++) {
            images[i][j] = (float)rand() / (float)RAND_MAX; // Random image pixel values between 0 and 1
        }
        
        labels[i] = rand() % NUM_CLASSES; // Random label between 0 and NUM_CLASSES-1
    }
    
    // In a paranoid system, we cannot trust external machine learning models
    // So we train our own model using the generated data
    float weights[NUM_CLASSES][784] = {0};
    
    for(int iter = 0; iter < 1000; iter++) {
        for(int i = 0; i < NUM_IMAGES; i++) {
            
            float features[784] = {0};
            extract_features(images[i], features);
            
            int true_class = labels[i];
            
            for(int j = 0; j < NUM_CLASSES; j++) {
                float loss = (j == true_class) - classify(features, weights);
                for(int k = 0; k < 784; k++) {
                    weights[j][k] += loss * features[k];
                }
            }
        }
    }
    
    // Testing the paranoid system is not easy, because we don't trust external inputs
    // So we generate a new set of images for testing
    float test_images[NUM_IMAGES][784] = {0};
    int test_labels[NUM_IMAGES] = {0};
    
    for(int i = 0; i < NUM_IMAGES; i++) {
        for(int j = 0; j < 784; j++) {
            test_images[i][j] = (float)rand() / (float)RAND_MAX; // Random image pixel values between 0 and 1
        }
        
        test_labels[i] = rand() % NUM_CLASSES; // Random label between 0 and NUM_CLASSES-1
    }
    
    // Testing our paranoid model using the generated test data
    int correct = 0;
    for(int i = 0; i < NUM_IMAGES; i++) {
        
        float features[784] = {0};
        extract_features(test_images[i], features);
        
        int predicted_class = classify(features, weights);
        if(predicted_class == test_labels[i]) {
            correct++;
        }
    }
    
    printf("%d out of %d test images classified correctly.\n", correct, NUM_IMAGES);
    
    return 0;
}