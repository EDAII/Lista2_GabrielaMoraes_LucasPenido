/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/0013143
*/

#include "funcoes.h"

int menuPrincipal(){
  //Variaveis
  int operacao;

  //Instruções
  printf("================================ Menu Principal =======================");
  printf("\n1 - Gerenciar registros");
  printf("\n0 - Sair");
  do{
    printf("\nDigite o número da operação que deseja realizar:  ");
    LIMPA_BUFFER;
    scanf("%d",&operacao);
  }while(operacao < 0 || operacao > 1);

  return operacao;
}

int menuTamanho(){

  //Variaveis
  int escolha, tamanho;

  //Instruções
  LIMPA_TELA;
  printf("================ Selecione o Número de Alunos ====================");
  printf("\n1 - 10 Alunos");
  printf("\n2 - 100 Alunos");
  printf("\n3 - 1.000 Alunos");
  printf("\n4 - 5.000 Alunos");
  printf("\n5 - 10.000 Alunos");
  printf("\n6 - 25.000 Alunos");
  printf("\n7 - 50.000 Alunos");
  printf("\n8 - 75.000 Alunos");
  printf("\n9 - 100.000 Alunos");
  printf("\n10 - 500.000 Alunos");
  printf("\n11 - 1.000.000 Alunos");
  do{
    printf("\nDigite o número da alternativa: ");
    LIMPA_BUFFER;
    scanf("%d", &escolha);
  }while(escolha <= 0 || escolha >= 12);

  tamanho = converteOpcaoEmTamanho(escolha);

  return tamanho;
}

int converteOpcaoEmTamanho(int opcaoTamanho){
  //Variaveis


  //Instruções
  switch(opcaoTamanho){
    case 1:
    opcaoTamanho = TAMANHO_1;
    break;
    case 2:
    opcaoTamanho = TAMANHO_2;
    break;
    case 3:
    opcaoTamanho = TAMANHO_3;
    break;
    case 4:
    opcaoTamanho = TAMANHO_4;
    break;
    case 5:
    opcaoTamanho = TAMANHO_5;
    break;
    case 6:
    opcaoTamanho = TAMANHO_6;
    break;
    case 7:
    opcaoTamanho = TAMANHO_7;
    break;
    case 8:
    opcaoTamanho = TAMANHO_8;
    break;
    case 9:
    opcaoTamanho = TAMANHO_9;
    break;
    case 10:
    opcaoTamanho = TAMANHO_10;
    break;
    case 11:
    opcaoTamanho = TAMANHO_11;
    break;
  }

  return opcaoTamanho;
}

aluno* alocaVetor(aluno *alunos, int qtdAlunos){
  //Variaveis

  //Instruções
  alunos = (aluno *) malloc (qtdAlunos * sizeof(aluno));
  if(alunos == NULL){
    printf("\n\nAlocação falhou!");
    exit(0);
  }
  return alunos;
}

FILE* abreArquivo(FILE *arquivo){
  // Variáveis

  // Instruções
  arquivo = fopen("nomes.txt","r");
  if(arquivo == NULL){
    printf("\n\nFalha ao abrir o arquivo!");
    exit(0);
  }
  return arquivo;
}

aluno* preencheVetorAlunos(aluno *alunos, int qtdAlunos, FILE *arquivo){
  // Variáveis
  int indiceNome, penultimo, status;
  char nomeSorteado[MAXNOME];
  // aux, status, inicio;
  // int tempInit = 0, tempAtual;

  // Instruções
  // inicio = clock();
  for (int i = 0; i < qtdAlunos; i++) {
    alunos[i].anoNascimento = rand() % 53 + 1949;
    indiceNome = rand() % 1094;
    // printf("\nindice do nome %d", indiceNome);
    for(int j = 0; j <= indiceNome; j++){
      LIMPA_BUFFER;
      fgets(nomeSorteado, MAXNOME, arquivo);
      penultimo = strlen(nomeSorteado) - 1;
      if(nomeSorteado[penultimo] == '\n'){
	       nomeSorteado[penultimo] = '\0';
      }
    }
    rewind(arquivo);
    strcpy(alunos[i].nome, nomeSorteado);
    do{
      alunos[i].matricula = rand() % 1000000 + 1;
      status =  NREPETIDO;
      for (int aux = 0; (aux < i) && (status == NREPETIDO); aux++){
            if (alunos[i].matricula == alunos[aux].matricula)
               status = REPETIDO;
         }
    }while (status == REPETIDO);

     // tempAtual = ((clock()-inicio)/CLOCKS_PER_SEC);
     // if (tempAtual != tempInit) {
     //  printf("%.0f%%\n", ((double)i/(double)tamanho)*100);
     //  tempInit = ((clock()-inicio)/CLOCKS_PER_SEC);
     // }
  }
  return alunos;
}

void imprimeRegistros(aluno *alunos, int qtdAlunos){
  // Variáveis

  // Instruções
  printf("\n\n============================ Imprimindo Registros =========================");
  for(int i = 0; i < qtdAlunos; i++){
    printf("\nAluno %d", i+1);
    printf("\nNome do aluno: %s", alunos[i].nome);
    printf("\nMatrícula: %d", alunos[i].matricula);
    printf("\nAno de Nascimento: %d\n\n", alunos[i].anoNascimento);
  }
}

int escolheCriterioOrdenacao(){
  //Variaveis
  int criterioOrdenacao;

  //Instruções
  printf("================================== Ordenar por ============================================");
  printf("\n1 - Nome");
  printf("\n2 - Matrícula");
  printf("\n3 - Ano de nascimento");
  printf("\n0 - Sair");
  do{
    printf("\n\nDigite o número do critério de ordenação: ");
    LIMPA_BUFFER;
    scanf("%d", &criterioOrdenacao);
  }while(criterioOrdenacao < 0 || criterioOrdenacao > 3);

  return criterioOrdenacao;
}

int menuOperacao(){
  //Variaveis
  int operacao;
  //Instruções
  printf("================================== Operações disponíveis ============================");
  printf("\n1 - Inserção");
  printf("\n2 - Remoção");
  do{
    printf("\n\nDigite o número do operação que deseja realizar: ");
    LIMPA_BUFFER;
    scanf("%d", &operacao);
  }while(operacao < 0 || operacao > 3);

  return operacao;
}
