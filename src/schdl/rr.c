#include <stdio.h>
#include "process.h"


void rr_schedule(Process p[], int n, int quantum)
{
    (void)p;
    (void)n;
    (void)quantum;

    // TODO: Aquí va la lógica de RR

    int time = 0;          
    int completed = 0;     
    int executed;          

    while (completed < n) {
        executed = 0;

        for (int i = 0; i < n; i++) {

            // Verificar si el proceso ya llegó y no ha terminado
            if (p[i].arrival_time <= time && p[i].remaining_time > 0) {
                executed = 1;

                int exec_time = (p[i].remaining_time > quantum)
                                ? quantum
                                : p[i].remaining_time;

                time += exec_time;
                p[i].remaining_time -= exec_time;

                // Si el proceso termina
                if (p[i].remaining_time == 0) {
                    p[i].completed = 1;
                    completed++;

                    p[i].turnaround_time = time - p[i].arrival_time;
                    p[i].waiting_time =
                        p[i].turnaround_time - p[i].burst_time;
                }
            }
        }

        if (!executed) {
            time++;
        }
    }
}

#ifndef UNIT_TEST
int main(void)
{
    int n;
    int quantum;

    printf("Número de procesos: ");
    scanf("%d", &n);

    printf("Quantum: ");
    scanf("%d", &quantum);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    rr_schedule(p, n, quantum);

    //Imprime los resultados
    print_results(p, n, "RR Scheduling");
    return 0;
}
#endif
