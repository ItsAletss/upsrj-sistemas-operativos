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
    int time=0;
    int completed = 0;

    while (completed < n){
        int min_burst = 9999; //para comparar los burst
        //indice de proeceso elegido 
        int ipe = -1;
  

    for (int i = 0; i < n; i++){
        if (p[i].arrival_time <= time && p[i].completed == 0 
        && p[i].burst_time < min_burst) {
            min_burst = p[i].burst_time;
            ipe = i;
        }
    }
    
    if (ipe != -1){
        //ejecuto el proceso seleccionado
        time += p[ipe].burst_time ;

        //aqui calculo el time de cuanto tardo
           p[ipe].turnaround_time = time - p[ipe].arrival_time;
           p[ipe].waiting_time = p[ipe].turnaround_time - p[ipe].burst_time;

           p[ipe].completed = 1;
           completed ++;
    }
    else { 
        time ++;

     }
    }
        
    

 

    print_results(p, n, "SJF Scheduling");
    return 0;
}