#include <stdio.h>
#include "BibArquivos.h" // Biblioteca para manipular arquivos do prof Nilton
#include "aglutina.h" // Biblioteca para manipular arquivos do prof Nilton
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

int main(int argc, const char * argv[]) {
	
	menu();

	printf("\n\n ----- Sistema Encerrado ----- \n\n");
	
	return 0;
}	
