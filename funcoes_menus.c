#include <stdio.h>
#include <stdlib.h>


void menu_sobre(void){

    printf("\n"
    "\t\tSobre o projeto:\n"
    "\tSIG-Custumer: Um sistema de controle de cliente\n"
    "As empresas da atualidade utilizam complexos sistemas gerenciais para, "
    "entre várias outras funções, gerenciar e manter seus clientes, "
    "além de ajudar a conseguir novos clientes. "
    "O presente projeto tem como objetivo propor um software que implementa "
    "funcionalidades básicas relacionadas ao controle de clientes de uma empresa, "
    "facilitando a gestão, além de, se possível, implementar sistemas de recomendação, "
    "nesse caso, com foco na área de games,"
    "\n\n"

    "\t\tDiscente/Autor do Projeto:\n"
    "Victor Ryan Galvão Silva\n"
    "matrícula:20220035163\n"
    "email:\n"
    "vitorsilva3612@gmail.com\n"
    "ryan.silva.706@ufrn.edu.br\n"
    "\n\n"

    "Ajudas externas:\n"
    "Dayanne Xavier: https://github.com/DayXL\n"
    "Flavius Gorgonio, professor da disciplina de programação\n"
    "\t\tlinks:"
    "https://replit.com/@flaviusgorgonio?tab=repls"
    "\n"
    );

}



void menu_principal(void){

    system("cls||clear");
    printf(""
        "|===================================================|\n"
        "|===================================================|\n"
        "|====                                           ====|\n"
        "|====       Programa Controle de Clientes       ====|\n"
        "|====                                           ====|\n"
        "|====                                           ====|\n"
        "|====            Digite qual deseja:            ====|\n"
        "|====           1 - Módulo Usuário              ====|\n"
        "|====           2 - Módulo Redes Sociais        ====|\n"
        "|====           3 - Módulo Mídia                ====|\n"
        "|====           4 - Módulo Relatórios           ====|\n"
        "|====           5 - Sobre e créditos            ====|\n"
        "|====                                           ====|\n"
        "|====                                           ====|\n"
        "|====               0 - Voltar                  ====|\n"
        "|===================================================|\n"
        "|===================================================|\n"
    );

}

void menu_usuario(void){

    system("cls||clear");

    printf(""
            "===================================================\n"
            "===================================================\n"
            "====                                           ====\n"
            "====         Controle de conta de Usuário      ====\n"
            "====                                           ====\n"
            "====                                           ====\n"
            "====               Digite qual deseja:         ====\n"
            "====             1 - Cadastrar Usuário         ====\n"
            "====             2 - Listar Usuários           ====\n"
            "====             3 - Procurar Usuário          ====\n"
            "====             4 - Editar Usuário            ====\n"
            "====             5 - Excluir Usuário           ====\n"
            "====                                           ====\n"
            "====                                           ====\n"
            "====               0 - Voltar                  ====\n"
            "===================================================\n"
            "===================================================\n"
        );
    
}

void menu_redeSocial(void){

    system("cls||clear");

    printf(""
            "===================================================\n"
            "===================================================\n"
            "====                                           ====\n"
            "====        Controle das Redes Sociais         ====\n"
            "====                                           ====\n"
            "====                                           ====\n"
            "====          Digite qual deseja:              ====\n"
            "====         1 - Cadastrar Rede Social         ====\n"
            "====         2 - Vizualizar Redes Sociais      ====\n"
            "====         3 - Procurar Rede Social          ====\n"
            "====         4 - Editar Rede Social            ====\n"
            "====         5 - Excluir Rede Social           ====\n"
            "====                                           ====\n"
            "====               0 - Voltar                  ====\n"
            "===================================================\n"
            "===================================================\n"
        );
}

void menu_midia(void){

    system("cls||clear");

    printf(""
        "===================================================\n"
        "===================================================\n"
        "====                                           ====\n"
        "====            Gerenciamento de Midia         ====\n"
        "====                                           ====\n"
        "====                                           ====\n"
        "====              Digite qual deseja:          ====\n"
        "====             1 - Cadastrar Midia           ====\n"
        "====             2 - Vizualizar Midia          ====\n"
        "====             3 - Procurar Midia            ====\n"
        "====             4 - Editar Midia              ====\n"
        "====             5 - Exlcuir Midia             ====\n"
        "====                                           ====\n"
        "====               0 - Voltar                  ====\n"
        "===================================================\n"
        "===================================================\n"
    );
    printf("\n\n");
    
}

void menu_relatorio(void){

    system("cls||clear");

    printf(""
            "===================================================\n"
            "===================================================\n"
            "====                                           ====\n"
            "====             Controle de Relatorio         ====\n"
            "====                                           ====\n"
            "====                                           ====\n"
            "====             Digite qual deseja:           ====\n"
            "====               1 - Listar Todos            ====\n"
            "====               2 - Por letra               ====\n"
            "====                                           ====\n"
            "====                                           ====\n"
            "====               0 - Voltar                  ====\n"
            "===================================================\n"
            "===================================================\n"
        );
    
}



///// Usuário

void menu_usuario_editar(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####              Edição de Usuário            ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####                 CPF:      1               ####\n"
        "####                 Nome:     2               ####\n"
        "####                 Email:    3               ####\n"
        "####                 Telefone: 4               ####\n"
        "####                                           ####\n"
        "####                 Voltar:  0                ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_usuario_excluir(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Exclusão de Usuário            ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####                 Voltar:  0                ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}




/////// midia
void menu_midia_cadastro(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####              Cadastro de Midia            ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####                 Jogo:   1                 ####\n"
        "####                 Livro:  2                 ####\n"
        "####                 Filme:  3                 ####\n"
        "####                                           ####\n"
        "####                 Voltar:  0                ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_midia_editar(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####              Edição de Mídia              ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####                 Jogo:   1                 ####\n"
        "####                 Livro:  2                 ####\n"
        "####                 Filme:  3                 ####\n"
        "####                                           ####\n"
        "####                 Voltar:  0                ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_midia_excluir(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Exclusão de Midias             ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####                 Voltar:  0                ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}



////// Rede Social
void menu_redeSocial_cadastro(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Cadastro de Rede Social        ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####             Digite qual deseja:           ####\n"
        "####                 Steam:    1               ####\n"
        "####                 Twitter:  2               ####\n"
        "####                 Youtube:  3               ####\n"
        "####                                           ####\n"
        "####                 Voltar:   0               ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_redeSocial_editar(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####            Edição de Rede Social          ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####             Digite qual deseja:           ####\n"
        "####                 Steam:    1               ####\n"
        "####                 Twitter:  2               ####\n"
        "####                 Youtube:  3               ####\n"
        "####                                           ####\n"
        "####                 Voltar:   0               ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_redeSocial_excluir(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####          Exclusão de Rede Social          ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####                 Voltar:  0                ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}




// Relatorios


void menu_listar_todos(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####                Listagem geral             ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####                                           ####\n"
        "####              Usuários:         1          ####\n"
        "####              Redes Sociais:    2          ####\n"
        "####              Mídias:           3          ####\n"
        "####                                           ####\n"
        "####                   Voltar:  0              ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_listar_todos_usuario(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####                Listagem Usuario           ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####                                           ####\n"
        "####              Ordem de cadastro:  1        ####\n"
        "####              Ordem Afabética:    2        ####\n"
        "####                                           ####\n"
        "####                   Voltar:  0              ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_listar_letra(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####              Listagem por letra           ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####              Digite qual deseja:          ####\n"
        "####                                           ####\n"
        "####              Usuários:         1          ####\n"
        "####              Redes Sociais:    2          ####\n"
        "####              Mídias:           3          ####\n"
        "####                                           ####\n"
        "####                   Voltar:  0              ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_letra_midia(void){

    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####               Listagem por letra          ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####               Digite qual deseja:         ####\n"
        "####                                           ####\n"
        "####                   Jogos:     1            ####\n"
        "####                   Livros:    2            ####\n"
        "####                   Filmes:    3            ####\n"
        "####                                           ####\n"
        "####                   Voltar:  0              ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}

void menu_letra_rede(void){
    system("cls||clear");
    printf(""
        "###################################################\n"
        "####                                           ####\n"
        "####               Listagem por letra          ####\n"
        "####                                           ####\n"
        "####                                           ####\n"
        "####               Digite qual deseja:         ####\n"
        "####                                           ####\n"
        "####                   Steam:      1           ####\n"
        "####                   Twitter:    2           ####\n"
        "####                   Youtube:    3           ####\n"
        "####                                           ####\n"
        "####                   Voltar:  0              ####\n"
        "###################################################\n"
    );
    printf("\n\n");
}