#include <stdio.h>
#include "process.h"

int main() {
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    // TODO: Aquí va la lógica del scheduler

    int time = 0;
    //contador de procesos terminados
    int completed = 0;
    int quantum;
    printf("Quantum: ");
    scanf("%d", &quantum);

   while (completed < n){
    int executed = 0;

    for (int i = 0; i < n; i++){
        if (p[i].arrival_time <= time && p[i].completed == 0){
            executed = 1;

            // si es la 1ra vez que se ejecuta
            if (p[i].remaining_time == p[i].burst_time){
            }

            // si el proceso termins en este quantum
            if (p[i].remaining_time <= quantum){
                time += p[i].remaining_time;
                p[i].remaining_time = 0;
                p[i].completed = 1;  
                completed++;

                p[i].turnaround_time = time - p[i].arrival_time;
                p[i].waiting_time =
                    p[i].turnaround_time - p[i].burst_time;
            }
            else {
                p[i].remaining_time -= quantum;
                time += quantum;
            }
        }
    }

    if (!executed){
        time++;
    }
}

    print_results(p, n, "RR Scheduling");
    return 0;
}