#include "./TAD_Fila_Lista/Fila.h"
#include "./TAD_Paciente/Paciente.h"
#include "./TAD_Pilha_Lista/Pilha.h"

int menu();

int main(int argc, char const *argv[]){
    Cadastro sistema;
    iniciar_cadastro(&sistema);

    Fila fila_vacinacao, fila_vacinados;
    iniciar_fila(&fila_vacinacao);
    iniciar_fila(&fila_vacinados);

    Pilha pilha_vacinados;
    init(&pilha_vacinados);

    int opcao;
    do{
        opcao = menu();

        switch (opcao) {
            case 1: {
                int numSUS, idade;
                printf("Numero do SUS: ");
                scanf("%d", &numSUS);
                printf("Idade: ");
                scanf("%d", &idade);

                bool ehTrabSaude, ehIndigena, ehRibeirinho, ehQuilombola, ehTrabEdu, ehDefiSevera, ehForcaSeg, ehTrabPeniten, ehDetento;

                printf("Trabalha na saude (1 para sim, 0 para nao): ");
                scanf("%d", &ehTrabSaude);

                printf("Indigena (1 para sim, 0 para nao): ");
                scanf("%d", &ehIndigena);

                printf("Ribeirinho (1 para sim, 0 para nao): ");
                scanf("%d", &ehRibeirinho);

                printf("Quilombola (1 para sim, 0 para nao): ");
                scanf("%d", &ehQuilombola);

                printf("Trabalha na educacao (1 para sim, 0 para nao): ");
                scanf("%d", &ehTrabEdu);

                printf("Deficiencia severa (1 para sim, 0 para nao): ");
                scanf("%d", &ehDefiSevera);

                printf("Forca de seguranca (1 para sim, 0 para nao): ");
                scanf("%d", &ehForcaSeg);

                printf("Trabalha no setor penitenciario (1 para sim, 0 para nao): ");
                scanf("%d", &ehTrabPeniten);

                printf("Detento (1 para sim, 0 para nao): ");
                scanf("%d", &ehDetento);

                Paciente paciente = criar_Paciente(numSUS, idade, ehTrabSaude, ehIndigena, ehRibeirinho, ehQuilombola, ehTrabEdu, ehDefiSevera, ehForcaSeg, ehTrabPeniten, ehDetento);

                if (confirma_cadastro(sistema, paciente)) {
                    printf("Paciente cadastrado com sucesso!\n");
                    inserir_na_fila_prioritaria(fila_vacinacao, (Paciente) paciente);
                } else {
                    printf("Erro ao cadastrar paciente.\n");
                }

                break;
            }
            case 2: {
                Element paciente_atual = sai_da_fila(fila_vacinacao);
                if (paciente_atual != -1) {
                    adicionar_fila(fila_vacinados, paciente_atual);
                    push(pilha_vacinados, paciente_atual);
                    printf("Paciente chamado para vacinação e movido para a pilha de vacinados.\n");
                } else {
                    printf("Fila de vacinação vazia. Nenhum paciente chamado.\n");
                }

                break;
            
            }
            case 3: {
                printf("Pacientes vacinados:\n");

                Pilha temp_pilha;
                init(&temp_pilha);

                while (!is_empty(pilha_vacinados)) {
                    Tipo_Informacao paciente_vacinado;
                    pop(pilha_vacinados, &paciente_vacinado);
                    //printf("%s\n", to_string_paciente((Paciente)paciente_vacinado));

                    push(temp_pilha, paciente_vacinado);
                }

                while (!is_empty(temp_pilha)) {
                    Tipo_Informacao paciente_temp;
                    pop(temp_pilha, &paciente_temp);
                    push(pilha_vacinados, paciente_temp);
                }

                break;
            }
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }while(opcao != 0);

    destruir_cadastro(sistema);
    free(fila_vacinacao);
    free(fila_vacinados);
    free(pilha_vacinados);

    return 0;
}

int menu() {
    int option;

    printf("\t--------------------------------------------------------------------\n\n");
    printf("\t=====Selecione a opção que deseja=====\n");
    printf("\t1 - Cadastrar paciente......:\n");
    printf("\t2 - Chamar paciente para ser vacinado.........:\n");
    printf("\t3 - Mostrar a lista dos pacientes que já foram vacinados................:\n");
    printf("\t0 - Sair.\n\n");
    printf("Digite a opção desejada...: ");
    scanf("%d", &option);

    return option;
}
