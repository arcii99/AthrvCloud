//FormAI DATASET v1.0 Category: Physics simulation ; Style: standalone
/* A simple physics simulation program for calculating projectile motion 
   with air resistance */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/* CONSTANTS */
#define GRAVITY 9.8 /* m/s^2 */
#define AIR_DENSITY 1.225 /* kg/m^3 */
#define DRAG_COEFFICIENT 0.47
#define BALL_RADIUS 0.05 /* meters */
#define BALL_MASS 0.1 /* kg */

/* USER INPUTS */
#define INITIAL_VELOCITY 25 /* m/s */
#define LAUNCH_ANGLE 45 /* degrees */
#define TIME_STEP 0.01 /* seconds */

/* FUNCTIONS */

double calculateDragForce(double airDensity, double dragCoefficient, double radius, double velocity);
double calculateNetForce(double airDensity, double dragCoefficient, double radius, double velocity, double angle, double mass);
double calculateAcceleration(double netForce, double mass);
double calculateVelocity(double initialVelocity, double acceleration, double time);
double calculateDistance(double initialVelocity, double time, double angle, double dragCoefficient, double radius, double airDensity, double mass);

int main() {
  
  /* initial conditions */
  double velocity_x = INITIAL_VELOCITY * cos(LAUNCH_ANGLE * PI/180.0);
  double velocity_y = INITIAL_VELOCITY * sin(LAUNCH_ANGLE * PI/180.0);
  double time = 0;
  double x = 0;
  double y = 0;
  
  /* simulation loop */
  while (y >= 0) {
    double netForce = calculateNetForce(AIR_DENSITY, DRAG_COEFFICIENT, BALL_RADIUS, sqrt(pow(velocity_x, 2) + pow(velocity_y, 2)), LAUNCH_ANGLE, BALL_MASS);
    double acceleration = calculateAcceleration(netForce, BALL_MASS);
    velocity_y = calculateVelocity(velocity_y, -1 * acceleration, TIME_STEP);
    velocity_x = calculateVelocity(velocity_x, 0, TIME_STEP);
    double distance = calculateDistance(INITIAL_VELOCITY, time + TIME_STEP, LAUNCH_ANGLE, DRAG_COEFFICIENT, BALL_RADIUS, AIR_DENSITY, BALL_MASS);
    x += distance;
    y += velocity_y * TIME_STEP;
    time += TIME_STEP;
    printf("Time: %lf s  X: %lf m  Y: %lf m\n", time, x, y);
  }
  
  return 0;
}

double calculateDragForce(double airDensity, double dragCoefficient, double radius, double velocity) {
  return 0.5 * airDensity * pow(velocity, 2) * dragCoefficient * PI * pow(radius, 2);
}

double calculateNetForce(double airDensity, double dragCoefficient, double radius, double velocity, double angle, double mass) {
  double dragForce = calculateDragForce(airDensity, dragCoefficient, radius, velocity);
  double gravityForce = mass * GRAVITY * sin(angle * PI/180.0);
  return gravityForce - dragForce;
}

double calculateAcceleration(double netForce, double mass) {
  return netForce/mass;
}

double calculateVelocity(double initialVelocity, double acceleration, double time) {
  return initialVelocity + acceleration * time;
}

double calculateDistance(double initialVelocity, double time, double angle, double dragCoefficient, double radius, double airDensity, double mass) {
  double v = initialVelocity;
  double a = calculateAcceleration(calculateNetForce(airDensity, dragCoefficient, radius, v, angle, mass), mass);
  double d = v*time + 0.5*a*pow(time, 2);
  return d;
}