#include "Paciente.h"

int main(int argc, char const *argv[]){
    
    Cadastro meus_cadastro;
    Paciente paciente;

    inciar_cadastro(&meus_cadastro);

    paciente = criar_Paciente(4900, 31, 0, 0, 0, 0, 1, 0, 0, 0, 0);
    confirma_cadastro(meus_cadastro, paciente);

    printf("%s\n", to_string_paciente(paciente));

    return 0;
}