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

void clear_menu();

void any_key();

void listar_camiao(CAMIAO camiao, int i);

void listar_carga(CARGA carga, int i);

void inserir_camiao(CAMIAO camioes[20], int *num_camioes);

void mostrar_info(CAMIAO camioes[20],int *num_camioes);

void alterar_info(CAMIAO camioes[20],int *num_camioes);

void eliminar_info(CAMIAO camioes[20], int *num_camioes);

void atribuir_carga(CAMIAO *camiao);

void inserir_carga(CAMIAO camioes[20], int *num_camioes);

void listar_frota(CAMIAO camioes[20], int *num_camioes);

void listar_cargas(CAMIAO camioes[20], int *num_camioes);

void listar_transportes(CAMIAO camioes[20], int *num_camioes);

void listar_inspecao(CAMIAO camioes[20], int *num_camioes);



#endif //MAIN_C_CAMIOES_H
