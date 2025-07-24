//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/sysinfo.h> 

int kb_to_mb(int lp){
 return lp/1024;
}

void print_ram_info(){
  struct sysinfo si;
  sysinfo(&si);
  int total_ram = kb_to_mb(si.totalram);
  int free_ram = kb_to_mb(si.freeram);
  int used_ram = total_ram - free_ram;
  printf("RAM usage: %d MB of %d MB used.\n", used_ram, total_ram);
}

int main(){
  while(1){
    print_ram_info();
    sleep(1); //sleep for 1 second
  }
  return 0;
}