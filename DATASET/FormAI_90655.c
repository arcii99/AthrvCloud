//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Touring
#include <stdio.h>
#include <complex.h>

#define PI 3.14159265358979323846

// Function to calculate impedance of a resistor
double complex resistor(double R) {
  return R;
}

// Function to calculate impedance of a capacitor
double complex capacitor(double C, double f) {
  return 1 / (2 * PI * f * C * I);
}

// Function to calculate impedance of an inductor
double complex inductor(double L, double f) {
  return 2*PI*f*L*I;
}

int main() {
  double R, C, L, f;

  printf("Enter the resistance (R) in ohms: ");
  scanf("%lf", &R);

  printf("Enter the capacitance (C) in farads: ");
  scanf("%lf", &C);

  printf("Enter the inductance (L) in henries: ");
  scanf("%lf", &L);

  printf("Enter the frequency (f) in hertz: ");
  scanf("%lf", &f);

  double complex Z_resistor = resistor(R);
  double complex Z_capacitor = capacitor(C, f);
  double complex Z_inductor = inductor(L, f);

  double complex Z_parallel = 1 / (1/Z_resistor + 1/Z_capacitor + 1/Z_inductor);
  double complex Z_series = Z_resistor + Z_capacitor + Z_inductor;

  printf("\nImpedance of resistor: %.2f%+.2fj ohms", creal(Z_resistor), cimag(Z_resistor));
  printf("\nImpedance of capacitor: %.2f%+.2fj ohms", creal(Z_capacitor), cimag(Z_capacitor));
  printf("\nImpedance of inductor: %.2f%+.2fj ohms", creal(Z_inductor), cimag(Z_inductor));
  printf("\nTotal impedance (parallel): %.2f%+.2fj ohms", creal(Z_parallel), cimag(Z_parallel));
  printf("\nTotal impedance (series): %.2f%+.2fj ohms", creal(Z_series), cimag(Z_series));

  return 0;
}