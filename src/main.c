/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/0013143
*/

#include "funcoes.h"

int main(){
  // Variáveis
  int operacao, qtdAlunos, criterioOrdenacao;
  aluno *alunosBubble = NULL;
  aluno *alunosInsertion = NULL;
  aluno *alunosSelection = NULL;
  FILE *arquivoNomes = NULL;
  clock_t inicioBubble, fimBubble, inicioSelection, fimSelection, inicioInsertion, fimInsertion;

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
        // Foram criados 3 vetores para relizar cada tipo de ordenação n2.
        alunosBubble = alocaVetor(alunosBubble, qtdAlunos);
        alunosInsertion = alocaVetor(alunosInsertion, qtdAlunos);
        alunosSelection = alocaVetor(alunosSelection, qtdAlunos);
        alunosBubble = preencheVetorAlunos(alunosBubble, qtdAlunos, arquivoNomes);
        copiaVetor(alunosInsertion, alunosBubble, qtdAlunos);
        copiaVetor(alunosSelection, alunosBubble, qtdAlunos);
        imprimeRegistros(alunosBubble, qtdAlunos);
        do{
          criterioOrdenacao = escolheCriterioOrdenacao();
          switch(criterioOrdenacao){
            case NOME:
            //algoritmos de ordenação
            break;
            case MATRICULA:
            inicioBubble = clock();
            bubble_sort_matricula(alunosBubble, qtdAlunos);
            fimBubble = clock();

            inicioSelection = clock();
            selection_sort_matricula(alunosSelection, qtdAlunos);
            fimSelection = clock();

            inicioInsertion = clock();
            insertion_sort_matricula(alunosInsertion, qtdAlunos);
            fimInsertion = clock();

            break;
            case ANODENASCIMENTO:
            inicioBubble = clock();
            bubble_sort_ano_nascimento(alunosBubble, qtdAlunos);
            fimBubble = clock();

            inicioSelection = clock();
            selection_sort_ano_nascimento(alunosSelection, qtdAlunos);
            fimSelection = clock();

            inicioInsertion = clock();
            insertion_sort_ano_nascimento(alunosInsertion, qtdAlunos);
            fimInsertion = clock();

            break;
          }
          imprimeRegistros(alunosBubble, qtdAlunos);
          imprimeRegistros(alunosSelection, qtdAlunos);
          imprimeRegistros(alunosInsertion, qtdAlunos);
          printf("\nTempo para ordenar utilizando o método Bubble Sort: %lf s\n\n",
          ((double)(fimBubble-inicioBubble)/CLOCKS_PER_SEC));
          printf("\nTempo para ordenar utilizando o método Selection Sort: %lf s\n\n",
          ((double)(fimSelection-inicioSelection)/CLOCKS_PER_SEC));
          printf("\nTempo para ordenar utilizando o método Insertion Sort: %lf s\n\n",
          ((double)(fimInsertion-inicioInsertion)/CLOCKS_PER_SEC));
        }while(criterioOrdenacao != SAIR);
      break;
      case SAIR:
        LIMPA_TELA;
        printf("Liberando Vetor...\n");
        free(alunosBubble);
        free(alunosInsertion);
        free(alunosSelection);
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
