//FormAI DATASET v1.0 Category: Image Classification system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SIZE 784
#define NUM_CLASSES 10

typedef struct{
    double weights[IMAGE_SIZE][NUM_CLASSES];
    double biases[NUM_CLASSES];
}NeuralNetwork;

double sigmoid(double x){
    return 1 / (1 + exp(-x));
}

int predict(double image[IMAGE_SIZE], NeuralNetwork nn){
    double activations[NUM_CLASSES];
    for(int i = 0; i < NUM_CLASSES; i++){
        activations[i] = 0;
        for(int j = 0; j < IMAGE_SIZE; j++){
            activations[i] += image[j] * nn.weights[j][i];
        }
        activations[i] += nn.biases[i];
        activations[i] = sigmoid(activations[i]);
    }

    int index_of_max = 0;
    double max_value = activations[0];
    for(int i = 1; i < NUM_CLASSES; i++){
        if(activations[i] > max_value){
            max_value = activations[i];
            index_of_max = i;
        }
    }

    return index_of_max;
}

int main(){
    double image[IMAGE_SIZE] = {0};
    NeuralNetwork nn;

    // Load trained weights and biases from file
    FILE* fp = fopen("weights.bin", "rb");
    if(fp == NULL){
        printf("Error opening weights file.\n");
        return 1;
    }
    fread(nn.weights, sizeof(double), IMAGE_SIZE * NUM_CLASSES, fp);
    fread(nn.biases, sizeof(double), NUM_CLASSES, fp);
    fclose(fp);

    int predicted_class = predict(image, nn);
    printf("Predicted class: %d\n", predicted_class);

    return 0;
}