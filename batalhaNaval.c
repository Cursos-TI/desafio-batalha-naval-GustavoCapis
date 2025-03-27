#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main()
{
    // Tabuleiro 10x10 inicializado com zeros (0 = água, 3 = navio)
    int tabuleiro[LINHAS][COLUNAS] = {0}; // Cria uma matriz 10x10 com todos os elementos zerados

    // Navios: arrays que representam partes de navios (cada 3 é uma parte do navio)
    int navioVertical[3] = {3, 3, 3};   // Navio vertical de 3 partes
    int navioHorizontal[3] = {3, 3, 3}; // Navio horizontal de 3 partes
    int navioDiagonal1[3] = {3, 3, 3};  // Navio diagonal de 3 partes
    int navioDiagonal2[3] = {3, 3, 3};

    // Imprime o cabeçalho das colunas (A até J)
    printf("   ");                                // Espaçamento para alinhar com os números das linhas
    for (char letra = 'A'; letra <= 'J'; letra++) // Loop de 'A' a 'J' (10 colunas)
    {
        printf(" %c", letra); // Imprime cada letra do cabeçalho
    }
    printf("\n"); // Quebra de linha após o cabeçalho

    // Posiciona o navio HORIZONTAL no tabuleiro (linha 2, colunas 6-8)
    for (int h = 0; h < 3; h++) // Loop para as 3 partes do navio horizontal
    {
        tabuleiro[2][6 + h] = navioHorizontal[h]; // Coloca cada parte do navio (valor 3)
    }

    // Posiciona o navio VERTICAL no tabuleiro (coluna 4, linhas 4-6)
    for (int v = 0; v < 3; v++) // Loop para as 3 partes do navio vertical
    {
        tabuleiro[4 + v][4] = navioVertical[v]; // Coloca cada parte do navio (valor 3)
    }

// Posiciona o navio DIAGONAL 1 no tabuleiro
for (int i = 0; i < LINHAS; i++) // Loop que itera sobre cada linha do tabuleiro
{
    for (int j = 0; j < COLUNAS; j++) // Loop que itera sobre cada coluna do tabuleiro
    {
        // Verifica se estamos na diagonal principal (i == j) e se o índice da linha (i) está entre 0 e 2
        if (i == j && i >= 0 && i < 3) 
        {
            tabuleiro[i][j] = 3; // Se a condição for verdadeira, coloca o valor 3 na posição (i, j) do tabuleiro
        }
    }
}

// Posiciona o navio DIAGONAL 2 no tabuleiro
for (int i = 0; i < LINHAS; i++) // Loop que itera sobre cada linha do tabuleiro
{
    for (int j = 0; j < COLUNAS; j++) // Loop que itera sobre cada coluna do tabuleiro
        // Verifica se a soma dos índices (i + j) é igual a 9 e se o índice da linha (i) está entre 7 e 9
        if (i + j == 9 && i >= 7 && i <= 9) 
        {
            tabuleiro[i][j] = 3; // Se a condição for verdadeira, coloca o valor 3 na posição (i, j) do tabuleiro
        }
}    

    // Imprime o tabuleiro completo com numeração das linhas
    for (int i = 0; i < LINHAS; i++) // Loop pelas linhas (0 a 9)
    {
        printf("%d  ", i);                // Imprime o número da linha com alinhamento
        for (int j = 0; j < COLUNAS; j++) // Loop pelas colunas (0 a 9)
        {
            printf(" %d", tabuleiro[i][j]); // Imprime cada célula do tabuleiro
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }

    return 0; // Retorna 0 indicando execução bem-sucedida
}