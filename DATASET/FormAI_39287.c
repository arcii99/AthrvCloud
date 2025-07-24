//FormAI DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Declare constants
#define L 10 // Length of each arm in cm
#define M1 1 // Weight of first arm in kg
#define M2 2 // Weight of second arm in kg
#define G 9.8 // Acceleration due to gravity in m/s^2

// Declare variables
float theta1 = 0; // Angle of first arm in degrees
float theta2 = 0; // Angle of second arm in degrees
float omega1 = 0; // Angular velocity of first arm in degrees/second
float omega2 = 0; // Angular velocity of second arm in degrees/second
float alpha1 = 0; // Angular acceleration of first arm in degrees/second^2
float alpha2 = 0; // Angular acceleration of second arm in degrees/second^2
float x = 0; // x coordinate of end effector in cm
float y = 0; // y coordinate of end effector in cm

// Declare functions
float degree_to_radian(float degree) {
    return degree * M_PI / 180.0;
}

float radian_to_degree(float radian) {
    return radian * 180.0 / M_PI;
}

void forward_kinematics() {
    // Compute x and y coordinates of end effector
    float radian1 = degree_to_radian(theta1);
    float radian2 = degree_to_radian(theta2);
    x = L * cos(radian1) + L * cos(radian1 + radian2);
    y = L * sin(radian1) + L * sin(radian1 + radian2);
}

void inverse_kinematics(float target_x, float target_y) {
    // Compute theta2 using law of cosines
    float cos_theta2 = (pow(target_x, 2) + pow(target_y, 2) - pow(L, 2) - pow(L, 2)) / (2 * L * L);
    float theta2_1 = radian_to_degree(acos(cos_theta2));
    float theta2_2 = radian_to_degree(-acos(cos_theta2));
    
    // Compute theta1 using atan2
    float sin_theta2_1 = sin(degree_to_radian(theta2_1));
    float cos_theta2_1 = cos(degree_to_radian(theta2_1));
    float sin_theta2_2 = sin(degree_to_radian(theta2_2));
    float cos_theta2_2 = cos(degree_to_radian(theta2_2));
    float theta1_1 = radian_to_degree(atan2(target_y * (L * sin_theta2_1) - target_x * (L * cos_theta2_1), target_x * (L * sin_theta2_1) + target_y * (L * cos_theta2_1)));
    float theta1_2 = radian_to_degree(atan2(target_y * (L * sin_theta2_2) - target_x * (L * cos_theta2_2), target_x * (L * sin_theta2_2) + target_y * (L * cos_theta2_2)));
    
    // Choose solution with lower absolute angle error
    if (fabs(theta1_1 - theta1) + fabs(theta2_1 - theta2) < fabs(theta1_2 - theta1) + fabs(theta2_2 - theta2)) {
        theta1 = theta1_1;
        theta2 = theta2_1;
    } else {
        theta1 = theta1_2;
        theta2 = theta2_2;
    }
}

void compute_velocity() {
    // Compute angular velocities of arms
    float radian1 = degree_to_radian(theta1);
    float radian2 = degree_to_radian(theta2);
    float sin_theta1_2 = sin(radian1 + radian2);
    float cos_theta1_2 = cos(radian1 + radian2);
    float term1 = -L * omega1 * sin(radian1) - L * (omega1 + omega2) * sin_theta1_2;
    float term2 = L * omega1 * cos(radian1) + L * (omega1 + omega2) * cos_theta1_2;
    float term3 = -L * (omega1 + omega2) * sin_theta1_2;
    float term4 = L * (omega1 + omega2) * cos_theta1_2;
    float det = term4 * term4 - term3 * term1;
    float alpha_theta1 = ((M2 * term4 * term1) - (M2 * term3 * term2)) / det;
    float alpha_theta2 = ((-M2 * term4 * term2) + (M1 + M2) * term3 * term1) / det;
    omega1 += alpha_theta1;
    omega2 += alpha_theta2;
}

void compute_acceleration() {
    // Compute angular accelerations of arms
    float radian1 = degree_to_radian(theta1);
    float radian2 = degree_to_radian(theta2);
    float sin_theta1_2 = sin(radian1 + radian2);
    float cos_theta1_2 = cos(radian1 + radian2);
    float term1 = -L * omega1 * sin(radian1) - L * (omega1 + omega2) * sin_theta1_2;
    float term2 = L * omega1 * cos(radian1) + L * (omega1 + omega2) * cos_theta1_2;
    float term3 = -L * (omega1 + omega2) * sin_theta1_2;
    float term4 = L * (omega1 + omega2) * cos_theta1_2;
    float det = term4 * term4 - term3 * term1;
    alpha1 = ((M2 * term4 * term1) - (M2 * term3 * term2)) / det - (M1 + M2) * G * L * sin(radian1) / det;
    alpha2 = ((-M2 * term4 * term2) + (M1 + M2) * term3 * term1) / det - M2 * G * L * sin(radian1 + radian2) / det;
}

int main() {
    // Move end effector to (5, 5)
    inverse_kinematics(5, 5);
    forward_kinematics();
    compute_velocity();
    compute_acceleration();
    printf("End effector position: (%.2f, %.2f)\n", x, y);
    printf("Theta1: %.2f degrees, Theta2: %.2f degrees\n", theta1, theta2);
    printf("Omega1: %.2f degrees/second, Omega2: %.2f degrees/second\n", omega1, omega2);
    printf("Alpha1: %.2f degrees/second^2, Alpha2: %.2f degrees/second^2\n", alpha1, alpha2);
    return 0;
}