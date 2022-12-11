//
// Created by joaoc on 06/12/2022.
//

#include "camioes.h"

//DEFINICAO DE FUNCOES

void clear_menu() {
    int i;
    for(i = 0; i < 5; i++) {
        printf("\n\n\n\n\n");
    }
}

void any_key() {
    printf("\nPress enter to continue...");
    getch();
}

void listar_camiao(CAMIAO camiao, int i){
    printf("Camiao n%i\n", i);
    printf("Matricula: %s\n", camiao.matricula);
    printf("Carga maxima: %.2f\n", camiao.cargamax);
    printf("Carga atual: %.2f\n", camiao.carga_atual);
    printf("Data de inspecao(mes/ano): %i/%i\n", camiao.mes, camiao.ano);
    printf("Custo por km: %.2f\n", camiao.custo_km);
    printf("Custo por tonelada: %.2f\n", camiao.custo_ton);
    printf("\n");
}

void listar_carga(CARGA carga, int i){
    printf("Carga n%i\n", i);
    printf("Nome do cliente: %s\n", carga.cliente);
    printf("Origem: %s\n", carga.origem);
    printf("Destino: %s\n", carga.destino);
    printf("Distancia: %i\n", carga.distancia);
    printf("Peso: %i\n", carga.peso);
    printf("Custo da carga: %.2f\n", carga.custo);
    printf("\n");
}

void inserir_camiao(CAMIAO camioes[20], int *num_camioes){
    CAMIAO camiao;
    int i;

    printf("Matricula:\n");
    scanf("%s", camiao.matricula);
    fflush(stdin);

    printf("Carga maxima:\n");
    scanf("%f", &camiao.cargamax);

    printf("Mes de inspecao:\n");
    scanf("%i", &camiao.mes);

    printf("Ano de inspecao:\n");
    scanf("%i", &camiao.ano);

    printf("Custo por km:\n");
    scanf("%f", &camiao.custo_km);

    printf("Custo por tonelada:\n");
    scanf("%f", &camiao.custo_ton);

    camiao.carga_atual=0;

    for(i = 0; i < 20; i++){
        strcpy(camiao.cargas[i].cliente, "");
    }

    camioes[*num_camioes] = camiao;
    (*num_camioes)++;

    printf("Camiao adicionado!");
}

void mostrar_info(CAMIAO camioes[20],int *num_camioes){
    char pesquisa[100];
    int i;

    printf("Selecione a matricula do camiao:\n");
    scanf("%s", pesquisa);

    for(i = 0; i < *num_camioes; i++){
        if(strcmp(camioes[i].matricula, pesquisa) == 0){
            listar_camiao(camioes[i], i);
            return;
        }
    }
    printf("Matricula nao encontrada!");
}

void alterar_info(CAMIAO camioes[20],int *num_camioes){
    char pesquisa[100];
    int i;

    printf("Selecione a matricula do camiao a alterar:\n");
    scanf("%s", pesquisa);

    for(i = 0; i < *num_camioes; i++){
        if(strcmp(camioes[i].matricula, pesquisa) == 0){

            printf("Matricula:\n");
            scanf("%s", camioes[i].matricula);
            fflush(stdin);

            printf("Carga maxima:\n");
            scanf("%f", &camioes[i].cargamax);

            printf("Mes de inspecao:\n");
            scanf("%i", &camioes[i].mes);

            printf("Ano de inspecao:\n");
            scanf("%i", &camioes[i].ano);

            printf("Custo por km:\n");
            scanf("%f", &camioes[i].custo_km);

            printf("Custo por tonelada:\n");
            scanf("%f", &camioes[i].custo_ton);

            camioes[i].carga_atual=0;

            printf("Informacao alterada!");
            return;
        }
    }
    printf("Matricula nao encontrada!");
}

void eliminar_info(CAMIAO camioes[20], int *num_camioes){
    char pesquisa[100];
    int i, j;

    printf("Selecione a matricula do camiao:\n");
    scanf("%s", pesquisa);

    for(i = 0; i < *num_camioes; i++){
        if(strcmp(camioes[i].matricula, pesquisa) == 0){
            for(j = i; j < *num_camioes; j++){
                camioes[j] = camioes[j + 1];
                (*num_camioes)--;
            }
            printf("Camiao eliminado!");
            return;
        }
    }
    printf("Matricula nao encontrada!");
}

void atribuir_carga(CAMIAO *camiao){
    int i;
    int calc_dist, res_dist;
    int calc_peso, res_peso;

    for(i = 0; i < 20; i++){
        if(strcmp(camiao->cargas[i].cliente, "") == 0){

            printf("Nome do cliente:\n");
            scanf("%s", camiao->cargas[i].cliente);
            fflush(stdin);

            printf("Local de origem:\n");
            scanf("%s", camiao->cargas[i].origem);
            fflush(stdin);

            printf("Local de destino:\n");
            scanf("%s", camiao->cargas[i].destino);
            fflush(stdin);

            printf("Distancia:\n");
            scanf("%i", &camiao->cargas[i].distancia);

            if(camiao->cargas[i].distancia == 0){
                printf("Distancia nao pode ser 0!");
                return;
            }

            printf("Peso:\n");
            scanf("%i", &camiao->cargas[i].peso);

            if(camiao->cargas[i].peso == 0){
                printf("Peso nao pode ser 0!");
                return;
            }

            if(camiao->cargas[i].peso + camiao->carga_atual < camiao->cargamax){
                camiao->carga_atual = camiao->carga_atual + camiao->cargas[i].peso;

                //Calcula custo da carga pela distancia
                calc_dist = (camiao->cargas[i].distancia / 100);
                res_dist = (camiao->cargas[i].distancia % 100);

                if(calc_dist == 0){
                    res_dist = 100;
                }
                if(calc_dist > 0 && res_dist > 0){
                    res_dist = ((calc_dist + 1) * 100);
                }
                if(calc_dist > 0 && res_dist == 0){
                    res_dist = calc_dist * 100;
                }

                //Calcula custo da carga pelo peso
                calc_peso = (camiao->cargas[i].peso / 1000);
                res_peso = (camiao->cargas[i].peso % 1000);

                if(calc_peso == 0){
                    res_peso = 1000;
                }
                if(calc_peso > 0 && res_peso > 0){
                    res_peso = ((calc_peso + 1) * 1000);
                }
                if(calc_peso > 0 && res_peso == 0){
                    res_peso = calc_peso * 1000;
                }

                //Calcula custo final da carga
                camiao->cargas[i].custo = (camiao->custo_km * res_dist) + (camiao->custo_ton * res_peso);

                printf("Custo final da carga: %.2f\n", camiao->cargas[i].custo);

                printf("Carga atribuida com sucesso!\n");
            }
            else
                printf("Ocorreu um erro!");
            return;
        }
    }
}

void inserir_carga(CAMIAO camioes[20], int *num_camioes){
    char pesquisa[100];
    int i;

    printf("Selecione a matricula do camiao desejado:\n");
    scanf("%s", pesquisa);

    for(i = 0; i < *num_camioes; i++){
        if(strcmp(camioes[i].matricula, pesquisa) == 0){
            atribuir_carga(&camioes[i]);
            return;
        }
    }
    printf("Matricula nao encontrada!");
}

void listar_frota(CAMIAO camioes[20], int *num_camioes){
    int i;

    if(*num_camioes == 0){
        printf("Nao tem nenhum camiao registado!");
    }

    for (i = 0; i < *num_camioes; i++) {
        listar_camiao(camioes[i], i);
    }
}

void listar_cargas(CAMIAO camioes[20], int *num_camioes){
    char pesquisa[100];
    int i, j;
    int encontrou = 0;

    printf("Selecione a matricula do camiao:\n");
    scanf("%s", pesquisa);

    for(i = 0; i < *num_camioes; i++){
        if(strcmp(camioes[i].matricula, pesquisa) == 0){
            j = 0;
            encontrou = 1;
            while (strcmp(camioes[i].cargas[j].cliente, "") != 0){
                listar_carga(camioes[i].cargas[j], j);
                j++;
            }
        }
    }
    if(encontrou == 0) {
        printf("Matricula nao encontrada!");
    }
}

void listar_transportes(CAMIAO camioes[20], int *num_camioes){
    char pesquisa[100];
    int i, j;
    int encontrou = 0;

    printf("Digite o nome do cliente:\n");
    scanf("%s", pesquisa);

    for(i = 0; i < *num_camioes; i++){
        j = 0;
        while (strcmp(camioes[i].cargas[j].cliente, "") != 0){
            if(strcmp(camioes[i].cargas[j].cliente, pesquisa) == 0) {
                listar_carga(camioes[i].cargas[j], j);
                encontrou = 1;
            }
            j++;
        }
    }
    if(encontrou == 0) {
        printf("Nome nao encontrado!");
    }
}

void listar_inspecao(CAMIAO camioes[20], int *num_camioes){
    int i;

    time_t data_atual;
    data_atual = time(NULL);
    struct tm tm = *localtime(&data_atual);

    if(*num_camioes == 0){
        printf("Nao tem nenhum camiao registado!");
    }

    for (i = 0; i < *num_camioes; i++) {
        if(camioes[i].mes == tm.tm_mon + 1 && camioes[i].ano == tm.tm_year + 1900){
            listar_camiao(camioes[i], i);
        }
    }
}
