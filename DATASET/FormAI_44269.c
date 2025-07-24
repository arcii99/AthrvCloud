//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Define circuit elements */

#define MAX_ELEMENTS 50
#define MAX_NAME 20

char ELEMENT_LIST[MAX_ELEMENTS][MAX_NAME] = {"resistor", "capacitor", "inductor"};

typedef struct Element {
    char name[MAX_NAME];
    double value;
    double current;
    double voltage;
} Element;

Element circuit[MAX_ELEMENTS];

/* Define circuit functions */

void initialize_circuit() {
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        strcpy(circuit[i].name, "");
        circuit[i].value = 0;
        circuit[i].current = 0;
        circuit[i].voltage = 0;
    }
}

void add_element(char name[], double value) {
    int i = 0;
    while(strcmp(ELEMENT_LIST[i], "") != 0) {
        if(strcmp(ELEMENT_LIST[i], name) == 0) {
            for(int j = 0; j < MAX_ELEMENTS; j++) {
                if(strcmp(circuit[j].name, "") == 0) {
                    strcpy(circuit[j].name, name);
                    circuit[j].value = value;
                    circuit[j].current = 0;
                    circuit[j].voltage = 0;
                    break;
                }
            }
            return;
        }
        else {
            i++;
        }
    }
    printf("Error: invalid element name.\n");
}

void remove_element(char name[]) {
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        if(strcmp(circuit[i].name, name) == 0) {
            strcpy(circuit[i].name, "");
            circuit[i].value = 0;
            circuit[i].current = 0;
            circuit[i].voltage = 0;
            return;
        }
    }
    printf("Error: element not found.\n");
}

void compute_current(double source_voltage) {
    double total_resistance = 0;
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        if(strcmp(circuit[i].name, "") != 0) {
            if(strcmp(circuit[i].name, "resistor") == 0) {
                total_resistance += circuit[i].value;
            }
            else if(strcmp(circuit[i].name, "capacitor") == 0) {
                circuit[i].current = circuit[i].value * source_voltage;
            }
            else if(strcmp(circuit[i].name, "inductor") == 0) {
                circuit[i].current = source_voltage / circuit[i].value;
            }
        }
    }
    double source_current = source_voltage / total_resistance;
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        if(strcmp(circuit[i].name, "") != 0) {
            if(strcmp(circuit[i].name, "resistor") == 0) {
                circuit[i].current = source_current;
            }
        }
    }
}

void compute_voltage(double source_voltage) {
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        if(strcmp(circuit[i].name, "") != 0) {
            if(strcmp(circuit[i].name, "capacitor") == 0) {
                circuit[i].voltage = source_voltage;
            }
            else if(strcmp(circuit[i].name, "inductor") == 0) {
                circuit[i].voltage = circuit[i].current * circuit[i].value;
            }
        }
    }
}

void output_results() {
    printf("Circuit Results:\n");
    for(int i = 0; i < MAX_ELEMENTS; i++) {
        if(strcmp(circuit[i].name, "") != 0) {
            printf("%s - Value: %f, Current: %f, Voltage: %f\n", circuit[i].name, circuit[i].value, circuit[i].current, circuit[i].voltage);
        }
    }
}

int main() {
    printf("Welcome to the paranoid circuit simulator!\n");
    printf("To add an element, enter the element name and value.\n");
    printf("To remove an element, enter 'remove' and then the element name.\n");
    printf("To compute circuit results, enter 'compute'.\n");
    printf("To quit, enter 'quit'.\n");
    initialize_circuit();
    while(1) {
        char input[80];
        printf(">");
        scanf(" %[^\n]", input);
        char *token = strtok(input, " ");
        if(strcmp(token, "add") == 0) {
            char name[MAX_NAME];
            double value;
            token = strtok(NULL, " ");
            strcpy(name, token);
            token = strtok(NULL, " ");
            value = atof(token);
            add_element(name, value);
        }
        else if(strcmp(token, "remove") == 0) {
            char name[MAX_NAME];
            token = strtok(NULL, " ");
            strcpy(name, token);
            remove_element(name);
        }
        else if(strcmp(token, "compute") == 0) {
            double source_voltage;
            printf("Enter source voltage: ");
            scanf("%lf", &source_voltage);
            compute_current(source_voltage);
            compute_voltage(source_voltage);
            output_results();
        }
        else if(strcmp(token, "quit") == 0) {
            printf("Goodbye!");
            break;
        }
        else {
            printf("Error: invalid command.\n");
        }
    }
    return 0;
}