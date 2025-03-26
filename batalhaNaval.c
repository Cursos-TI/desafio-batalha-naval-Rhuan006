#include <stdio.h>

#define TAMANHO 10
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
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
    printf("\n");
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (direcao == 'H' && coluna + 2 < TAMANHO) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 'V' && linha + 2 < TAMANHO) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else if (direcao == 'D' && linha + 2 < TAMANHO && coluna + 2 < TAMANHO) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else if (direcao == 'I' && linha + 2 < TAMANHO && coluna - 2 >= 0) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

// Função para aplicar a matriz da habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int origemX, int origemY, int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int deslocamento = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemX - deslocamento + i;
            int y = origemY - deslocamento + j;
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = HABILIDADE;
            }
        }
    }
}

// Função para criar uma matriz de habilidade em formato de cone
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) ? 1 : 0;
        }
    }
}

// Função para criar uma matriz de habilidade em formato de cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Função para criar uma matriz de habilidade em formato de octaedro
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios
    posicionarNavio(tabuleiro, 2, 2, 'H');
    posicionarNavio(tabuleiro, 5, 5, 'V');
    posicionarNavio(tabuleiro, 1, 7, 'D');
    posicionarNavio(tabuleiro, 6, 3, 'I');

    printf("Tabuleiro com navios:\n");
    exibirTabuleiro(tabuleiro);

    // Aplica habilidade em formato de cone
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, 4, 4, habilidade);
    printf("Tabuleiro com habilidade em cone:\n");
    exibirTabuleiro(tabuleiro);

    // Aplica habilidade em formato de cruz
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, 7, 7, habilidade);
    printf("Tabuleiro com habilidade em cruz:\n");
    exibirTabuleiro(tabuleiro);

    // Aplica habilidade em formato de octaedro
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, 5, 2, habilidade);
    printf("Tabuleiro com habilidade em octaedro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}