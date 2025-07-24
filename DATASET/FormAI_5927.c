//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: synchronous
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 //Gravitational constant
#define dt 1000 //Time step
#define AU 149597870700 //Astronomical Unit (1 AU in meters)
#define EPOCH 2451545.0 //Epoch Julian date (01/01/2000 12:00:00 UTC)

typedef struct {
    double x, y, z; //Position in meters
    double vx, vy, vz; //Velocity in m/s
    double m; //Mass in kg
} Body;

void update_acc(Body *bodies, double *acc_x, double *acc_y, double *acc_z, int n) {
    for (int i = 0; i < n; i++) {
        acc_x[i] = 0.0;
        acc_y[i] = 0.0;
        acc_z[i] = 0.0;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = G * bodies[i].m * bodies[j].m / (r * r);
                acc_x[i] += f * dx / r;
                acc_y[i] += f * dy / r;
                acc_z[i] += f * dz / r;
            }
        }
    }
}

void update_vel(Body *bodies, double *acc_x, double *acc_y, double *acc_z, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].vx += acc_x[i] * dt;
        bodies[i].vy += acc_y[i] * dt;
        bodies[i].vz += acc_z[i] * dt;
    }
}

void update_pos(Body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void print_body(Body b) {
    printf("[x=%.3e y=%.3e z=%.3e] [vx=%.3e vy=%.3e vz=%.3e] [m=%.3e]\n",
        b.x / AU, b.y / AU, b.z / AU, b.vx, b.vy, b.vz, b.m);
}

int main() {
    int n = 9;
    Body bodies[n];

    //Positions and velocities at epoch (01/01/2000 12:00:00 UTC)
    bodies[0] = (Body) {1.471047882985825e+11, -2.597120020519745e+10, -3.963272782942528e+07,  2.203187250000000e+04, 4.107225454989959e+04,  5.566120106288926e-01,  5.9742e+24}; //Earth
    bodies[1] = (Body) {0.0, 0.0, 0.0,  0.0, 0.0, 0.0, 1.9891e+30}; //Sun
    bodies[2] = (Body) {2.279132538129906e+11, -3.417170166058228e+10, -5.786188064088539e+09,  1.307307336911719e+04, 2.481294492160763e+04, -8.017108921532313e+02, 6.4191e+23}; //Mars
    bodies[3] = (Body) {5.909278544358474e+10, -7.785961464766386e+10, -6.870200119116570e+07,  2.885068382494429e+04, 2.189827933068088e+04, -1.760118648796056e+03,  3.3011e+23}; //Venus
    bodies[4] = (Body) {1.426728986369328e+11, -7.310198345469900e+10, -5.108710956690698e+10,  1.265044548595693e+04, 2.110797517930251e+04,  9.131904307252543e+03,  6.4185e+23}; //Jupiter
    bodies[5] = (Body) {-1.493718194774150e+12, -2.924832884826255e+11,  3.180225108465169e+10,  1.456577913742703e+03, -7.372872472116847e+03, -8.293510985486740e+01,  8.6810e+25}; //Saturn
    bodies[6] = (Body) {-2.676738958447656e+12, -1.307884345302398e+11,  5.607722717078021e+10,  3.451224167839850e+02, -7.102642103345623e+03,  2.932752076030880e+01,  1.0241e+26}; //Uranus
    bodies[7] = (Body) {-4.332840178215857e+12, -2.946609107315222e+12,  5.234026012407126e+10,  2.667835051785328e+03, -3.766976645474090e+03, -5.264964958369956e+01,  1.4719e+23}; //Neptune
    bodies[8] = (Body) {-3.992954725338090e+12,  9.541531931993296e+12, -7.222275436512258e+11, -1.192848474721207e+03, -4.954982145022371e+02,  2.115776731913008e+02,  1.9885e+30}; //Sun2

    double acc_x[n], acc_y[n], acc_z[n];
    double t = 0.0, t_final = 1.0 * 31557600.0, t_print = 0.0, t_step = 86400.0;

    printf("Initial Conditions:\n");
    for (int i = 0; i < n; i++) {
        print_body(bodies[i]);
    }
    printf("--------------------\n");

    while (t < t_final) {
        update_acc(bodies, acc_x, acc_y, acc_z, n);
        update_vel(bodies, acc_x, acc_y, acc_z, n);
        update_pos(bodies, n);
        t += dt;

        if (t >= t_print) {
            printf("Time: %.2e years\n", (t - dt) / 31557600.0 + EPOCH);
            for (int i = 0; i < n; i++) {
                print_body(bodies[i]);
            }
            t_print += t_step;
        }
    }

    return 0;
}