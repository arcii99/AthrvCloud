//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: genious
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11 //Gravitational constant
#define M_SUN 1.989e30 //Mass of the Sun
#define M_EARTH 5.972e24 //Mass of the Earth
#define M_MOON 7.34767309e22 //Mass of the Moon
#define AU 149597870700 //Astronomical unit
#define DAY 86400 //Day in seconds

int main() {

    double t, dt = DAY; //Time and time step
    double x_E, y_E, z_E, vx_E, vy_E, vz_E; //Earth position and velocity components
    double x_M, y_M, z_M, vx_M, vy_M, vz_M; //Moon position and velocity components

    //Initial conditions for Earth
    x_E = 0;
    y_E = 0;
    z_E = 0;
    vx_E = 0;
    vy_E = 29783; //Velocity relative to the Sun
    vz_E = 0;

    //Initial conditions for Moon
    x_M = AU + 384400000; //Distance from Sun to Moon + distance from Moon to Earth
    y_M = 0;
    z_M = 0;
    vx_M = vx_E + 1022; //Velocity relative to the Earth
    vy_M = vy_E;
    vz_M = 0;

    //Simulation loop
    for (t=0; t<=365*DAY; t+=dt) {

        //Calculate distances between Earth and Moon, and between Earth and Sun
        double dx_EM = x_M - x_E;
        double dy_EM = y_M - y_E;
        double dz_EM = z_M - z_E;
        double r_EM = sqrt(dx_EM*dx_EM + dy_EM*dy_EM + dz_EM*dz_EM);

        double dx_ES = -x_E;
        double dy_ES = -y_E;
        double dz_ES = -z_E;
        double r_ES = sqrt(dx_ES*dx_ES + dy_ES*dy_ES + dz_ES*dz_ES);

        //Calculate accelerations using Newton's law of gravitation
        double ax_E = G*M_SUN*dx_ES/(r_ES*r_ES*r_ES);
        double ay_E = G*M_SUN*dy_ES/(r_ES*r_ES*r_ES);
        double az_E = G*M_SUN*dz_ES/(r_ES*r_ES*r_ES);

        double ax_M = G*M_EARTH*dx_EM/(r_EM*r_EM*r_EM) + G*M_SUN*dx_ES/(r_ES*r_ES*r_ES);
        double ay_M = G*M_EARTH*dy_EM/(r_EM*r_EM*r_EM) + G*M_SUN*dy_ES/(r_ES*r_ES*r_ES);
        double az_M = G*M_EARTH*dz_EM/(r_EM*r_EM*r_EM) + G*M_SUN*dz_ES/(r_ES*r_ES*r_ES);

        //Update velocities
        vx_E += ax_E*dt;
        vy_E += ay_E*dt;
        vz_E += az_E*dt;

        vx_M += ax_M*dt;
        vy_M += ay_M*dt;
        vz_M += az_M*dt;

        //Update positions
        x_E += vx_E*dt;
        y_E += vy_E*dt;
        z_E += vz_E*dt;

        x_M += vx_M*dt;
        y_M += vy_M*dt;
        z_M += vz_M*dt;

        //Output positions and time
        printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", t, x_E, y_E, z_E, x_M, y_M, z_M, vx_E, vy_E, vz_E, vx_M, vy_M, vz_M);
    }

    return 0;
}