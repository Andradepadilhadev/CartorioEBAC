#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

   int registro()// função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variaveis/string
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
    //final da criação de variaveis/string
    
	printf("digitar o cpf a ser cadastrado: ");//coletando informações do usuario
	scanf("%s", cpf);//%s refere-se a string (salvar uma string)
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo eo "w" significa escrever 
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecho o arquivo
	
	file = fopen(arquivo, "a");//responsavel por abrir o arquivo,adicionar informações a um arquivo existente ou criar um novo arquivo se ele não existir, sem perder os dados anteriores.
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//responsavel por abrir o arquivo,adicionar informações a um arquivo existente ou criar um novo arquivo se ele não existir, sem perder os dados anteriores.
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//responsavel por abrir o arquivo,adicionar informações a um arquivo existente ou criar um novo arquivo se ele não existir, sem perder os dados anteriores.
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");//responsavel por abrir o arquivo,adicionar informações a um arquivo existente ou criar um novo arquivo se ele não existir, sem perder os dados anteriores.
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//responsavel por abrir o arquivo,adicionar informações a um arquivo existente ou criar um novo arquivo se ele não existir, sem perder os dados anteriores.
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");//responsavel por abrir o arquivo,adicionar informações a um arquivo existente ou criar um novo arquivo se ele não existir, sem perder os dados anteriores.
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
	

}
int consultar()//função responsavel por consultar os usuarios no sistema

{  setlocale(LC_ALL, "portuguese"); //definindo a linguagem

   char cpf[40];
   char conteudo[200];
   
   printf("digite o cpf a ser consultado!\n");//armazenando a variavel"cpf" utilizando a função "%s"
   scanf("%s",cpf);
   
   FILE *file;//cria o arquivo
   file = fopen(cpf,"r");//abre o arquivo correspondente ao cpf para leitura "R" de road (ler) a informção
   
   if(file == NULL)//se o arquivo naõ puder ser aberto exibe uma mensagem de erro
   {
   	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
   }
   
   while(fgets(conteudo, 200, file) != NULL)
   {
   	printf("\nEssas são as informações do usuario: ");
   	printf("%s", conteudo);
   	printf("\n\n");//comando utilizado para pular linhas um final
   	
   	system("pause");
   }
}
    int deletar()//função responsavel por deletar os usuarios
{
	char cpf [40];
	printf("digite o cpf do usuario a ser deletado:");
	scanf("%s",cpf);
	remove(cpf);
	FILE *file;
	file = fopen(cpf,"r");//abre o arquivo correspondente ao cpf para leitura "R" de road (ler) a informção
	if(file == NULL)
	{
	printf("usuario deletado com sucesso! \n");
	system("pause");
	}
	
}

int main() 
{
	int opcao=0; //definindo variáveis
	int laco=1;
	for(laco =1; laco ==1;)
   	{
   	   system("cls");//responsavel por linpar a tela
	
       setlocale(LC_ALL, "portuguese"); //definindo a linguagem
       
       printf("### cartório da EBAC ###\n\n"); //inicio do menu
       printf("escolha a opção desejada no menu:\n\n");  
       printf("\t1 -  registrar nomes \n\n");
       printf("\t2 -  consultar nomes \n\n");
       printf("\t3 -  deletar  nomes \n\n"); 
       printf("opcão:");//fim do menu
    
       scanf("%d", &opcao); //armazenando a escolha do usuário
    
       system("cls");//responsavel por linpar a tela
       
       
       switch(opcao)//inicio da seleção  do menu 
       
       {
       	case 1:
	    registro();// ira fazer a chamada da função registro
  	    break;
  	   
  	    case 2:
  	   	consultar();// ira fazer a chamada da função consultar
  	    break;
  	   
  	    case 3:
  	   	deletar ();// ira fazer a cahamada da função deletar
  	    break;
  	    
  	   
  	    default:
  	    printf("essa opcão não está disponivel!\n ");
  	    system("pause");
  	    break;
	   }
       


}




}
  	
  
  
    
 
    

