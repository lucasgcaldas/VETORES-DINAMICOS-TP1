#include <stdio.h>
#include "BibArquivos.h" // Biblioteca para manipular arquivos do prof Nilton
#include <stdlib.h> //Necessario para free()

int menu(){
	FILE *AR = NULL;
    
	char opcao = 0; 
	char NomeArq[30] = "";
	
	while(opcao != 5){
        
		printf("\n################## MENU ##################");
        printf("\n");
        printf("\n1 - Ler o dataset do Trip Adivisor");
        printf("\n2 - Gerar vocabulario");
        printf("\n3 - Exibir TF-IDFs");
        printf("\n4 - Exibir TF-IDF de uma Nota");
        printf("\n5 - Sair");
        printf("\nNumero da opcao: ");
        
		scanf("\n%c", &opcao);
        
		switch (opcao) {
        	case '1':
        		printf("Arquivo de Referencia: ");
                scanf("%s",NomeArq); // digite: Arquivos/doc.csv
                if(AR != NULL)
                    fclose(AR);
                AR = Arquivo_AbreLeitura(NomeArq);
                if(AR == NULL){
                    printf("Erro 1: Arquivo de Referencia nao pode ser aberto\n");
                }
                else {
                    printf("\n%s aberto!!!\n", NomeArq);
                	gerarCorpusTextual(AR);
				}
			    
                break;
			case '2':
				printf("Caso %c\n", opcao);
				break;
			case '3':
				printf("Caso %c\n", opcao);
				break;
			case '4':
				printf("Caso %c\n", opcao);
				break;
			case '5':	
				printf("Caso %c\n", opcao);
        		break;
        	default:
        		printf("\nOpcao invalida, tente novamente!\n");
        		menu();
        }
        if(opcao == '5'){
    		break;
		}
	}
}

int gerarCorpusTextual(FILE *AR){
	FILE *Nota1 = NULL;
    FILE *Nota2 = NULL;
    FILE *Nota3 = NULL;
    FILE *Nota4 = NULL;
    FILE *Nota5 = NULL;
    
    // Criar e abrir aquivos
    Nota1 = fopen("Arquivos/Nota1.txt","w");
    Nota2 = fopen("Arquivos/Nota2.txt","w");
    Nota3 = fopen("Arquivos/Nota3.txt","w");
    Nota4 = fopen("Arquivos/Nota4.txt","w");
    Nota5 = fopen("Arquivos/Nota5.txt","w");

	char linha[100000];
	char *pt;
	char frase;
	char nota;
	
	// Pula o cabecalho.
    fseek(AR,14,SEEK_SET); 
    
     while((fgets(linha, 100000, AR) != NULL)) {
      
        pt = strtok(linha,"\"");
        frase = *pt;
//		printf("Frase: %c\n", frase);
        
		pt = strtok(NULL,",");
        nota = *pt;
//        printf("nota: %c\n", nota);
        
        if (nota == '1') {
        	
        	fputs(linha, Nota1);
        	fputs("\n", Nota1);
        	
		} else if(nota == '2') {

        	fputs(linha, Nota2);
        	fputs("\n", Nota2);
        	
    	}else if(nota == '3') {
    		
        	fputs(linha, Nota3);
        	fputs("\n", Nota3);
        	
    	}else if(nota == '4') {
    		
        	fputs(linha, Nota4);
        	fputs("\n", Nota4);
        	
    	}else {
    		
        	fputs(linha, Nota5);
        	fputs("\n", Nota5);
    	}
    }

	fclose(AR);
    fclose(Nota1);
    fclose(Nota2);
    fclose(Nota3);
    fclose(Nota4);
    fclose(Nota5);
}	

int main(int argc, const char * argv[]) {
	
	menu();

	printf("\n\n ----- Sistema Encerrado ----- \n\n");
	
	return 0;
}	
