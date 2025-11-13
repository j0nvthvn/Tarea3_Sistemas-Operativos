//
// Created by jonathan on 12-11-25.
//

#ifndef MEMORIA_H
#define MEMORIA_H

#include <time.h>
#include <stdbool.h>

typedef struct {
    int id_proceso;       // <- ¿De qué proceso es?
    int numero_pagina;    // <- ¿Qué página del proceso es?
    bool en_memoria_ram;  // <- ¿Está en RAM o en SWAP?
    int frame;            // <- ¿En que frame está? (NO aplica para SWAP, en
                          //                        ese caso frame = -1)
    time_t ultimo_acceso; // <- Para LRU
} Pagina;

typedef struct {
    int tamanio_ram;
    int tamanio_pagina;
    int tamanio_swap;

    // Frames
    int num_frames_swap;
    int num_frames_ram;

    // Arrays dinámicos de frames
    Pagina **ram;
    Pagina **swap;

    int frames_libres_ram;
    int frames_libres_swap;
} SistemaMemoria;

#endif //MEMORIA_H