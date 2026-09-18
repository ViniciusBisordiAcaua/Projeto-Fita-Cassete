#include <stdio.h>

#define MAX_MUSICAS 50

typedef struct {
    int minutos;
    int segundos;
    int duracaoSegundos;
} Musica;

int lerCaso(
    FILE *arquivo,
    int *duracaoFita,
    int *quantidadeMusicas,
    Musica musicas[]
) {
    if (fscanf(arquivo, "%d %d", duracaoFita, quantidadeMusicas) != 2) {
        return 0;
    }

    if (*quantidadeMusicas < 0 || *quantidadeMusicas > MAX_MUSICAS) {
        return 0;
    }

    for (int i = 0; i < *quantidadeMusicas; i++) {

        int minutos;
        int segundos;

        if (fscanf(arquivo, "%d %d", &minutos, &segundos) != 2) {
            return 0;
        }

        musicas[i].minutos = minutos;
        musicas[i].segundos = segundos;

        musicas[i].duracaoSegundos =
            minutos * 60 + segundos;
    }

    return 1;
}