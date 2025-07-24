//FormAI DATASET v1.0 Category: Recursive ; Style: Donald Knuth
#include <stdio.h>

void hanoi_towers(int num, char from_rod, char to_rod, char aux_rod){
    if (num == 1) {
        printf("\rMove disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    hanoi_towers(num - 1, from_rod, aux_rod, to_rod);
    printf("\rMove disk %d from rod %c to rod %c", num, from_rod, to_rod);
    hanoi_towers(num - 1, aux_rod, to_rod, from_rod);
}

int main(){
    int num = 5;
    hanoi_towers(num, 'A', 'C', 'B');
    return 0;
}