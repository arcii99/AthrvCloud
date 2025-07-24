//FormAI DATASET v1.0 Category: Image Classification system ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784
#define HIDDEN_LAYER_SIZE 16
#define OUTPUT_SIZE 10

float sigmoid(float x) {
     return 1/(1+exp(-x));
}

int main() {
     
     // create input and output arrays
     float input[INPUT_SIZE], hidden_layer[HIDDEN_LAYER_SIZE], output[OUTPUT_SIZE];

     // create weight matrices
     float weights_ih[INPUT_SIZE][HIDDEN_LAYER_SIZE], weights_ho[HIDDEN_LAYER_SIZE][OUTPUT_SIZE];

     // initialize weights with random values between -1 and 1
     for (int i = 0; i < INPUT_SIZE; i++) {
          for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
               weights_ih[i][j] = (float)rand()/(float)(RAND_MAX/2) - 1;
          }
     }
     for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
          for (int j = 0; j < OUTPUT_SIZE; j++) {
               weights_ho[i][j] = (float)rand()/(float)(RAND_MAX/2) - 1;
          }
     }

     // read input image from file
     char* filename = "input_image.txt";
     FILE* fp = fopen(filename, "r");
     if (fp == NULL) {
          printf("Error opening file %s", filename);
          exit(1);
     }
     for (int i = 0; i < INPUT_SIZE; i++) {
          fscanf(fp, "%f", &input[i]);
     }
     fclose(fp);

     // feedforward
     // input → hidden layer
     for (int j = 0; j < HIDDEN_LAYER_SIZE; j++) {
          float sum = 0;
          for (int i = 0; i < INPUT_SIZE; i++) {
               sum += input[i] * weights_ih[i][j];
          }
          hidden_layer[j] = sigmoid(sum);
     }

     // hidden layer → output
     for (int j = 0; j < OUTPUT_SIZE; j++) {
          float sum = 0;
          for (int i = 0; i < HIDDEN_LAYER_SIZE; i++) {
               sum += hidden_layer[i] * weights_ho[i][j];
          }
          output[j] = sigmoid(sum);
     }

     // find max output value
     float max_output = output[0];
     int prediction = 0;
     for (int i = 1; i < OUTPUT_SIZE; i++) {
          if (output[i] > max_output) {
               max_output = output[i];
               prediction = i;
          }
     }

     printf("The image is classified as %d", prediction);
     
     return 0;
}