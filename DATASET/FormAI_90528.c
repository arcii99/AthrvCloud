//FormAI DATASET v1.0 Category: Physics simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PLAYERS 10

// Constants for game simulation
#define TABLE_WIDTH 100
#define TABLE_HEIGHT 50
#define BALL_RADIUS 2
#define PLAYER_RADIUS 4
#define MAX_SPEED 10
#define MIN_SPEED 5
#define FRICTION 0.1

// Struct representing a player
typedef struct {
    int id;
    double x, y, vx, vy;
} Player;

// Struct representing the ball
typedef struct {
    double x, y, vx, vy;
} Ball;

// Random double generator between min and max (inclusive)
double rand_double(double min, double max) {
    return (double) rand() / RAND_MAX * (max - min) + min;
}

// Collision detection between a player and the ball
int check_collision(Player p, Ball b) {
    double distance = sqrt(pow(p.x - b.x, 2) + pow(p.y - b.y, 2));
    return distance < PLAYER_RADIUS + BALL_RADIUS;
}

// Update position and velocity for a player
void update_position(Player *p, double time) {
    p->x += p->vx * time;
    p->y += p->vy * time;
}

// Update velocity for a player based on friction
void update_velocity(Player *p, double time) {
    double speed = sqrt(pow(p->vx, 2) + pow(p->vy, 2));
    double friction = FRICTION * time;
    if (speed > friction) {
        p->vx -= friction * p->vx / speed;
        p->vy -= friction * p->vy / speed;
    } else {
        p->vx = 0;
        p->vy = 0;
    }
}

// Update ball position and velocity
void update_ball_position(Ball *b, double time) {
    b->x += b->vx * time;
    b->y += b->vy * time;

    // Check for collision with wall
    if (b->x - BALL_RADIUS < 0 || b->x + BALL_RADIUS > TABLE_WIDTH) {
        b->vx *= -1;
    }
    if (b->y - BALL_RADIUS < 0 || b->y + BALL_RADIUS > TABLE_HEIGHT) {
        b->vy *= -1;
    }
}

// Main function for the game simulation
int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    Ball ball;
    ball.x = rand_double(BALL_RADIUS, TABLE_WIDTH - BALL_RADIUS);
    ball.y = rand_double(BALL_RADIUS, TABLE_HEIGHT - BALL_RADIUS);
    ball.vx = rand_double(-MAX_SPEED, MAX_SPEED);
    ball.vy = rand_double(-MAX_SPEED, MAX_SPEED);

    int num_players;
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    // Initialize players with random initial positions and velocities
    for (int i = 0; i < num_players; i++) {
        players[i].id = i + 1;
        players[i].x = rand_double(PLAYER_RADIUS, TABLE_WIDTH - PLAYER_RADIUS);
        players[i].y = rand_double(PLAYER_RADIUS, TABLE_HEIGHT - PLAYER_RADIUS);
        players[i].vx = rand_double(-MAX_SPEED, MAX_SPEED);
        players[i].vy = rand_double(-MAX_SPEED, MAX_SPEED);
    }

    // Simulation loop
    double time_step = 0.01; // Time step for each iteration
    double game_time = 0; // Total simulation time
    while (1) {
        // Update player positions and velocities
        for (int i = 0; i < num_players; i++) {
            update_position(&players[i], time_step);
            update_velocity(&players[i], time_step);
        }

        // Check if any player collides with the ball
        for (int i = 0; i < num_players; i++) {
            if (check_collision(players[i], ball)) {
                // Player hits the ball
                double angle = rand_double(-M_PI, M_PI);
                double speed = rand_double(MIN_SPEED, MAX_SPEED);
                ball.vx = speed * cos(angle);
                ball.vy = speed * sin(angle);
                break;
            }
        }

        // Update ball position and velocity
        update_ball_position(&ball, time_step);

        // Print current status
        printf("Time: %.2f\n", game_time);
        printf("Ball position: (%.2f, %.2f)\n", ball.x, ball.y);
        for (int i = 0; i < num_players; i++) {
            printf("Player %d position: (%.2f, %.2f)\n",
                   players[i].id, players[i].x, players[i].y);
        }
        printf("\n");

        // Wait for a short time before the next iteration
        usleep(100000);
        game_time += time_step;
    }

    return 0;
}