//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Cyberpunk Solar System Simulation
    int i, j, k, n = 9, steps = 365;
    double G = 6.67408e-11, dt = 86400.0, softener = 1e10;
    double R[n][3], V[n][3], A[n][3], M[n], F[3];
    char* name[] = {"Sun", "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
    srand(time(NULL));

    // Initial conditions
    M[0] = 1.9885e30; R[0][0] = R[0][1] = R[0][2] = 0.0; V[0][0] = V[0][1] = V[0][2] = 0.0;
    M[1] = 3.302e23; R[1][0] = 0.39 * 1.496e11; R[1][1] = 0.0; R[1][2] = 0.0; V[1][0] = 0.0; V[1][1] = 4.79e4; V[1][2] = 0.0;
    M[2] = 4.869e24; R[2][0] = 0.72 * 1.496e11; R[2][1] = 0.0; R[2][2] = 0.0; V[2][0] = 0.0; V[2][1] = 3.503e4; V[2][2] = 0.0;
    M[3] = 5.97e24; R[3][0] = R[3][1] = 0.0; R[3][2] = 0.0; V[3][0] = -2.978e4; V[3][1] = 0.0; V[3][2] = 0.0;
    M[4] = 6.39e23; R[4][0] = 0.0; R[4][1] = 1.52 * 1.496e11; R[4][2] = 0.0; V[4][0] = 0.0; V[4][1] = -2.41e4; V[4][2] = 0.0;
    M[5] = 1.898e27; R[5][0] = 5.20 * 1.496e11; R[5][1] = 0.0; R[5][2] = 0.0; V[5][0] = 0.0; V[5][1] = 1.307e4; V[5][2] = 0.0;
    M[6] = 5.69e26; R[6][0] = 9.54 * 1.496e11; R[6][1] = 0.0; R[6][2] = 0.0; V[6][0] = 0.0; V[6][1] = 9.64e3; V[6][2] = 0.0;
    M[7] = 8.68e25; R[7][0] = 19.18 * 1.496e11; R[7][1] = 0.0; R[7][2] = 0.0; V[7][0] = 0.0; V[7][1] = 6.80e3; V[7][2] = 0.0;
    M[8] = 1.02e26; R[8][0] = 30.07 * 1.496e11; R[8][1] = 0.0; R[8][2] = 0.0; V[8][0] = 0.0; V[8][1] = 5.43e3; V[8][2] = 0.0;

    // Simulation
    for (i = 0; i < steps; i++){
        // Reset accelerations to zero
        for (j = 0; j < n; j++){
            for (k = 0; k < 3; k++){
                A[j][k] = 0.0;
            }
        }

        // Compute forces and accelerations
        for (j = 0; j < n; j++){
            for (k = 0; k < n; k++){
                if (j != k){
                    F[0] = R[k][0] - R[j][0];
                    F[1] = R[k][1] - R[j][1];
                    F[2] = R[k][2] - R[j][2];
                    double d = sqrt(F[0]*F[0] + F[1]*F[1] + F[2]*F[2]);
                    double Fg = G * M[j] * M[k] / (d*d + softener*softener);
                    A[j][0] += Fg * F[0] / d;
                    A[j][1] += Fg * F[1] / d;
                    A[j][2] += Fg * F[2] / d;
                }
            }
        }

        // Update positions and velocities using leapfrog algorithm
        for (j = 0; j < n; j++){
            for (k = 0; k < 3; k++){
                R[j][k] += V[j][k] * dt + 0.5 * A[j][k] * dt * dt;
                V[j][k] += 0.5 * A[j][k] * dt;
            }
        }

        // Print output for each step
        printf("Step %d:\n", i+1);
        for (j = 0; j < n; j++){
            printf("%s : x = %g, y = %g, z = %g\n", name[j], R[j][0], R[j][1], R[j][2]);
        }
    }

    return 0;
}