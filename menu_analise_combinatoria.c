#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "menu_analise_combinatoria.h"
#include "menu.h"

void handleMenuAnaliseCombinatoriaInput(char selectedOption[1]);

uint64_t fatorial(uint64_t n)
{
  if (n == 0)
    return 1;
  else
    return n * fatorial(n - 1);
}

uint64_t arranjoRepeticao(int n, int k)
{
  return pow(n, k);
}

uint64_t combinacaoSimples(int n, int k)
{
  uint64_t nFatorial = fatorial(n);
  uint64_t kFatorial = fatorial(k);
  uint64_t subtracaoFatorial = fatorial(n - k);

  return nFatorial / (kFatorial * subtracaoFatorial);
}

uint64_t arranjoSimples(int n, int k)
{
  uint64_t nFatorial = fatorial(n);
  uint64_t subtracaoFatorial = fatorial(n - k);

  return nFatorial / subtracaoFatorial;
}

uint64_t permutacaoSimples(int n)
{
  return fatorial(n);
}

bool isInteger(float n)
{
  int aux = n;

  if (n < 0 || n != aux)
    return false;
  else
    return true;
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
  char selectedOption[1];

  scanf("%s", &selectedOption);

  handleMenuAnaliseCombinatoriaInput(selectedOption);
}

void handleMenuAnaliseCombinatoriaInput(char selectedOption[1])
{
  int n, k;

  if (strcmp(selectedOption, "1") == 0)
  {
    n = getInputAndCheckIsValid("n");

    printf("Resultado: %llu", permutacaoSimples(n));
  }
  else if (strcmp(selectedOption, "2") == 0)
  {
    n = getInputAndCheckIsValid("n");
    k = getInputAndCheckIsValid("k");

    printf("Resultado: %llu", arranjoSimples(n, k));
  }
  else if (strcmp(selectedOption, "3") == 0)
  {
    n = getInputAndCheckIsValid("n");
    k = getInputAndCheckIsValid("k");

    printf("Resultado: %llu", combinacaoSimples(n, k));
  }
  else if (strcmp(selectedOption, "4") == 0)
  {
    n = getInputAndCheckIsValid("n");
    k = getInputAndCheckIsValid("k");

    printf("Resultado: %llu", arranjoRepeticao(n, k));
  }
  else if (strcmp(selectedOption, "5") == 0)
  {
    puts("Selecionou 5");
  }
  else if (strcmp(selectedOption, "6") == 0)
  {
    puts("Selecionou 6");
  }
  else if (strcmp(selectedOption, "7") == 0)
  {
    showMainMenu();
  }
  else
  {
    puts("Ops, insira uma opcao valida:");

    getMenuAnaliseCombinatoriaInput();
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
