//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void set_traffic_conditions(int* lane1, int* lane2, int* lane3, int* lane4);
void print_traffic(int* lane1, int* lane2, int* lane3, int* lane4);

int main() { 
    
    int lane1[20] = {0}, lane2[20] = {0}, lane3[20] = {0}, lane4[20] = {0};
    int stoplight = 0, timer = 0;
    int i = 0, j = 0;
    set_traffic_conditions(lane1, lane2, lane3, lane4);
    
    while(timer <= 30) {
        system("cls");
        printf("Time Left: %d seconds\n", 30-timer);
        
        if(stoplight == 0) {
            printf("GREEN LIGHT\n");
            print_traffic(lane1, lane2, lane3, lane4);
            stoplight = 1;
        } else {
            printf("RED LIGHT\n");
            print_traffic(lane1, lane2, lane3, lane4);
            stoplight = 0;
        }
        
        for(i=0; i<20; i++) {
            if(lane1[i] != 0 && lane1[i] != -1) {
                lane1[i]--;
            }
            if(lane2[i] != 0 && lane2[i] != -1) {
                lane2[i]--;
            }
            if(lane3[i] != 0 && lane3[i] != -1) {
                lane3[i]--;
            }
            if(lane4[i] != 0 && lane4[i] != -1) {
                lane4[i]--;
            }
        }
        
        if(stoplight == 0) {
            // car on lane 1 tries to change lane
            for(i=0; i<20; i++) {
                if(lane1[i] == -1 && i+1 < 20) {
                    lane1[i] = lane1[i+1];
                    lane1[i+1] = -1;
                }
            }
            // car on lane 2 tries to change lane
            for(i=0; i<20; i++) {
                if(lane2[i] == -1 && i+1 < 20) {
                    lane2[i] = lane2[i+1];
                    lane2[i+1] = -1;
                }
            }
            // car on lane 3 tries to change lane to 2 or 4
            for(i=0; i<20; i++) {
                if(lane3[i] == -1) {
                    if(rand()%2 == 0 && lane2[19] == 0) {
                        lane2[19] = -1;
                        lane3[i] = 0;
                    } else if(lane4[19] == 0) {
                        lane4[19] = -1;
                        lane3[i] = 0;
                    }
                }
            }
            // car on lane 4 tries to change lane to 2 or 4
            for(i=0; i<20; i++) {
                if(lane4[i] == -1) {
                    if(rand()%2 == 0 && lane2[19] == 0) {
                        lane2[19] = -1;
                        lane4[i] = 0;
                    } else if(lane3[19] == 0) {
                        lane3[19] = -1;
                        lane4[i] = 0;
                    }
                }
            }
            
            // car entrance from top
            if(rand()%2 == 0 && lane1[0] == 0) {
                lane1[0] = 10 + rand()%5;
            }
            // car entrance from bottom
            if(rand()%2 == 0 && lane2[0] == 0) {
                lane2[0] = 10 + rand()%5;
            }
        } else {
            // car on lane 2 tries to change lane
            for(i=0; i<20; i++) {
                if(lane2[i] == -1 && i+1 < 20) {
                    lane2[i] = lane2[i+1];
                    lane2[i+1] = -1;
                }
            }
            // car on lane 1 tries to change lane
            for(i=0; i<20; i++) {
                if(lane1[i] == -1 && i+1 < 20) {
                    lane1[i] = lane1[i+1];
                    lane1[i+1] = -1;
                }
            }
            // car on lane 4 tries to change lane to 1 or 3
            for(i=0; i<20; i++) {
                if(lane4[i] == -1) {
                    if(rand()%2 == 0 && lane1[19] == 0) {
                        lane1[19] = -1;
                        lane4[i] = 0;
                    } else if(lane3[19] == 0) {
                        lane3[19] = -1;
                        lane4[i] = 0;
                    }
                }
            }
            // car on lane 3 tries to change lane to 1 or 3
            for(i=0; i<20; i++) {
                if(lane3[i] == -1) {
                    if(rand()%2 == 0 && lane1[19] == 0) {
                        lane1[19] = -1;
                        lane3[i] = 0;
                    } else if(lane4[19] == 0) {
                        lane4[19] = -1;
                        lane3[i] = 0;
                    }
                }
            }
            
            // car entrance from left
            if(rand()%2 == 0 && lane3[0] == 0) {
                lane3[0] = 10 + rand()%5;
            }
            // car entrance from right
            if(rand()%2 == 0 && lane4[0] == 0) {
                lane4[0] = 10 + rand()%5;
            }
        }
        
        for(i=0; i<100000000; i++) {} // delay
        timer++;
    }
    
    printf("Simulation Complete\n");
    
    return 0; 
}

void set_traffic_conditions(int* lane1, int* lane2, int* lane3, int* lane4) {
    int i = 0, j = 0;
    srand(time(NULL));
    
    // initial traffic conditions
    for(i=0; i<20; i++) {
        if(rand()%2 == 0) {
            lane1[i] = 10 + rand()%5;
        }
        if(rand()%2 == 0) {
            lane2[i] = 10 + rand()%5;
        }
        if(rand()%2 == 0) {
            lane3[i] = 10 + rand()%5;
        }
        if(rand()%2 == 0) {
            lane4[i] = 10 + rand()%5;
        }
    }
}

void print_traffic(int* lane1, int* lane2, int* lane3, int* lane4) {
    int i = 0, j = 0;
    for(i=0; i<20; i++) {
        if(lane1[i] == -1) {
            printf("<");
        } else if(lane1[i] == 0) {
            printf(" ");
        } else {
            printf("%d", lane1[i]);
        }
    }
    printf("\n");
    for(i=0; i<20; i++) {
        if(lane3[i] == -1) {
            printf("<");
        } else if(lane3[i] == 0) {
            printf(" ");
        } else {
            printf("%d", lane3[i]);
        }
    }
    printf("  ");
    for(i=0; i<20; i++) {
        if(lane4[i] == -1) {
            printf("<");
        } else if(lane4[i] == 0) {
            printf(" ");
        } else {
            printf("%d", lane4[i]);
        }
    }
    printf("\n");
    for(i=0; i<20; i++) {
        if(lane2[i] == -1) {
            printf("<");
        } else if(lane2[i] == 0) {
            printf(" ");
        } else {
            printf("%d", lane2[i]);
        }
    }
    printf("\n");
}