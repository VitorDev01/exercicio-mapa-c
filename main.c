  #include <stdio.h>
  #include <stdlib.h>
  #include <locale.h>
  #include <stdbool.h>
  
  //registro 
  struct Consulta {
  	char nome[100];
  	int dia;
  	int hora;
  };
  
  // variaveis globais
  struct Consulta agenda[300];
  int qtdAgendamento;
  
  bool verificarDisponibilidade(int diaAgenda, int horaAgenda) {
  	 
  	 if (horaAgenda < 8 || horaAgenda > 20){
  	 	printf("Clinica fechada neste horario\n");
  	 	return false;
	   }
	   return true;
  }
  
  void agendarConsulta(){
  
  	int diaAgenda;
  	printf("qual dia deseja agendar:\n");
  	fflush(stdin);
  	scanf("%d", &diaAgenda);
  	
  	int horaAgenda;
  	printf("Qual hora do dia:\n");
  	fflush(stdin);
  	scanf("%d", &horaAgenda);
  	
  	if(verificarDisponibilidade(diaAgenda, horaAgenda)) {
  		printf("Hor�rio disponivel\n");
  		printf("Vamos Confirmar Seu Agendamento\n");
  		agenda[qtdAgendamento].dia = diaAgenda;
  		agenda[qtdAgendamento].hora = horaAgenda;
  		printf("Qual � o seu nome:\n");
  		fflush(stdin);
  		gets(agenda[qtdAgendamento].nome);
  		qtdAgendamento = qtdAgendamento + 1;
  		printf("Agendamento realizado!\n");	
	  }  else {
	  	printf("Hor�rio indisponivel\n"); 	
	  }	  
  }
  
  void listarConsulta() {
  	int i;
  	for(i = 0; i < qtdAgendamento; i++) {
  		printf("================================\n");
  		printf("Nome: %s\n", agenda[i].nome);
  		printf("Dia %d\n", agenda[i].dia);
  	    printf("Hora %d\n", agenda[i].hora);
	  }
  }
  
  void main() {
  	
  	setlocale(LC_ALL, "");
  	
  	int opcao;
  	qtdAgendamento = 0;
  	
  	do{
  		printf("Escolha uma op��o agora\n");
  		printf("1 - Agendar\n");
  		printf("2 - listar\n");
  		printf("3 - Sair\n");
  		fflush(stdin);
  		scanf("%d", &opcao);
  		
  		switch(opcao){
  		    case 1 : {
              agendarConsulta();
              break;
			}
            case 2 : {				
              listarConsulta();
              break;
            }
           case 3 : {
              printf("Saindo do programa...\n");
              break;
			}
			default : {
				printf("Saindo do Programa\n...");
				break;
			}
        }
        }while (opcao !=3);	   	  
   }

