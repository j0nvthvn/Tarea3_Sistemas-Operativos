//
// Created by jonathan on 12-11-25.
//

#include "memoria.h"
#include <stdio.h>
#include <stdlib.h>

SistemaMemoria *inicializar_sistema(int ram_mb, int tam_pagina_kb)
{
    // 1. Reservar memoria
    SistemaMemoria *sistema = (SistemaMemoria *)malloc(sizeof(SistemaMemoria));
    if (sistema == NULL)
    {
        fprintf(stderr, "Error: No se pudo reservar memoria para el sistema\n");
        return NULL;
    }

    // 2. Convertir MB a KB
    int ram_kb = ram_mb * 1024;
    sistema->tamaño_ram = ram_kb;
    sistema->tamaño_pagina = tam_pagina_kb;

    // 3. Calcular SWAP (aleatorio 1.5 a 4.5 veces)
    srand(time(NULL));
    float multiplicador = 1.5f + ((float)rand() / RAND_MAX) * 3.0f;
    sistema->tamaño_swap = (int)(ram_kb * multiplicador);

    // 4. Calcular num_frames_ram y num_frames_swap
    sistema->num_frames_ram = ram_kb / tam_pagina_kb;
    sistema->num_frames_swap = sistema->tamaño_swap / tam_pagina_kb;

    // 5. Crear arrays con calloc (inicializamos en NULL)
    sistema->ram = (Pagina **)calloc(sistema->num_frames_ram, sizeof(Pagina *));
    sistema->swap = (Pagina **)calloc(sistema->num_frames_swap, sizeof(Pagina *));

    if (sistema->ram == NULL || sistema->swap == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria para frames \n");
        free(sistema);
        return NULL;
    }

    // 6. Inicializar contadores
    sistema->frames_libres_ram = sistema->num_frames_ram;
    sistema->frames_libres_swap = sistema->num_frames_swap;

    // 7. Mostrar información
    printf("\n______________________________________ \n");
    printf("    SISTEMA DE MEMORIA INICIALIZANDO     \n");
    printf("  ______________________________________ \n");
    printf("  RAM:                                   \n");
    printf("    - Tamaño total:    %6d KB (%2d MB)   \n",
           ram_kb, ram_mb);
    printf("    - Frames totales:  %6d               \n\n",
           sistema->num_frames_ram);
    printf("  SWAP:                                  \n");
    printf("   - Tamaño total:     %6d KB (%.1fx RAM)\n",
           sistema->tamaño_swap, multiplicador);
    printf("   - Frames totales:   %6d               \n\n",
           sistema->num_frames_swap);
    printf("  PÁGINAS:                               \n");
    printf("   - Tamaño de página: %6d KB            \n",
           tam_pagina_kb);
    printf("  ______________________________________ \n");

    return sistema;
}

void liberar_sistema(SistemaMemoria *sistema)
{
    if (sistema == NULL)
        return;

    printf("\n[SISTEMA] Liberando memoria del sistema...\n");

    // Liberar todas las páginas en RAM
    if (sistema->ram != NULL)
    {
        for (int i = 0; i < sistema->num_frames_ram; i++)
        {
            if (sistema->ram[i] != NULL)
            {
                free(sistema->ram[i]);
                sistema->ram[i] = NULL;
            }
        }
        free(sistema->ram);
    }

    // Liberar todas las páginas n SWAP
    if (sistema->swap != NULL)
    {
        for (int i = 0; i < sistema->num_frames_swap; i++)
        {
            if (sistema->swap[i] != NULL)
            {
                free(sistema->swap[i]);
                sistema->swap[i] = NULL;
            }
        }
        free(sistema->swap);
    }

    // Liberar estructura del sistema
    free(sistema);

    printf("[SISTEMA] Memoria liberada exitosamente\n");
}

void mostrar_estado_memoria(SistemaMemoria *sistema)
{
    if (sistema == NULL)
        return;

    // Calcular frames usados
    int frames_usados_ram = sistema->num_frames_ram - sistema->frames_libres_ram;
    int frames_usados_swap = sistema->num_frames_swap - sistema->frames_libres_swap;

    // Calcular porcentajes de uso
    float porcentaje_ram = (frames_usados_ram * 100.0f) / sistema->num_frames_ram;
    float porcentaje_swap = (frames_usados_swap * 100.0f) / sistema->num_frames_swap;

    // Calcular KB usados
    int kb_usados_ram = frames_usados_ram * sistema->tamaño_pagina;
    int kb_usados_swap = frames_usados_swap * sistema->tamaño_pagina;

    printf("\n______________________________________ \n");
    printf("          ESTADO DE MEMORIA              \n");
    printf("  ______________________________________ \n");

    // Info de RAM
    printf("  RAM:                                   \n");
    printf("    Usado:   %6d / %6d frames (%5.1f%%)  \n",
           frames_usados_ram, sistema->num_frames_ram, porcentaje_ram);
    printf("             %6d / %6d KB                \n",
           kb_usados_ram, sistema->tamaño_ram);
    printf("    Libre:   %6d frames                  \n",
           sistema->frames_libres_ram);

    // Info de SWAP
    printf("  SWAP:                                   \n");
    printf("    Usado:   %6d / %6d frames (%5.1f%%)  \n",
           frames_usados_swap, sistema->num_frames_swap, porcentaje_swap);
    printf("             %6d / %6d KB                \n",
           kb_usados_swap, sistema->tamaño_swap);
    printf("    Libre:   %6d frames                  \n",
           sistema->frames_libres_swap);
    printf("  ______________________________________ \n");
}

int asignar_frame_ram(SistemaMemoria* sistema, Pagina* pag) {
    // 1. Verificar que hay frames libres
    // 2. Buscar primer frame NULL
    // 3. Asignar pagina al frame
    // 4. Actualizar campos de la pagina
    // 5. Decrementar contador
    // 6. Retornar numero de frame
}

int asignar_frame_swap(SistemaMemoria* sistema, Pagina* pag) {
    // Similar a asignar_frame_ram pero en SWAP
}

void liberar_memoria_ram(SistemaMemoria* sistema, int frame) {
    // 1. Verficar que frame es valido
    // 2. Poner frame en NULL
    // 3. Incrementar contador
}

void liberar_memoria_swap(SistemaMemoria* sistema, Pagina* pag) {
    // 1. Buscar pagina en SWAP
    // 2. Poner en NULL
    // 3. Incrementar contador
}