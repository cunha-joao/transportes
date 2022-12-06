//
// Created by joaoc on 06/12/2022.
//

#ifndef MAIN_C_CAMIOES_H
#define MAIN_C_CAMIOES_H

#include "stdio.h"
#include "string.h"
#include "time.h"
#include "conio.h"

//DEFINICAO DE STRUCTS
typedef struct carga{
    char cliente[100];
    char origem[50];
    char destino[50];
    int distancia;
    int peso;
    float custo;
}CARGA;

typedef struct camiao{
    char matricula[6];
    float cargamax;
    int mes, ano;
    float custo_km;
    float custo_ton;
    float carga_atual;
    CARGA cargas[20];
}CAMIAO;

//DEFINICAO DE FUNCOES

// Limpar menu
void clear_menu();

//Aguardar por uma chave
void any_key();

//Listar camiao
void listar_camiao(CAMIAO camiao, int i);

//Listar carga
void listar_carga(CARGA carga, int i);

//1 - Inserir camiao
void inserir_camiao(CAMIAO camioes[20], int *num_camioes);

//2 - Mostrar informacao
void mostrar_info(CAMIAO camioes[20],int *num_camioes);

//3 - Alterar informacao
void alterar_info(CAMIAO camioes[20],int *num_camioes);

//4 - Eliminar informacao
void eliminar_info(CAMIAO camioes[20], int *num_camioes);

//2 - Atribuir cargas
void atribuir_carga(CAMIAO *camiao);

//2.1 - Selecionar camiao para atribuir carga
void inserir_carga(CAMIAO camioes[20], int *num_camioes);

//1 - Listar frota de camioes
void listar_frota(CAMIAO camioes[20], int *num_camioes);

//2 - Listar cargas de um camiao
void listar_cargas(CAMIAO camioes[20], int *num_camioes);

//3 - Listar transportes de um cliente
void listar_transportes(CAMIAO camioes[20], int *num_camioes);

//4 - Listar camioes com inspecao
void listar_inspecao(CAMIAO camioes[20], int *num_camioes);



#endif //MAIN_C_CAMIOES_H
