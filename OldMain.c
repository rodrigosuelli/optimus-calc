#include <stdio.h>
#include <string.h>

int main()
{
  char selectedOption[1];

  puts("%%%%%%%%%%%%%%%%%%%%%%");
  puts("%    OPTIMUS CALC    %");
  puts("%%%%%%%%%%%%%%%%%%%%%%");
  puts("     MENU PRINCIPAL");
  puts("1. Somatorio");
  puts("2. Logica Proposicional");
  puts("3. Analise Combinatoria");
  puts("4. Sair");
  printf("=> ");

  do
  {
    scanf("%s", &selectedOption);

    if (strcmp(selectedOption, "1") == 0)
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
    }
    else if (strcmp(selectedOption, "2") == 0)
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
    }
    else if (strcmp(selectedOption, "3") == 0)
    {
      puts("SUBMENU ANALISE COMBINATORIA");
      puts("1. Permutacao Simples: P(n)");
      puts("2. Arranjo Simples: A(n, k)");
      puts("3. Combinacao Simples: C(n, k)");
      puts("4. Arranjo com Repeticao: AR(n, k)");
      puts("5. Combinacao com Repeticao: CR(n, k)");
      puts("6. Permutacao com Repeticao: P(n, k1, ⋯ , kp)");
      puts("7. Voltar ao Menu Anterior");
    }
    else if (strcmp(selectedOption, "4") == 0)
    {
      return 0;
    }
    else
    {
      puts("Ops, insira uma opcao valida:");
    }
  } while (
      strcmp(selectedOption, "1") != 0 &&
      strcmp(selectedOption, "2") != 0 &&
      strcmp(selectedOption, "3") != 0 &&
      strcmp(selectedOption, "4") != 0);
}
