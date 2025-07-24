//FormAI DATASET v1.0 Category: Image Classification system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 10
#define IMAGE_SIZE 784
#define NUM_HIDDEN_NODES 256

float hidden[NUM_HIDDEN_NODES];
float output[NUM_CLASSES];

float weights1[NUM_HIDDEN_NODES][IMAGE_SIZE];
float weights2[NUM_CLASSES][NUM_HIDDEN_NODES];

float input[IMAGE_SIZE];
int label;

//Function to initialize the network's weights
void init_weights(){
    for(int i=0; i<NUM_HIDDEN_NODES; i++){
        for(int j=0; j<IMAGE_SIZE; j++){
            weights1[i][j] = (rand()/(double)(RAND_MAX)) - 0.5;
        }
    }
    for(int i=0; i<NUM_CLASSES; i++){
        for(int j=0; j<NUM_HIDDEN_NODES; j++){
            weights2[i][j] = (rand()/(double)(RAND_MAX)) - 0.5;
        }
    }
}

//Function to feed forward through the network
void feed_forward(){
    //Calculating the hidden layer activations
    for(int i=0; i<NUM_HIDDEN_NODES; i++){
        hidden[i] = 0;
        for(int j=0; j<IMAGE_SIZE; j++){
            hidden[i] += weights1[i][j] * input[j];
        }
        hidden[i] = 1 / (1 + exp(-hidden[i]));
    }

    //Calculating the output layer activations
    for(int i=0; i<NUM_CLASSES; i++){
        output[i] = 0;
        for(int j=0; j<NUM_HIDDEN_NODES; j++){
            output[i] += weights2[i][j] * hidden[j];
        }
        output[i] = exp(output[i]);
    }
}

//Function to train the network using backpropagation
void train(float learning_rate){
    //Calculating the error at the output layer
    float error[NUM_CLASSES];
    for(int i=0; i<NUM_CLASSES; i++){
        error[i] = (label == i) ? (1 - output[i]) : (0 - output[i]);
    }

    //Calculating the error at the hidden layer and updating the weights
    for(int i=0; i<NUM_HIDDEN_NODES; i++){
        float delta = 0;
        for(int j=0; j<NUM_CLASSES; j++){
            delta += error[j] * weights2[j][i];
        }
        delta *= hidden[i] * (1 - hidden[i]);

        for(int j=0; j<IMAGE_SIZE; j++){
            weights1[i][j] += (learning_rate * delta * input[j]);
        }
    }

    //Updating the weights at the output layer
    for(int i=0; i<NUM_CLASSES; i++){
        for(int j=0; j<NUM_HIDDEN_NODES; j++){
            weights2[i][j] += (learning_rate * error[i] * hidden[j]);
        }
    }
}

int main(){
    //Initializing the weights
    init_weights();

    //Reading the dataset
    int num_examples;
    scanf("%d", &num_examples);

    for(int i=0; i<num_examples; i++){
        for(int j=0; j<IMAGE_SIZE; j++){
            scanf("%f", &input[j]);
        }
        scanf("%d", &label);

        //Feeding forward and backpropagating to train the network
        feed_forward();
        train(0.1);
    }

    //Testing the network on a sample image
    for(int i=0; i<IMAGE_SIZE; i++){
        scanf("%f", &input[i]);
    }
    feed_forward();

    //Printing the output of the network
    printf("Output: ");
    for(int i=0; i<NUM_CLASSES; i++){
        printf("%f ", output[i]);
    }

    return 0;
}