#include <stdio.h>
#include "process.h"

void sjf_schedule(Process p[], int n)
{
    int time = 0;
    int completed = 0;
    Process result[n];  
    int k = 0;

    while (completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        // Buscar proceso disponible con menor burst_time
        for (int i = 0; i < n; i++) {
            if (!p[i].completed &&
                p[i].arrival_time <= time &&
                p[i].burst_time < min_bt) {

                min_bt = p[i].burst_time;
                idx = i;
            }
        }

        // Si no hay procesos listos, avanzar tiempo
        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].waiting_time = time - p[idx].arrival_time;
        time += p[idx].burst_time;
        p[idx].turnaround_time = time - p[idx].arrival_time;
        p[idx].completed = 1;

        // Guardar en orden de ejecución
        result[k++] = p[idx];
        completed++;
    }

    for (int i = 0; i < n; i++) {
        p[i] = result[i];
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

    sjf_schedule(p, n);

    print_results(p, n, "SJF Scheduling");
    return 0;
}
#endif