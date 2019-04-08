/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/0013143
*/

#include "funcoes.h"

int main(){
  // Variáveis
  int operacao, qtdAlunos, criterioOrdenacao, novosRegistros;
  double tempoBubble, tempoInsertion, tempoSelection;
  aluno *alunosBubble = NULL;
  aluno *alunosInsertion = NULL;
  aluno *alunosSelection = NULL;
  FILE *arquivoNomes = NULL, *arquivoHistorico = NULL;
  clock_t inicioBubble, fimBubble, inicioSelection, fimSelection, inicioInsertion, fimInsertion;
  char opcao;
  char linha[1000];

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
        arquivoHistorico = fopen("historico.txt","r+");
        if(arquivoHistorico == NULL){
          arquivoHistorico = fopen("historico.txt", "w+");
        }
        qtdAlunos = menuTamanho();
        // Foram criados 3 vetores para relizar cada tipo de ordenação n2.
        alunosBubble = alocaVetor(alunosBubble, qtdAlunos);
        alunosInsertion = alocaVetor(alunosInsertion, qtdAlunos);
        alunosSelection = alocaVetor(alunosSelection, qtdAlunos);
        alunosBubble = preencheVetorAlunos(alunosBubble, qtdAlunos, arquivoNomes);
        copiaVetor(alunosInsertion, alunosBubble, qtdAlunos);
        copiaVetor(alunosSelection, alunosBubble, qtdAlunos);
        imprimeRegistros(alunosBubble, qtdAlunos);
        novosRegistros = 0;
        fprintf(arquivoHistorico,"%s\n", "Histórico");
        fprintf(arquivoHistorico,"%s\t%s\t\t\t\t%s\t%s\t%s\n", "Tamanho","Tipo de Ordenação", "Bubble Sort", "Selection Sort", "Insertion Sort");
        do{
          criterioOrdenacao = escolheCriterioOrdenacao();
          switch(criterioOrdenacao){
            case NOME:
              printf("\n\nOrdenando...");
              inicioBubble = clock();
              bubble_sort_nome(alunosBubble, qtdAlunos);
              fimBubble = clock();
              tempoBubble = ((double)(fimBubble-inicioBubble)/CLOCKS_PER_SEC);

              inicioSelection = clock();
              selection_sort_nome(alunosSelection, qtdAlunos);
              fimSelection = clock();
              tempoSelection = ((double)(fimSelection-inicioSelection)/CLOCKS_PER_SEC);

              inicioInsertion = clock();
              insertion_sort_nome(alunosInsertion, qtdAlunos);
              fimInsertion = clock();
              tempoInsertion = ((double)(fimInsertion-inicioInsertion)/CLOCKS_PER_SEC);

              fseek(arquivoHistorico, 0, SEEK_END);
              fprintf(arquivoHistorico,"%d\t%s\t\t\t%lf\t%lf\t%lf\n",qtdAlunos,"Nome (sujeito à repetições)", tempoBubble, tempoSelection, tempoInsertion);
            break;

            case MATRICULA:
              printf("\n\nOrdenando...");
              inicioBubble = clock();
              bubble_sort_matricula(alunosBubble, qtdAlunos);
              fimBubble = clock();
              tempoBubble = ((double)(fimBubble-inicioBubble)/CLOCKS_PER_SEC);

              inicioSelection = clock();
              selection_sort_matricula(alunosSelection, qtdAlunos);
              fimSelection = clock();
              tempoSelection = ((double)(fimSelection-inicioSelection)/CLOCKS_PER_SEC);

              inicioInsertion = clock();
              insertion_sort_matricula(alunosInsertion, qtdAlunos);
              fimInsertion = clock();
              tempoInsertion = ((double)(fimInsertion-inicioInsertion)/CLOCKS_PER_SEC);

              fseek(arquivoHistorico, 0, SEEK_END);
              fprintf(arquivoHistorico,"%d\t%s\t\t\t%lf\t%lf\t%lf\n", qtdAlunos,"Matrícula (chave primária)", tempoBubble, tempoSelection, tempoInsertion);
            break;

            case ANODENASCIMENTO:
              printf("\n\nOrdenando...");
              inicioBubble = clock();
              bubble_sort_ano_nascimento(alunosBubble, qtdAlunos);
              fimBubble = clock();
              tempoBubble = ((double)(fimBubble-inicioBubble)/CLOCKS_PER_SEC);

              inicioSelection = clock();
              selection_sort_ano_nascimento(alunosSelection, qtdAlunos);
              fimSelection = clock();
              tempoSelection = ((double)(fimSelection-inicioSelection)/CLOCKS_PER_SEC);

              inicioInsertion = clock();
              insertion_sort_ano_nascimento(alunosInsertion, qtdAlunos);
              fimInsertion = clock();
              tempoInsertion = ((double)(fimInsertion-inicioInsertion)/CLOCKS_PER_SEC);

              fseek(arquivoHistorico, 0, SEEK_END);
              fprintf(arquivoHistorico,"%d\t%s\t%lf\t%lf\t%lf\n", qtdAlunos,"Ano de Nascimento (sujeito à repetições)", tempoBubble, tempoSelection, tempoInsertion);
            break;
          }
          if(criterioOrdenacao != SAIR){
            printf("\n\n=============================== Bubble Sort ========================================");
            imprimeRegistros(alunosBubble, qtdAlunos);
            printf("\n\n=============================== Selection Sort ========================================");
            imprimeRegistros(alunosSelection, qtdAlunos);
            printf("\n\n=============================== Insertion Sort ========================================");
            imprimeRegistros(alunosInsertion, qtdAlunos);
            printf("\nTempo para ordenar utilizando o método Bubble Sort: %lf s\n\n", tempoBubble);
            printf("\nTempo para ordenar utilizando o método Selection Sort: %lf s\n\n", tempoSelection);
            printf("\nTempo para ordenar utilizando o método Insertion Sort: %lf s\n\n", tempoInsertion);

            printf("\n\n\n\nDeseja fazer alguma inserção nesse vetor? (S ou N) ");
            LIMPA_BUFFER;
            opcao = getchar();
            opcao = toupper(opcao);
            if(opcao == 'S'){
              printf("\n\nQuantos registros deseja inserir: ");
              LIMPA_BUFFER;
              scanf("%d", &novosRegistros);

              alunosBubble = insereRegistro(alunosBubble, qtdAlunos, arquivoNomes, novosRegistros);

              qtdAlunos = qtdAlunos + novosRegistros;
              alunosInsertion = (aluno*) realloc(alunosInsertion, (qtdAlunos * sizeof(aluno)));
              alunosSelection = (aluno*) realloc(alunosSelection, (qtdAlunos * sizeof(aluno)));
              copiaVetor(alunosInsertion, alunosBubble, qtdAlunos);
              copiaVetor(alunosSelection, alunosBubble, qtdAlunos);
              imprimeRegistros(alunosBubble, qtdAlunos);
              imprimeRegistros(alunosInsertion, qtdAlunos);
              imprimeRegistros(alunosSelection, qtdAlunos);
            }
          }
        }while(criterioOrdenacao != SAIR);
        fclose(arquivoHistorico);
        arquivoHistorico = fopen("historico.txt","r");
        if(arquivoHistorico == NULL){
          printf("\n\nFalha ao abrir o arquivo!");
          exit(0);
        }
        printf("\n");
        while(!feof(arquivoHistorico)) {
          if(fgets(linha, 1000, arquivoHistorico) != NULL){
            printf("%s", linha);
          }
        }
        printf("\n\nAperte ENTER para continuar... ");
        LIMPA_BUFFER;
        getchar();
        fclose(arquivoHistorico);
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
