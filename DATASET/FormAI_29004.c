//FormAI DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>

int main() {
  int server1_cpu = 90;
  int server1_memory = 80;
  int server1_storage = 70;
  
  int server2_cpu = 80;
  int server2_memory = 85;
  int server2_storage = 75;
  
  int total_cpu = server1_cpu + server2_cpu;
  int total_memory = server1_memory + server2_memory;
  int total_storage = server1_storage + server2_storage;
  
  printf("Server 1 CPU usage: %d%%\n", server1_cpu);
  printf("Server 1 Memory usage: %d%%\n", server1_memory);
  printf("Server 1 Storage usage: %d%%\n\n", server1_storage);
  
  printf("Server 2 CPU usage: %d%%\n", server2_cpu);
  printf("Server 2 Memory usage: %d%%\n", server2_memory);
  printf("Server 2 Storage usage: %d%%\n\n", server2_storage);
  
  printf("Total CPU usage across all servers: %d%%\n", total_cpu);
  printf("Total Memory usage across all servers: %d%%\n", total_memory);
  printf("Total Storage usage across all servers: %d%%\n", total_storage);
  
  if(total_cpu > 95) {
    printf("CPU usage is high on the servers. Alerting the administrator...\n");
  }
  
  if(total_memory > 90) {
    printf("Memory usage is high on the servers. Alerting the administrator...\n");
  }
  
  if(total_storage > 80) {
    printf("Storage usage is high on the servers. Alerting the administrator...\n");
  }
  
  return 0;
}