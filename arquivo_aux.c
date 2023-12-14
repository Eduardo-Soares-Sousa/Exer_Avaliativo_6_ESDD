#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 20
#define MAX_SIZE 10
#define MAX_SIZE_FILA 10

// Definição dos TADs

typedef struct stack* Pilha;
typedef int Tipo_Informacao;

void init(Pilha* pilha);
bool is_full(Pilha pilha);
bool is_empty(Pilha pilha);
bool push(Pilha pilha, Tipo_Informacao elemento);
bool pop(Pilha pilha, Tipo_Informacao* elemento);

typedef struct paciente* Paciente;
typedef struct cadastro* Cadastro;

struct paciente {
    int numSUS;
    int idade;
    int prioridade;
};

struct cadastro {
    Paciente vetor[MAX_SIZE];
    int cadastrados;
};

typedef struct node* Node;

struct node {
    Tipo_Informacao info;
    Node next;
};

struct stack {
    Node topo;
};

typedef struct fila* Fila;
typedef int Element;

struct fila {
    Node inicio;
    Node fim;
};

// Protótipos das funções relacionadas ao TAD Paciente
Paciente criar_Paciente(int numSUS, int idade, bool ehTrabSaude, bool ehIndigena, bool ehRibeirinho, bool ehQuilombola, bool ehTrabEdu, bool ehDefiSevera, bool ehForcaSeg, bool ehTrabPeniten, bool ehDetento);
void destruir_Paciente(Paciente paciente);
char* to_string_paciente(Paciente paciente);
int prioridades(bool ehTrabSaude, int idade, bool ehIndigena, bool ehRibeirinho, bool ehQuilombola, bool ehTrabEdu, bool ehDefiSevera, bool ehForcaSeg, bool ehTrabPeniten, bool ehDetento);

// Protótipos das funções relacionadas ao TAD Cadastro
void iniciar_cadastro(Cadastro* sistema);
bool confirma_cadastro(Cadastro sistema, Paciente paciente);
int tamanho_cadastro(Cadastro sistema);
bool esta_cheio(Cadastro sistema);
bool esta_vazio(Cadastro sistema);
void destruir_cadastro(Cadastro sistema);

// Protótipos das funções relacionadas ao TAD Fila
void iniciar_fila(Fila* fila);
bool eh_cheia_fila(Fila fila);
bool eh_vazia_fila(Fila fila);
bool adicionar_fila(Fila fila, Element novo_elemento);
Element sai_da_fila(Fila fila);

void inserir_na_fila_prioritaria(Fila fila, Element novo_elemento);
int menu();
// Função principal
int main() {
    // Inicializar sistema e filas
    Cadastro sistema;
    iniciar_cadastro(&sistema);

    Fila fila_vacinacao, fila_vacinados;
    iniciar_fila(&fila_vacinacao);
    iniciar_fila(&fila_vacinados);

    Pilha pilha_vacinados;
    init(&pilha_vacinados);

    int opcao;
    do {
        opcao = menu();

        switch (opcao) {
            case 1: {
                // Cadastrar paciente
                int numSUS, idade;
                printf("Numero do SUS: ");
                scanf("%d", &numSUS);
                printf("Idade: ");
                scanf("%d", &idade);

                // Preencher o questionário
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

                // Criar paciente com base no questionário
                Paciente paciente = criar_Paciente(numSUS, idade, ehTrabSaude, ehIndigena, ehRibeirinho, ehQuilombola, ehTrabEdu, ehDefiSevera, ehForcaSeg, ehTrabPeniten, ehDetento);

                // Adicionar paciente ao cadastro
                if (confirma_cadastro(sistema, paciente)) {
                    printf("Paciente cadastrado com sucesso!\n");
                    inserir_na_fila_prioritaria(fila_vacinacao, (Element) paciente);
                } else {
                    printf("Erro ao cadastrar paciente.\n");
                }

                break;
            }
            case 2: {
                // Chamar paciente para vacinação
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
                // Mostrar lista dos pacientes vacinados
                printf("Pacientes vacinados:\n");

                Pilha temp_pilha;
                init(&temp_pilha);

                while (!is_empty(pilha_vacinados)) {
                    Tipo_Informacao paciente_vacinado;
                    pop(pilha_vacinados, &paciente_vacinado);
                    printf("%s\n", to_string_paciente((Paciente)paciente_vacinado));

                    // Transferir para uma pilha temporária para manter a ordem original
                    push(temp_pilha, paciente_vacinado);
                }

                // Restaurar a ordem original
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
    } while (opcao != 0);

    // Liberar memória alocada
    destruir_cadastro(sistema);
    free(fila_vacinacao);
    free(fila_vacinados);
    free(pilha_vacinados);

    return 0;
}

// Implementação das funções relacionadas ao TAD Paciente
Paciente criar_Paciente(int numSUS, int idade, bool ehTrabSaude, bool ehIndigena, bool ehRibeirinho, bool ehQuilombola, bool ehTrabEdu, bool ehDefiSevera, bool ehForcaSeg, bool ehTrabPeniten, bool ehDetento) {
    Paciente paciente = malloc(sizeof(struct paciente));

    paciente->numSUS = numSUS;
    paciente->idade = idade;
    paciente->prioridade = prioridades(ehTrabSaude, idade, ehIndigena, ehRibeirinho, ehQuilombola, ehTrabEdu, ehDefiSevera, ehForcaSeg, ehTrabPeniten, ehDetento);

    return paciente;
}

void destruir_Paciente(Paciente paciente) {
    free(paciente);
}

char* to_string_paciente(Paciente paciente) {
    char* string = malloc(sizeof(char) * 200);

    char prioridade_str[20];
    snprintf(prioridade_str, 20, "%d", paciente->prioridade);

    snprintf(string, 200, "Paciente [numSUS = %d, idade = %d, prioridade = %s]", paciente->numSUS, paciente->idade, prioridade_str);

    return string;
}

int prioridades(bool ehTrabSaude, int idade, bool ehIndigena, bool ehRibeirinho, bool ehQuilombola, bool ehTrabEdu, bool ehDefiSevera, bool ehForcaSeg, bool ehTrabPeniten, bool ehDetento) {
    if (idade > 60) {
        return 2;
    } else if (ehTrabSaude) {
        return 1;
    } else if (ehIndigena) {
        return 3;
    } else if (ehRibeirinho || ehQuilombola) {
        return 4;
    } else if (ehTrabEdu) {
        return 6;
    } else if (ehDefiSevera) {
        return 7;
    } else if (ehForcaSeg) {
        return 8;
    } else if (ehTrabPeniten) {
        return 9;
    } else if (ehDetento) {
        return 10;
    }

    return 0;
}

// Implementação das funções relacionadas ao TAD Cadastro
void iniciar_cadastro(Cadastro* sistema) {
    *sistema = malloc(sizeof(struct cadastro));
    (*sistema)->cadastrados = 0;
}

bool confirma_cadastro(Cadastro sistema, Paciente paciente) {
    if (esta_cheio(sistema) || paciente == NULL) {
        return false;
    }
    sistema->vetor[sistema->cadastrados] = paciente;
    sistema->cadastrados += 1;
    return true;
}

int tamanho_cadastro(Cadastro sistema) {
    return sistema->cadastrados;
}

bool esta_cheio(Cadastro sistema) {
    return sistema->cadastrados == MAX_SIZE - 1;
}

bool esta_vazio(Cadastro sistema) {
    return sistema->cadastrados == 0;
}

void destruir_cadastro(Cadastro sistema) {
    free(sistema);
}

// Implementação das funções relacionadas ao TAD Fila
void iniciar_fila(Fila* fila) {
    *fila = malloc(sizeof(struct fila));
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;
}

bool eh_cheia_fila(Fila fila) {
    return false;
}

bool eh_vazia_fila(Fila fila) {
    return fila->inicio == NULL;
}

bool adicionar_fila(Fila fila, Element novo_elemento) {
    Node new_Node = malloc(sizeof(struct node));

    if (new_Node == NULL) {
        return false;
    }

    new_Node->info = novo_elemento;
    new_Node->next = NULL;

    if (eh_vazia_fila(fila)) {
        fila->inicio = new_Node;
    } else {
        fila->fim->next = new_Node;
    }

    fila->fim = new_Node;

    return true;
}

Element sai_da_fila(Fila fila) {
    if (eh_vazia_fila(fila)) {
        return -1;
    }

    Node first_node = fila->inicio;
    Element elemento = first_node->info;

    fila->inicio = first_node->next;
    free(first_node);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return elemento;
}

// Implementação das funções relacionadas ao TAD Pilha
bool is_full(Pilha pilha) {
    return false;
}

bool is_empty(Pilha pilha) {
    return pilha->topo == NULL;
}

void init(Pilha* pilha) {
    *pilha = malloc(sizeof(struct stack));
    (*pilha)->topo = NULL;
}

bool push(Pilha pilha, Tipo_Informacao elemento) {
    if (pilha != NULL) {
        Node novo = malloc(sizeof(struct node));
        novo->info = elemento;
        novo->next = pilha->topo;
        pilha->topo = novo;
        return true;
    }
    return false;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento) {
    if (pilha != NULL) {
        if (!is_empty(pilha)) {
            Node rip = pilha->topo;
            *elemento = rip->info;
            pilha->topo = rip->next;
            free(rip);
            return true;
        }
    }
    return false;
}

// Função para exibir o menu
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

void inserir_na_fila_prioritaria(Fila fila, Element novo_elemento) {
    if (eh_vazia_fila(fila)) {
        adicionar_fila(fila, novo_elemento);
        return;
    }

    Node novo_node = malloc(sizeof(struct node));
    novo_node->info = novo_elemento;
    novo_node->next = NULL;

    Node anterior = NULL;
    Node atual = fila->inicio;

    while (atual != NULL && ((Paciente)novo_elemento)->prioridade > ((Paciente)atual->info)->prioridade) {
        anterior = atual;
        atual = atual->next;
    }

    if (anterior == NULL) {
        // O novo elemento tem a maior prioridade
        novo_node->next = fila->inicio;
        fila->inicio = novo_node;
    } else {
        // Inserir no meio ou no final
        anterior->next = novo_node;
        novo_node->next = atual;
    }

    if (atual == NULL) {
        // Atualizar o fim da fila se necessário
        fila->fim = novo_node;
    }
}