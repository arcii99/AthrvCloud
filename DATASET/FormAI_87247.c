//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: automated
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 700
#define TIMER_INTERVAL 10

#define G 6.67408e-11

#define SUN_MASS 1.989e30
#define SUN_RADIUS 15

#define EARTH_MASS 5.972e24
#define EARTH_RADIUS 5
#define EARTH_ORBIT_RADIUS 150e9
#define EARTH_VELOCITY 29.78e3

struct planet {
    double x, y, z;
    double vx, vy, vz;
    double mass;
    double radius;
    double axis_tilt;
    double day_length;
    double year_length;
    double orbit_radius;
};

double camera_yaw = 0, camera_pitch = 30, camera_distance = 2e11;
struct planet sun, earth;
struct planet planets[] = {
    {1.900e11, 0e0, 0, 0, 29.78e3, 0, 0, 0, 1.898e27, 10, 10, 5.2*150e9},
    {0.0, 0.0, -10, 47.87e3, 0, 0, 0, 0, 3.3e23, 10, 10, 0.39*150e9},
    {0.0, 0.0, -18, 35.03e3, 0, 0, 0, 0, 4.88e24, 10, 10, 0.72*150e9},
    {0.0, 0.0, -22, 24.07e3, 0, 0, 0, 0, 6.0e24, 10, 10, 1.0*150e9},
    {0.0, 0.0, -24, 13.07e3, 0, 0, 0, 0, 6.418e23, 10, 10, 1.524*150e9},
    {0.0, 0.0, -26, 9.69e3, 0, 0, 0, 0, 1.9e27, 10, 10, 5.2*150e9},
};

int planet_count = sizeof(planets) / sizeof(planets[0]);

void init(void) {
    sun.x = sun.y = sun.z = 0;
    sun.vx = sun.vy = sun.vz = 0;
    sun.mass = SUN_MASS;
    sun.radius = SUN_RADIUS;

    earth.x = EARTH_ORBIT_RADIUS;
    earth.y = earth.z = 0;
    earth.vx = 0;
    earth.vy = EARTH_VELOCITY;
    earth.vz = 0;
    earth.mass = EARTH_MASS;
    earth.radius = EARTH_RADIUS;
    earth.axis_tilt = 23.5;
    earth.day_length = 24*60*60;
    earth.year_length = 365.25*earth.day_length;
    earth.orbit_radius = EARTH_ORBIT_RADIUS;
}

void compute_forces(void) {
    int i, j;

    double dx, dy, dz, distance, force, acceleration;

    for (i = 0; i < planet_count; i++) {
        planets[i].vx = planets[i].vy = planets[i].vz = 0;
        for (j = 0; j < planet_count; j++) {
            if (i == j) continue;

            dx = planets[i].x - planets[j].x;
            dy = planets[i].y - planets[j].y;
            dz = planets[i].z - planets[j].z;

            distance = sqrt(dx*dx + dy*dy + dz*dz);

            force = G * planets[i].mass * planets[j].mass / (distance * distance);
            acceleration = force / planets[i].mass;

            planets[i].vx -= dx / distance * acceleration * TIMER_INTERVAL / 1000;
            planets[i].vy -= dy / distance * acceleration * TIMER_INTERVAL / 1000;
            planets[i].vz -= dz / distance * acceleration * TIMER_INTERVAL / 1000;
        }
    }

    for (i = 0; i < planet_count; i++) {
        planets[i].x += planets[i].vx * TIMER_INTERVAL / 1000;
        planets[i].y += planets[i].vy * TIMER_INTERVAL / 1000;
        planets[i].z += planets[i].vz * TIMER_INTERVAL / 1000;
    }
}

void draw_circle(int x, int y, int radius) {
    glBegin(GL_POLYGON);
    for (double angle = 0; angle <= 2 * 3.14159; angle += 3.14159/16)
        glVertex3f(x + (radius * cos(angle)), y + (radius * sin(angle)), 0);
    glEnd();
}

void draw_planet(struct planet p) {
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(p.x, p.y, p.z);
    glRotated(p.day_length / p.year_length * 360, 0, 1, 0);
    glRotated(-p.axis_tilt, 0, 0, 1);
    draw_circle(0, 0, p.radius);
    glPopMatrix();
}

void display(void) {
    int i;

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, WINDOW_WIDTH/WINDOW_HEIGHT, 1, 1e15);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        -(camera_distance * cos(camera_pitch/180.0*3.14159) * sin(camera_yaw/180.0*3.14159)),
        -(camera_distance * sin(camera_pitch/180.0*3.14159)),
        -(camera_distance * cos(camera_pitch/180.0*3.14159) * cos(camera_yaw/180.0*3.14159)),
        0, 0, 0, 0, 1, 0
    );

    draw_planet(sun);

    for (i = 0; i < planet_count; i++) {
        draw_planet(planets[i]);
    }

    glutSwapBuffers();
}

void on_timer(int value) {
    compute_forces();
    glutPostRedisplay();
    glutTimerFunc(TIMER_INTERVAL, on_timer, 0);
}

void on_reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

void on_mouse_move(int x, int y) {
    static int last_x = 0;
    static int last_y = 0;

    camera_yaw += x - last_x;
    camera_pitch += y - last_y;

    if (camera_pitch > 89) camera_pitch = 89;
    if (camera_pitch < -89) camera_pitch = -89;

    last_x = x;
    last_y = y;
}

void on_mouse_wheel(int button, int dir, int x, int y) {
    camera_distance += dir * 1e9;
    if (camera_distance < 0) camera_distance = 0;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Solar System");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(on_reshape);
    glutTimerFunc(TIMER_INTERVAL, on_timer, 0);
    glutPassiveMotionFunc(on_mouse_move);
    glutMouseWheelFunc(on_mouse_wheel);

    glClearColor(0, 0, 0, 1);

    glutMainLoop();
    return 0;
}