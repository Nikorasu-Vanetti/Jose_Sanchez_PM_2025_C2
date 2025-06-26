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
    printf("Introduce un número ASCII: ");
    scanf("%d", &num);

    // Mostrar información básica
    printf("\nNúmero ASCII: %d", num);
    printf("\nCarácter correspondiente: %c", num);

    // Verificar y convertir
    if (esMayuscula(num)) {
        printf("\nEs mayúscula");
        int minuscula = num + 32;
        printf("\nConvertido a minúscula: %c (%d)", minuscula, minuscula);
    }
    else if (esMinuscula(num)) {
        printf("\nEs minúscula");
        int mayuscula = num - 32;
        printf("\nConvertido a mayúscula: %c (%d)", mayuscula, mayuscula);
    }
    else {
        printf("\nNo es una letra");
    }

    printf("\n");
    return 0;
}
