//FormAI DATASET v1.0 Category: Image Classification system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 28*28 // Input size of image
#define OUTPUT_SIZE 10 // Output classes

// Define Neural Net Variables
float weights[INPUT_SIZE][OUTPUT_SIZE];
float biases[OUTPUT_SIZE];

// Define sigmoid function
float sigmoid(float x){
    return 1/(1+exp(-x));
}

// Define forward pass to make predictions
int predict(float* input){
    float output[OUTPUT_SIZE];
    for(int i=0;i<OUTPUT_SIZE;i++){
        output[i] = biases[i];
        for(int j=0;j<INPUT_SIZE;j++){
            output[i] += input[j]*weights[j][i];
        }
        output[i] = sigmoid(output[i]);
    }
    // Get index with highest probability
    int index = 0;
    float max_output = 0;
    for(int i=0;i<OUTPUT_SIZE;i++){
        if(output[i]>max_output){
            max_output = output[i];
            index = i;
        }
    }
    return index;
}

int main(){
    // Let's use random weights and biases for now
    for(int i=0;i<INPUT_SIZE;i++){
        for(int j=0;j<OUTPUT_SIZE;j++){
            weights[i][j] = (float)rand()/RAND_MAX;
        }
    }
    for(int i=0;i<OUTPUT_SIZE;i++){
        biases[i] = (float)rand()/RAND_MAX;
    }

    // Test image data
    float input[INPUT_SIZE];
    for(int i=0;i<INPUT_SIZE;i++){
        input[i] = (float)rand()/RAND_MAX;
    }

    // Make prediction
    int prediction = predict(input);

    // Print prediction
    printf("Prediction: %d",prediction);

    return 0;
}