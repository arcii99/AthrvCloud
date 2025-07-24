//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000
#define MAX_TIME 3600

void accelerate(double *current_speed, const double max_speed, const double acceleration);
void decelerate(double *current_speed, double *distance_to_car, const double safe_distance, const double braking_power);
int get_next_car(double *distances, int n_cars, int current_car);
double rand_normal(const double mean, const double stddev);

int main() {
    // Initialize simulation parameters
    const double simulation_time = MAX_TIME;
    const double time_step = 0.1;
    const double max_speed = 60.0;
    const double safe_distance = 2.0;
    const double acceleration = 2.0;
    const double braking_power = -2.0;
    const double mean_velocity = 30.0;
    const double stddev_velocity = 10.0;

    // Set up initial conditions
    int n_cars = 1;
    double times[MAX_CARS] = {0};
    double distances[MAX_CARS] = {0};
    double speeds[MAX_CARS] = {0};
    speeds[0] = max_speed * (1.0 - rand_normal(mean_velocity, stddev_velocity));

    // Run simulation
    double current_time = 0.0;
    while (current_time < simulation_time && n_cars < MAX_CARS) {
        // Accelerate/decelerate for each car
        for (int i = 0; i < n_cars; i++) {
            double acceleration_factor = 1.0;
            if (i > 0) {
                double distance_to_car = distances[i] - distances[i-1];
                decelerate(&speeds[i], &distance_to_car, safe_distance, braking_power);
                acceleration_factor = fmin(1.0, distance_to_car / safe_distance);
            }
            accelerate(&speeds[i], max_speed * acceleration_factor, acceleration);
        }

        // Update positions
        for (int i = 0; i < n_cars; i++) {
            distances[i] += speeds[i] * time_step;
            times[i] += time_step;
        }

        // Add new car if necessary
        if (times[n_cars-1] > 60.0) {
            double new_speed = max_speed * (1.0 - rand_normal(mean_velocity, stddev_velocity));
            speeds[n_cars] = new_speed;
            distances[n_cars] = distances[n_cars-1] - speeds[n_cars-1] * (60.0 - times[n_cars-1]);
            times[n_cars] = 0.0;
            n_cars++;
        }

        // Update time
        current_time += time_step;
    }

    // Print results
    printf("Time,Distance,Speed\n");
    for (int i = 0; i < n_cars; i++) {
        printf("%f,%f,%f\n", times[i], distances[i], speeds[i]);
    }

    return 0;
}

void accelerate(double *current_speed, const double max_speed, const double acceleration) {
    *current_speed += acceleration * 0.1;
    if (*current_speed > max_speed) {
        *current_speed = max_speed;
    }
}

void decelerate(double *current_speed, double *distance_to_car, const double safe_distance, const double braking_power) {
    if (*distance_to_car <= safe_distance) {
        double max_braking_distance = (*current_speed * *current_speed) / (-2.0 * braking_power);
        double actual_braking_distance = *distance_to_car - safe_distance;
        double braking_factor = fmin(1.0, actual_braking_distance / max_braking_distance);
        *current_speed += braking_power * 0.1 * braking_factor;
        *distance_to_car += *current_speed * 0.1;
    }
}

int get_next_car(double *distances, int n_cars, int current_car) {
    for (int i = current_car+1; i < n_cars; i++) {
        if (distances[i] > distances[current_car]) {
            return i;
        }
    }
    return -1;
}

double rand_normal(const double mean, const double stddev) {
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached) {
        double x, y, r;
        do {
            x = 2.0 * rand() / RAND_MAX - 1.0;
            y = 2.0 * rand() / RAND_MAX - 1.0;
            r = x*x + y*y;
        } while (r == 0.0 || r > 1.0);
        double d = sqrt(-2.0 * log(r) / r);
        double n1 = x * d;
        n2 = y * d;
        double result = n1 * stddev + mean;
        n2_cached = 1;
        return result;
    } else {
        n2_cached = 0;
        return n2 * stddev + mean;
    }
}