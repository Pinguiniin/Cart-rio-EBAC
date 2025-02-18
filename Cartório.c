#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	char arquivo[40]; //�nicio da cria��o de vari�veis/string
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40]; //Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" siginifica escrever
	fprintf(file, cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	 
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, "|"); //Faz uma divis�o no texto
	fclose(file); //Fecha a atualiza��o
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, nome); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, " "); //Faz uma divis�o no texto
	fclose(file); //Fecha a atualiza��o
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, sobrenome); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, "|"); //Faz uma divis�o no texto
	fclose(file); //Fecha a atualiza��o

	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, cargo); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o sistema
		
}

int consulta()
{
	
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //�nicio da cria��o de vari�veis/string
	char conteudo[200]; //Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Consultando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //Procura o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" siginifica ler
	
	if(file == NULL) //Verificando se o arquivo exite
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); //Aviso ao cliente caso n�o exista o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Mostra a descri��o que est� em loop
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //�nico das informa��es para o usu�rio
		printf("%s", conteudo); //%s refere-se a string, que mostra as informa��es do usu�rio
		printf("\n\n");  //Fim das informa��es para o usu�rio
	}
	
	system ("pause"); //Pausa o sistema
	
}

int deletar()
{
	char cpf[40]; //Cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Consultando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	remove(cpf); //deleta a vari�vel
		
	FILE *file; //Procura o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" siginifica ler
	
	if(file == NULL) //Verificando se o arquivo exite
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //Aviso ao cliente caso n�o exista o arquivo
		system("pause"); //Pausa o sistema
	}
	
}


int main()
{
	int opcao = 0; //Definindo vari�veis
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
		
		system("cls"); //respon�vel por limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
		printf("###Cart�rio da EBAC### \n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //respon�vel por limpar a tela
		
		switch(opcao) //�nicio da sele��o do menu
		{
			case 1: //Inicio da escolha do usu�rio
				registro(); //Chamada de fun��es
			break;
			
			case 2:
				consulta(); //Chamada de fun��es
			break;
			
			case 3:
				deletar(); //Chamada de fun��es
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default:
				printf ("Essa op��o n�o est� dispon�vel!\n"); //Aviso ao cliente caso selecione uma op��o inexistente
				system("pause"); //Pausa o sistema
		} //Fim da escolha do usu�rio
	
	
		printf("\nEsse Softare � de livre uso dos alunos\n");
	}
}
