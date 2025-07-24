//FormAI DATASET v1.0 Category: Physics simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define N 1000000
#define G 6.674e-11

double x[N], y[N], z[N];
double vx[N], vy[N], vz[N];
double fx[N], fy[N], fz[N], m[N];

void init_particles() {
  for (int i = 0; i < N; ++i) {
    x[i] = (double) rand() / RAND_MAX * 10 - 5;
    y[i] = (double) rand() / RAND_MAX * 10 - 5;
    z[i] = (double) rand() / RAND_MAX * 10 - 5;
    vx[i] = (double) rand() / RAND_MAX * 2 - 1;
    vy[i] = (double) rand() / RAND_MAX * 2 - 1;
    vz[i] = (double) rand() / RAND_MAX * 2 - 1;
    m[i] = (double) rand() / RAND_MAX;
  }
}

void compute_forces(int tid) {
  for (int i = tid; i < N; i += NUM_THREADS) {
    fx[i] = fy[i] = fz[i] = 0.0;
    for (int j = 0; j < N; ++j) {
      double dx = x[i] - x[j];
      double dy = y[i] - y[j];
      double dz = z[i] - z[j];
      double dist = sqrt(dx * dx + dy * dy + dz * dz);
      double f = G * m[i] * m[j] / (dist * dist + 1e-9);
      fx[i] += f * dx / dist;
      fy[i] += f * dy / dist;
      fz[i] += f * dz / dist;
    }
  }
}

void update_positions(int tid) {
  for (int i = tid; i < N; i += NUM_THREADS) {
    double ax = fx[i] / m[i];
    double ay = fy[i] / m[i];
    double az = fz[i] / m[i];
    x[i] += vx[i] + ax / 2;
    y[i] += vy[i] + ay / 2;
    z[i] += vz[i] + az / 2;
  }
}

void update_velocities(int tid) {
  for (int i = tid; i < N; i += NUM_THREADS) {
    double ax = fx[i] / m[i];
    double ay = fy[i] / m[i];
    double az = fz[i] / m[i];
    vx[i] += ax;
    vy[i] += ay;
    vz[i] += az;
  }
}

void* compute_thread(void* arg) {
  int tid = *(int*) arg;
  compute_forces(tid);
  pthread_exit(NULL);
}

void* update_position_thread(void* arg) {
  int tid = *(int*) arg;
  update_positions(tid);
  pthread_exit(NULL);
}

void* update_velocity_thread(void* arg) {
  int tid = *(int*) arg;
  update_velocities(tid);
  pthread_exit(NULL);
}

int main() {
  init_particles();

  pthread_t threads[NUM_THREADS];
  int tids[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; ++i) {
    tids[i] = i;
    pthread_create(&threads[i], NULL, compute_thread, (void*) &tids[i]);
  }
  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < NUM_THREADS; ++i) {
    tids[i] = i;
    pthread_create(&threads[i], NULL, update_position_thread, (void*) &tids[i]);
  }
  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < NUM_THREADS; ++i) {
    tids[i] = i;
    pthread_create(&threads[i], NULL, update_velocity_thread, (void*) &tids[i]);
  }
  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}