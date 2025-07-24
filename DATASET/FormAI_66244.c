//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
// Priority-based CPU Scheduling Algorithm Example

struct Process {
  char name[32];
  int priority;
  int cpu_time;
  int deadline;
};

void scheduleProcesses(struct Process processes[], int num_processes) {
  int time_slice = 1;
  struct Process *highest_priority_process;

  while (num_processes > 0) {
    highest_priority_process = &processes[0];

    for (int i = 1; i < num_processes; i++) {
      if (processes[i].priority > highest_priority_process->priority) {
        highest_priority_process = &processes[i];
      }
    }

    if (highest_priority_process->cpu_time > time_slice) {
      highest_priority_process->cpu_time -= time_slice;
    } else {
      highest_priority_process->cpu_time = 0;
      printf("%s completed.\n", highest_priority_process->name);

      for (int i = 0; i < num_processes - 1; i++) {
        processes[i] = processes[i + 1];
      }
      num_processes--;
    }

    for (int i = 0; i < num_processes; i++) {
      if (processes[i].deadline <= 0) {
        printf("%s missed its deadline.\n", processes[i].name);
        break;
      }
      processes[i].priority = processes[i].deadline * 10 / processes[i].cpu_time;
      processes[i].deadline -= time_slice;
    }
  }
}

int main() {
  struct Process processes[5] = {
    {"Program A", 5, 20, 100},
    {"Program B", 3, 30, 50},
    {"Program C", 2, 15, 40},
    {"Program D", 1, 50, 200},
    {"Program E", 4, 25, 80}
  };

  scheduleProcesses(processes, 5);

  return 0;
}