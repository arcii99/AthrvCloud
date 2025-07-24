//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: inquisitive
#include<stdio.h>
#include<math.h>

// Structure to hold the details of a celestial body

struct body{
    char name[50];
    float mass;
    float position[3];
    float velocity[3];
};

void simulate(struct body celestial[], int num_bodies, float time_step, int duration){

    // Loop through the specified duration
    for(int i = 0; i < duration; i++){
        
        // Reset the gravitational force on each body to zero
        for(int j = 0; j < num_bodies; j++){
            celestial[j].position[0] = celestial[j].position[0] + time_step * celestial[j].velocity[0];
            celestial[j].position[1] = celestial[j].position[1] + time_step * celestial[j].velocity[1];
            celestial[j].position[2] = celestial[j].position[2] + time_step * celestial[j].velocity[2];
            
            float total_force_x = 0;
            float total_force_y = 0;
            float total_force_z = 0;
            
            // Calculate the gravitational force on each body due to other bodies
            for(int k = 0; k < num_bodies; k++){
                if(j != k){
                    float distance = sqrt(pow(celestial[k].position[0] - celestial[j].position[0],2) + pow(celestial[k].position[1] - celestial[j].position[1],2) + pow(celestial[k].position[2] - celestial[j].position[2],2));
                    float force = celestial[k].mass/pow(distance,2);
                    total_force_x += force * (celestial[k].position[0] - celestial[j].position[0])/distance;
                    total_force_y += force * (celestial[k].position[1] - celestial[j].position[1])/distance;
                    total_force_z += force * (celestial[k].position[2] - celestial[j].position[2])/distance;
                }
            }
            
            // Update the velocity of the body based on the gravitational force
            celestial[j].velocity[0] = celestial[j].velocity[0] + time_step * total_force_x/celestial[j].mass;
            celestial[j].velocity[1] = celestial[j].velocity[1] + time_step * total_force_y/celestial[j].mass;
            celestial[j].velocity[2] = celestial[j].velocity[2] + time_step * total_force_z/celestial[j].mass;
        }
    }
}

int main(){

    // Define the number of bodies in the system
    int num_bodies = 3;
    
    // Define the celestial bodies in the system
    struct body celestial[num_bodies];
    strcpy(celestial[0].name, "Sun");
    celestial[0].mass = 1.989e30;
    celestial[0].position[0] = 0;
    celestial[0].position[1] = 0;
    celestial[0].position[2] = 0;
    celestial[0].velocity[0] = 0;
    celestial[0].velocity[1] = 0;
    celestial[0].velocity[2] = 0;
    
    strcpy(celestial[1].name, "Earth");
    celestial[1].mass = 5.972e24;
    celestial[1].position[0] = 0;
    celestial[1].position[1] = 1.496e11;
    celestial[1].position[2] = 0;
    celestial[1].velocity[0] = 29783;
    celestial[1].velocity[1] = 0;
    celestial[1].velocity[2] = 0;
    
    strcpy(celestial[2].name, "Moon");
    celestial[2].mass = 7.342e22;
    celestial[2].position[0] = 0;
    celestial[2].position[1] = 1.496e11 + 3.844e8;
    celestial[2].position[2] = 0;
    celestial[2].velocity[0] = 30468;
    celestial[2].velocity[1] = 0;
    celestial[2].velocity[2] = 0;
    
    // Define the simulation parameters
    float time_step = 3600; // in seconds
    int duration = 365 * 24; // in hours
    
    // Run the simulation
    simulate(celestial, num_bodies, time_step, duration);
    
    // Print the final positions of all the bodies
    for(int i = 0; i < num_bodies; i++){
       printf("%s: (%.2f, %.2f, %.2f)\n", celestial[i].name, celestial[i].position[0], celestial[i].position[1], celestial[i].position[2]);
    }
    
    return 0;
}