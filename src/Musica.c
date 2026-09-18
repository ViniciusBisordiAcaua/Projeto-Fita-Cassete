#include <stdio.h>

typedef struct {
    int minutos;
    int segundos;
    int duracaoSegundos;
} Musica;

int converterParaSegundos(int minutos, int segundos) {
    return minutos * 60 + segundos;
}

void imprimirMusica(Musica musica) {
    printf("%dm %ds\n", musica.minutos, musica.segundos);
}