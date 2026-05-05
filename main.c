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

        printf("o total de tarefas e: %d", contador);

        return;

}


int opc = 0;
char tarefa[150];

int main()
{
    while(1){
    switch(opc){

    case 0:{
        system("cls");
        printf("MENU\n\n1-exibir tarefas\n2-adicionar tarefa\n3-marcar tarefa como concluida\n4-remover tarefa\n5-fechar programa");
        do{printf("\n\ndigite o que deseja fazer:");
        scanf("%d", &opc);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if(opc < 0 || opc > 5)
            printf("numero invalido, digite novamente.");
        }while(opc < 0 || opc > 5);
        break;
    }
    case 1:{

        exibir();

        printf("\ndigite 0 para voltar ao menu:");
        do{
            scanf("%d", &opc);
            if(opc != 0)
                printf("numero invalido, digite novamente: ");
       }while(opc != 0);
        break;
    }
    case 2:{

        system("cls");

        FILE *arq;

        arq = fopen("arquivo.txt", "a");

        if(arq)
        {

        printf("digite as tarefas que deseja adicionar e o 1 para parar:");

        for(int i = 0;; i++){
            printf("\n%d - ",i+1);
            fgets(tarefa, 150, stdin);
            if( strcmp(tarefa, "1\n") == 0){
                break;
            }
            if( strcmp(tarefa, "\n") == 0){
                i--;
                continue;
            }
            fputs(tarefa,arq);


        }
        }
        printf("\n\ndigite 0 se deseja voltar ao menu ou 2 se deseja adicionar mais tarefas: ");
        do{
            scanf("%d", &opc);
            if(opc != 0 && opc !=2)
                printf("numero invalido, digite novamente: ");
        }while(opc != 0 && opc != 2);
        fclose(arq);

    break;
    }
    case 3:{

    FILE *arq;

    arq = fopen("arquivo.txt","r");
    char tarefas [100][150];
    char temp [150]; 
    int total = 0;
    int escolha;

    while (fgets(tarefas[total], sizeof(tarefas[total]), arq)) {
        total++;
    }
    fclose(arq);

    exibir();

    printf("\ndigite o numero da tarefa que deseja marcar como conlcuida: ");

    do{
        scanf("%d", &escolha);
        if(escolha<1 || escolha > total)
            printf("numero invalido, digite novamente: ");
        getchar();
    }while(escolha < 1 || escolha > total);

    for (int i = 0; tarefas[escolha - 1][i] != '\0'; i++) {
        if (tarefas[escolha - 1][i] == '\n') {
            tarefas[escolha - 1][i] = '\0';
        }
    }

    arq = fopen("arquivo.txt", "w");
    snprintf(temp, sizeof(temp), "%s [OK]\n", tarefas[escolha - 1]);
    strcpy(tarefas[escolha - 1], temp);
    for(int a = 0; a < total; a ++){
        fputs(tarefas[a],arq);
    }
    fclose(arq);
    printf("\n\nse deseja marcar mais tarefas como concluida '3', se deseja voltar ao menu digite '0': ");
    do{
    scanf("%d", &opc);
    if(opc != 3 && opc != 0)
        printf("unmero invalido, digite novamente: ");
    }while(opc != 3 && opc != 0);
    break;
    }
    case 4:{

    FILE *arq;

    arq = fopen("arquivo.txt","r");
    char tarefas [100][150];
    int total = 0;
    int escolha;

    while (fgets(tarefas[total], sizeof(tarefas[total]), arq)) {
        total++;
    }

    fclose(arq);

    exibir();

    printf("\ndigite o numero da tarefa que deseja excluir: ");
    do{
        scanf("%d", &escolha);
        if(escolha<1 || escolha > total)
            printf("numero invalido, digite novamente: ");
        getchar();
    }while(escolha < 1 || escolha > total);

    for(int i = escolha - 1; i < total - 1; i++){ 
        strcpy(tarefas[i], tarefas[i + 1]);

    }
    total--; 
    arq = fopen("arquivo.txt", "w");
    for(int i = 0; i < total; i ++){
        fputs(tarefas[i],arq);
    }
    fclose(arq);
    printf("\n\nse deseja apagar mais tarefar digite '4', se deseja voltar ao menu digite '0': ");
    do{
    scanf("%d", &opc);
    if(opc != 4 && opc != 0)
        printf("unmero invalido, digite novamente: ");
    }while(opc != 4 && opc != 0);
    break;
    }
    case 5:{
        system("cls");
        printf("encerrando o programa...");
        exit(5);
    }
    }
    }
    return 0;
}
