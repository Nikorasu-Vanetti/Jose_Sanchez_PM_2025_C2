#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nombre[50];
    float promedio;
} Alumno;

// Prototipos
void guardarAlumnos(const char *filename);
int leerAlumnos(const char *filename, Alumno alumnos[]);
void ordenarPorNombre(Alumno alumnos[], int n);
void ordenarPorPromedio(Alumno alumnos[], int n);
void imprimirAlumnos(Alumno alumnos[], int n);
void intercambiar(Alumno *a, Alumno *b);

int main() {
    Alumno alumnos[MAX];
    int cantidad, opcion;
    char filename[] = "alumnos.dat";

    guardarAlumnos(filename);
    cantidad = leerAlumnos(filename, alumnos);

    if (cantidad == 0) {
        printf("No hay alumnos para mostrar.\n");
        return 0;
    }

    printf("Seleccione el orden:\n");
    printf("1. Ordenar por nombre (alfabético)\n");
    printf("2. Ordenar por promedio\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        ordenarPorNombre(alumnos, cantidad);
    } else if (opcion == 2) {
        ordenarPorPromedio(alumnos, cantidad);
    } else {
        printf("Opción no válida.\n");
        return 1;
    }

    imprimirAlumnos(alumnos, cantidad);
    return 0;
}

void guardarAlumnos(const char *filename) {
    FILE *f = fopen(filename, "wb");
    int n;

    if (!f) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }

    printf("¿Cuántos alumnos desea ingresar? ");
    scanf("%d", &n);
    getchar();  // limpiar buffer

    for (int i = 0; i < n; i++) {
        Alumno a;
        printf("Nombre del alumno %d: ", i + 1);
        fgets(a.nombre, sizeof(a.nombre), stdin);
        a.nombre[strcspn(a.nombre, "\n")] = '\0';  // elimina salto de línea

        printf("Promedio de %s: ", a.nombre);
        scanf("%f", &a.promedio);
        getchar(); // limpiar buffer

        fwrite(&a, sizeof(Alumno), 1, f);
    }

    fclose(f);
}

int leerAlumnos(const char *filename, Alumno alumnos[]) {
    FILE *f = fopen(filename, "rb");
    int i = 0;

    if (!f) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }

    while (fread(&alumnos[i], sizeof(Alumno), 1, f)) {
        i++;
    }

    fclose(f);
    return i;
}

void ordenarPorNombre(Alumno alumnos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0) {
                intercambiar(&alumnos[j], &alumnos[j + 1]);
            }
        }
    }
}

void ordenarPorPromedio(Alumno alumnos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (alumnos[j].promedio > alumnos[j + 1].promedio) {
                intercambiar(&alumnos[j], &alumnos[j + 1]);
            }
        }
    }
}

void intercambiar(Alumno *a, Alumno *b) {
    Alumno temp = *a;
    *a = *b;
    *b = temp;
}

void imprimirAlumnos(Alumno alumnos[], int n) {
    printf("\nLista de alumnos:\n");
    for (int i = 0; i < n; i++) {
        printf("Nombre: %-20s | Promedio: %.2f\n", alumnos[i].nombre, alumnos[i].promedio);
    }
}
