/*
 *  Trabalho 1 - Passos para resolver o sudoku
 *  Autor: Gustavo Henrique Sebold da Silva
 *  GRR: grr20204429
 *  Data: 07/02/2021
 */

#include <stdio.h>
#define TAMANHO  9
void showMat(int mat[][TAMANHO],int tam);
void inicializaVetor(int v[], int tam);
void FaltaLinha(int jogo[][9], int lin, int resultado[], int tam);
void FaltaColuna(int jogo[][9], int col, int resultado[], int tam);
void FaltaGrupo(int jogo[][9], int grupo, int res[], int tam);

int main(void)
{
    int jogoInicial[9][9] = {{9,4,0, 1,0,2, 0,5,8},
                            {6,0,0, 0,5,0, 0,0,4},
                            {0,0,2, 4,0,3, 1,0,0},
                            {0,2,0, 0,0,0, 0,6,0},
                            {5,0,8, 0,2,0, 4,0,1},
                            {0,6,0, 0,0,0, 0,8,0},
                            {0,0,1, 6,0,8, 7,0,0},
                            {7,0,0, 0,4,0, 0,0,3},
                            {4,3,0, 5,0,9, 0,1,2}};
    int linha[9], coluna[9], grupo[9], l, c, g, opt, possibilidades=0;

    printf("Configuracao inicial do jogo:\n");
    showMat(jogoInicial, 9 );
    printf("O que você deseja fazer:\n1 - Ver quais valores faltam em uma linha\n2 - Ver quais valores faltam em uma coluna\n3 - Ver quais valores faltam em um grupo\n4 - Ver quais valores uma célula pode conter\n5 - Ver quais valores uma célula não pode ter\n6 - Quantos valores são possíveis em uma célula\n");
    scanf("%d", &opt);

    switch(opt){
        case 1:
            printf("Digite a linha que você gostaria de saber quais valores faltam: ");
            scanf("%d", &l);
            FaltaLinha(jogoInicial, l, linha, TAMANHO);
            for(int i = 0; i < 9; i++){
                if (linha[i]){
                    printf("%d\n", linha[i]);
                }
            }  
            break;
        case 2:    
            printf("Digite a coluna que você gostaria de saber quais valores faltam: ");
            scanf("%d", &c);
            FaltaColuna(jogoInicial, c, coluna, TAMANHO);
            for(int i = 0; i < 9; i++){
                if (coluna[i]){
                    printf("%d\n", coluna[i]);
                }
            }
            break;
        case 3:
            printf("Digite o grupo que você gostaria de saber quais valores faltam: ");
            scanf("%d", &g);
            FaltaGrupo(jogoInicial, g, grupo, TAMANHO);
            for(int i = 0; i < 9; i++){
                if (grupo[i]){
                    printf("%d\n", grupo[i]);
                }
            }
            break;
        case 4:
            printf("Digite a linha da célula: ");
            scanf("%d", &l);
            printf("Digite a coluna da célula: ");
            scanf("%d", &c);
            printf("Digite o grupo que a célula pertence: ");
            scanf("%d", &g);
            FaltaLinha(jogoInicial, l, linha, TAMANHO);
            FaltaColuna(jogoInicial, c, coluna, TAMANHO);
            FaltaGrupo(jogoInicial, g, grupo, TAMANHO);
            for(int i = 0; i < 9; i++){
                if(linha[i] && coluna[i] && grupo[i]){
                    printf("%d\n", linha[i]);
                }
            }
            break;
        case 5:
            printf("Digite a linha da célula: ");
            scanf("%d", &l);
            printf("Digite a coluna da célula: ");
            scanf("%d", &c);
            printf("Digite o grupo que a célula pertence: ");
            scanf("%d", &g);
            FaltaLinha(jogoInicial, l, linha, TAMANHO);
            FaltaColuna(jogoInicial, c, coluna, TAMANHO);
            FaltaGrupo(jogoInicial, g, grupo, TAMANHO);
            for(int i = 0; i < 9; i++){
                if(linha[i] == 0 || coluna[i] == 0 || grupo[i] == 0){
                    printf("%d\n", i+1);
                }
            }
            break;
        case 6:
            printf("Digite a linha da célula: ");
            scanf("%d", &l);
            printf("Digite a coluna da célula: ");
            scanf("%d", &c);
            printf("Digite o grupo que a célula pertence: ");
            scanf("%d", &g);
            FaltaLinha(jogoInicial, l, linha, TAMANHO);
            FaltaColuna(jogoInicial, c, coluna, TAMANHO);
            FaltaGrupo(jogoInicial, g, grupo, TAMANHO);
            for(int i = 0; i < 9; i++){
                if(linha[i] && coluna[i] && grupo[i]){
                    possibilidades++;
                }
            }
            printf("%d\n", possibilidades);
            break;
    }
}

void showMat(int mat[][TAMANHO],int tam) {
    int i,j;
    printf("\n +-----------+-----------+-----------+\n");
    for(i=0 ; i<tam ; i++ ) {
        printf(" | ");
        for(j=0 ; j<tam; j++ ) {
            if( mat[i][j]>0 ) {
                printf(" %1d ",mat[i][j]);
            } else {
                printf(" _ ");
            }
            if( j==2 || j==5 || j==8 ) {
                printf(" | ");
            }
        }
        if( i%3==2 ) {   // mesma coisa que i%3 == 0
            printf("\n +-----------+-----------+-----------+\n");
        } else
            printf("\n");
    }
}

void inicializaVetor(int v[], int tam) {
    int i;
    for(i=0 ; i<tam ; i++ ) {
        v[i] = 0;
    }
}

void FaltaLinha(int jogo[][9], int lin, int res[], int tam)
{
    int aux, pos;
    inicializaVetor(res, tam);
    for (int num = 1; num<=9; num++){
        pos = 0;
        aux = 1;
        while (aux == 1 && pos<9)
        {
            if(jogo[lin-1][pos] == num){
                aux = 0;
            }
            pos++;
        }
        if (aux){
            res[num-1] = num;
        }
    }
}
void FaltaColuna(int jogo[][9], int col, int res[], int tam)
{
    int aux, pos;
    inicializaVetor(res, tam);
    for (int num = 1; num<=9; num++){
        pos = 0;
        aux = 1;
        while (aux == 1 && pos<9)
        {
            if(jogo[pos][col-1] == num){
                aux = 0;
            }
            pos++;
        }
        if (aux){
            res[num-1] = num;
        }
    }
}
void FaltaGrupo(int jogo[][TAMANHO], int grp, int res[], int tam){
    int raiz_tam = (int)tam/3;
    int linha = ((grp-1)/raiz_tam)*raiz_tam;
    int coluna = ((grp-1+raiz_tam)%raiz_tam)*raiz_tam;
    inicializaVetor(res, tam);
    for(int i = 0; i<tam; i++){
        res[i] = i+1;
    }
    for(int i = linha;i<linha+raiz_tam;i++){
        for(int j = coluna; j<coluna+raiz_tam; j++){
            if((jogo[i][j])){
                res[jogo[i][j]-1]=0;
            }
        }
    }
}