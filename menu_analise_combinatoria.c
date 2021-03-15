#include <stdio.h>
#include <string.h>

#include "menu_analise_combinatoria.h"
#include "menu.h"

void handleMenuAnaliseCombinatoriaInput()
{
  char selectedOption[1];

  scanf("%s", &selectedOption);

  if (strcmp(selectedOption, "1") == 0)
  {
    puts("Selecionou 1");
  }
  else if (strcmp(selectedOption, "2") == 0)
  {
    puts("Selecionou 2");
  }
  else if (strcmp(selectedOption, "3") == 0)
  {
    puts("Selecionou 3");
  }
  else if (strcmp(selectedOption, "4") == 0)
  {
    puts("Selecionou 4");
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
    handleMenuAnaliseCombinatoriaInput();
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

  handleMenuAnaliseCombinatoriaInput();
}
