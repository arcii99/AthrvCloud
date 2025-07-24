//FormAI DATASET v1.0 Category: Physics simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define L1 1.0 // length of first pendulum
#define L2 0.75 // length of second pendulum
#define M1 1.0 // mass of first pendulum
#define M2 0.5 // mass of second pendulum
#define G 9.81 // acceleration due to gravity

int main()
{
    double t = 0; // initial time
    double dt = 0.01; // time step
    double m1 = M1;
    double m2 = M2;
    double l1 = L1;
    double l2 = L2;
    double g = G;
  
    double th1 = M_PI/2; // initial angle of first pendulum
    double w1 = 0; // initial angular velocity of first pendulum
    double th2 = M_PI; // initial angle of second pendulum
    double w2 = 0; // initial angular velocity of second pendulum
  
    double th1_prev = th1 - 0.001; // previous value of theta1
    double th2_prev = th2 - 0.001; // previous value of theta2
  
    while (1)
    {
        // calculate angular accelerations
        double num1 = -g * (2 * m1 + m2) * sin(th1);
        double num2 = -m2 * g * sin(th1 - 2 * th2);
        double num3 = -2 * sin(th1 - th2) * m2;
        double num4 = w2 * w2 * l2 + w1 * w1 * l1 * cos(th1 - th2);
        double den = l1 * (2 * m1 + m2 - m2 * cos(2 * th1 - 2 * th2));
        double a1 = (num1 + num2 + num3 * num4) / den;
      
        num1 = 2 * sin(th1 - th2);
        num2 = w1 * w1 * l1 * (m1 + m2);
        num3 = g * (m1 + m2) * cos(th1);
        num4 = w2 * w2 * l2 * m2 * cos(th1 - th2);
        den = l2 * (2 * m1 + m2 - m2 * cos(2 * th1 - 2 * th2));
        double a2 = (num1 * (num2 + num3 + num4)) / den;
      
        // update velocities
        w1 += a1 * dt;
        w2 += a2 * dt;
        // update angles
        th1 += w1 * dt;
        th2 += w2 * dt;
        
        // check for divergence
        if (fabs(th1 - th1_prev) > 50 || fabs(th2 - th2_prev) > 50)
        {
            printf("System diverged at t = %f\n", t);
            break;
        }
      
        // print results every 100 steps
        if ((int)(t*100) % 100 == 0)
        {
            printf("%f %f %f %f\n", t, th1, th2, fabs(th1 - th2));
        }
      
        // save previous values of angles
        th1_prev = th1;
        th2_prev = th2;
        // increment time
        t += dt;
    }
  
    return 0;
}