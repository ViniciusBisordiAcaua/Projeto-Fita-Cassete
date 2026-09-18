#include <stdio.h>

//Estrutura que representa uma música 
typedef struct {
    int minutos;
    int segundos;
    int duracaoSegundos;
} Musica;

//Converter minutos e segundos para segundos
int converterParaSegundos(int minutos, int segundos) {
    return minutos * 60 + segundos;
}


//Cria uma música 
Musica criarMusica(int minutos, int segundos) {
    Musica musica;

    musica.minutos = minutos;
    musica.segundos = segundos;
    musica.duracaoSegundos = converterParaSegundos(minutos, segundos);

    return musica;
}

//Exibe uma música no formato pedido pelo projeto 
void imprimirMusica(Musica musica) {
    printf("%dm %ds\n", musica.minutos, musica.segundos);
}