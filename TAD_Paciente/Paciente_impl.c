#include "Paciente.h"
#include "Pilha.h"
#include "Fila.h"

struct paciente {
    int numSUS;
    int idade;
    int prioridade;
};

struct cadastro {
    Paciente vetor[MAX_SIZE];
    int cadastrados;
};

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

/*------------------------------------------------------------------------*/

Paciente criar_Paciente(int numSUS, int idade, bool ehTrabSaude, bool ehIndigena, bool ehRibeirinho, bool ehQuilombola, bool ehTrabEdu, bool ehDefiSevera, bool ehForcaSeg, bool ehTrabPeniten, bool ehDetento) {
    Paciente paciente = malloc(sizeof(struct paciente));

    paciente->numSUS = numSUS;
    paciente->idade = idade;
    paciente->prioridade = prioridades(ehTrabSaude, idade, ehIndigena, ehRibeirinho, ehQuilombola, ehTrabEdu, ehDefiSevera, ehForcaSeg, ehTrabPeniten, ehDetento);

    return paciente;
}

void destruir_Paciente(Paciente paciente){
    free(paciente);
}

/*
char* to_string_paciente(Paciente paciente){
    char* string = malloc(sizeof(char) * 200);

    char prioridade_str[20];
    snprintf(prioridade_str, 20, "%d", paciente->prioridade);

    snprintf(string, 200, "Paciente [numSUS = %d, idade = %d, prioridade = %s]", paciente->numSUS, paciente->idade, prioridade_str);

    return string;
}
*/

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