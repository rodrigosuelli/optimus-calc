#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "menu_logica_proposicional.h"
#include "menu.h"

void handleMenuLogicaProposicionalInput(unsigned char selectedOption);

char equivalencia(unsigned char p, unsigned char q)
{
  if (p == q)
    return 'V';
  else
    return 'F';
}

char implicacao(unsigned char p, unsigned char q)
{
  if (p == 1 && q == 0)
    return 'F';
  else
    return 'V';
}

char disjuncaoExclusiva(unsigned char p, unsigned char q)
{
  if (p != q)
    return 'V';
  else
    return 'F';
}

char disjuncao(unsigned char p, unsigned char q)
{
  if (p == 0 && q == 0)
    return 'F';
  else
    return 'V';
}

char conjuncao(unsigned char p, unsigned char q)
{
  if (p == 1 && q == 1)
    return 'V';
  else
    return 'F';
}

char negacao(unsigned char n)
{
  if (n == 1)
    return 'F';
  else
    return 'V';
}

bool isValid(unsigned char userInput)
{
  if (userInput != 0 && userInput != 1)
    return false;
  else
    return true;
}

void getMenuLogicaProposicionalInput()
{
  unsigned char selectedOption;
  char enterKey;

  if (scanf("%hhu%c", &selectedOption, &enterKey) != 2 || enterKey != '\n' || selectedOption < 1 || selectedOption > 8)
  {
    puts("Ops, insira uma opcao valida:");
    fflush(stdin);
    getMenuLogicaProposicionalInput();
  }
  else
  {
    handleMenuLogicaProposicionalInput(selectedOption);
  }
}

void handleMenuLogicaProposicionalInput(unsigned char selectedOption)
{
  int p, q;

  switch (selectedOption)
  {
  case 1:
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    printf("%c", negacao(p));
    break;
  case 2:
    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    printf("%c", negacao(q));
    break;
  case 3:
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    printf("%c", conjuncao(p, q));
    break;
  case 4:
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    printf("%c", disjuncao(p, q));
    break;
  case 5:
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    printf("%c", disjuncaoExclusiva(p, q));
    break;
  case 6:
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    printf("%c", implicacao(p, q));
    break;
  case 7:
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    printf("%c", equivalencia(p, q));
    break;
  case 8:
    showMainMenu();
    break;
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
