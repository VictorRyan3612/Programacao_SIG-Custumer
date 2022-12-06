#include <stdio.h>
#include <stdlib.h>


#include "funcoes_aux.h"
#include "modulo_usuario.h"
#include "modulo_redeSocial.h"
#include "modulo_midia.h"


void menu_relatorio(void);
void menu_listar_todos(void);

void rel_listar_usuario(void);
void rel_listar_redeSocial(void);
void rel_listar_midia(void);

void listar_todos();
void menu_listar_letra(void);

void listar_letra(void);
void rel_letra_usuario(void);
void rel_letra_redeSocial(void);
void rel_letra_midia(void);




void modulo_relatorio(){
    char opcao = '\0';

    do{
        system("cls||clear");
        menu_relatorio();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                listar_todos();
            }
            else if (opcao == '2'){
                listar_letra();
            }
            else {
                printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        else{
            printf("Voltando ao menu principal...\n");
        }

    } while (opcao != '0');

}

void listar_todos(void){
    char opcao = '\0';
    do{
        system("cls||clear");
        menu_listar_todos();

        opcao = opcoes_pergunta();
        if (opcao != '0'){
            if (opcao == '1'){
                rel_listar_usuario();
            }
            else if (opcao == '2'){
                rel_listar_redeSocial();
            }
            else if (opcao == '3'){
                rel_listar_midia();
            }
        
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        
        else{
            printf("Voltando ao menu principal...\n");
        }



    }while (opcao != '0');
}

void listar_letra(void){
    char opcao = '\0';

    do{
        system("cls||clear");
        menu_listar_letra();
        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                rel_letra_usuario();
            }
            else if (opcao == '2'){
                rel_letra_redeSocial();
            }
            else if (opcao == '3'){
                rel_letra_midia();
            }
        
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        
        else{
            printf("Voltando ao menu principal...\n");
        }



    }while(opcao != '0');  
}

void rel_listar_usuario(void){
    system("cls||clear");

    FILE* fp;
    Usuario* fulano_aqr;
    fulano_aqr = (Usuario*) malloc(sizeof(Usuario));

    int i;

    usuario_arq();

    printf(""
    "=================================\n"
    "======  Lista de Usuários  ======\n"
    "=================================\n"
    ""); 
    fp = fopen("arq_usuarios.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    i = 1;
    while(fread(fulano_aqr, sizeof(Usuario), 1, fp)) {
        if (fulano_aqr->status != 'x') {
            printf("\n= = = Usuario nº %d = = =\n",i);
            usuario_exibe(fulano_aqr);
            i+=1;
        }
    }

    fclose(fp);
    free(fulano_aqr);
}



void rel_listar_redeSocial(void){
    system("cls||clear");

    FILE* fp;
    RedeSocial* fulano_aqr;
    fulano_aqr = (RedeSocial*) malloc(sizeof(RedeSocial));

    int i;

    redeSocial_arq();

    printf(""
        "=================================\n"
        "==== Lista de Redes Sociais  ====\n"
        "=================================\n"
    "");
    fp = fopen("arq_redes_Sociais.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    i = 1;
    while(fread(fulano_aqr, sizeof(RedeSocial), 1, fp)) {
        if (fulano_aqr->status != 'x') {
            printf("\n= = = Redes Sociais nº %d = = =\n",i);
            redeSocial_exibe(fulano_aqr);
            i+=1;
        }
    }

    fclose(fp);
    free(fulano_aqr);
}


void rel_listar_midia(void){
    system("cls||clear");

    FILE* fp;
    Midia* fulano_aqr;
    fulano_aqr = (Midia*) malloc(sizeof(Midia));

    int i;

    midia_arq();

    printf(""
        "=================================\n"
        "======   Lista de Midias   ======\n"
        "=================================\n"
    "");
    fp = fopen("arq_midias.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }

    i = 1;
    while(fread(fulano_aqr, sizeof(Midia), 1, fp)) {
        if (fulano_aqr->status != 'x') {
            printf("\n= = = Midias nº %d = = =\n",i);
            midia_exibe(fulano_aqr);
            i+=1;
        }
    }

    fclose(fp);
    free(fulano_aqr);
}


void rel_letra_usuario(void){
    printf("\n");
}

void rel_letra_redeSocial(void){
    printf("\n");
}

void rel_letra_midia(void){
    printf("\n");
}