#include <stdio.h>
#include <string.h>

#include "menu.h"
#include "menu_somatorio.h"
#include "menu_logica_proposicional.h"
#include "menu_analise_combinatoria.h"

void showMainMenu()
{
  puts("%%%%%%%%%%%%%%%%%%%%%%");
  puts("%    OPTIMUS CALC    %");
  puts("%%%%%%%%%%%%%%%%%%%%%%");
  puts("     MENU PRINCIPAL");
  puts("1. Somatorio");
  puts("2. Logica Proposicional");
  puts("3. Analise Combinatoria");
  puts("4. Sair");

  handleMainMenuInput();
}

void handleMainMenuInput()
{
  char selectedOption[1];

  scanf("%s", &selectedOption);

  if (strcmp(selectedOption, "1") == 0)
  {
    showMenuSomatorio();
  }
  else if (strcmp(selectedOption, "2") == 0)
  {
    showMenuLogicaProposicional();
  }
  else if (strcmp(selectedOption, "3") == 0)
  {
    showMenuAnaliseCombinatoria();
  }
  else if (strcmp(selectedOption, "4") == 0)
  {
    return;
  }
  else
  {
    puts("Ops, insira uma opcao valida:");
    handleMainMenuInput();
  }
}
