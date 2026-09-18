#include <stdio.h>

#define MAX_MUSICAS 50

typedef struct {
    int minutos;
    int segundos;
    int duracaoSegundos;
} Musica;

int backtracking(
    Musica musicas[],
    int quantidade,
    int indice,
    int tempoA,
    int tempoB,
    int capacidadeLado,
    int lado[]
) {
    // Caso base:
    // todas as músicas foram distribuídas
    if (indice == quantidade) {
        return 1;
    }

    // Tenta colocar a música atual no Lado A
    if (tempoA + musicas[indice].duracaoSegundos <= capacidadeLado) {

        lado[indice] = 1;

        if (backtracking(
                musicas,
                quantidade,
                indice + 1,
                tempoA + musicas[indice].duracaoSegundos,
                tempoB,
                capacidadeLado,
                lado
            )) {

            return 1;
        }
    }

    // Tenta colocar a música atual no Lado B
    if (tempoB + musicas[indice].duracaoSegundos <= capacidadeLado) {

        lado[indice] = 2;

        if (backtracking(
                musicas,
                quantidade,
                indice + 1,
                tempoA,
                tempoB + musicas[indice].duracaoSegundos,
                capacidadeLado,
                lado
            )) {

            return 1;
        }
    }

    // Nenhuma escolha funcionou
    lado[indice] = 0;

    return 0;
}

int resolver(
    Musica musicas[],
    int quantidade,
    int duracaoFitaMinutos,
    int lado[]
) {
    // A duração L representa a fita inteira.
    // Portanto, cada lado possui metade.
    int capacidadeLado =
        (duracaoFitaMinutos * 60) / 2;

    for (int i = 0; i < quantidade; i++) {
        lado[i] = 0;
    }

    return backtracking(
        musicas,
        quantidade,
        0,
        0,
        0,
        capacidadeLado,
        lado
    );
}