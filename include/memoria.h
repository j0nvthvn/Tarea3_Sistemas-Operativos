//
// Created by jonathan on 12-11-25.
//

#ifndef MEMORIA_H
#define MEMORIA_H

#include <time.h>
#include <stdbool.h>

typedef struct SistemaMemoria SistemaMemoria;
typedef struct Pagina Pagina;

SistemaMemoria* inicializar_sistema(int ram_mb, int tam_pagina_mb);
void liberar_sistema(SistemaMemoria* sistema);
void mostrar_estado_memoria(SistemaMemoria* sistema);
int asignar_frame_ram(SistemaMemoria* sistema, Pagina* pag);
int asignar_frame_swap(SistemaMemoria* sistema, Pagina* pag);
void liberar_memoria_ram(SistemaMemoria* sistema, int frame);
void liberar_memoria_swap(SistemaMemoria* sistema, Pagina* pag);

/* Definiciones de las estructuras con nombre para no chocar con las forward declarations */
struct Pagina {
    int id_proceso;       // <- ¿De qué proceso es?
    int numero_pagina;    // <- ¿Qué página del proceso es?
    bool en_memoria_ram;  // <- ¿Está en RAM o en SWAP?
    int frame;            // <- ¿En qué frame está? (no aplica para SWAP, en
                          //                        ese caso frame = -1)
    time_t ultimo_acceso; // <- Para LRU
};

struct SistemaMemoria {
    int tamaño_ram;
    int tamaño_pagina;
    int tamaño_swap;

    // Frames
    int num_frames_swap;
    int num_frames_ram;

    // Arrays dinámicos de frames
    Pagina **ram;
    Pagina **swap;

    int frames_libres_ram;
    int frames_libres_swap;
};

#endif //MEMORIA_H