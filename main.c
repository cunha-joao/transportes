#include "stdio.h"
#include "string.h"
#include "time.h"
#include "conio.h"

//DEFINICAO DE STRUCTS
typedef struct carga{
    char cliente[100];
    char origem[50];
    char destino[50];
    float distancia;
    float peso;
    float custo;
}CARGA;

typedef struct camiao{
    char matricula[6];
    float cargamax;
    int mes, ano;
    float custo_km;
    float custo_ton;
    float carga_atual;
    CARGA cargas[50];
}CAMIAO;

//DEFINICAO DE FUNCOES

// Limpar menu
void clear_menu() {
    int i = 0;
    for(i = 0; i < 5; i++) {
        printf("\n\n\n\n\n");
    }
}

//Aguardar por uma chave
void any_key() {
    printf("\nPress enter to continue...");
    getch();
}

//Listar camiao
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

//Listar carga
void listar_carga(CARGA carga, int i){
    printf("Carga n%i\n", i);
    printf("Nome do cliente: %s\n", carga.cliente);
    printf("Origem: %s\n", carga.origem);
    printf("Destino: %s\n", carga.destino);
    printf("Distancia: %.2f\n", carga.distancia);
    printf("Custo da carga: %.2f\n", carga.custo);
    printf("\n");
}

//1 - Inserir camiao
void inserir_camiao(CAMIAO camioes[20], int *num_camioes){
    CAMIAO camiao;

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

    camioes[*num_camioes] = camiao;
    (*num_camioes)++;

    printf("Camiao adicionado!");
}

//2 - Mostrar informacao
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

//3 - Alterar informacao
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

//4 - Eliminar informacao
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

//2 - Atribuir cargas!!!
void atribuir_carga(CAMIAO camioes[20], CARGA cargas[20], int *num_camioes, int *num_cargas){
    CARGA carga;
    int i;
    int calculo, resultado;

    printf("Nome do cliente:\n");
    scanf("%s", carga.cliente);
    fflush(stdin);

    printf("Local de origem:\n");
    scanf("%s", carga.origem);
    fflush(stdin);

    printf("Local de destino:\n");
    scanf("%s", carga.destino);
    fflush(stdin);

    printf("Distancia:\n");
    scanf("%f", &carga.distancia);

    printf("Peso:\n");
    scanf("%f", &carga.peso);

    for(i = 0; i < *num_camioes; i++){
        if(carga.peso + camioes[i].carga_atual < camioes[i].cargamax){
            camioes[i].carga_atual = camioes[i].carga_atual + carga.peso;

            cargas[*num_cargas] = carga;
            (*num_cargas)++;

            carga.custo = 100;
            //Calcula custo da carga
            /*calculo = (carga.distancia / 100);
            resultado = (calculo - calculo % 1);

            if(calculo%1 > 0){
                resultado = ((resultado + 1) * 100);
            }else{
                resultado = resultado * 100;
            }

            printf("%i\n", resultado);*/

            printf("Carga atribuida com sucesso!");
            return;
        }
    }
    printf("Ocorreu um erro!");


}

//1 - Listar frota de camioes
void listar_frota(CAMIAO camioes[20], int *num_camioes){
    int i;

    if(*num_camioes == 0){
        printf("Nao tem nenhum camiao registado!");
    }

    for (i = 0; i < *num_camioes; i++) {
        listar_camiao(camioes[i], i);
    }
}

//2 - Listar cargas de um camiao!!!
void listar_cargas(CAMIAO camioes[20], CARGA cargas[10],int *num_camioes, int *num_cargas){
    char pesquisa[100];
    int i, j;

    printf("Selecione a matricula do camiao:\n");
    scanf("%s", pesquisa);

    for(i = 0; i < *num_camioes; i++){
        if(strcmp(camioes[i].matricula, pesquisa) == 0){
            for(j = 0; j < *num_cargas; j++){
                listar_carga(cargas[i], i);
                return;
            }
        }
    }
    printf("Matricula nao encontrada!");
}

//3 - Listar transportes de um cliente!!!
void listar_transportes(CARGA cargas[10], int *num_cargas){
    char pesquisa[100];
    int i;

    printf("Digite o nome do cliente:\n");
    scanf("%s", pesquisa);

    for(i = 0; i < *num_cargas; i++){
        if(strcmp(cargas[i].cliente, pesquisa) == 0){
            listar_carga(cargas[i], i);
            return;
        }
    }
    printf("Nome nao encontrado!");
}

//4 - Listar camioes com inspecao
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

//1 - Menu "Gerir camioes"
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

//3 - Menu "Listar informacao"
void menu_listar(CAMIAO camioes[20], CARGA cargas[10], int *num_camioes, int *num_cargas){
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
                listar_cargas(camioes, cargas, num_camioes, num_cargas);
                any_key();
                break;
            case 3:
                listar_transportes(cargas, num_cargas);
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

//MAIN
int main() {
    int opcao;
    int num_camioes = 0;
    int num_cargas = 0;
    CAMIAO camioes[20];
    CARGA cargas[10];


    do {
        //Menu inicial
        clear_menu();

        printf("1 - Gerir camioes;\n");
        printf("2 - Atribuir cargas a camioes\n");
        printf("3 - Listar informacao\n");
        printf("0 - Terminar\n");

        printf("Escolha uma opcao:\n");
        scanf("%i", &opcao);

        clear_menu();
        switch (opcao) {
            case 1:
                menu_gerir(camioes, &num_camioes);
                break;
            case 2:
                atribuir_carga(camioes, cargas, &num_camioes, &num_cargas);
                any_key();
                break;
            case 3:
                menu_listar(camioes, cargas, &num_camioes, &num_cargas);
                break;
        }
    } while (opcao != 0);

    printf("Programa terminado!");
    return 0;
}
