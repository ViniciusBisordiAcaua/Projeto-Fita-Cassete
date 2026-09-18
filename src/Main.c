#include <stdio.h>

#define MAX_MUSICAS 50

typedef struct {
    int minutos;
    int segundos;
    int duracaoSegundos;
} Musica;


// Função implementada no LeitorArquivo.c
int lerCaso(
    FILE *arquivo,
    int *duracaoFita,
    int *quantidadeMusicas,
    Musica musicas[]
);


// Função implementada no Solver.c
int resolver(
    Musica musicas[],
    int quantidade,
    int duracaoFitaMinutos,
    int lado[]
);


int main(void) {

    FILE *arquivo = fopen("entrada/tape.in", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir entrada/tape.in\n");
        return 1;
    }

    int quantidadeCasos;

    if (fscanf(arquivo, "%d", &quantidadeCasos) != 1) {
        printf("Erro ao ler a quantidade de casos.\n");
        fclose(arquivo);
        return 1;
    }


    for (int caso = 1; caso <= quantidadeCasos; caso++) {

        int duracaoFita;
        int quantidadeMusicas;

        Musica musicas[MAX_MUSICAS];
        int lado[MAX_MUSICAS];


        // Lê um caso do tape.in
        if (!lerCaso(
                arquivo,
                &duracaoFita,
                &quantidadeMusicas,
                musicas
            )) {

            printf("Erro ao ler o caso %d.\n", caso);

            fclose(arquivo);
            return 1;
        }


        // Chama o Solver
        int possivel = resolver(
            musicas,
            quantidadeMusicas,
            duracaoFita,
            lado
        );


        printf("Caso:%d\n", caso);


        if (!possivel) {

            printf("Impossivel gravar as musicas nessa fita.\n");

        } else {

            printf("Lado A\n");

            for (int i = 0; i < quantidadeMusicas; i++) {

                if (lado[i] == 1) {

                    printf(
                        "%dm %ds\n",
                        musicas[i].minutos,
                        musicas[i].segundos
                    );
                }
            }


            printf("Lado B\n");

            for (int i = 0; i < quantidadeMusicas; i++) {

                if (lado[i] == 2) {

                    printf(
                        "%dm %ds\n",
                        musicas[i].minutos,
                        musicas[i].segundos
                    );
                }
            }
        }


        if (caso < quantidadeCasos) {
            printf("\n");
        }
    }


    fclose(arquivo);

    return 0;
}