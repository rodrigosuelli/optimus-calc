#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "menu_logica_proposicional.h"
#include "menu.h"

void handleMenuLogicaProposicionalInput(char selectedOption[1]);

char equivalencia(int p, int q)
{
  if (p == q)
    return 'V';
  else
    return 'F';
}

char implicacao(int p, int q)
{
  if (p == 1 && q == 0)
    return 'F';
  else
    return 'V';
}

char disjuncaoExclusiva(int p, int q)
{
  if (p != q)
    return 'V';
  else
    return 'F';
}

char disjuncao(int p, int q)
{
  if (p == 0 && q == 0)
    return 'F';
  else
    return 'V';
}

char conjuncao(int p, int q)
{
  if (p == 1 && q == 1)
    return 'V';
  else
    return 'F';
}

char negacao(int n)
{
  if (n == 1)
    return 'F';
  else if (n == 0)
    return 'V';
}

bool isValid(int userInput)
{
  if (userInput != 0 && userInput != 1)
    return false;
  else
    return true;
}

void getMenuLogicaProposicionalInput()
{
  char selectedOption[1];

  scanf("%s", &selectedOption);

  handleMenuLogicaProposicionalInput(selectedOption);
}

void handleMenuLogicaProposicionalInput(char selectedOption[1])
{
  int p, q;

  if (strcmp(selectedOption, "1") == 0)
  {
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    if (isValid(p))
    {
      printf("%c", negacao(p));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuLogicaProposicionalInput("1");
    }
  }
  else if (strcmp(selectedOption, "2") == 0)
  {
    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    if (isValid(q))
    {
      printf("%c", negacao(q));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuLogicaProposicionalInput("2");
    }
  }
  else if (strcmp(selectedOption, "3") == 0)
  {
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    if (isValid(p) && isValid(q))
    {
      printf("%c", conjuncao(p, q));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuLogicaProposicionalInput("3");
    }
  }
  else if (strcmp(selectedOption, "4") == 0)
  {
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    if (isValid(p) && isValid(q))
    {
      printf("%c", disjuncao(p, q));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuLogicaProposicionalInput("4");
    }
  }
  else if (strcmp(selectedOption, "5") == 0)
  {
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    if (isValid(p) && isValid(q))
    {
      printf("%c", disjuncaoExclusiva(p, q));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuLogicaProposicionalInput("5");
    }
  }
  else if (strcmp(selectedOption, "6") == 0)
  {
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    if (isValid(p) && isValid(q))
    {
      printf("%c", implicacao(p, q));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuLogicaProposicionalInput("6");
    }
  }
  else if (strcmp(selectedOption, "7") == 0)
  {
    puts("Insira o valor de p (0 ou 1):");
    scanf("%d", &p);

    puts("Insira o valor de q (0 ou 1):");
    scanf("%d", &q);

    if (isValid(p) && isValid(q))
    {
      printf("%c", equivalencia(p, q));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuLogicaProposicionalInput("7");
    }
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
