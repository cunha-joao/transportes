#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"

//Definição de structs
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
    printf("Matricula:%s\n", camiao.matricula);
    printf("Carga maxima:%.2f\n", camiao.cargamax);
    printf("Data de Inspecao:%i/%i\n", camiao.mes, camiao.ano);
    printf("Custo por km:%.2f\n", camiao.custo_km);
    printf("\n");
}

//Inserir camiao
void inserir_camiao(CAMIAO camioes[20], int *num_camioes){
    CAMIAO camiao;

    printf("Matricula:\n");
    scanf("%s", &camiao.matricula);
    fflush(stdin);

    printf("Carga maxima:\n");
    scanf("%f", &camiao.cargamax);

    printf("Mes de inspecao:\n");
    scanf("%i", &camiao.mes);

    printf("Ano de inspecao:\n");
    scanf("%i", &camiao.ano);

    printf("Custo por km:\n");
    scanf("%f", &camiao.custo_km);

    camioes[*num_camioes] = camiao;
    (*num_camioes)++;

    printf("Camiao adicionado!");
    return;
}

//Mostrar informacao
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

//Alterar informacao
void alterar_info(){
    CAMIAO camiao;
    char pesquisa;

    printf("Selecione a matricula do camiao a alterar:\n");
    scanf("%s", &pesquisa);

    return;
}

//Eliminar informacao
void eliminar_info(){
    CAMIAO camiao;
    char pesquisa_info;

    printf("Seleciona a matricula do camiao a eliminar:\n");
    scanf("%s", &pesquisa_info);

    return;
}

//Atribuir cargas
void atribuir_carga(){
    CARGA carga;
    CAMIAO camiao;

    printf("Nome do cliente:\n");
    scanf("%s", &carga.cliente);

    printf("Local de origem:\n");
    scanf("%s", &carga.origem);

    printf("Local de destino:\n");
    scanf("%s", &carga.destino);

    printf("Distancia:\n");
    scanf("%f", &carga.distancia);

    printf("Peso:\n");
    scanf("%f", &carga.peso);

    //Calcula custo da carga
}

//Listar frota de camioes
void listar_frota(CAMIAO camioes[20], int *num_camioes){
    int i = 0;

    for(i =0 ; i < *num_camioes; i++){
        listar_camiao(camioes[i], i);
    }
    return;
}

//Listar cargas de um camiao
void listar_carga(){
    CAMIAO camiao;
    char pesquisa;

    printf("Digite a matricula do camiao:\n");
    scanf("%s", &pesquisa);

    return;
}

//Listar transportes de um cliente
void listar_transportes(){
    CAMIAO camiao;
    char pesquisa;

    printf("Digite o nome do cliente:\n");
    scanf("%s", &pesquisa);

    return;
}

//Listar camioes com inspecao
void listar_inspecao(CAMIAO camioes[20], int *num_camioes){
    int i = 0;

    time_t data_atual;
    data_atual = time(NULL);
    struct tm tm = *localtime(&data_atual);

    for (int i = 0; i < *num_camioes; i++) {
        if(camioes[i].mes == tm.tm_mon + 1 && camioes[i].ano == tm.tm_year + 1900){
            listar_camiao(camioes[i], i);
        }
    }
    return;
}


//Menu "Gerir camioes"
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
                break;
            case 4:
                break;
        }
    } while (opcao != 0);
    return;
}

//Menu "Listar informacao"
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
                break;
            case 3:
                break;
            case 4:
                listar_inspecao(camioes, num_camioes);
                any_key();
                break;
        }
    } while (opcao != 0);
    return;
}


int main() {
    int opcao;
    int num_camioes = 0;
    CAMIAO camioes[20];


    do {
        //Definir o menu inicial
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
                any_key();
                break;
            case 3:
                menu_listar(camioes, &num_camioes);
                break;
        }
    } while (opcao != 0);

    printf("Programa terminado!");
    return 0;
}
