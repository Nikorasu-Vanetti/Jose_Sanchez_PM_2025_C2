#include <stdio.h>

int esMayuscula(int c) {
    if (c >= 65 && c <= 90){
        return 1;
    } else {
    return 0;
    }
}

int esMinuscula(int c) {
    if (c >= 97 && c <= 122) {
        return 1;
    } else {
    return 0;
    }
}

int main() {
    int num;
    printf("Introduce un n�mero ASCII: ");
    scanf("%d", &num);

    // Mostrar informaci�n b�sica
    printf("\nN�mero ASCII: %d", num);
    printf("\nCar�cter correspondiente: %c", num);

    // Verificar y convertir
    if (esMayuscula(num)) {
        printf("\nEs may�scula");
        int minuscula = num + 32;
        printf("\nConvertido a min�scula: %c (%d)", minuscula, minuscula);
    }
    else if (esMinuscula(num)) {
        printf("\nEs min�scula");
        int mayuscula = num - 32;
        printf("\nConvertido a may�scula: %c (%d)", mayuscula, mayuscula);
    }
    else {
        printf("\nNo es una letra");
    }

    printf("\n");
    return 0;
}
