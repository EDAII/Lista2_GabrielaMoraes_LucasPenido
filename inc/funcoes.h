/*
Alunos:
  Gabriela Chaves de Moraes - 16/0006872
  Lucas Penido Antunes - 16/0013143
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>


#define LIMPA_TELA system("clear")
#define LIMPA_BUFFER __fpurge(stdin)
#define SAIR 0
#define GERENCIAR 1
#define REPETIDO 0
#define NREPETIDO 1
#define NOME 1
#define MATRICULA 2
#define ANODENASCIMENTO 3
#define MAXNOME 50
#define TAMANHO_1 10
#define TAMANHO_2 100
#define TAMANHO_3 1000
#define TAMANHO_4 5000
#define TAMANHO_5 10000
#define TAMANHO_6 25000
#define TAMANHO_7 50000
#define TAMANHO_8 75000
#define TAMANHO_9 100000
#define TAMANHO_10 500000
#define TAMANHO_11 1000000

typedef struct Aluno{
  int matricula;
  char nome[MAXNOME];
  int anoNascimento;
} aluno;

int menuPrincipal();
int menuTamanho();
int converteOpcaoEmTamanho(int);
aluno* alocaVetor(aluno *, int);
FILE* abreArquivo(FILE *);
aluno* preencheVetorAlunos(aluno *, int, FILE*);
void imprimeRegistros(aluno *, int);
int escolheCriterioOrdenacao();
int menuOperacao();
void copiaVetor(aluno *, aluno *, int);
void bubble_sort_nome(aluno *, int);
void bubble_sort_matricula(aluno *, int);
void bubble_sort_ano_nascimento(aluno *, int);
void selection_sort_nome(aluno *, int);
void selection_sort_matricula(aluno *, int);
void selection_sort_ano_nascimento(aluno *, int);
void insertion_sort_nome(aluno *, int);
void insertion_sort_matricula(aluno *, int);
void insertion_sort_ano_nascimento(aluno *, int);
aluno* insereRegistro(aluno *, int, FILE *, int);
