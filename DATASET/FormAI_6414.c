//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct capacitor {
   double capacitance;
   double voltage;
};

struct inductor {
   double inductance;
   double current;
};

struct resistor {
   double resistance;
   double current;
   double voltage;
};

int main() {

   struct capacitor c1, c2;

   c1.capacitance = 0.1;
   c1.voltage = 0;

   c2.capacitance = 0.2;
   c2.voltage = 0;

   struct inductor l1, l2;

   l1.inductance = 0.1;
   l1.current = 0;

   l2.inductance = 0.2;
   l2.current = 0;

   struct resistor r1, r2;

   r1.resistance = 1000;
   r1.voltage = 0;
   r1.current = 0;

   r2.resistance = 2000;
   r2.voltage = 0;
   r2.current = 0;

   double time = 0;
   double timeStep = 0.001;
   double endTime = 0.1;

   while (time < endTime) {

      // Update voltage across capacitors
      c1.voltage = c1.voltage + ((r2.current - r1.current) * timeStep) / c1.capacitance;
      c2.voltage = c2.voltage + (r2.current * timeStep) / c2.capacitance;

      // Update current through inductors
      l1.current = l1.current + ((c1.voltage - r1.voltage) * timeStep) / l1.inductance;
      l2.current = l2.current + ((c2.voltage - r2.voltage) * timeStep) / l2.inductance;

      // Update voltage across resistors
      r1.voltage = r1.resistance * r1.current;
      r2.voltage = r2.resistance * r2.current;

      // Update current flowing in resistors
      r1.current = (c1.voltage - r1.voltage + (l1.current * r2.resistance)) / (r1.resistance + r2.resistance);
      r2.current = (c2.voltage - r2.voltage - (l2.current * r2.resistance)) / (r1.resistance + r2.resistance);

      // Increment time
      time = time + timeStep;

      // Output results
      printf("Time: %.3f\n", time);
      printf("C1 Voltage: %f\n", c1.voltage);
      printf("C2 Voltage: %f\n", c2.voltage);
      printf("L1 Current: %f\n", l1.current);
      printf("L2 Current: %f\n", l2.current);
      printf("R1 Current: %f\n", r1.current);
      printf("R2 Current: %f\n", r2.current);
      printf("\n");
   }

   return 0;
}