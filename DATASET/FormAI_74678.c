//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdio.h>

// define the circuit elements
typedef struct {
    double v;
    double r;
    double i;
} Resistor;

typedef struct {
    double v;
    double c;
    double i;
} Capacitor;

typedef struct {
    double v;
    double l;
    double i;
} Inductor;

// simulate the circuit
void simulate(Resistor r, Capacitor c, Inductor l, double t) {
    double v_r = r.i * r.r;
    double q_c = c.i * c.c;
    double q_l = l.i * l.l;
    printf("t=%lf V_R=%lf Q_C=%lf Q_L=%lf\n", t, v_r, q_c, q_l);
}

int main() {
    Resistor r = { 1.0, 2.0, 0.0 };
    Capacitor c = { 0.0, 1.0, 0.0 };
    Inductor l = { 0.0, 0.5, 0.0 };
    double time_step = 0.01;
    for (double t = 0.0; t < 1.0; t += time_step) {
        r.i = c.v / r.r;
        c.i = (c.v - l.v) / (c.c * time_step) + c.i;
        l.i = (c.v - l.v) / (l.l * time_step) + l.i;
        c.v = c.i * time_step / c.c + c.v;
        l.v = l.i * time_step / l.l + l.v;
        simulate(r, c, l, t);
    }
    return 0;
}