#include <stdio.h>
#include <string.h>

#include "menu_somatorio.h"
#include "menu.h"

void handleMenuSomatorioInput()
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
    showMainMenu();
  }
  else
  {
    puts("Ops, insira uma opcao valida:");
    handleMenuSomatorioInput();
  }
}

void showMenuSomatorio()
{
  puts("SUBMENU SOMATORIO");
  puts("    n");
  printf("1. %c\n", 228);
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

  handleMenuSomatorioInput();
}
