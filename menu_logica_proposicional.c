#include <stdio.h>
#include <string.h>

#include "menu_logica_proposicional.h"
#include "menu.h"

void handleMenuLogicaProposicionalInput(char selectedOption[1]);

void getMenuLogicaProposicionalInput()
{
  char selectedOption[1];

  scanf("%s", &selectedOption);

  handleMenuLogicaProposicionalInput(selectedOption);
}

void handleMenuLogicaProposicionalInput(char selectedOption[1])
{
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
    puts("Selecionou 7");
  }
  else if (strcmp(selectedOption, "8") == 0)
  {
    showMainMenu();
  }
  else
  {
    puts("Ops, insira uma opcao valida:");

    getMenuLogicaProposicionalInput();
  }
}

void showMenuLogicaProposicional()
{
  puts("SUBMENU LOGICA PROPOSICIONAL");
  puts("1. ~p");
  puts("2. ~q");
  puts("3. p ^ q");
  puts("4. p v q");
  puts("5. p _v_ q");
  puts("6. p -> q");
  puts("7. p <-> q");
  puts("8. Voltar ao Menu Anterior");

  getMenuLogicaProposicionalInput();
}
