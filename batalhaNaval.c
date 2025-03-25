#include <stdio.h>

#define TAMANHO 10  // Tamanho do tabuleiro (10x10)
#define NAVIO_TAMANHO 3  // Tamanho dos navios

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Inicializa com água (0)
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    // Valida se o navio cabe dentro do tabuleiro
    if ((direcao == 'H' && coluna + NAVIO_TAMANHO > TAMANHO) ||
        (direcao == 'V' && linha + NAVIO_TAMANHO > TAMANHO)) {
        return 0; // Falha no posicionamento
    }
    
    // Valida se há sobreposição
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        if ((direcao == 'H' && tabuleiro[linha][coluna + i] != 0) ||
            (direcao == 'V' && tabuleiro[linha + i][coluna] != 0)) {
            return 0; // Falha no posicionamento
        }
    }

    // Posiciona o navio
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = 3;
        } else {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
    return 1; // Sucesso
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Definição fixa das coordenadas iniciais dos navios
    int linhaH = 2, colunaH = 3; // Navio horizontal começa em (2,3)
    int linhaV = 5, colunaV = 6; // Navio vertical começa em (5,6)

    // Tenta posicionar os navios
    if (!posicionarNavio(tabuleiro, linhaH, colunaH, 'H')) {
        printf("Falha ao posicionar navio horizontal.\n");
    }
    if (!posicionarNavio(tabuleiro, linhaV, colunaV, 'V')) {
        printf("Falha ao posicionar navio vertical.\n");
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    return 0;
}
