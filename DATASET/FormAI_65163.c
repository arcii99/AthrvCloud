//FormAI DATASET v1.0 Category: Robot movement control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Robot struct
typedef struct
{
    int x_pos;
    int y_pos;
    int hp;
} Robot;

// Define constant variables for max and min range of robot movements
const int MIN_MOVE = 1;
const int MAX_MOVE = 5;

// Generate random movement for robot
int generate_movement()
{
    int move;
    move = rand() % (MAX_MOVE - MIN_MOVE + 1) + MIN_MOVE;
    return move;
}

// Check if robot is out of bounds
int check_bounds(Robot robot)
{
    if (robot.x_pos < 0 || robot.x_pos > 10 || robot.y_pos < 0 || robot.y_pos > 10)
    {
        return 1;
    }
    return 0;
}

int main()
{
    // Initialize seed for random number generator
    srand(time(0));

    // Initialize two robots with randomized positions and HP
    Robot robot1 = {rand() % 10, rand() % 10, rand() % 100};
    Robot robot2 = {rand() % 10, rand() % 10, rand() % 100};
    
    // Set initial turn to robot 1
    int current_turn = 1;

    // Print initial robot positions and HPs
    printf("Robot 1: (%d, %d) HP: %d\nRobot 2: (%d, %d) HP: %d\n", robot1.x_pos, robot1.y_pos, robot1.hp, robot2.x_pos, robot2.y_pos, robot2.hp);

    // Begin game loop
    while (1)
    {
        // Check if any robot has run out of HP
        if (robot1.hp <= 0)
        {
            printf("Game Over! Robot 2 Wins!\n");
            break;
        }
        else if (robot2.hp <= 0)
        {
            printf("Game Over! Robot 1 Wins!\n");
            break;
        }

        // Check whose turn it is
        if (current_turn == 1)
        {
            // Generate a random movement for robot 1
            int movement = generate_movement();
            printf("Robot 1 moves %d spaces!\n", movement);
            robot1.x_pos += movement;
            robot1.y_pos += movement;

            // Check if robot 1 is out of bounds and reset it to the nearest bound
            if (check_bounds(robot1))
            {
                printf("Robot 1 is out of bounds! Resetting position...\n");
                robot1.x_pos = abs(robot1.x_pos - 10);
                robot1.y_pos = abs(robot1.y_pos - 10);
            }

            // Generate a random attack damage for robot 1
            int attack_damage = rand() % 50 + 1;
            printf("Robot 1 deals %d damage to Robot 2!\n", attack_damage);
            robot2.hp -= attack_damage;

            // Print current robot positions and HPs
            printf("Robot 1: (%d, %d) HP: %d\nRobot 2: (%d, %d) HP: %d\n", robot1.x_pos, robot1.y_pos, robot1.hp, robot2.x_pos, robot2.y_pos, robot2.hp);
            current_turn = 2; // Set turn to robot 2
        }
        else if (current_turn == 2)
        {
            // Generate a random movement for robot 2
            int movement = generate_movement();
            printf("Robot 2 moves %d spaces!\n", movement);
            robot2.x_pos += movement;
            robot2.y_pos += movement;

            // Check if robot 2 is out of bounds and reset it to the nearest bound
            if (check_bounds(robot2))
            {
                printf("Robot 2 is out of bounds! Resetting position...\n");
                robot2.x_pos = abs(robot2.x_pos - 10);
                robot2.y_pos = abs(robot2.y_pos - 10);
            }

            // Generate a random attack damage for robot 2
            int attack_damage = rand() % 50 + 1;
            printf("Robot 2 deals %d damage to Robot 1!\n", attack_damage);
            robot1.hp -= attack_damage;

            // Print current robot positions and HPs
            printf("Robot 1: (%d, %d) HP: %d\nRobot 2: (%d, %d) HP: %d\n", robot1.x_pos, robot1.y_pos, robot1.hp, robot2.x_pos, robot2.y_pos, robot2.hp);
            current_turn = 1; // Set turn to robot 1
        }
    }

    // Exit program
    return 0;
}