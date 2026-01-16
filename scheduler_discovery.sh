#!/bin/bash

# exploracion del scheduler linux
# ruta: /usr/src/linux-headers-$(uname -r)/kernel/sched/fair.c

echo "localizando el archivo del scheduler..."
ruta_archivo="/usr/src/linux-headers-$(uname -r)/kernel/sched/fair.c"

echo "el archivo se encuentra en: $ruta_archivo"
echo ""

# explicacion:
# linux usa cfs (completely fair scheduler)
# se basa en el tiempo de ejecucion virtual (vruntime)
# busca que cada proceso tenga una parte justa de cpu
# usa un arbol rojo-negro para decidir quien sigue

echo "mostrando el codigo real del scheduler (primeras lineas):"
echo ""
cat $ruta_archivo | head -n 50

echo ""
echo "pregunta de reflexion:"
echo "por que linux no usa fcfs, sjf o rr de los libros?"
echo "respuesta: los algoritmos teoricos son muy simples para la vida real"
echo "fcfs haria que el sistema se trabe con procesos largos"
echo "sjf no se puede porque no sabemos cuanto durara un proceso a futur"
echo "rr no maneja bien las prioridades complejas."
echo "linux usa cfs porque es mas eficiente y justo para el usuario"

