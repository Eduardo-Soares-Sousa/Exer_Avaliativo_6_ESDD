#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct paciente* Paciente;
typedef struct cadastro* Cadastro;

/*Cadastro de paciente*/

void inciar_cadastro(Cadastro* sistema);

bool confirma_cadastro(Cadastro, Paciente paciente);

int tamanho_cadastro(Cadastro sistema);  

bool esta_cheio(Cadastro sistema);

bool esta_vazio(Cadastro sistema);

void destruir_cadastro(Cadastro sistema);

/*Fim Cadastro paciente*/

/*-------------------------------------------------------*/

/*Paciente*/

int prioridades(int prioridades);

Paciente criar_Paciente(int numSUS, int idade, bool ehTrabSaude, bool ehIndigena, bool ehRibeirinho, bool ehQuilombola, bool ehTrabEdu, bool ehDefiSevera, bool ehForcaSeg, bool ehTrabPeniten, bool ehDetento);

void destruir_Paciente(Paciente paciente);

char* to_string_paciente(Paciente paciente);

/*Fim Paciente*/