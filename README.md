# Projeto-Fita-Cassete

## Projeto e Análise de Algoritmos II

Projeto desenvolvido para a disciplina de **Projeto e Análise de Algoritmos II** da Universidade Presbiteriana Mackenzie.

## Objetivo

Desenvolver um programa capaz de distribuir uma lista de músicas entre os dois lados de uma fita cassete.

Cada música possui uma duração em minutos e segundos, e os lados **A** e **B** possuem a mesma capacidade.

O programa deverá encontrar uma combinação que permita gravar **todas as músicas** sem ultrapassar o limite de duração de cada lado da fita.

Caso não exista uma combinação possível, o programa deverá informar que não é possível gravar todas as músicas.

## Funcionamento

O programa recebe os dados através do arquivo:

```text
tape.in
```

Para cada caso de teste são informados:

* duração total da fita;
* quantidade de músicas;
* duração de cada música.

O programa deverá então encontrar uma distribuição válida entre:

```text
Lado A
Lado B
```

Caso não exista uma distribuição possível:

```text
Impossivel gravar as musicas nessa fita.
```

## Integrantes

* **Integrante 1:** Caio
* **Integrante 2:** Helen
* **Integrante 3:** Vinicius Bisordi Acauã / RA: 10739883

## Divisão das atividades

### Integrante 1 – Entrada e modelagem

Responsável por:

* leitura do arquivo `tape.in`;
* representação das músicas;
* tratamento e preparação dos dados.

### Integrante 2 – Algoritmo

Responsável por:

* implementação do algoritmo principal;
* busca pela distribuição das músicas;
* verificação da capacidade dos lados A e B;
* análise da solução.

### Integrante 3 – Saída e testes

Responsável por:

* apresentação da solução;
* organização das músicas dos lados A e B;
* tratamento dos casos impossíveis;
* criação e execução dos testes.

## Tecnologia utilizada

* Java
* Git
* GitHub
* GitHub Codespaces

## Estrutura do projeto

```text
projeto-fita/
│
├── src/
│   ├── Musica.java
│   ├── LeitorArquivo.java
│   ├── Solver.java
│   └── Main.java
│
├── tape.in
│
└── README.md
```