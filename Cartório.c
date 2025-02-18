#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	char arquivo[40]; //Ínicio da criação de variáveis/string
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40]; //Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" siginifica escrever
	fprintf(file, cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	 
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, "|"); //Faz uma divisão no texto
	fclose(file); //Fecha a atualização
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, nome); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, " "); //Faz uma divisão no texto
	fclose(file); //Fecha a atualização
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, sobrenome); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, "|"); //Faz uma divisão no texto
	fclose(file); //Fecha a atualização

	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo com o "a" de atualizar
	fprintf(file, cargo); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o sistema
		
}

int consulta()
{
	
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	char cpf[40]; //Ínicio da criação de variáveis/string
	char conteudo[200]; //Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //Consultando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //Procura o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" siginifica ler
	
	if(file == NULL) //Verificando se o arquivo exite
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n"); //Aviso ao cliente caso não exista o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Mostra a descrição que está em loop
	{
		printf("\nEssas são as informações do usuário: "); //Ínico das informações para o usuário
		printf("%s", conteudo); //%s refere-se a string, que mostra as informações do usuário
		printf("\n\n");  //Fim das informações para o usuário
	}
	
	system ("pause"); //Pausa o sistema
	
}

int deletar()
{
	char cpf[40]; //Criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //Consultando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	remove(cpf); //deleta a variável
		
	FILE *file; //Procura o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" siginifica ler
	
	if(file == NULL) //Verificando se o arquivo exite
	{
		printf("O usuário não se encontra no sistema!.\n"); //Aviso ao cliente caso não exista o arquivo
		system("pause"); //Pausa o sistema
	}
	
}


int main()
{
	int opcao = 0; //Definindo variáveis
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
		
		system("cls"); //responável por limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
		printf("###Cartório da EBAC### \n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responável por limpar a tela
		
		switch(opcao) //Ínicio da seleção do menu
		{
			case 1: //Inicio da escolha do usuário
				registro(); //Chamada de funções
			break;
			
			case 2:
				consulta(); //Chamada de funções
			break;
			
			case 3:
				deletar(); //Chamada de funções
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default:
				printf ("Essa opção não está disponível!\n"); //Aviso ao cliente caso selecione uma opção inexistente
				system("pause"); //Pausa o sistema
		} //Fim da escolha do usuário
	
	
		printf("\nEsse Softare é de livre uso dos alunos\n");
	}
}
