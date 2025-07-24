//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: ephemeral
#include <stdio.h>

int main() {
  int resistor_1_value = 220;
  int resistor_2_value = 100;
  int voltage_source_value = 5;

  float total_resistance = (float)resistor_1_value + resistor_2_value;
  float current = voltage_source_value / total_resistance;

  printf("Circuit Diagram:\n");
  printf("             ___\n");
  printf("            |   |\n");
  printf("      ----  |   |\n");
  printf("     | R1 | |   |\n");
  printf("V1---| %d | |   |\n", resistor_1_value);
  printf("     |   | |___|\n");
  printf("      ----  |   |\n");
  printf("            |   |\n");
  printf("             ---\n");
  printf("             ___\n");
  printf("            |   |\n");
  printf("            |   |\n");
  printf("      ----  | R2|\n");
  printf("     |    | | %d |\n", resistor_2_value);
  printf("     |    | |   |\n");
  printf("     |____| |   |\n");
  printf("            ----\n");
  printf("         V- = %dV\n", voltage_source_value);
  printf("\n");

  printf("Total Resistance = %.2f\n", total_resistance);
  printf("Current = %.2fA\n", current);
  
  return 0;
}