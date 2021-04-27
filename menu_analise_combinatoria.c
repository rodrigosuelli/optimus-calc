#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "menu_analise_combinatoria.h"
#include "menu.h"

void handleMenuAnaliseCombinatoriaInput(unsigned char selectedOption);

uint64_t fatorial(uint64_t n)
{
  if (n == 0)
    return 1;
  else
    return n * fatorial(n - 1);
}

uint64_t combinacaoRepeticao(int n, int k)
{
  return fatorial(n + k - 1) / (fatorial(k) * fatorial(n - 1));
}

uint64_t arranjoRepeticao(int n, int k)
{
  return pow(n, k);
}

uint64_t combinacaoSimples(int n, int k)
{
  return fatorial(n) / (fatorial(k) * fatorial(n - k));
}

uint64_t arranjoSimples(int n, int k)
{
  return fatorial(n) / fatorial(n - k);
}

uint64_t permutacaoSimples(int n)
{
  return fatorial(n);
}

unsigned int getInputAndCheckIsValid(char varName[1])
{
  int n;
  char enterKey;

  printf("Insira o valor de %s, sabendo que %s deve ser um numero natural:\n", varName, varName);

  if (scanf("%d%c", &n, &enterKey) != 2 || enterKey != '\n' || n < 0)
  {
    puts("Ops, entrada invalida.");
    fflush(stdin);
    getInputAndCheckIsValid(varName);
  }
  else
  {
    return n;
  }
}

void getMenuAnaliseCombinatoriaInput()
{
  unsigned char selectedOption;
  char enterKey;

  if (scanf("%hhu%c", &selectedOption, &enterKey) != 2 || enterKey != '\n' || selectedOption < 1 || selectedOption > 7)
  {
    puts("Ops, insira uma opcao valida:");
    fflush(stdin);
    getMenuAnaliseCombinatoriaInput();
  }
  else
  {
    handleMenuAnaliseCombinatoriaInput(selectedOption);
  }
}

void handleMenuAnaliseCombinatoriaInput(unsigned char selectedOption)
{
  int n, k;

  if (selectedOption == 1)
  {
    n = getInputAndCheckIsValid("n");
  }
  else if (selectedOption != 7)
  {
    n = getInputAndCheckIsValid("n");
    k = getInputAndCheckIsValid("k");
  }

  switch (selectedOption)
  {
  case 1:
    printf("Resultado: %llu", permutacaoSimples(n));
    break;
  case 2:
    printf("Resultado: %llu", arranjoSimples(n, k));
    break;
  case 3:
    printf("Resultado: %llu", combinacaoSimples(n, k));
    break;
  case 4:
    printf("Resultado: %llu", arranjoRepeticao(n, k));
    break;
  case 5:
    printf("Resultado: %llu", combinacaoRepeticao(n, k));
    break;
  case 6:
    puts("Selecionou 6");
    break;
  case 7:
    showMainMenu();
    break;
  }
}

void showMenuAnaliseCombinatoria()
{
  puts("SUBMENU ANALISE COMBINATORIA");
  puts("1. Permutacao Simples: P(n)");
  puts("2. Arranjo Simples: A(n, k)");
  puts("3. Combinacao Simples: C(n, k)");
  puts("4. Arranjo com Repeticao: AR(n, k)");
  puts("5. Combinacao com Repeticao: CR(n, k)");
  puts("6. Permutacao com Repeticao: P(n, k1, ..., kp)");
  puts("7. Voltar ao Menu Anterior");

  getMenuAnaliseCombinatoriaInput();
}
