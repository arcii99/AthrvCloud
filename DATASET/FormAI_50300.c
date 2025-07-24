//FormAI DATASET v1.0 Category: Physics simulation ; Style: complex
#include<stdio.h>
#include<math.h>

#define PI 3.14159265359

int main()
{
    double g = 9.81, t = 0.0, dt = 0.001, theta = PI/3.0, v_init = 20.0, x = 0.0, y = 0.0, v_x, v_y;
    double m = 0.1, k = 0.05, v_air, delta_t;
  
    FILE *outfile;
    outfile = fopen("trajectory.dat","wt");
  
    v_x = v_init * cos(theta);
    v_y = v_init * sin(theta);
  
    while(y >= 0.0)
    {
        delta_t = dt * (1 + k*v_y/m);
        x += v_x * delta_t;
        y += v_y * delta_t;
        v_air = pow(v_x,2) + pow(v_y,2);
        v_x -= k*v_air/m * v_x * delta_t;
        v_y -= (k*v_air/m * v_y + g) * delta_t;
        t += delta_t;
        fprintf(outfile, "%f %f\n", x, y);
    }
  
    fclose(outfile);

    return 0;
}