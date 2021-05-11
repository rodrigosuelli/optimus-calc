#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "menu_analise_combinatoria.h"
#include "menu.h"

void handleMenuAnaliseCombinatoriaInput(unsigned char selectedOption);

unsigned int getInputAndCheckIsNatural(char message[])
{
  int n;
  char enterKey;

  puts(message);

  if (scanf("%d%c", &n, &enterKey) != 2 || enterKey != '\n' || n < 0)
  {
    puts("Ops, entrada invalida.");
    fflush(stdin);
    getInputAndCheckIsNatural(message);
  }
  else
  {
    return n;
  }
}

uint64_t fatorial(uint64_t n)
{
  if (n == 0)
    return 1;
  else
    return n * fatorial(n - 1);
}

uint64_t permutacaoRepeticao()
{
  int n, k;
  uint64_t multiplicacaoFatoriaisK = 1;

  n = getInputAndCheckIsNatural("Insira a quantidade de elementos (numero natural):");

  do
  {
    k = getInputAndCheckIsNatural("Insira a quantidade de vezes que determinado elemento se repete (insira 0 para sair e exibir o resultado):");

    if (k != 0)
    {
      multiplicacaoFatoriaisK = multiplicacaoFatoriaisK * fatorial(k);
    }
  } while (k != 0);

  return fatorial(n) / multiplicacaoFatoriaisK;
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

  if (selectedOption < 6)
    n = getInputAndCheckIsNatural("Insira o valor de n, sabendo que n deve ser um numero natural:");
  if (selectedOption > 1 && selectedOption < 7)
    k = getInputAndCheckIsNatural("Insira o valor de k, sabendo que k deve ser um numero natural:");

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
    printf("Resultado: %llu", permutacaoRepeticao());
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
