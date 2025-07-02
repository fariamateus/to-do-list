#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajuda.h"

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
        int qtdtar;

        arq = fopen("arquivo.txt", "a");

        if(arq)
        {

        printf("digite o numero de tarefas que deseja adicionar:");

        do{
            scanf("%d", &qtdtar);
            if(qtdtar <0)
                printf("numero invalido, digite novamente: ");
            getchar();
        }while(qtdtar<0);

        for(int i = 0; i < qtdtar; i++){
            printf("\n%d - ",i+1);
            fgets(tarefa, 150, stdin);
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
    char temp [150]; // variavel para armazenar temporariamente a tarefa que vai ser marcada como concluida ja que nao é possivel usar a mesma varivavel como argumento duas bezes em strcpy
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

    for(int i = escolha - 1; i < total - 1; i++){ // o -1 é necessario porque o indice do vetor comecar no 0, entao se vocd deseja mudar a tarefa 1, no indice no vetor ela estara localizada na posicao 0
        strcpy(tarefas[i], tarefas[i + 1]);

    }
    total--; // como uma tarefa foi apagada é necessario diminuir tambem o total de tarefas que estao salvas
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
