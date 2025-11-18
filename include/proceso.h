//
// Created by jonathan on 12-11-25.
//

#ifndef PROCESO_H
#define PROCESO_H

#include <stdbool.h>

typedef struct Proceso Proceso;

Proceso* crear_proceso(int id, int tam_min, int tam_max, int tam_pagina);
void liberar_proceso(Proceso* proc);
void mostrar_proceso(Proceso* proc);

struct Proceso {
    int id;
    int tamano;      // Tamaño en Kb
    int num_paginas;  // ¿Cuántas páginas necesita?
    int *paginas_ids; // Referencias a sus páginas
    bool activo;      // ¿Está ejecutándose?

};

#endif //PROCESO_H