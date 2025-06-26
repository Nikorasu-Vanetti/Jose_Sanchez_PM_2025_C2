#include <stdio.h>
/* Frecuencia de calificaciones.
El programa, al recibir como datos las calificaciones de un grupo de 50
alumnos, obtiene la frecuencia de cada una de las calificaciones y adem�s
escribe cu�l es la frecuencia m�s alta. */
const int TAM = 50;
void Lectura(int VEC[], int T);
void Frecuencia(int VEC[], int T1, int FRE[], int T2); /* Prototipo corregido */
void Impresion(int VEC[], int T);
void Mayor(int VEC[], int T);
void main(void)
{
    int CAL[TAM], FRE[6] = {0}; /* Declaraci�n de los arreglos. */
    Lectura(CAL, TAM); /* Se llama a la funci�n Lectura. */
    Frecuencia(CAL, TAM, FRE, 6);
    /* Se llama a la funci�n Frecuencia, se pasan ambos arreglos. */
    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);
    Mayor(FRE, 6);
}
void Lectura(int VEC[], int T)
/* La funci�n Lectura se utiliza para leer el arreglo de calificaciones. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese la calificaci�n -0:5- del alumno %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}
void Frecuencia(int VEC[], int T1, int FRE[], int T2)
/* La funci�n Frecuencia calcula la frecuencia de cada calificaci�n (0 a 5). */
{
    int I;
    for (I = 0; I < T1; I++)
    {
        if (VEC[I] >= 0 && VEC[I] <= 5) /* Asumimos calificaciones v�lidas */
            FRE[VEC[I]]++;
    }
}
void Impresion(int VEC[], int T)
/* La funci�n Impresion imprime las frecuencias de las calificaciones. */
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nCalificaci�n %d: %d", I, VEC[I]);
}
void Mayor(int VEC[], int T)
/* La funci�n Mayor encuentra e imprime la frecuencia m�s alta. */
{
    int I, MAY = VEC[0], IND = 0;
    for (I = 1; I < T; I++)
        if (VEC[I] > MAY)
        {
            MAY = VEC[I];
            IND = I;
        }
    printf("\n\nFrecuencia m�s alta: %d (Calificaci�n %d)\n", MAY, IND);
}
