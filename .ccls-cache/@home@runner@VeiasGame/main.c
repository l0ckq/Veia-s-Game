#include <stdio.h>
#include <stdlib.h>

void ImprimeTabuleiro(char p_tabuleiro[3][3]) {
    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            printf(" %c ", p_tabuleiro[line][column]);

            if (column < 2) {
                printf("|");
        }  }
        printf("\n");

        if (line < 2) {
            printf("---+---+---\n");
        }    }    }


char VerificaVencedor(char p_tabuleiro[3][3]){
    // VALIDAÇÃO DAS LINHAS
    for (int line = 0; line < 3; line++) {
        if (p_tabuleiro[line][0] != ' ' && p_tabuleiro[line][0] == p_tabuleiro[line][1] && p_tabuleiro[line][1] == p_tabuleiro[line][2]) {
            return p_tabuleiro[line][0];
        }
    }

    // VALIDAÇÃO DAS COlUNAS
    for (int column = 0; column < 3; column++) {
        if (p_tabuleiro[0][column] != ' ' && p_tabuleiro[0][column] == p_tabuleiro[1][column] && p_tabuleiro[1][column] == p_tabuleiro[2][column]) {
            return p_tabuleiro[0][column];
        }
    }

    // VALIDAÇÃO DAS DIAGONAIS
    if (p_tabuleiro[0][0] != ' ' && p_tabuleiro[0][0] == p_tabuleiro[1][1] && p_tabuleiro[1][1] == p_tabuleiro[2][2]) {
        return p_tabuleiro[0][0];
    }

    if (p_tabuleiro[0][2] != ' ' && p_tabuleiro[0][2] == p_tabuleiro[1][1] && p_tabuleiro[1][1] == p_tabuleiro[2][0]) {
        return p_tabuleiro[0][2];
    }

    // Se não houver vencedor
    return ' ';
}

int main(void) {
  int linha, coluna, jogadas = 0;
  char tabuleiro[3][3] = 
  {{' ', ' ', ' '}, 
  { ' ', ' ', ' '}, 
  { ' ', ' ', ' '}};

  char jogadorAtual = 'X';
  char vencedor = ' ';

  printf("Bem-vindo ao Jogo da Velha!\n");
  
  while (vencedor == ' ' && jogadas < 9){
    printf("Jogador %c, digite a linha e coluna (de 1 a 3) separados por espaço: ", jogadorAtual);
    scanf(" %1d %1d", &linha, &coluna);

    
    if ((linha < 1) || (linha > 3) || (coluna < 1) || (coluna > 3) || (tabuleiro[linha-1][coluna-1] != ' ')){
      printf("Você fez uma jogada inválida. Tente novamente.\n\n\n");
      continue; }

    
    tabuleiro[linha-1][coluna-1] = jogadorAtual;
    jogadas ++;

    if(jogadorAtual == 'X'){
      jogadorAtual = 'O';
    }  else  {  jogadorAtual = 'X';}

    printf("Jogada %d concluida\n\n", jogadas);
    
    ImprimeTabuleiro(tabuleiro);
    if(jogadas >= 5){
      vencedor = VerificaVencedor(tabuleiro);  }
    
  }

    switch(vencedor){
      case ' ': printf("Deu velha!\n"); break;
      case 'X': printf("Jogador X venceu!\n"); break;
      case 'O': printf("Jogador O venceu!\n"); break;
      default: printf("Erro\n"); break;
    }
  
  
  return 0;
}