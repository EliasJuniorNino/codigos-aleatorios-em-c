#include <stdio.h>

typedef unsigned long long bInt;

#define para_todo(var, tipo, max)for(unsigned tipo var=0;var<max;var++)
#define inicializa(var, tamanho, valor)for(bInt i=0;i<tamanho;i++)var[i]=valor

int main(void)
{
  #define tamanho_lista 5

  int lista[tamanho_lista];
  inicializa(lista, tamanho_lista, 0);

  para_todo(i, char, tamanho_lista) {
    printf("[%d] = %d\n", i, lista[i]);
  }

  return 0;
}