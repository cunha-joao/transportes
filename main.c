#include "camioes.h"
#include "menus.h"

//MAIN
int main() {
    int opcao;
    int num_camioes = 0;
    CAMIAO camioes[20];

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
                inserir_carga(camioes, &num_camioes);
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
