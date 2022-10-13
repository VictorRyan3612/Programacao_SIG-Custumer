#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "modulo_midia.h"
#include "funcoes_aux.h"

#define True 1
#define False 0


///// Assinatura das funções:

char opcoes_pergunta(void);
int menu_midia(void);
void menu_midia_cadastro(void);
void menu_midia_editar(void);
void menu_midia_excluir(void);

int midia_cadastro(char a[], char b[], char c[]);
int midia_vizualizar(char a[], char b[], char c[]);
int midia_pesquisar(char a[], char b[], char c[]);
int midia_editar(char a[], char b[], char c[]);
int midia_excluir(char a[], char b[], char c[]);




int modulo_midia(char a[], char b[], char c[]){

    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do{
        menu_midia();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                midia_cadastro(a,b,c);
            }
            else if (opcao == '2'){
                midia_vizualizar(a,b,c);
            }
            else if (opcao == '3'){
                midia_pesquisar(a,b,c);
            }
            else if (opcao == '4'){
                midia_editar(a,b,c);
            }
            else if (opcao == '5'){
                midia_excluir(a,b,c);
            }
            
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            printf("Aperte enter para continuar\n");
            getchar();
        }
            
        
        if (opcao == '0'){
            printf("Voltando ao menu principal...\n");
        }

    }
    while (opcao != '0');
    return 0;
}


int midia_cadastro(char a[], char b[], char c[]){
    char opcao;
    int resp;
    
    menu_midia_cadastro();
    opcao = opcoes_pergunta();


    //Jogo
    if (opcao == '1'){
        do {
            printf(""
                "=======================================\n"
                "====  Qual jogo está interessado?  ====\n"
                "=======================================\n"
                );
            printf("(use ; para mais de um)\n");
            printf("\n");
            scanf("%20[^\n]", a);
            getchar();

            resp = validar_nomeMidia(a);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }


    //Livro
    if (opcao == '2'){
        do {
            printf(""
                "=======================================\n"
                "====  Qual livro está interessado? ====\n"
                "=======================================\n"
                );
            printf("use ; para mais de um\n");
            printf("\n");
            scanf("%20[^\n]", b);
            getchar();

            resp = validar_nomeMidia(b);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }

    //Filme
    if (opcao == '3'){
        do{
            printf(""
                "=======================================\n"
                "====  Qual Filme está interessado? ====\n"
                "=======================================\n"
                );
            printf("use ; para mais de um\n");
            printf("\n");
            scanf("%20[^\n]", c);
            getchar();

            resp = validar_nomeMidia(c);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }
    return 0;
}



int midia_vizualizar(char a[], char b[], char c[]){
    printf("\n");

    printf("Esse são os jogos que está interessado:\n");
    vizualizar_lista(a);
    printf("\n\n\n");

    printf("Esse são os livros que está interessado:\n");
    vizualizar_lista(b);
    printf("\n\n\n");


    printf("Esse são os filmes que está interessado:\n");
    vizualizar_lista(c);
    printf("\n\n\n");

    return 0;
}

int midia_pesquisar(char a[], char b[], char c[]){
    printf("Busca não disponível\n");

    return 0;
}

int midia_editar(char a[], char b[], char c[]){
    char opcao;
    int resp;

    menu_midia_editar();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    midia_vizualizar(a,b,c);

    opcao = opcoes_pergunta();

    
    // Editar Jogo
    if (opcao == '1'){
        printf("Seu atual interesse em jogo é:\n");
        printf("%s", a);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", a);
            getchar();

            resp = validar_nomeMidia(a);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }
    
    // Editar livro
    else if (opcao == '2'){
        printf("Seu atual interesse em livro é:\n");
        printf("%s", b);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", b);
            getchar();

            resp = validar_nomeMidia(b);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }

        
    // Editar filme
    else if (opcao == '3'){


        printf("Seu atual interesse em filme é:\n");
        printf("%s", c);
        printf("\n\n");
        do{
            printf(""
                "=======================================\n"
                "====        Atualize a lista       ====\n"
                "=======================================\n"
            );
            printf("\n");
            scanf("%20[^\n]", c);
            getchar();

            resp = validar_nomeMidia(c);
            if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);
    }


    return 0;
}

int midia_excluir(char a[], char b[], char c[]){
    char opcao;
    int resp;

    menu_midia_excluir();

    printf("\n\n");
    printf("Suas informações atualmente cadastradas são:\n");
    midia_vizualizar(a,b,c);

    printf("Digite qual deseja:\n");
    opcao = opcoes_pergunta();

    resp = confirmacao();
    if (resp == True){
        if (opcao == '1'){
            printf("Exluindo seu interesse em jogo\n");
            strcpy(a, "");
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '2'){
            printf("Exluindo seu livro interessado\n");
            strcpy(b, "");
            printf("Exluído com sucesso\n");

        }

        else if (opcao == '3'){
            printf("Exluindo seu filme interessado\n");
            strcpy(c, "");
            printf("Exluído com sucesso\n");
            
        }
    }
    return 0;
}