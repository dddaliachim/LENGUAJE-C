#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ALIMENTOS 4  

int main() {
  
    float precios[NUM_ALIMENTOS] = {50.00, 80.00, 25.00, 20.50};
    int cantidades[NUM_ALIMENTOS] = {0, 0, 0, 0};
    int cantidad;
    int opcion;
    char continuar;

    char **alimentos = (char **)malloc(NUM_ALIMENTOS * sizeof(char *));
    if (alimentos == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < NUM_ALIMENTOS; i++) {
        alimentos[i] = (char *)malloc(50 * sizeof(char));  
        if (alimentos[i] == NULL) {
            printf("Error al asignar memoria.\n");
            return 1;
        }
        printf("Ingresa el nombre del alimento %d: ", i + 1);
        scanf("%s", alimentos[i]);  
    }

    printf("Bienvenido al restaurante\n");

   
    do {
        printf("\nMenu:\n");
        for (int i = 0; i < NUM_ALIMENTOS; i++) {
            printf("%d - %s - $%.2f\n", i + 1, alimentos[i], precios[i]);
        }
        printf("5) Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= NUM_ALIMENTOS) {
            printf("Ingresa la cantidad de %s: ", alimentos[opcion - 1]);
            scanf("%d", &cantidad);
            cantidades[opcion - 1] += cantidad;

            printf("¿Deseas ordenar algo más? (s/n): ");
            scanf(" %c", &continuar);
        } else if (opcion == 5) {
            printf("Has salido del pedido.\n");
            break;
        } else {
            printf("Opción no válida. Intenta nuevamente.\n");
            continuar = 's';  
        }

    } while (continuar == 's' || continuar == 'S');

    // Mostrar resumen de cuenta
    printf("\n--- Resumen de cuenta ---\n");
    float totalcuenta = 0.0;
    for (int i = 0; i < NUM_ALIMENTOS; i++) {
        if (cantidades[i] > 0) {
            float total = cantidades[i] * precios[i];
            printf("%s - $%.2f x %d = $%.2f\n", alimentos[i], precios[i], cantidades[i], total);
            totalcuenta += total;
        }
    }
    printf("Total a pagar: $%.2f\n", totalcuenta);

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < NUM_ALIMENTOS; i++) {
        free(alimentos[i]);
    }
    free(alimentos);

    return 0;
}
