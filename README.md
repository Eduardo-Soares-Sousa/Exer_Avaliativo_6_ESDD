Feito por: Eduardo Soares de Sousa
Disciplina: Estrutura de Dados
Orientador: Ednilson Geraldo Rossi

Para o projeto foi utilizado a definição de três TADs: Fila LDE (lista duplamente encadeada), Pilha LSE (lista simplesmente encadeada) e
Paciente, cujas funções são respectivamente: a fila que armazena as pessoas a serem vacinadas, a pilha de pessoas já vacinadas e
Paciente que realiza o cadastro e armazenamento dos dados do paciente. Desse modo, o paciente ao ser cadastrado será inserido na fila de
acordo com sua prioridade e ao ser chamado para se vacinar este é sai da fila e é inserido na pilha dos vacinados. A divisão do trabalho foi
realizada de forma a ser implementado um TAD de cada vez para assim manter a objetividade do projeto.

Com o intuito de compilar o sistema é necessário realizar o "Run code" no arquivo "arquivo_aux.c", abrir em um terminal integrado e executar o 
arquivo .exe.

Sistema funcionando:

![image](https://github.com/Eduardo-Soares-Sousa/esdd_avaliativo_5/assets/141190077/bd9c209d-2bb0-4313-8076-3b9ab13d5f16)

Como dito anteriormente os TADs foram dividos em três em que a Fila LDE armazenaria os pacientes a serem vacinados além de realizar a movimentação
seguindo as priooridades, por esse motivo foi utilizado a lista duplamente encadeada, em que a movimentação dos dados torna-se mais fácil do que 
a lista simplesmente encadeada e o TAD pilha seria armazenados os pacientes que já foram vacinados esse TAD permite ver qual a última pessoa que foi
vacinada tendo assim o acesso do último grupo que já foi vacinado, e para manter essas funcionalidades o TAD Paciente permite o cadastro dos
pacientes armazenando o seu número do SUS, a idade e sua prioridade para vacinação, ademais de acodo com a prioridade do paciente a fila fará os 
ajustes necessários para adiciona-lo.

