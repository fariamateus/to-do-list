#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajuda.h"
void exibir(){



system("cls");

        FILE *arq;
        char tarefa [150], *resultado;
        int contador = 0;

        arq = fopen("arquivo.txt", "r");

        if(arq)
        {
            while(!feof(arq)){
                resultado = fgets(tarefa, 150, arq);
                if(resultado){
                    printf("%d - %s\n", contador + 1, tarefa);
                    contador++;
            }
            }
            fclose(arq);
        }

        printf("o total de tarefa e: %d", contador);

        return;

}
