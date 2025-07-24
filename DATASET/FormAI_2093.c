//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_NAME 20

typedef struct
{
    char name[MAX_NAME];
    int node[2];
    double value;
} component;

int num_nodes = 0;
component circuit[MAX_NODES];

double voltage[MAX_NODES];
double admittance[MAX_NODES][MAX_NODES], Yn[MAX_NODES][MAX_NODES];
double current[MAX_NODES];
double delta[MAX_NODES], rhs[MAX_NODES];

void stamp_component(int i)
{
    int n1 = circuit[i].node[0];
    int n2 = circuit[i].node[1];
    double value = circuit[i].value;
    admittance[n1][n1] += 1.0 / value;
    admittance[n2][n2] += 1.0 / value;
    admittance[n1][n2] -= 1.0 / value;
    admittance[n2][n1] -= 1.0 / value;
}

void stamp_resistor(int i)
{
    stamp_component(i);
}

void stamp_capacitor(int i, double delta_t)
{
    int n1 = circuit[i].node[0];
    int n2 = circuit[i].node[1];
    double value = circuit[i].value;
    admittance[n1][n1] += 1.0 / value;
    admittance[n2][n2] += 1.0 / value;
    admittance[n1][n2] -= 1.0 / value;
    admittance[n2][n1] -= 1.0 / value;
    admittance[n1][n1] += delta_t / value;
    admittance[n2][n2] += delta_t / value;
    admittance[n1][n2] -= delta_t / value;
    admittance[n2][n1] -= delta_t / value;
}

void stamp_inductor(int i, double delta_t)
{
    int n1 = circuit[i].node[0];
    int n2 = circuit[i].node[1];
    double value = circuit[i].value;
    admittance[n1][n1] += 1.0 / delta_t;
    admittance[n2][n2] += 1.0 / delta_t;
    admittance[n1][n2] -= 1.0 / delta_t;
    admittance[n2][n1] -= 1.0 / delta_t;
    admittance[n1][n1] += value;
    admittance[n2][n2] += value;
    admittance[n1][n2] -= value;
    admittance[n2][n1] -= value;
}

void stamp_current_source(int i)
{
    int n1 = circuit[i].node[0];
    int n2 = circuit[i].node[1];
    double value = circuit[i].value;
    current[n1] -= value;
    current[n2] += value;
}

void stamp_voltage_source(int i)
{
    int n1 = circuit[i].node[0];
    int n2 = circuit[i].node[1];
    double value = circuit[i].value;
    admittance[n1][num_nodes] += 1.0;
    admittance[n2][num_nodes] -= 1.0;
    admittance[num_nodes][n1] -= 1.0;
    admittance[num_nodes][n2] += 1.0;
    rhs[num_nodes] += value;
    num_nodes++;
}

void stamp_component_type(int i, double delta_t)
{
    if (circuit[i].name[0] == 'R')
    {
        stamp_resistor(i);
    }
    else if (circuit[i].name[0] == 'C')
    {
        stamp_capacitor(i, delta_t);
    }
    else if (circuit[i].name[0] == 'L')
    {
        stamp_inductor(i, delta_t);
    }
    else if (circuit[i].name[0] == 'I')
    {
        stamp_current_source(i);
    }
    else if (circuit[i].name[0] == 'V')
    {
        stamp_voltage_source(i);
    }
}

void stamp_circuit(double delta_t)
{
    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < num_nodes; j++)
        {
            Yn[i][j] = admittance[i][j];
        }
        rhs[i] = current[i];
    }
}

void solve_circuit()
{
    for (int i = 0; i < num_nodes; i++)
    {
        int max_row = i;
        for (int j = i + 1; j < num_nodes; j++)
        {
            if (fabs(Yn[j][i]) > fabs(Yn[max_row][i]))
            {
                max_row = j;
            }
        }
        if (i != max_row)
        {
            for (int j = i; j < num_nodes; j++)
            {
                double temp = Yn[i][j];
                Yn[i][j] = Yn[max_row][j];
                Yn[max_row][j] = temp;
            }
            double temp = rhs[i];
            rhs[i] = rhs[max_row];
            rhs[max_row] = temp;
        }
        for (int j = i + 1; j < num_nodes; j++)
        {
            double factor = Yn[j][i] / Yn[i][i];
            for (int k = i + 1; k < num_nodes; k++)
            {
                Yn[j][k] -= factor * Yn[i][k];
            }
            rhs[j] -= factor * rhs[i];
        }
    }
    for (int i = num_nodes - 1; i >= 0; i--)
    {
        double sum = 0.0;
        for (int j = i + 1; j < num_nodes; j++)
        {
            sum += Yn[i][j] * delta[j];
        }
        delta[i] = (rhs[i] - sum) / Yn[i][i];
    }
}

void update_voltage(double delta_t)
{
    for (int i = 0; i < num_nodes; i++)
    {
        voltage[i] += delta[i];
        admittance[i][i] = 0.0;
    }
}

void print_voltage()
{
    printf("\nNodal voltages:\n");
    for (int i = 0; i < num_nodes; i++)
    {
        printf("%s: %f\n", circuit[i].name, voltage[i]);
    }
}

int main()
{
    // Initialize circuit components
    circuit[0].name[0] = 'V';
    circuit[0].node[0] = 0;
    circuit[0].node[1] = 1;
    circuit[0].value = 5.0;
    circuit[1].name[0] = 'R';
    circuit[1].node[0] = 1;
    circuit[1].node[1] = 2;
    circuit[1].value = 100.0;
    circuit[2].name[0] = 'C';
    circuit[2].node[0] = 2;
    circuit[2].node[1] = 0;
    circuit[2].value = 0.00001;

    // Initialize simulation variables
    double t = 0.0;
    double delta_t = 0.0001;
    int num_steps = 10000;

    // Initialize nodal voltages
    for (int i = 0; i < MAX_NODES; i++)
    {
        voltage[i] = 0.0;
    }
    voltage[0] = 5.0;

    // Simulation loop
    for (int i = 0; i < num_steps; i++)
    {
        for (int j = 0; j < MAX_NODES; j++)
        {
            for (int k = 0; k < MAX_NODES; k++)
            {
                admittance[j][k] = 0.0;
            }
            current[j] = 0.0;
        }
        num_nodes = 0;

        for (int j = 0; j < MAX_NODES; j++)
        {
            if (circuit[j].name[0] != 0)
            {
                stamp_component_type(j, delta_t);
            }
        }
        stamp_circuit(delta_t);
        solve_circuit();
        update_voltage(delta_t);

        t += delta_t;
    }

    print_voltage();

    return 0;
}