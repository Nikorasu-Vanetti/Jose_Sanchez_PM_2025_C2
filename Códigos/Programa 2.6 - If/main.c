#include <stdio.h>
#include <math.h>
/* Función matemática.
El programa obtiene el resultado de una función.
OP y T: variables de tipo entero.
RES: variable de tipo real. */
int main(void)
{
    int OP, T;
    float RES;
    printf("Ingrese la opción del cálculo y el valor entero: ");
    scanf("%d %d", &OP, &T);

    if (OP == 1)
    {
        RES = T / 5.0; // ¡Atento! Usé 5.0 para asegurar división flotante.
    }
    else if (OP == 2)
    {
        RES = pow(T, T);
    }
    else if (OP == 3 || OP == 4)
    {
        RES = 6 * T / 2.0; // Dividir entre 2.0 para asegurar flotante.
    }
    else
    {
        RES = 1;
    }

    printf("\nResultado: %7.2f", RES);

    return 0;
}
