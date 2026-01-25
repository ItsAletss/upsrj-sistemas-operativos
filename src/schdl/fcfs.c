#include <stdio.h>
#include "process.h"


void fcfs_schedule(Process p[], int n)
{
    (void)p;
    (void)n;
    int time = 0;


    // TODO: Aquí va la lógica del scheduler

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {

        // Si el proceso llega después, el CPU espera
        if (time < p[i].arrival_time) {
            time = p[i].arrival_time;
        }

        // Waiting Time 
        p[i].waiting_time = time - p[i].arrival_time;

        // Ejecutar proceso completo
        time += p[i].burst_time;

        // Turnaround Time = tiempo final - arrival time
        p[i].turnaround_time = time - p[i].arrival_time;

        p[i].completed = 1;
    }
}
#ifndef UNIT_TEST
int main(void)
{
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    fcfs_schedule(p, n);

    print_results(p, n, "FCFS Scheduling");
    return 0;
}
#endif