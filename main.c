#include <stdio.h>
#include "BibArquivos.h" // Biblioteca para manipular arquivos do prof Nilton
#include "aglutina.h" // Biblioteca para aglutinar as notas
#include "geraVocab.h" // Biblioteca para gerar vocabulario
#include "tfidf.h" // Biblioteca auxiliar para o calculo do TF-IDF
#include <stdlib.h> //Necessario para free()
#include <string.h>
#include <math.h>//Necessaria para usar as funcoes matematicas

//-------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------- UNIVERSIDADE DE BRASILIA - CAMPUS FGA -------------------------------------------//
//                                                   estrutura de dados e algoritmos                                             //
// GRUPO 2:
// Arthur D'Assumpção - 190084570
// Lucas Gomes Caldas - 212005426         
//-------------------------------------------------------------------------------------------------------------------------------//


void menu(){
	FILE *AR = NULL;
	FILE *Nota1 = NULL;
    FILE *Nota2 = NULL;
    FILE *Nota3 = NULL;
    FILE *Nota4 = NULL;
    FILE *Nota5 = NULL;
    FILE *VocabNota1 = NULL;
    FILE *VocabNota2 = NULL;
    FILE *VocabNota3 = NULL;
    FILE *VocabNota4 = NULL;
    FILE *VocabNota5 = NULL;
    FILE *SemRepticao1 = NULL;
    FILE *SemRepticao2 = NULL;
    FILE *SemRepticao3 = NULL;
    FILE *SemRepticao4 = NULL;
    FILE *SemRepticao5 = NULL;
	char opcao = 0; 
	char NomeArq[30] = "";
	int n = 0;
	char *termos[100];	
	int numRepet[4] = {0, 0, 0, 0};
	int numPalavrasDoc[4] = {0, 0, 0, 0};
	int numDocTermo = 0; // num de doc com o respectivo termo
	float IDF = 0.0;
	float TF= 0.0;
	float tfIDF[4] = {0.0, 0.0, 0.0, 0.0};
	
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
                	printf("Os 5 arquivos de notas foram criados!!!\n");
				}
                break;
			case '2':	
			    
			    // Abrir e ler aquivos
			    Nota1 = fopen("Arquivos/Nota1.txt","r");
			    Nota2 = fopen("Arquivos/Nota2.txt","r");
			    Nota3 = fopen("Arquivos/Nota3.txt","r");
			    Nota4 = fopen("Arquivos/Nota4.txt","r");
			    Nota5 = fopen("Arquivos/Nota5.txt","r");
				
				// Criar e abrir aquivos
			    VocabNota1 = fopen("Arquivos/VocabularioNota1.txt","w");
			    VocabNota2 = fopen("Arquivos/VocabularioNota2.txt","w");
			    VocabNota3 = fopen("Arquivos/VocabularioNota3.txt","w");
			    VocabNota4 = fopen("Arquivos/VocabularioNota4.txt","w");
			    VocabNota5 = fopen("Arquivos/VocabularioNota5.txt","w");
			    
			    // Criar e abrir aquivos
//			    SemRepticao1 = fopen("Arquivos/SemRepticao1.txt","w");
//			    SemRepticao2 = fopen("Arquivos/SemRepticao2.txt","w");
//			    SemRepticao3 = fopen("Arquivos/SemRepticao3.txt","w");
//			    SemRepticao4 = fopen("Arquivos/SemRepticao4.txt","w");
//			    SemRepticao5 = fopen("Arquivos/SemRepticao5.txt","w");
				
				gerarVocabulario(Nota1, VocabNota1);
//				VocabNota1 = fopen("Arquivos/VocabularioNota1.txt","r"); // Abrir e ler aquivos
//				geraDiferentesPalavras(VocabNota1, SemRepticao1);
				
				gerarVocabulario(Nota2, VocabNota2);
				gerarVocabulario(Nota3, VocabNota3);
				gerarVocabulario(Nota4, VocabNota4);
				gerarVocabulario(Nota5, VocabNota5);
				
				break;
				
			case '3':
				printf("Quantos termos deja exibir TF-IDF? ");
				scanf("%d", &n);	
				printf("\n");
				
				printf("Para qual(ais) termo(s) deseja calcular o TF-IDF?\n");
				int i = 0;
				for (i = 0; i < n; i++){
					printf("Termo %d = ", i + 1);
					scanf("%s", &termos[i]);
				}
		
				VocabNota1 = fopen("Arquivos/VocabularioNota1.txt","r");
			    VocabNota2 = fopen("Arquivos/VocabularioNota2.txt","r");
			    VocabNota3 = fopen("Arquivos/VocabularioNota3.txt","r");
			    VocabNota4 = fopen("Arquivos/VocabularioNota4.txt","r");
			    VocabNota5 = fopen("Arquivos/VocabularioNota5.txt","r");

				numRepet[0] = checaPalavrasRepetidas(termos, VocabNota1, n);
				printf("numRepet1: %d\n", numRepet[0]);
				numRepet[1] = checaPalavrasRepetidas(termos, VocabNota2, n);
				printf("numRepet2: %d\n", numRepet[1]);
				numRepet[2] = checaPalavrasRepetidas(termos, VocabNota3, n);
				printf("numRepet3: %d\n", numRepet[2]);
				numRepet[3] = checaPalavrasRepetidas(termos, VocabNota4, n);
				printf("numRepet4: %d\n", numRepet[3]);
				numRepet[4] = checaPalavrasRepetidas(termos, VocabNota5, n);
				printf("numRepet5: %d\n", numRepet[4]);
				
				if (numRepet[0] > 0){
					numDocTermo++;
				} if (numRepet[1] > 0){
					numDocTermo++;
				} if (numRepet[2] > 0){
					numDocTermo++;
				} if (numRepet[3] > 0){
					numDocTermo++;
				} if (numRepet[4] > 0){
					numDocTermo++;
				} 
				
				printf("numDocPalavra: %d\n", numDocTermo);
				
				fclose(VocabNota1);
				fclose(VocabNota2);
				fclose(VocabNota3);
				fclose(VocabNota4);
				fclose(VocabNota5);	
				
				IDF = calculaIDF(numDocTermo, n);
//				printf("IDE = %f\n", calculaIDF(numDocPalavra));

				TF = calculaTF(numRepet, numPalavrasDoc, n);
								
				printf("VOCABULARIO  NOTA1  NOTA2  NOTA3  NOTA4  NOTA5");		
//				calculaTFIDF();
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
