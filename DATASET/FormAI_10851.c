//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

struct drone{
  int battery_level;
  int x_coordinate;
  int y_coordinate;
  int z_coordinate;
};

void move_forward(struct drone *drone){
  drone->x_coordinate += 10;
}

void move_backward(struct drone *drone){
  drone->x_coordinate -= 10;
}

void ascend(struct drone *drone){
  drone->z_coordinate += 10;
}

void descend(struct drone *drone){
  drone->z_coordinate -= 10;
}

void turn_left(struct drone *drone){
  drone->y_coordinate -= 10;
}

void turn_right(struct drone *drone){
  drone->y_coordinate += 10;
}

void battery_drain(struct drone *drone){
  drone->battery_level -= 2;
}

void recharge_battery(struct drone *drone){
  drone->battery_level = 100;
}

int main(){
  struct drone my_drone = {100, 0, 0, 0};
  
  //async
  #pragma omp parallel num_threads(2)
  {
    //move forward continuously
    #pragma omp section
    {
      while(1){
        #pragma omp atomic
        my_drone.battery_level--;
        
        if(my_drone.battery_level < 20){
          printf("Battery low, returning home for recharge!\n");
          break;
        }
        
        move_forward(&my_drone);
        sleep(1);
      }
    }
    
    //turn right continuously
    #pragma omp section
    {
      while(1){
        #pragma omp atomic
        my_drone.battery_level--;
        
        
        if(my_drone.battery_level < 20){
          printf("Battery low, returning home for recharge!\n");
          break;
        }
        
        turn_right(&my_drone);
        sleep(1);
      }
    }
  }
  
  printf("Battery level: %d\n", my_drone.battery_level);
  return 0;
}