#include <stdio.h>
#include <stdlib.h>
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

unsigned char getInputAndCheckIsBoolean(char varName)
{
  int p;
  char enterKey;

  printf("Insira o valor de %c (0 ou 1):\n", varName);

  if (scanf("%d%c", &p, &enterKey) != 2 || enterKey != '\n' || p != 0 && p != 1)
  {
    puts("Ops, entrada invalida.");
    fflush(stdin);
    getInputAndCheckIsBoolean(varName);
  }
  else
  {
    return p;
  }
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
  unsigned char p, q;

  if (selectedOption != 2 && selectedOption < 8)
  {
    p = getInputAndCheckIsBoolean('p');
  }

  if (selectedOption > 1 && selectedOption < 8)
  {
    q = getInputAndCheckIsBoolean('q');
  }

  switch (selectedOption)
  {
  case 1:
    printf("%c", negacao(p));
    break;
  case 2:
    printf("%c", negacao(q));
    break;
  case 3:
    printf("%c", conjuncao(p, q));
    break;
  case 4:
    printf("%c", disjuncao(p, q));
    break;
  case 5:
    printf("%c", disjuncaoExclusiva(p, q));
    break;
  case 6:
    printf("%c", implicacao(p, q));
    break;
  case 7:
    printf("%c", equivalencia(p, q));
    break;
  case 8:
    showMainMenu();
    break;
  }

  if (selectedOption != 8)
  {
    puts("");
    system("pause");
    showMenuLogicaProposicional();
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
