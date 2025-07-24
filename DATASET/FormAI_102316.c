//FormAI DATASET v1.0 Category: Data mining ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_INPUTS 10 // number of inputs
#define NUM_HIDDEN 5 // number of hidden neurons
#define NUM_OUTPUTS 1 // number of outputs
#define ETA 0.05 // learning rate
#define ALPHA 0.9 // momentum factor
#define ERROR_THRESHOLD 0.01 // stopping criteria for training
#define NUM_EPOCHS 1000 // maximum number of training epochs

/* neural network data structure */
typedef struct {
    double **weights_ih; // input to hidden weights
    double **weights_ho; // hidden to output weights
    double *bias_h; // hidden biases
    double *bias_o; // output bias
    double *input; // input layer
    double *hidden; // hidden layer
    double *output; // output layer
    double *delta_h; // hidden layer error
    double *delta_o; // output layer error
} NeuralNet;

/* sigmoid activation function */
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

/* derivative of sigmoid activation function */
double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

/* initialize neural network weights and biases */
void init_neural_net(NeuralNet *net) {
    int i, j;

    /* allocate memory for input to hidden weights */
    net->weights_ih = (double **) calloc(NUM_INPUTS, sizeof(double *));
    for (i = 0; i < NUM_INPUTS; ++i) {
        net->weights_ih[i] = (double *) calloc(NUM_HIDDEN, sizeof(double));
    }

    /* initialize input to hidden weights randomly */
    for (i = 0; i < NUM_INPUTS; ++i) {
        for (j = 0; j < NUM_HIDDEN; ++j) {
            net->weights_ih[i][j] = 2.0 * rand() / RAND_MAX - 1.0;
        }
    }

    /* allocate memory for hidden to output weights */
    net->weights_ho = (double **) calloc(NUM_HIDDEN, sizeof(double *));
    for (i = 0; i < NUM_HIDDEN; ++i) {
        net->weights_ho[i] = (double *) calloc(NUM_OUTPUTS, sizeof(double));
    }

    /* initialize hidden to output weights randomly */
    for (i = 0; i < NUM_HIDDEN; ++i) {
        for (j = 0; j < NUM_OUTPUTS; ++j) {
            net->weights_ho[i][j] = 2.0 * rand() / RAND_MAX - 1.0;
        }
    }

    /* allocate memory for hidden neuron biases */
    net->bias_h = (double *) calloc(NUM_HIDDEN, sizeof(double));

    /* initialize hidden neuron biases randomly */
    for (i = 0; i < NUM_HIDDEN; ++i) {
        net->bias_h[i] = 2.0 * rand() / RAND_MAX - 1.0;
    }

    /* allocate memory for output neuron bias */
    net->bias_o = (double *) calloc(NUM_OUTPUTS, sizeof(double));

    /* initialize output neuron bias randomly */
    for (i = 0; i < NUM_OUTPUTS; ++i) {
        net->bias_o[i] = 2.0 * rand() / RAND_MAX - 1.0;
    }

    /* allocate memory for input, hidden, and output layers */
    net->input = (double *) calloc(NUM_INPUTS, sizeof(double));
    net->hidden = (double *) calloc(NUM_HIDDEN, sizeof(double));
    net->output = (double *) calloc(NUM_OUTPUTS, sizeof(double));

    /* allocate memory for hidden and output layer errors */
    net->delta_h = (double *) calloc(NUM_HIDDEN, sizeof(double));
    net->delta_o = (double *) calloc(NUM_OUTPUTS, sizeof(double));
}

/* free neural network memory */
void free_neural_net(NeuralNet *net) {
    int i;

    /* free memory for input to hidden weights */
    for (i = 0; i < NUM_INPUTS; ++i) {
        free(net->weights_ih[i]);
    }
    free(net->weights_ih);

    /* free memory for hidden to output weights */
    for (i = 0; i < NUM_HIDDEN; ++i) {
        free(net->weights_ho[i]);
    }
    free(net->weights_ho);

    /* free memory for hidden neuron biases */
    free(net->bias_h);

    /* free memory for output neuron bias */
    free(net->bias_o);

    /* free memory for input, hidden, and output layers */
    free(net->input);
    free(net->hidden);
    free(net->output);

    /* free memory for hidden and output layer errors */
    free(net->delta_h);
    free(net->delta_o);
}

/* forward pass through neural network */
void forward_pass(NeuralNet *net) {
    int i, j;

    /* compute hidden layer */
    for (i = 0; i < NUM_HIDDEN; ++i) {
        net->hidden[i] = 0.0;
        for (j = 0; j < NUM_INPUTS; ++j) {
            net->hidden[i] += net->input[j] * net->weights_ih[j][i];
        }
        net->hidden[i] += net->bias_h[i];
        net->hidden[i] = sigmoid(net->hidden[i]);
    }

    /* compute output layer */
    for (i = 0; i < NUM_OUTPUTS; ++i) {
        net->output[i] = 0.0;
        for (j = 0; j < NUM_HIDDEN; ++j) {
            net->output[i] += net->hidden[j] * net->weights_ho[j][i];
        }
        net->output[i] += net->bias_o[i];
        net->output[i] = sigmoid(net->output[i]);
    }
}

/* backpropagation algorithm to update weights and biases */
void backpropagation(NeuralNet *net, double *target) {
    int i, j;

    /* compute output layer error */
    for (i = 0; i < NUM_OUTPUTS; ++i) {
        net->delta_o[i] = (target[i] - net->output[i]) * sigmoid_derivative(net->output[i]);
    }

    /* compute hidden layer error */
    for (i = 0; i < NUM_HIDDEN; ++i) {
        net->delta_h[i] = 0.0;
        for (j = 0; j < NUM_OUTPUTS; ++j) {
            net->delta_h[i] += net->delta_o[j] * net->weights_ho[i][j];
        }
        net->delta_h[i] *= sigmoid_derivative(net->hidden[i]);
    }

    /* update hidden to output weights */
    for (i = 0; i < NUM_HIDDEN; ++i) {
        for (j = 0; j < NUM_OUTPUTS; ++j) {
            double delta_weight = ETA * net->delta_o[j] * net->hidden[i] + ALPHA * net->weights_ho[i][j];
            net->weights_ho[i][j] += delta_weight;
        }
    }

    /* update output bias */
    for (i = 0; i < NUM_OUTPUTS; ++i) {
        double delta_bias = ETA * net->delta_o[i];
        net->bias_o[i] += delta_bias;
    }

    /* update input to hidden weights */
    for (i = 0; i < NUM_INPUTS; ++i) {
        for (j = 0; j < NUM_HIDDEN; ++j) {
            double delta_weight = ETA * net->delta_h[j] * net->input[i] + ALPHA * net->weights_ih[i][j];
            net->weights_ih[i][j] += delta_weight;
        }
    }

    /* update hidden bias */
    for (i = 0; i < NUM_HIDDEN; ++i) {
        double delta_bias = ETA * net->delta_h[i];
        net->bias_h[i] += delta_bias;
    }
}

/* train neural network on data set */
void train_neural_net(NeuralNet *net, double **data, double **targets, int data_size) {
    int i, j, epoch;
    double error;

    /* train neural network for maximum number of epochs */
    for (epoch = 1; epoch <= NUM_EPOCHS; ++epoch) {
        error = 0.0;

        /* train neural network on each data instance */
        for (i = 0; i < data_size; ++i) {
            /* load input and target data */
            for (j = 0; j < NUM_INPUTS; ++j) {
                net->input[j] = data[i][j];
            }
            double target[NUM_OUTPUTS] = { targets[i][0] };

            /* run forward pass through neural network */
            forward_pass(net);

            /* compute error between actual and target output */
            double instance_error = 0.0;
            for (j = 0; j < NUM_OUTPUTS; ++j) {
                double delta = target[j] - net->output[j];
                instance_error += delta * delta;
            }
            instance_error /= NUM_OUTPUTS;

            /* update weights and biases using backpropagation */
            backpropagation(net, target);

            /* add instance error to total error */
            error += instance_error;
        }

        /* compute average error over all data instances */
        error /= data_size;

        /* print current epoch and error */
        printf("Epoch: %d, Error: %f\n", epoch, error);

        /* check if error is below threshold */
        if (error < ERROR_THRESHOLD) {
            printf("Training complete!\n");
            return;
        }
    }

    printf("Maximum number of epochs reached!\n");
}

/* main function */
int main(void) {
    int i;
    double **data = (double **) calloc(1000, sizeof(double *));
    double **targets = (double **) calloc(1000, sizeof(double *));

    /* generate random data set */
    for (i = 0; i < 1000; ++i) {
        data[i] = (double *) calloc(NUM_INPUTS, sizeof(double));
        targets[i] = (double *) calloc(NUM_OUTPUTS, sizeof(double));

        data[i][0] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][1] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][2] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][3] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][4] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][5] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][6] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][7] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][8] = 2.0 * rand() / RAND_MAX - 1.0;
        data[i][9] = 2.0 * rand() / RAND_MAX - 1.0;

        targets[i][0] = sin(data[i][0]) + cos(data[i][1]) - tan(data[i][2]) + atan(data[i][3]) - asin(data[i][4]) - acos(data[i][5]) + sinh(data[i][6]) - cosh(data[i][7]) + tanh(data[i][8]) - atanh(data[i][9]);
    }

    /* initialize neural network */
    NeuralNet net;
    init_neural_net(&net);

    /* train neural network */
    train_neural_net(&net, data, targets, 1000);

    /* free neural network memory */
    free_neural_net(&net);

    /* free data set memory */
    for (i = 0; i < 1000; ++i) {
        free(data[i]);
        free(targets[i]);
    }
    free(data);
    free(targets);

    return 0;
}