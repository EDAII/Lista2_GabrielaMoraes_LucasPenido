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

void copiaVetor(aluno alunoCopia[], aluno aluno[], int size) {
  int i;
  for(i = 0; i < size; i++)
    alunoCopia[i] = aluno[i];
}

void bubble_sort_nome(aluno *aluno, int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int troca;

  /* Enquanto houver trocas acontecendo o aluno não está ordenado */
  do {
    troca = 0;

    for (int i = 1; i < size; i++) {
      /* Faz a comparação do elemento da direita com o da esquerda.
      Caso o da esquerda seja maior que o da direita, é feita a troca entre eles. */
      if (strcmp(aluno[i-1].nome, aluno[i].nome) > 0) {
        aux[0] = aluno[i-1];
        aluno[i-1] = aluno[i];
        aluno[i] = aux[0];

        troca = 1;
      }
    }
    size--;
  } while(troca);
}

void bubble_sort_matricula(aluno aluno[], int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int troca;

  /* Enquanto houver trocas acontecendo o aluno não está ordenado */
  do {
    troca = 0;

    for (int i = 1; i < size; i++) {
      /* Faz a comparação do elemento da direita com o da esquerda.
      Caso o da esquerda seja maior que o da direita, é feita a troca entre eles. */
      if (aluno[i-1].matricula > aluno[i].matricula) {
        aux[0] = aluno[i-1];
        aluno[i-1] = aluno[i];
        aluno[i] = aux[0];

        troca = 1;
      }
    }
    size--;
  } while(troca);
}

void bubble_sort_ano_nascimento(aluno aluno[], int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int troca;

  /* Enquanto houver trocas acontecendo o aluno não está ordenado */
  do {
    troca = 0;

    for (int i = 1; i < size; i++) {
      /* Faz a comparação do elemento da direita com o da esquerda.
      Caso o da esquerda seja maior que o da direita, é feita a troca entre eles. */
      if (aluno[i-1].anoNascimento > aluno[i].anoNascimento) {
        aux[0] = aluno[i-1];
        aluno[i-1] = aluno[i];
        aluno[i] = aux[0];

        troca = 1;
      }
    }
    size--;
  } while(troca);
}

void selection_sort_nome(aluno aluno[], int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int min, flag = 0, nElements = size - 1;

  /* O número de iterações vai depender do número de elementos no array - 1. */
  while (nElements) {

    /* Flag criada para marcar a primeira posição não ordenada.
    E min é a posição do menor número. */
    min = flag;

    for (int i = flag; i < size; i++) {
      if (strcmp(aluno[i].nome, aluno[min].nome) < 0) {
        min = i;
      }
    }
    /* Faz a troca do menor número com o primeiro número não ordenado.  */
    aux[0] = aluno[flag];
    aluno[flag] = aluno[min];
    aluno[min] = aux[0];

    flag++;
    nElements--;
  }
}

void selection_sort_matricula(aluno aluno[], int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int min, flag = 0, nElements = size - 1;

  /* O número de iterações vai depender do número de elementos no array - 1. */
  while (nElements) {

    /* Flag criada para marcar a primeira posição não ordenada.
    E min é a posição do menor número. */
    min = flag;

    for (int i = flag; i < size; i++) {
      if (aluno[i].matricula < aluno[min].matricula) {
        min = i;
      }
    }
    /* Faz a troca do menor número com o primeiro número não ordenado.  */
    aux[0] = aluno[flag];
    aluno[flag] = aluno[min];
    aluno[min] = aux[0];

    flag++;
    nElements--;
  }
}

void selection_sort_ano_nascimento(aluno aluno[], int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int min, flag = 0, nElements = size - 1;

  /* O número de iterações vai depender do número de elementos no array - 1. */
  while (nElements) {

    /* Flag criada para marcar a primeira posição não ordenada.
    E min é a posição do menor número. */
    min = flag;

    for (int i = flag; i < size; i++) {
      if (aluno[i].anoNascimento < aluno[min].anoNascimento) {
        min = i;
      }
    }
    /* Faz a troca do menor número com o primeiro número não ordenado.  */
    aux[0] = aluno[flag];
    aluno[flag] = aluno[min];
    aluno[min] = aux[0];

    flag++;
    nElements--;
  }
}

void insertion_sort_nome(aluno aluno[], int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int j;

  for (int i = 1; i < size; i++) {
    aux[0] = aluno[i];
    j = i - 1;

    while ((j >= 0) && ((strcmp(aluno[j].nome, aux[0].nome) > 0))) {
      aluno[j + 1] = aluno[j];
      j--;
    }

    aluno[j + 1] = aux[0];
  }
}


void insertion_sort_matricula(aluno aluno[], int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int j;

  for (int i = 1; i < size; i++) {
    aux[0] = aluno[i];
    j = i - 1;

    while ((j >= 0) && (aluno[j].matricula > aux[0].matricula)) {
      aluno[j + 1] = aluno[j];
      j--;
    }

    aluno[j + 1] = aux[0];
  }
}

void insertion_sort_ano_nascimento(aluno aluno[], int size) {

  struct Aluno *aux = NULL;
  aux = alocaVetor(aux, 1);
  int j;

  for (int i = 1; i < size; i++) {
    aux[0] = aluno[i];
    j = i - 1;

    while ((j >= 0) && (aluno[j].anoNascimento > aux[0].anoNascimento)) {
      aluno[j + 1] = aluno[j];
      j--;
    }

    aluno[j + 1] = aux[0];
  }
}

aluno* insereRegistro(aluno *alunos, int qtdAlunos, FILE *arquivo, int novosRegistros){
  int indiceNome, penultimo, status;
  char nomeSorteado[MAXNOME];

  alunos = (aluno*) realloc(alunos, ((qtdAlunos + novosRegistros) * sizeof(aluno)));

  for(int i = 0; i < (qtdAlunos + novosRegistros); i++){
    if(i >= qtdAlunos){
      alunos[i].anoNascimento = rand() % 53 + 1949;

      indiceNome = rand() % 1094;
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
    }
  }
  return alunos;
}
