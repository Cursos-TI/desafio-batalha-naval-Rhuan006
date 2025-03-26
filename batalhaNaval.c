#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se o navio pode ser posicionado
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H' && (coluna + i >= TAMANHO || tabuleiro[linha][coluna + i] == NAVIO)) return 0;
        if (direcao == 'V' && (linha + i >= TAMANHO || tabuleiro[linha + i][coluna] == NAVIO)) return 0;
        if (direcao == 'D' && (linha + i >= TAMANHO || coluna + i >= TAMANHO || tabuleiro[linha + i][coluna + i] == NAVIO)) return 0;
        if (direcao == 'I' && (linha + i >= TAMANHO || coluna - i < 0 || tabuleiro[linha + i][coluna - i] == NAVIO)) return 0;
    }
    return 1;
}

// Função para posicionar navios no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') tabuleiro[linha][coluna + i] = NAVIO;
        if (direcao == 'V') tabuleiro[linha + i][coluna] = NAVIO;
        if (direcao == 'D') tabuleiro[linha + i][coluna + i] = NAVIO;
        if (direcao == 'I') tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionando navios (3 casas cada)
    if (podePosicionar(tabuleiro, 2, 2, 3, 'H'))
        posicionarNavio(tabuleiro, 2, 2, 3, 'H'); // Horizontal
    if (podePosicionar(tabuleiro, 4, 5, 3, 'V'))
        posicionarNavio(tabuleiro, 4, 5, 3, 'V'); // Vertical
    if (podePosicionar(tabuleiro, 0, 0, 3, 'D'))
        posicionarNavio(tabuleiro, 0, 0, 3, 'D'); // Diagonal principal
    if (podePosicionar(tabuleiro, 0, 9, 3, 'I'))
        posicionarNavio(tabuleiro, 0, 9, 3, 'I'); // Diagonal inversa

    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);
    return 0;
}