//FormAI DATASET v1.0 Category: System boot optimizer ; Style: surprised
#include <stdio.h>

int main()
{
  printf("Oh boy! You're going to love this one. Sit tight!\n");
  int boot_time = 45;
  int num_files = 150;
  int num_services = 200;
  int memory_usage = 80;
  int optim_score = 0;
  char* optim_status = "not optimized";
  
  printf("First things first, let's check the current boot time...\n");
  
  if(boot_time > 60)
  {
    printf("Currently the system takes %d seconds to boot. That's not good!\n", boot_time);
    boot_time -= 10;
    optim_score += 10;
    printf("After removing unnecessary services, the system now takes %d seconds to boot.\n", boot_time);
  }
  else
  {
    printf("Currently the system takes %d seconds to boot. That's not too bad!\n", boot_time);
  }
  
  printf("Now let's look at the number of files on the system...\n");
  
  if(num_files > 100)
  {
    printf("There are currently %d files on the system. That's too many!\n", num_files);
    num_files -= 50;
    optim_score += 10;
    printf("After deleting unnecessary files, there are now %d files on the system.\n", num_files);
  }
  else
  {
    printf("There are currently %d files on the system. That's a good number!\n", num_files);
  }
  
  printf("Next up, let's analyze the number of services running...\n");
  
  if(num_services > 150)
  {
    printf("There are currently %d services running on the system. That's too many!\n", num_services);
    num_services -= 50;
    optim_score += 10;
    printf("After stopping unnecessary services, there are now %d services running.\n", num_services);
  }
  else
  {
    printf("There are currently %d services running on the system. That's a good number!\n", num_services);
  }
  
  printf("Finally, let's check the amount of memory being used...\n");
  
  if(memory_usage > 70)
  {
    printf("The system is currently using %d percent of memory. That's too high!\n", memory_usage);
    memory_usage -= 10;
    optim_score += 10;
    printf("After freeing up memory, the system now uses %d percent of memory.\n", memory_usage);
  }
  else
  {
    printf("The system is currently using %d percent of memory. That's a good usage!\n", memory_usage);
  }
  
  if(optim_score == 40)
  {
    optim_status = "fully optimized";
  }
  else if(optim_score > 20)
  {
    optim_status = "partially optimized";
  }
  
  printf("The system optimization score is %d out of 40. The system is %s.\n", optim_score, optim_status);
  
  return 0;
}