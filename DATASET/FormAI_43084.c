//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Bienvenido a la traducción de lenguaje de gato C.\n");
    printf("Por favor, ingrese la línea de código a traducir.\n");
    fgets(input, 100, stdin);
    strtok(input, "\n");

    printf("\nTraducción de lenguaje de gato C:\n");

    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        switch (input[i]) {
            case '(': printf("mi"); break;
            case ')': printf("au"); break;
            case '{': printf("ronroneo"); break;
            case '}': printf("maullido"); break;
            case '<': printf("prrrr"); break;
            case '>': printf("bufido"); break;
            case '+': printf("ronroneo alto"); break;
            case '-': printf("ronroneo bajo"); break;
            case '*': printf("arañazo"); break;
            case '/': printf("toma un baño"); break;
            case '%': printf("juego con un ovillo de lana"); break;
            case '=': printf("marco mi territorio"); break;
            case ';': printf("ronroneo suave"); break;
            case ',': printf("ronroneo corto"); break;
            case '0': printf("cero"); break;
            case '1': printf("uno"); break;
            case '2': printf("dos"); break;
            case '3': printf("tres"); break;
            case '4': printf("cuatro"); break;
            case '5': printf("cinco"); break;
            case '6': printf("seis"); break;
            case '7': printf("siete"); break;
            case '8': printf("ocho"); break;
            case '9': printf("nueve"); break;
            case 'a': printf("ronroneo miau"); break;
            case 'b': printf("ronroneo marrón"); break;
            case 'c': printf("ronroneo claro"); break;
            case 'd': printf("ronroneo oscuro"); break;
            case 'e': printf("ronroneo entrada"); break;
            case 'f': printf("ronroneo salida"); break;
            case 'g': printf("ronroneo grande"); break;
            case 'h': printf("ronroneo pequeño"); break;
            case 'i': printf("adivino que quiere un pescado"); break;
            case 'j': printf("ronroneo puntiagudo"); break;
            case 'k': printf("ronroneo peludo"); break;
            case 'l': printf("ronroneo rizado"); break;
            case 'm': printf("ronroneo múltiples"); break;
            case 'n': printf("ronroneo ninguno"); break;
            case 'o': printf("ronroneo octal"); break;
            case 'p': printf("ronroneo privado"); break;
            case 'q': printf("ronroneo rápido"); break;
            case 'r': printf("ronroneo crudo"); break;
            case 's': printf("ronroneo estático"); break;
            case 't': printf("ronroneo temporal"); break;
            case 'u': printf("ronroneo sin signo"); break;
            case 'v': printf("ronroneo volátil"); break;
            case 'w': printf("ronroneo ancho"); break;
            case 'x': printf("ronroneo hexadeciaml"); break;
            case 'y': printf("ronroneo ay"); break;
            case 'z': printf("ronroneo zzz"); break;
            case 'A': printf("ronroneo meow"); break;
            case 'B': printf("ronroneo Black"); break;
            case 'C': printf("ronroneo Clear"); break;
            case 'D': printf("ronroneo Dark"); break;
            case 'E': printf("ronroneo Entry"); break;
            case 'F': printf("ronroneo Fast"); break;
            case 'G': printf("ronroneo Great"); break;
            case 'H': printf("ronroneo Huge"); break;
            case 'I': printf("ronroneo In"); break;
            case 'J': printf("ronroneo Jagged"); break;
            case 'K': printf("ronroneo Kitty"); break;
            case 'L': printf("ronroneo Long"); break;
            case 'M': printf("ronroneo Multi"); break;
            case 'N': printf("ronroneo None"); break;
            case 'O': printf("ronroneo Octal"); break;
            case 'P': printf("ronroneo Private"); break;
            case 'Q': printf("ronroneo Quick"); break;
            case 'R': printf("ronroneo Raw"); break;
            case 'S': printf("ronroneo Static"); break;
            case 'T': printf("ronroneo Temp"); break;
            case 'U': printf("ronroneo Unsigned"); break;
            case 'V': printf("ronroneo Volatile"); break;
            case 'W': printf("ronroneo Wide"); break;
            case 'X': printf("ronroneo Hex"); break;
            case 'Y': printf("ronroneo Why"); break;
            case 'Z': printf("ronroneo Zzz"); break;
            default: printf("¡No entiendo lo que estás diciendo!\n"); break;
        }
    }

    return 0;
}