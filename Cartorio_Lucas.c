#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h>//''aloca��o de esp�o de memoria
#include <locale.h>//texto por regiao
#include <string.h>//responsavel por cuidar da string

int registro()//Fun��o responsavelpor registrar os usuarios.
{
	//inicio cria��o de v�riaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o cpf a ser cadastrado:\n");//coletando informa��es dos usuarios
	scanf("%s",cpf);//%s serve para salvar as string
	
	strcpy(arquivo,cpf);//copiar os valores
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo,"w");//abre o arquivo 
	fprintf(file,cpf);//salva o valor no arquivo
	fclose(file);//fecha o arquivo
	
		file = fopen(arquivo,"a");//abre o aruivo e atualiza oque esta nele
		fprintf(file,",");
		fclose(file);
				
	printf("digite o nome a ser cadastrado:\n");
	scanf("%s",nome);
					
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
			
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
				
	printf("digite o sobrenome a ser cadastrado:\n");
	scanf("%s",sobrenome);
					
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
			
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
			
	printf("digite o cargo a ser cadastrado:\n");
	scanf("%s",cargo);
					
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
			
	system("pause");
			
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");//defindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
			
}

int deletar()
{
 	char cpf[40];
 	
 	printf("digite o cpf a ser deletado: ");
 	scanf("%s",cpf);
 	
 	remove(cpf);
 	
 	
 	FILE *file;
 	file = fopen(cpf,"r");
 	
 	if(file == NULL);
	{
		printf("o usuario n�o se encontra no sistema e foi deletado!\n");
		system("pause");
		
	} 	
 	
}


int main()
{
	int opcao=0;//definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
	    
	     system("cls");
	    
	    setlocale(LC_ALL,"Portuguese");//defindo linguagem
	
	    printf("###C�rtorio Da Ebac###\n\n");//incio do menu
	    printf("escolha a op��o desejada no menu:\n\n");
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-Consultar nomes\n");
	    printf("\t3-Deletar nomes\n\n");
	    printf("Op��o:");//final do menu
	
    	scanf("%d",&opcao);//armazenamendo escolha do usuario
	
	    system("cls");//sistema
	    
	    
	    switch(opcao)//opcao mais rapida e eficaz
	    {   
		    case 1://chamando as fun��es
	    	registro();
		    break;
		    
		    case 2:
		    consulta();
            break;
           	
           	case 3:
            deletar();
		    break;
		    	
		    default:
			 printf("Essa op��o n�o �sta disponivel\n");
		    system("pause");
		   	break;
		}
    }
}
