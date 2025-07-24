//FormAI DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GRAVITY 9.81
#define BALL_RADIUS 0.05
#define BALL_ELASTICITY 0.7

struct Ball {
    double mass;
    double x, y;
    double vx, vy;
    double ax, ay;
};

typedef struct Ball Ball;

int main()
{
    Ball ball1 = {0.25, 0.15, 1.0, 1.0, 0.0, 0.0, 0.0};
    Ball ball2 = {0.75, 0.85, 0.5, -1.0, -1.0, 0.0, 0.0};

    double time_step = 0.01;
    double time_elapsed = 0.0;

    while (time_elapsed < 10.0)
    {
        double distance_squared = pow(ball1.x - ball2.x, 2) + pow(ball1.y - ball2.y, 2);
        double distance = sqrt(distance_squared);

        if (distance <= 2 * BALL_RADIUS)
        {
            double normal_x = (ball2.x - ball1.x) / distance;
            double normal_y = (ball2.y - ball1.y) / distance;

            double tangent_x = -normal_y;
            double tangent_y = normal_x;

            double relative_velocity_x = ball2.vx - ball1.vx;
            double relative_velocity_y = ball2.vy - ball1.vy;

            double normal_velocity = normal_x * relative_velocity_x + normal_y * relative_velocity_y;
            double tangent_velocity = tangent_x * relative_velocity_x + tangent_y * relative_velocity_y;

            if (normal_velocity < 0.0)
            {
                double impulse_magnitude = (1 + BALL_ELASTICITY) * normal_velocity;
                double jx = impulse_magnitude * normal_x;
                double jy = impulse_magnitude * normal_y;

                ball1.vx -= jx / ball1.mass;
                ball1.vy -= jy / ball1.mass;
                ball2.vx += jx / ball2.mass;
                ball2.vy += jy / ball2.mass;
            }
        }

        ball1.ax = 0.0;
        ball1.ay = -GRAVITY;
        ball2.ax = 0.0;
        ball2.ay = -GRAVITY;

        ball1.vx += ball1.ax * time_step;
        ball1.vy += ball1.ay * time_step;
        ball2.vx += ball2.ax * time_step;
        ball2.vy += ball2.ay * time_step;

        ball1.x += ball1.vx * time_step;
        ball1.y += ball1.vy * time_step;
        ball2.x += ball2.vx * time_step;
        ball2.y += ball2.vy * time_step;

        printf("Time elapsed: %.2f seconds. Ball1: (%.2f, %.2f). Ball2: (%.2f, %.2f).\n", time_elapsed, ball1.x, ball1.y, ball2.x, ball2.y);

        time_elapsed += time_step;
    }

    return 0;
}