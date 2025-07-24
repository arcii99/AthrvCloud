//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // setting random seed

    int n_carts = rand() % 10 + 10; // number of carts in traffic
    int n_lanes = rand() % 3 + 2; // number of lanes on the road
    int cart_speeds[n_carts]; // speeds of each cart
    int cart_positions[n_carts]; // position of each cart on the road
    int lane_speeds[n_lanes]; // speed limit of each lane
    int lane_positions[n_lanes]; // positions of the boundaries of each lane
    int timer = 0; // timer for simulation

    // randomly setting carts' speeds and positions
    for(int i=0; i<n_carts; i++) {
        cart_speeds[i] = rand() % 5 + 1; // speeds range from 1 to 5 units
        cart_positions[i] = rand() % (n_lanes*20 - 20); // positions range from 0 to 20 units before end of road
    }

    // randomly setting lane speeds and positions
    for(int i=0; i<n_lanes; i++) {
        int lane_speed = rand() % 15 + 5; // speeds range from 5 to 20 units
        lane_speeds[i] = lane_speed;
        lane_positions[i] = i*20; // lane boundaries are every 20 units
    }

    printf("Welcome to the medieval traffic flow simulator!\n");
    printf("Number of carts: %d\n", n_carts);
    printf("Number of lanes: %d\n", n_lanes);
    printf("Lane speed limits: ");
    for(int i=0; i<n_lanes; i++) {
        printf("%d ", lane_speeds[i]);
    }
    printf("\n");

    // simulation loop
    while(timer < 100) {
        
        // moving each cart according to its speed
        for(int i=0; i<n_carts; i++) {
            cart_positions[i] += cart_speeds[i];
        }

        // checking for collisions between carts
        for(int i=0; i<n_carts; i++) {
            for(int j=i+1; j<n_carts; j++) {
                if(cart_positions[i] == cart_positions[j]) { // collided
                    printf("Cart %d and cart %d collided at position %d!\n", i, j, cart_positions[i]);
                    return 0; // end simulation
                }
            }
        }

        // checking for speeding carts
        for(int i=0; i<n_carts; i++) {
            int lane_num = cart_positions[i] / 20; // finding which lane the cart is in
            if(lane_speeds[lane_num] < cart_speeds[i]) { // speeding
                printf("Cart %d is speeding at position %d!\n", i, cart_positions[i]);
            }
        }

        timer++; // incrementing timer
    }

    printf("Simulation complete with no collisions!\n");

    return 0;
}