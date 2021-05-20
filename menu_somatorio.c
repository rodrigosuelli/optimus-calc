#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "menu_somatorio.h"
#include "menu_analise_combinatoria.h"
#include "menu.h"

int j, resultado;

void handleMenuSomatorioInput(unsigned char selectedOption);

uint64_t somatorioDeJ1(unsigned int n)
{
  for (j = 0; j <= n; j++)
  {
    resultado += j;
  }

  return resultado;
}

int64_t somatorioDeJ2(unsigned int n)
{
  for (j = 0; j <= n; j++)
  {
    resultado += pow(-j, j + 1);
  }

  return resultado;
}

double aproximacaoPiSomatorio(unsigned int n)
{
  for (j = 0; j <= n; j++)
  {
    resultado += 8 / (4 * j + 1) * (4 * j + 3);
  }

  return resultado;
}

double aproximacaoNeperianoSomatorio(unsigned int n)
{
  for (j = 0; j <= n; j++)
  {
    resultado += 1 / fatorial(j);
  }

  return resultado;
}

unsigned char getInputAndCheckIsValid(char varName)
{
  int n;
  char enterKey;

  printf("Insira o valor de %c (numero natural maior que 0):\n", varName);

  if (scanf("%d%c", &n, &enterKey) != 2 || enterKey != '\n' || n <= 0)
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

void getMenuSomatorioInput()
{
  unsigned char selectedOption;
  char enterKey;

  if (scanf("%hhu%c", &selectedOption, &enterKey) != 2 || enterKey != '\n' || selectedOption < 1 || selectedOption > 5)
  {
    puts("Ops, insira uma opcao valida:");
    fflush(stdin);
    getMenuSomatorioInput();
  }
  else
  {
    handleMenuSomatorioInput(selectedOption);
  }
}

void handleMenuSomatorioInput(unsigned char selectedOption)
{
  unsigned int n;

  if (selectedOption < 5)
  {
    n = getInputAndCheckIsValid('n');
  }

  switch (selectedOption)
  {
  case 1:
    printf("Resultado: %llu", somatorioDeJ1(n));
    break;
  case 2:
    printf("Resultado: %lld", somatorioDeJ2(n));
    break;
  case 3:
    printf("Resultado: %0.2f", aproximacaoPiSomatorio(n));
    break;
  case 4:
    printf("Resultado: %0.2f", aproximacaoNeperianoSomatorio(n));
    break;
  case 5:
    showMainMenu();
    break;
  }
}

void showMenuSomatorio()
{
  puts("SUBMENU SOMATORIO");
  puts("    n");
  printf("1. %c       j\n", 228);
  puts("    j=0");
  puts("============================");

  puts("    n       j+1");
  printf("2. %c     (-j)\n", 228);
  puts("    j=0");
  puts("============================");

  puts("        n            8");
  printf("3. %c %c %c     -----------------\n", 227, 247, 228);
  puts("        k=0  (4k + 1).(4k + 3)");
  puts("============================");

  puts("        n        1");
  printf("4. e %c %c       -----\n", 247, 228);
  puts("        k=0      k!");
  puts("============================");

  puts("5. Voltar ao Menu anterior");

  getMenuSomatorioInput();
}
