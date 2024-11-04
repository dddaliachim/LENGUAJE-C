#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
// Definición de la estructura Persona 
typedef struct {
    char nombre[50];
    int edad;
} Persona;

// Función para ordenar las personas de mayor a menor edad
// "n" toma el valor de elementos en la lista(en este caso es 3)
void ordenarPersonas(Persona personas[], int n) { 
    // temp es nuestra variable donde se almacenra temporalmente los datos de "persona"
    Persona temp;
    //help meeeee no me sale la estrycturaaaaaa de burbujaaaaaaaa aaaaaaaaaaaaaaaahhhhhhhhhhhhhhh:(
    //creo que ya me salio...falsa a larma(creo:v)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            //este es para comparar las edades y poder saber cual es la mayor
            if (personas[i].edad < personas[j].edad) {
                temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
        }
    }
}

int main() {
    Persona personas[3]; //cantidad de elementos que tendra la lista personas
    //tiene el valor 3 para usarlo en el contador para ordenar por edades
    int n = 3;
    // ciclo for para que el usuario ingrese los nombres y edades segun corresponda:)
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        scanf("%s", personas[i].nombre);
        //procedemos a pedir la edad de la persona segun sunombre
        printf("Ingrese la edad de %s: ", personas[i].nombre);
        scanf("%d", &personas[i].edad);
    }

    // llamamos a la funcion "Ordenarpersonas" para ordenarlas de mayor a menor edad...
    //(creoq ya ahora si mee salio:) tengo fe 
    ordenarPersonas(personas, n);

    // mostramos la lista ordenada(intento num 19 ("se hacia un bucle pipipi"))
    for (int i = 0; i < n; i++) {
        // imprimimos el indice,el nombre y la edad de las personas corespondientemente(segun lo guardado en el struct)
        printf("%d. %s, tu tienes %d anios de edad\n", i + 1, personas[i].nombre, personas[i].edad);
    }

    // le mostramos el mensaje al usuario de quien es mayor y quien es el menor de los tres(el de en medio no aparecexd)

    printf("La persona mayor es: %s con %d anios\n", personas[0].nombre, personas[0].edad);

    printf("La persona con menos edad es: %s con %d anios\n", personas[n - 1].nombre, personas[n - 1].edad);

    // y a jala asi que a momirZZZZZZZZ(son las 1:35 am del lunes:) 
    //fue un finde ocupadito(llora en miniadulto pipipi:'(

    return 0;
}
