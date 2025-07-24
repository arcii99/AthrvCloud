//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: all-encompassing
/*
* This program is a classical circuit simulator that allows users to create 
* circuits with resistors, capacitors, and inductors. The program uses circuit laws 
* such as Kirchhoff's laws and Ohm's law to solve for the voltage and current in each 
* component of the circuit. The user can also simulate various circuit parameters such as 
* frequency response, phase shift, and time-domain response. 
*/

#include <stdio.h>
#include <math.h>

#define MAX_COMPONENTS 20
#define PI 3.14159265358979323846

struct Component{
    char type;
    double value;
    int node1;
    int node2;
};

struct Circuit{
    int num_components;
    struct Component components[MAX_COMPONENTS];
};

void simulate_frequency_response(struct Circuit* circuit, double min_freq, double max_freq, int num_points){
    double frequency_step = (max_freq - min_freq)/(num_points - 1);
    double current_frequency = min_freq;
    for(int i = 0; i < num_points; i++){
        printf("Frequency: %f Hz\n", current_frequency);
        simulate(circuit, current_frequency);
        current_frequency += frequency_step;
    }
}

void simulate_time_domain_response(struct Circuit* circuit, double end_time, double time_step){
    double current_time = 0;
    while(current_time <= end_time){
        printf("Time: %f seconds\n", current_time);
        simulate(circuit, -1);
        current_time += time_step;
    }
}

void simulate(struct Circuit* circuit, double frequency){
    int num_nodes = get_num_nodes(circuit);
    double conductance_matrix[num_nodes][num_nodes];
    double current_sources[num_nodes];
    double voltage_sources[num_nodes];
    double node_voltages[num_nodes];

    // Initialize matrices and vectors
    for(int i = 0; i < num_nodes; i++){
        for(int j = 0; j < num_nodes; j++){
            conductance_matrix[i][j] = 0;
        }
        current_sources[i] = 0;
        voltage_sources[i] = 0;
        node_voltages[i] = 0;
    }

    // Set up circuit equations
    for(int i = 0; i < circuit->num_components; i++){
        struct Component component = circuit->components[i];
        double admittance;

        if(component.type == 'R'){
            admittance = 1/component.value;
            conductance_matrix[component.node1-1][component.node1-1] += admittance;
            conductance_matrix[component.node2-1][component.node2-1] += admittance;
            conductance_matrix[component.node1-1][component.node2-1] -= admittance;
            conductance_matrix[component.node2-1][component.node1-1] -= admittance;
        }

        else if(component.type == 'C'){
            if(frequency == 0){
                printf("Error: Cannot simulate capacitor with 0 frequency.");
                return;
            }
            admittance = 2*PI*frequency*component.value;
            conductance_matrix[component.node1-1][component.node1-1] += admittance;
            conductance_matrix[component.node2-1][component.node2-1] += admittance;
            conductance_matrix[component.node1-1][component.node2-1] -= admittance;
            conductance_matrix[component.node2-1][component.node1-1] -= admittance;
        }

        else if(component.type == 'L'){
            if(frequency == 0){
                printf("Error: Cannot simulate inductor with 0 frequency.");
                return;
            }
            admittance = 1/(2*PI*frequency*component.value);
            conductance_matrix[component.node1-1][component.node1-1] += admittance;
            conductance_matrix[component.node2-1][component.node2-1] += admittance;
            conductance_matrix[component.node1-1][component.node2-1] -= admittance;
            conductance_matrix[component.node2-1][component.node1-1] -= admittance;
        }

        else if(component.type == 'V'){
            voltage_sources[component.node2-1] -= component.value;
            voltage_sources[component.node1-1] += component.value;
        }

        else if(component.type == 'I'){
            current_sources[component.node1-1] -= component.value;
            current_sources[component.node2-1] += component.value;
        }
    }

    // Solve for node voltages
    for(int i = 0; i < num_nodes - 1; i++){ // Solve all but the last node
        for(int j = i + 1; j < num_nodes; j++){
            double ratio = conductance_matrix[j][i]/conductance_matrix[i][i];
            for(int k = i; k < num_nodes; k++){
                conductance_matrix[j][k] -= ratio*conductance_matrix[i][k];
            }
            current_sources[j] -= ratio*current_sources[i];
            voltage_sources[j] -= ratio*voltage_sources[i];
        }
    }

    node_voltages[num_nodes-1] = voltage_sources[num_nodes-1]/conductance_matrix[num_nodes-1][num_nodes-1]; // Solve for last node

    for(int i = num_nodes - 2; i >= 0; i--){ // Back-substitute to solve for all other node voltages
        double sum = 0;
        for(int j = i + 1; j < num_nodes; j++){
            sum += conductance_matrix[i][j]*node_voltages[j];
        }
        node_voltages[i] = (voltage_sources[i] - current_sources[i] - sum)/conductance_matrix[i][i];
    }

    // Print out results
    for(int i = 0; i < num_nodes; i++){
        printf("Node %d voltage: %f V\n", i+1, node_voltages[i]);
    }

    for(int i = 0; i < circuit->num_components; i++){
        struct Component component = circuit->components[i];
        if(component.type == 'R'){
            double voltage_drop = node_voltages[component.node1-1] - node_voltages[component.node2-1];
            printf("Resistor %d current: %f A\n", i+1, voltage_drop/component.value);
        }
        else if(component.type == 'C'){
            double current = -2*PI*frequency*component.value*(node_voltages[component.node1-1] - node_voltages[component.node2-1]);
            printf("Capacitor %d current: %f A\n", i+1, current);
        }
        else if(component.type == 'L'){
            double current = (node_voltages[component.node1-1] - node_voltages[component.node2-1])/(2*PI*frequency*component.value);
            printf("Inductor %d current: %f A\n", i+1, current);
        }
        else if(component.type == 'V'){
            printf("Voltage source %d current: %f A\n", i+1, component.value);
        }
        else if(component.type == 'I'){
            printf("Current source %d current: %f A\n", i+1, component.value);
        }
    }
}

int get_num_nodes(struct Circuit* circuit){
    int max_node = 0;
    for(int i = 0; i < circuit->num_components; i++){
        if(circuit->components[i].node1 > max_node){
            max_node = circuit->components[i].node1;
        }
        if(circuit->components[i].node2 > max_node){
            max_node = circuit->components[i].node2;
        }
    }
    return max_node;
}

int main(){
    struct Circuit circuit;
    circuit.num_components = 0;

    // Example circuit with one resistor and one voltage source
    struct Component resistor;
    resistor.type = 'R';
    resistor.value = 100;
    resistor.node1 = 1;
    resistor.node2 = 2;
    circuit.components[circuit.num_components++] = resistor;

    struct Component voltage_source;
    voltage_source.type = 'V';
    voltage_source.value = 10;
    voltage_source.node1 = 1;
    voltage_source.node2 = 0;
    circuit.components[circuit.num_components++] = voltage_source;

    simulate(&circuit, -1); // Simulate circuit in time domain
    simulate_frequency_response(&circuit, 1000, 1000000, 10); // Simulate circuit frequency response
    return 0;
}