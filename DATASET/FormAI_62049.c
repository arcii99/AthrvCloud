//FormAI DATASET v1.0 Category: Physics simulation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double temperature(double v, double m){
    double k = 1.38e-23; // Boltzmann constant
    double T = (v * v * m) / (3 * k);
    return T;
}

int main(){
    int particles = 1000; // Number of particles
    double mass = 1e-23; // Mass of each particle
    double radius = 1e-9; // Radius of container
    double density = 1000; // Density of gas particles
    double volume = (4.0/3.0) * M_PI * pow(radius, 3); // Volume of container
    double area = M_PI * pow(radius, 2); // Surface Area of container

    double u;
    double v;
    double w;
    double r;
    double theta;
    double phi;

    double x[particles], y[particles], z[particles];
    double vx[particles], vy[particles], vz[particles];
    double fx[particles], fy[particles], fz[particles];
    double dt = 1e-15; // Time step

    double T = 300; // Temperature
    double kb = 1.38e-23; // Boltzmann constant

    // Initialize position, velocity, and force
    for(int i=0; i<particles; i++){
        r = ((double) rand()) / RAND_MAX;
        theta = ((double) rand()) / RAND_MAX;
        phi = ((double) rand()) / RAND_MAX;

        x[i] = radius * pow(r, 1.0/3.0) * sin(theta) * cos(phi);
        y[i] = radius * pow(r, 1.0/3.0) * sin(theta) * sin(phi);
        z[i] = radius * pow(r, 1.0/3.0) * cos(theta);

        u = ((double) rand()) / RAND_MAX;
        v = ((double) rand()) / RAND_MAX;
        w = ((double) rand()) / RAND_MAX;

        vx[i] = sqrt(-2 * kb * T * log(u)) * sin(2 * M_PI * v);
        vy[i] = sqrt(-2 * kb * T * log(u)) * sin(2 * M_PI * w);
        vz[i] = sqrt(-2 * kb * T * log(u)) * cos(2 * M_PI * v);

        fx[i] = 0;
        fy[i] = 0;
        fz[i] = 0;
    }

    double time = 0;
    double kinetic_energy;
    double pressure;

    while(time < 1e-12){
        kinetic_energy = 0;
        pressure = 0;

        // Compute force
        for(int i=0; i<particles; i++){
            fx[i] = 0;
            fy[i] = 0;
            fz[i] = 0;

            for(int j=0; j<particles; j++){
                if(i != j){
                    double dx = x[j] - x[i];
                    double dy = y[j] - y[i];
                    double dz = z[j] - z[i];
                    double r2 = dx*dx + dy*dy + dz*dz;
                    double r = sqrt(r2);

                    double f = (4 * kb * T / (mass * pow(r, 12))) - (4 * kb * T / (mass * pow(r, 6)));
                    fx[i] += f * dx / r;
                    fy[i] += f * dy / r;
                    fz[i] += f * dz / r;
                }
            }
        }

        // Update position and velocity
        for(int i=0; i<particles; i++){
            vx[i] += fx[i] / mass * dt;
            vy[i] += fy[i] / mass * dt;
            vz[i] += fz[i] / mass * dt;

            x[i] += vx[i] * dt;
            y[i] += vy[i] * dt;
            z[i] += vz[i] * dt;

            // Compute kinetic energy and pressure
            kinetic_energy += 0.5 * mass * (vx[i]*vx[i] + vy[i]*vy[i] + vz[i]*vz[i]);
            pressure += mass / (3 * volume) * (vx[i]*vx[i] + vy[i]*vy[i] + vz[i]*vz[i]);
        }

        // Apply periodic boundary conditions
        for(int i=0; i<particles; i++){
            if(x[i] < -radius){
                x[i] += 2 * radius;
            }
            if(x[i] > radius){
                x[i] -= 2 * radius;
            }
            if(y[i] < -radius){
                y[i] += 2 * radius;
            }
            if(y[i] > radius){
                y[i] -= 2 * radius;
            }
            if(z[i] < -radius){
                z[i] += 2 * radius;
            }
            if(z[i] > radius){
                z[i] -= 2 * radius;
            }
        }

        // Update time
        time += dt;
    }

    printf("Kinetic Energy: %e J\n", kinetic_energy);
    printf("Temperature: %e K\n", temperature(sqrt(kinetic_energy/particles), mass));
    printf("Pressure: %e Pa\n", pressure);

    return 0;
}