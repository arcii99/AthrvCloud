//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define G 6.67408e-11

typedef struct Vector {
    double x, y, z;
} Vector;

typedef struct Body {
    Vector r; // position
    Vector v; // velocity
    Vector a; // acceleration
    double m; // mass
    double radius;
    Vector color;
} Body;

typedef struct Node {
    Vector center_of_mass;
    double mass;
    Body body;
    double size; // length of side of cube
    int num_bodies;
    struct Node* NW; // child nodes
    struct Node* NE;
    struct Node* SW;
    struct Node* SE;
} Node;

void update_acceleration(Body* body, Node* node) {
    // calculate distance and direction to node's center of mass
    Vector r = {
        node->center_of_mass.x - body->r.x,
        node->center_of_mass.y - body->r.y,
        node->center_of_mass.z - body->r.z
    };
    double distance = sqrt(r.x*r.x + r.y*r.y + r.z*r.z);
    if(distance == 0) return; // avoid division by zero
    Vector direction = { r.x/distance, r.y/distance, r.z/distance };
    
    if(node->num_bodies == 1 && &node->body != body) { // update acceleration based on other body
        double force = G*node->mass/body->m;
        body->a.x += force*direction.x;
        body->a.y += force*direction.y;
        body->a.z += force*direction.z;
    } else {
        double width = node->size / 2.0;
        // update acceleration based on child nodes
        if(node->NW != NULL) update_acceleration(body, node->NW);
        if(node->NE != NULL) update_acceleration(body, node->NE);
        if(node->SW != NULL) update_acceleration(body, node->SW);
        if(node->SE != NULL) update_acceleration(body, node->SE);
        // calculate s/d ratio for node
        double s_over_d = width / distance;
        if(s_over_d < 0.5) { // if s/d < 0.5, we use the node, otherwise we use the center of mass
            double force = G*node->mass/body->m;
            body->a.x += force*direction.x;
            body->a.y += force*direction.y;
            body->a.z += force*direction.z;
         }
    }
}

void update_velocity_position(Body* body, double dt) {
    // update velocity based on acceleration
    body->v.x += body->a.x*dt;
    body->v.y += body->a.y*dt;
    body->v.z += body->a.z*dt;
    // update position based on velocity
    body->r.x += body->v.x*dt;
    body->r.y += body->v.y*dt;
    body->r.z += body->v.z*dt;
}

void insert_body(Node* node, Body* body) {
    if(node->num_bodies == 0) { // node has no body so just add it
        node->body = *body;
        node->center_of_mass = body->r;
        node->mass = body->m;
    } else if(node->num_bodies == 1) { // add second body and subdivide node
        Body old_body = node->body;
        node->body = (Body) { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0, 0, {0, 0, 0} };
        // subdivide node
        double width = node->size / 2.0;
        node->NW = (Node*) malloc(sizeof(Node));
        node->NE = (Node*) malloc(sizeof(Node));
        node->SW = (Node*) malloc(sizeof(Node));
        node->SE = (Node*) malloc(sizeof(Node));
        *node->NW = (Node) { {node->center_of_mass.x - width/2.0, node->center_of_mass.y + width/2.0, 0}, 0, {0, 0, 0}, width, 0, NULL, NULL, NULL, NULL };
        *node->NE = (Node) { {node->center_of_mass.x + width/2.0, node->center_of_mass.y + width/2.0, 0}, 0, {0, 0, 0}, width, 0, NULL, NULL, NULL, NULL };
        *node->SW = (Node) { {node->center_of_mass.x - width/2.0, node->center_of_mass.y - width/2.0, 0}, 0, {0, 0, 0}, width, 0, NULL, NULL, NULL, NULL };
        *node->SE = (Node) { {node->center_of_mass.x + width/2.0, node->center_of_mass.y - width/2.0, 0}, 0, {0, 0, 0}, width, 0, NULL, NULL, NULL, NULL };
        // add old_body and new body to sub-nodes
        insert_body(node->NW, &old_body);
        insert_body(node->NW, body);
        node->num_bodies = -1; // denotes that this node is a parent node
        node->mass = old_body.m + body->m;
        node->center_of_mass.x = (old_body.r.x*old_body.m + body->r.x*body->m) / node->mass;
        node->center_of_mass.y = (old_body.r.y*old_body.m + body->r.y*body->m) / node->mass;
        node->center_of_mass.z = (old_body.r.z*old_body.m + body->r.z*body->m) / node->mass;
    } else { // parent node, add body to sub-node
        double dx = body->r.x - node->center_of_mass.x;
        double dy = body->r.y - node->center_of_mass.y;
        if(dx > 0) { // E
            if(dy > 0) { // N
                insert_body(node->NE, body);
            } else { // S
                insert_body(node->SE, body);
            }
        } else { // W
            if(dy > 0) { // N
                insert_body(node->NW, body);
            } else { // S
                insert_body(node->SW, body);
            }
        }
        node->mass += body->m;
        node->center_of_mass.x = (node->center_of_mass.x*node->mass + body->r.x*body->m) / (node->mass + 1);
        node->center_of_mass.y = (node->center_of_mass.y*node->mass + body->r.y*body->m) / (node->mass + 1);
        node->center_of_mass.z = (node->center_of_mass.z*node->mass + body->r.z*body->m) / (node->mass + 1);
    }
    node->num_bodies++;
}

void init_bodies(Body* bodies) {
    // sun
    bodies[0] = (Body) { {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.9891e30, 6.9634e8, { 1.0, 1.0, 0.0 } };
    // eight planets
    double d2r = 3.141592/180.0;
    double au = 1.495978707e11;
    // mercury
    double a = 0.3871*au, e = 0.2056, i = 7.0045*d2r, LoAN = 48.34*d2r, LoP = 77.456*d2r, M = 174.7959*d2r;
    double E = M, E_old;
    do {
        E_old = E;
        E = M + e*sin(E_old);
    } while(fabs(E - E_old) > 1e-6);
    double v = 2.0*atan(sqrt((1.0+e)/(1.0-e))*tan(E/2.0));
    bodies[1] = (Body) { {a*(cos(v) - e), a*sqrt(1 - e*e)*sin(v), 0}, {0, 0, 0}, {0, 0, 0}, 3.3022e23, 2439.7, {0.5, 0.5, 0.5} };
    // venus
    a = 0.7233*au, e = 0.0068, i = 3.3946*d2r, LoAN = 76.680*d2r, LoP = 131.532*d2r, M = 50.115*d2r;
    E = M;
    do {
        E_old = E;
        E = M + e*sin(E_old);
    } while(fabs(E - E_old) > 1e-6);
    v = 2.0*atan(sqrt((1.0+e)/(1.0-e))*tan(E/2.0));
    bodies[2] = (Body) { {a*(cos(v) - e), a*sqrt(1 - e*e)*sin(v), 0}, {0, 0, 0}, {0, 0, 0}, 4.8685e24, 6051.8, {0.7, 0.5, 1.0} };
    // earth
    a = 1.000*au, e = 0.0167, i = 0.000*d2r, LoAN = -11.26064*d2r, LoP = 102.94719*d2r, M = 358.617*d2r;
    E = M;
    do {
        E_old = E;
        E = M + e*sin(E_old);
    } while(fabs(E - E_old) > 1e-6);
    v = 2.0*atan(sqrt((1.0+e)/(1.0-e))*tan(E/2.0));
    bodies[3] = (Body) { {a*(cos(v) - e), a*sqrt(1 - e*e)*sin(v), 0}, {0, 0, 0}, {0, 0, 0}, 5.9736e24, 6371.0, {0.0, 0.2, 1.0} };
    // mars
    a = 1.5237*au, e = 0.0934, i = 1.850*d2r, LoAN = 49.57854*d2r, LoP = 336.04084*d2r, M = 19.373*d2r;
    E = M;
    do {
        E_old = E;
        E = M + e*sin(E_old);
    } while(fabs(E - E_old) > 1e-6);
    v = 2.0*atan(sqrt((1.0+e)/(1.0-e))*tan(E/2.0));
    bodies[4] = (Body) { {a*(cos(v) - e), a*sqrt(1 - e*e)*sin(v), 0}, {0, 0, 0}, {0, 0, 0}, 6.4171e23, 3389.5, {1.0, 0.25, 0.25} };
    // jupiter
    a = 5.2026*au, e = 0.0489, i = 1.305*d2r, LoAN = 100.55615*d2r, LoP = 14.75385*d2r, M = 20.020*d2r;
    E = M;
    do {
        E_old = E;
        E = M + e*sin(E_old);
    } while(fabs(E - E_old) > 1e-6);
    v = 2.0*atan(sqrt((1.0+e)/(1.0-e))*tan(E/2.0));
    bodies[5] = (Body) { {a*(cos(v) - e), a*sqrt(1 - e*e)*sin(v), 0}, {0, 0, 0}, {0, 0, 0}, 1.8986e27, 69911, {1.0, 0.7, 0.3} };
    // saturn
    a = 9.5549*au, e = 0.0556, i = 2.484*d2r, LoAN = 113.71504*d2r, LoP = 92.43194*d2r, M = 317.020*d2r;
    E = M;
    do {
        E_old = E;
        E = M + e*sin(E_old);
    } while(fabs(E - E_old) > 1e-6);
    v = 2.0*atan(sqrt((1.0+e)/(1.0-e))*tan(E/2.0));
    bodies[6] = (Body) { {a*(cos(v) - e), a*sqrt(1 - e*e)*sin(v), 0}, {0, 0, 0}, {0, 0, 0}, 5.6846e26, 58232, {1.0, 1.0, 0.0} };
    // uranus
    a = 19.2184*au, e = 0.0463, i = 0.7699*d2r, LoAN = 74.22988*d2r, LoP = 170.96424*d2r, M = 142.238*d2r;
    E = M;
    do {
        E_old = E;
        E = M + e*sin(E_old);
    } while(fabs(E - E_old) > 1e-6);
    v = 2.0*atan(sqrt((1.0+e)/(1.0-e))*tan(E/2.0));
    bodies[7] = (Body) { {a*(cos(v) - e), a*sqrt(1 - e*e)*sin(v), 0}, {0, 0, 0}, {0, 0, 0}, 8.6810e25, 25362, {0.5, 1.0, 0.5} };
    // neptune
    a = 30.1104*au, e = 0.0094, i = 1.7692*d2r, LoAN = 131.72169*d2r, LoP = 44.97135*d2r, M = 256.508*d2r;
    E = M;
    do {
        E_old = E;
        E = M + e*sin(E_old);
    } while(fabs(E - E_old) > 1e-6);
    v = 2.0*atan(sqrt((1.0+e)/(1.0-e))*tan(E/2.0));
    bodies[8] = (Body) { {a*(cos(v) - e), a*sqrt(1 - e*e)*sin(v), 0}, {0, 0, 0}, {0, 0, 0}, 1.0243e26, 24622, {0.2, 0.5, 1.0} };
}

int main() {
    // initialization
    Body bodies[9] = {0};
    init_bodies(bodies);
    time_t start_time = time(NULL);
    double dt = 3600; // time step size
    Node tree = { {0, 0, 0}, 0, {0, 0, 0}, 5e12, 0, NULL, NULL, NULL, NULL }; // root node
    for(int i = 0; i < 9; i++) {
        insert_body(&tree, &bodies[i]);
    }
    // simulation loop
    while(1) {
        double time_elapsed = difftime(time(NULL), start_time);
        if(time_elapsed > 3600*24*365*50) break; // stop after 50 years          
        // clear forces and update accelerations
        for(int i = 0; i < 9; i++) {
            bodies[i].a.x = 0;
            bodies[i].a.y = 0;
            bodies[i].a.z = 0;
            update_acceleration(&bodies[i], &tree);
        }
        // update velocities and positions
        for(int i = 0; i < 9; i++) {
            update_velocity_position(&bodies[i], dt);
        }
        // output to file
        char filename[100];
        sprintf(filename, "output/simulation_%d.txt", (int) (time_elapsed/3600));
        FILE* file = fopen(filename, "w+");
        for(int i = 0; i < 9; i++) {
            fprintf(file, "%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n",
                bodies[i].r.x, bodies[i].r.y, bodies[i].r.z,
                bodies[i].v.x, bodies[i].v.y, bodies[i].v.z,
                bodies[i].radius, bodies[i].color.x, bodies[i].color.y, bodies[i].color.z
            );
        }
        fclose(file);
    }
    // free memory
    free(tree.NW); free(tree.NE); free(tree.SW); free(tree.SE);
    return 0;
}