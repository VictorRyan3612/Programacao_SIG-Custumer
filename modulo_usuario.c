#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modulo_usuario.h"
#include "funcoes_aux.h"

typedef struct usuario Usuario;

#define True 1
#define False 0

// Assinatura das funções:
int menu_usuario(void);
void menu_usuario_editar(void);
void menu_usuario_excluir(void);
int confirmacao(void);

void usuario_arq(void);
void usuario_cadastro(void);
void usuario_gravar(Usuario* fulano);
Usuario* usuario_busca(void);
void usuario_exibe(Usuario* fulano);
void usuario_pesquisar(void);
void usuario_editar(void);
void usuario_excluir(void);


int usuario_existente(char fulano_cpf[12]);



void modulo_usuario(void){
    
    char opcao = '\0';

    do{
        menu_usuario();

        opcao = opcoes_pergunta();

        if (opcao != '0'){
            if (opcao == '1'){
                usuario_cadastro();
            }
            else if (opcao == '2'){
                rel_listar_usuario();
            }
            else if (opcao == '3'){
                usuario_pesquisar();
            }
            else if (opcao == '4'){
                usuario_editar();
            }
            else if (opcao == '5'){
                usuario_excluir();
            }
            
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            enter();
        }
            
        
        else{
            printf("Voltando ao menu principal...\n");
        }

    }
    while (opcao != '0');

}



void usuario_cadastro(void){
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));

    int resp;
    int valido;
    int achou;
    char fulano_cpf[12];

    system("cls||clear");
    printf("\n");


    // CPF
    do {
        printf(""
            "=======================================\n"
            "====       Informe seu cpf:        ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%12[^\n]", fulano -> cpf);
        getchar();
        
        resp = validar_num(fulano -> cpf);
        valido = validar_cpf(fulano -> cpf);
        if (resp != True){
            printf("Caractere inválido detectado, digite novamente:\n");
            }
        else if (valido != True){
            printf("CPF inválido, digite novamente:\n");
        }


        strcpy(fulano_cpf,fulano -> cpf);
        achou = usuario_existente(fulano_cpf);
        if (achou == True){
            printf("Usuário já cadastrado, digite outro\n");
        }

    } while ((resp != True) || (valido != True) || (achou == True));


    
    //nome
    do {
        printf(""
            "=======================================\n"
            "====       Informe seu nome:       ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%81[^\n]", fulano -> nome);
        getchar();

        resp = validar_nome(fulano -> nome);
        if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
        } while (resp != True);


    //email
    do {
        printf(""
            "=======================================\n"
            "====       Informe seu email:      ====\n"
            "=======================================\n"
        );
        printf("\n");
        scanf("%s", fulano -> email);
        getchar();
        
        resp = validar_email(fulano -> email);
        if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
    } while (resp != True);



    //telefone
    do {
        printf(""
            "=======================================\n"
            "====     Informe seu telefone:     ====\n"
            "=======================================\n"
            "obs: apenas numeros e parenteses\n"
        );
        printf("\n");
        scanf("%21[^\n]", fulano -> telefone);
        getchar();

        resp = validar_telefone(fulano -> telefone);
        if (resp != True){
                printf("Caractere inválido detectado, Digite novamente:\n");
            }
    } while (resp != True);

    
    fulano -> status = 'c';
    usuario_gravar(fulano);
    free(fulano);
}



int usuario_existente(char fulano_cpf[12]){
    int achou;
    FILE* fp;

    Usuario* fulano_aqr;
    fulano_aqr = (Usuario*) malloc(sizeof(Usuario));

    usuario_arq();

    fp = fopen("arq_usuarios.dat", "rb");
    

    while(!feof(fp)) {
        fread(fulano_aqr, sizeof(Usuario), 1, fp);
            if ((strcmp(fulano_aqr->cpf, fulano_cpf) == 0) && (fulano_aqr->status != 'x')){
                fclose(fp);
                return achou = True;;
            }
        }

    fclose(fp);
    return achou = False;
}



void usuario_arq(void){
    FILE* fp;
    fp = fopen("arq_usuarios.dat", "ab");
    fclose(fp);
}

void usuario_gravar(Usuario* fulano){
  FILE* fp;
  fp = fopen("arq_usuarios.dat", "ab");
  fwrite(fulano, sizeof(Usuario), 1, fp);
  fclose(fp);
}



void usuario_exibe(Usuario* fulano){
    printf("\n");
    
    char situacao[20];
    char status;

    if ((fulano == NULL) || (fulano->status == 'x')) {
        printf("\n= = = Usuario Inexistente = = =\n");
    } 
    else {
        printf("CPF: %s\n", fulano->cpf);
        printf("Nome do Usuario: %s\n", fulano->nome);
        printf("Endereço eletrônico: %s\n", fulano->email);
        printf("Telefone do usuario: %s\n", fulano->telefone);
    
        status = fulano->status;
        strcpy(situacao,status_exibe(status,situacao));
        printf("Situação do Usuario: %s\n", situacao);
    }

}


Usuario* usuario_busca(void){
    FILE* fp;
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));

    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();

    usuario_arq();

    fp = fopen("arq_usuarios.dat", "rb");
    

    while(!feof(fp)) {
        fread(fulano, sizeof(Usuario), 1, fp);
        if ((strcmp(fulano->cpf, cpf_busca_dig) == 0) && (fulano->status != 'x')){
            fclose(fp);
            return fulano;
        }
    }
    free(cpf_busca_dig);
    fclose(fp);
    return NULL;
}


void usuario_pesquisar(){
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));
    fulano = usuario_busca();
    usuario_exibe(fulano);
    enter();
}

void usuario_editar(){
    system("cls||clear");

    FILE* fp;
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));

    char resp;
    int certeza;
    char continuar;
    char opcao;
    int achou = False;

    usuario_arq();

    char* cpf_busca_dig;
    menu_usuario_editar();
    cpf_busca_dig = cpf_busca();


    fp = fopen("arq_usuarios.dat", "r+b");
    

    while(!feof(fp) && achou == False){
        fread(fulano, sizeof(Usuario), 1, fp);
        if ((strcmp(fulano->cpf, cpf_busca_dig) == 0) && (fulano->status != 'x')){
            achou = True;
        }
    }

    if (achou == False){
        printf("Usuario não concontrado\n");
    }

    else if (achou == True){
        do{
            system("cls||clear");
            menu_usuario_editar();
            usuario_exibe(fulano);

            printf("\n\n");
            printf("Digite qual campo deseja editar\n");
            opcao = opcoes_pergunta();


            // Editar cpf
            if (opcao == '1'){
                printf("Indisponível no momento\n");
                enter();
            }


            // Editar nome
            else if (opcao == '2'){
                printf("#### Seu atual nome é esse: ####\n");
                printf("%s", fulano -> nome);
                printf("\n\n");
                
                printf("Deseja realmente editar?\n");
                certeza = confirmacao();

                if (certeza == True){
                    do{
                        printf(""
                            "=======================================\n"
                            "====      Informe o atualizado:    ====\n"
                            "=======================================\n"
                        );
                        printf("\n");
                        scanf("%81[^\n]", fulano -> nome);
                        getchar();

                        resp = validar_nome(fulano -> nome);
                        if (resp != True){
                            printf("Caractere inválido detectado, Digite novamente:\n");
                        }
                    } while (resp != True);
                }
            }

            // Editar email
            else if (opcao == '3'){
                printf("#### Seu atual email é esse: ####\n");
                printf("%s", fulano -> email);
                printf("\n\n");

                printf("Deseja realmente editar?\n");
                certeza = confirmacao();
                if (certeza == True){
                    do{
                        printf(""
                            "=======================================\n"
                            "====      Informe o atualizado:    ====\n"
                            "=======================================\n"
                        );
                        printf("\n");
                        scanf("%s", fulano -> email);
                        getchar();
                        
                        resp = validar_email(fulano -> email);
                        if (resp != True){
                            printf("Caractere inválido detectado, Digite novamente:\n");
                        }
                    } while (resp != True);
                }
            }

                
            // Editar telefone
            else if (opcao == '4'){
                printf("#### Seu atual telefone é esse: ####\n");
                printf("%s", fulano -> telefone);
                printf("\n\n");

                printf("Deseja realmente editar?\n");
                certeza = confirmacao();

                if (certeza == True){
                    do{
                        printf(""
                            "=======================================\n"
                            "====      Informe o atualizado:    ====\n"
                            "=======================================\n"
                        );
                        printf("\n");
                        scanf("%s", fulano -> telefone);
                        getchar();

                        resp = validar_telefone(fulano -> telefone);
                        if (resp != True){
                            printf("Caractere inválido detectado, Digite novamente:\n");
                        }
                    } while (resp != True);
                }
            }

            else if (opcao == '0'){
                printf("Voltando ao menu principal...\n");
                getchar();
                continuar = False;
            }
            else{
                printf("Opção não dessenvolvida ou inválida\n");
            }
            if (opcao!='0'){
                printf("\nDeseja continuar?");
                continuar = confirmacao();
            }

        }while(continuar == True); 

        int var = 0;

        var = -1;

        fseek(fp, var*sizeof(Usuario), SEEK_CUR);
        fwrite(fulano, sizeof(Usuario), 1, fp);

    }
    free(cpf_busca_dig);
    free(fulano);
    fclose(fp);
}

void usuario_excluir(void){
    system("cls||clear");

    FILE* fp;
    Usuario* fulano;
    fulano = (Usuario*) malloc(sizeof(Usuario));

    int certeza;
    int achou = False;
    int var;

    usuario_arq();

    menu_usuario_excluir();
    char* cpf_busca_dig;
    cpf_busca_dig = cpf_busca();


    fp = fopen("arq_usuarios.dat", "r+b");
    

    while(!feof(fp) && achou == False){
        fread(fulano, sizeof(Usuario), 1, fp);
        if ((strcmp(fulano->cpf, cpf_busca_dig) == 0) && (fulano->status != 'x')){
            achou = True;
        }
    }

    if (achou == False){
        printf("Usuário não encontrado\n");
        enter();
    }

    else if (achou == True){
        usuario_exibe(fulano);
        printf("\n\n\n");
        printf("Deseja realmente apagar este usuario?");
        certeza = confirmacao();
        if (certeza == True){

            fulano->status = 'x';
            var = -1;
            fseek(fp, var*sizeof(Usuario), SEEK_CUR);
            fwrite(fulano, sizeof(Usuario), 1, fp);
            printf("\nUsuario excluído com sucesso!\n");
            fseek(fp, var*sizeof(Usuario), SEEK_CUR);
            fwrite(fulano, sizeof(Usuario), 1, fp);
        }
        else{
            printf("\nOk, os dados não foram alterados\n");
        }

        

    }
  free(fulano);
  free(cpf_busca_dig);
  fclose(fp);
}
