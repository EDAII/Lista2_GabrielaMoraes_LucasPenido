/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/0013143
*/

#include "funcoes.h"

int main(){
  // Variáveis
  int operacao, qtdAlunos, criterioOrdenacao;
  aluno *alunos = NULL;
  FILE *arquivoNomes = NULL;

  // Instruções
  setlocale(LC_ALL,"Portuguese");
  srand(time(NULL));
  LIMPA_TELA;
  printf("Bem vindo ao gerenciador de registro de alunos!\n");
  printf("\n\nCada registro possui as seguinte informações: \n");
  printf("Nome do aluno\nMatrícula\nAno de nascimento\n");
  sleep(3);
  do{
    LIMPA_TELA;
    operacao = menuPrincipal();
    arquivoNomes = abreArquivo(arquivoNomes);
    switch (operacao) {
      case GERENCIAR:
        qtdAlunos = menuTamanho();
        alunos = alocaVetor(alunos, qtdAlunos);
        alunos = preencheVetorAlunos(alunos, qtdAlunos, arquivoNomes);
        imprimeRegistros(alunos, qtdAlunos);
        do{
          criterioOrdenacao = escolheCriterioOrdenacao();
          switch(criterioOrdenacao){
            case NOME:
            //algoritmos de ordenação
            break;
            case MATRICULA:
            //algoritmos de ordenação
            break;
            case ANODENASCIMENTO:
            //algoritmos de ordenação
            break;
          }
        }while(criterioOrdenacao != SAIR);
      break;
      case SAIR:
        LIMPA_TELA;
        printf("Liberando Vetor...\n");
        free(alunos);
        sleep(1);
        printf("Fechando Arquivo...\n");
        fclose(arquivoNomes);
        sleep(1);
        printf("Programa finalizado!\n");
      break;
    }
  }while(operacao != SAIR);
  return 0;
}
