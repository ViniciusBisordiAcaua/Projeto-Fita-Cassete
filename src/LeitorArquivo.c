#include <stdio.h>
#include <stdlib.h>

#define MAX_MUSICAS 50

typedef struct {
    int minutos;
    int segundos;
    int duracaoSegundos;
} Musica;

//Converte minutos e segundos para segundos
int converterParaSegundos(int minutos, int segundos) {
    return (minutos * 60) + segundos;
    
}

//Lê um caso de teste do arquivo 
int lerCaso(FILE *arquivo, int *duracaoFita, int *quantidadeMusicas, Musica musicas[]) {
    if (fscanf(arquivo, "%d %d", duracaoFita, quantidadeMusicas) != 2) {
        return 0;
    }

    if (*quantidadeMusicas > MAX_MUSICAS) {

        printf("Erro: quantidade de musicas maior que 50.\n");

        return 0;
    }

    for (int i = 0; i < *quantidadeMusicas; i++) {
        int minutos;
        int segundos;
        if (fscanf(arquivo, "%d %d", &minutos, &segundos) != 2) {
            printf("Erro ao ler musica.\n");
            return 0;
        }

        musicas[i].minutos = minutos;
        musicas[i].segundos = segundos;
        musicas[i].duracaoSegundos = converterDuracao(minutos, segundos);

    }

    return 1;

}