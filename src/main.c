//
// Created by jonathan on 12-11-25.
//

#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"

int main()
{

    printf("Iniciando programa...\n\n");
    printf(" \n_______________________________________\n");

    printf("|    SIMULADOR DE PAGINACIÓN DE MEMORIA |\n");
    printf(" _______________________________________ \n");

    int ram_mb, tam_pagina_kb;
    printf("Ingrese un tamaño de RAM (MB): ");
    scanf("%d", &ram_mb);

    printf("Ingrese el tamaño de página en KB: ");
    scanf("%d", &tam_pagina_kb);

    if (ram_mb <= 0 || tam_pagina_kb <= 0)
    {
        fprintf(stderr, "Error: Los valores deben ser positivos\n");
        return 0;
    }

    SistemaMemoria *sistema = inicializar_sistema(ram_mb, tam_pagina_kb);

    printf("Estado inicial de la memoria:\n");
    mostrar_estado_memoria(sistema);

    printf("[PRUEBA] Simulando uso de memoria...\n");
    sistema->frames_libres_ram -= 10;
    sistema->frames_libres_swap -= 5;

    mostrar_estado_memoria(sistema);

    liberar_sistema(sistema);

    printf("[PRUEBA] Programa finalizado correctamente\n\n");

    return 0;
}