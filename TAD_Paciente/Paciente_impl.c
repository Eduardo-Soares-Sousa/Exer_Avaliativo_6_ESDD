#include "Paciente.h"

struct paciente{
    int numSUS;
    int idade;
    int prioridade;
};

struct cadastro{
    Paciente vetor[MAX_SIZE];
    int cadastrados;
};

int tamanho_cadastro(Cadastro sistema){
    return sistema->cadastrados;
}

void inciar_cadastro(Cadastro* sistema){
    *sistema = malloc(sizeof(struct cadastro));
    (*sistema)->cadastrados = 0;
}

bool confirma_cadastro(Cadastro sistema, Paciente paciente){
    if(esta_cheio(sistema) || paciente == NULL){
        return false;
    }
    sistema->vetor[sistema->cadastrados] = paciente;
    sistema->cadastrados += 1;
    return true;    
}

bool esta_cheio(Cadastro sistema){
    if(sistema->cadastrados == MAX_SIZE-1){
        return true;
    }else{
        return false;                                                                                                   
    }
}

bool esta_vazio(Cadastro sistema){
    return sistema->cadastrados == 0;
}

/*------------------------------------------------------------------------*/

/*
bool questionario(bool t){
    
}
*/

Paciente criar_Paciente(int numSUS, int idade, bool ehTrabSaude, bool ehIndigena, bool ehRibeirinho, bool ehQuilombola, bool ehTrabEdu, bool ehDefiSevera, bool ehForcaSeg, bool ehTrabPeniten, bool ehDetento){
    Paciente paciente;
    paciente = malloc(sizeof(struct paciente));

    paciente->numSUS = numSUS;
    paciente->idade = idade;
    //paciente->prioridade = prioridades(int prioridades);

    if(idade > 60){
        paciente->prioridade = 2;
    }else if(ehTrabSaude){
        paciente->prioridade = 1;
    } else if(ehIndigena){
        paciente->prioridade = 3;
    } else if(ehRibeirinho || ehQuilombola){
        paciente->prioridade = 4;
    } else if(ehTrabEdu){
        paciente->prioridade = 6;
    } else if(ehDefiSevera){
        paciente->prioridade = 7;
    } else if(ehForcaSeg){
        paciente->prioridade = 8;
    } else if(ehTrabPeniten){
        paciente->prioridade = 9;
    } else if(ehDetento){
        paciente->prioridade = 10;
    }

    return paciente;                        
}

void destruir_Paciente(Paciente paciente){
    free(paciente);
}

char* to_string_paciente(Paciente paciente){
    char* string;
    string = malloc(sizeof(char) * 200);

    char prioridade_str[20];
    snprintf(prioridade_str, 20, "%d", paciente->prioridade);

    snprintf(string, 200, "Paciente [numSUS = %d, idade = %d, prioridade = %s]", paciente->numSUS, paciente->idade, prioridade_str);

    return string;
}