//
// Created by jonathan on 12-11-25.
//

#ifndef PROCESO_H
#define PROCESO_H

#include <stdbool.h>

typedef struct {
    int id;
    int tamanio;      // Tamaño en Kb
    int num_paginas;  // ¿Cuántas páginas necesita?
    int *paginas_ids; // Referencias a sus páginas
    bool activo;      // ¿Está ejecutándose?

} Proceso;

#endif //PROCESO_H