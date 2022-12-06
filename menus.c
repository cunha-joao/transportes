//
// Created by joaoc on 06/12/2022.
//

#include "menus.h"

void menu_gerir(CAMIAO camioes[20], int *num_camioes){
    int opcao;

    do {
        clear_menu();
        printf("1 - Inserir novo camiao\n");
        printf("2 - Mostrar informacao de um camiao\n");
        printf("3 - Alterar informacao de um camiao\n");
        printf("4 - Eliminar um camiao\n");
        printf("0 - Voltar atras\n");

        printf("Escolha uma opcao:\n");
        scanf("%i", &opcao);
        clear_menu();

        switch (opcao) {
            case 1:
                inserir_camiao(camioes, num_camioes);
                any_key();
                break;
            case 2:
                mostrar_info(camioes, num_camioes);
                any_key();
                break;
            case 3:
                alterar_info(camioes, num_camioes);
                any_key();
                break;
            case 4:
                eliminar_info(camioes, num_camioes);
                any_key();
                break;
        }
    } while (opcao != 0);
    return;
}

void menu_listar(CAMIAO camioes[20], int *num_camioes){
    int opcao;

    do {
        clear_menu();
        printf("1 - Listar frota de camioes\n");
        printf("2 - Listar cargas de um camiao\n");
        printf("3 - Listar transportes de um cliente\n");
        printf("4 - Listar camioes para inspecao\n");
        printf("0 - Voltar atras\n");

        printf("Escolha uma opcao:\n");
        scanf("%i", &opcao);
        clear_menu();

        switch (opcao) {
            case 1:
                listar_frota(camioes, num_camioes);
                any_key();
                break;
            case 2:
                listar_cargas(camioes, num_camioes);
                any_key();
                break;
            case 3:
                listar_transportes(camioes, num_camioes);
                any_key();
                break;
            case 4:
                listar_inspecao(camioes, num_camioes);
                any_key();
                break;
        }
    } while (opcao != 0);
    return;
}