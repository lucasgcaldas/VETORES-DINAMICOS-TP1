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
//                                         Estrutura de Dados e Algoritmos - Prof. Nilton                                        //
// GRUPO 2:                                                                                                                      //
// Arthur D'Assumpção - 190084570                                                                                                // 
// Lucas Gomes Caldas - 212005426                                                                                                //
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
	char opcao = 0; 
	char NomeArq[30] = "";
	char termo[15];	
	int numRepet[5] = {0, 0, 0, 0, 0};
	int numPalavrasDoc[5] = {0, 0, 0, 0, 0};
	int numDocTermo = 0; // num de doc com o respectivo termo
	double IDF = 0.0;
	double TF[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
	double tfIDF[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
	char nota;
	FILE *ArqNota = NULL;
	
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
			    
				// Gera vocabulario
				gerarVocabulario(Nota1, VocabNota1);
				gerarVocabulario(Nota2, VocabNota2);
				gerarVocabulario(Nota3, VocabNota3);
				gerarVocabulario(Nota4, VocabNota4);
				gerarVocabulario(Nota5, VocabNota5);
				
				break;
				
			case '3':				
				printf("Para qual termo deseja calcular o TF-IDF?\n");
				scanf("%s", &termo);
				printf("\n");
		
				VocabNota1 = fopen("Arquivos/VocabularioNota1.txt","r");
			    VocabNota2 = fopen("Arquivos/VocabularioNota2.txt","r");
			    VocabNota3 = fopen("Arquivos/VocabularioNota3.txt","r");
			    VocabNota4 = fopen("Arquivos/VocabularioNota4.txt","r");
			    VocabNota5 = fopen("Arquivos/VocabularioNota5.txt","r");

				numRepet[0] = checaPalavrasRepetidas(termo, VocabNota1);
				printf("A palavra se repete no doc1: %d vezes\n", numRepet[0]);
				numRepet[1] = checaPalavrasRepetidas(termo, VocabNota2);
				printf("A palavra se repete no doc2: %d vezes\n", numRepet[1]);
				numRepet[2] = checaPalavrasRepetidas(termo, VocabNota3);
				printf("A palavra se repete no doc3: %d vezes\n", numRepet[2]);
				numRepet[3] = checaPalavrasRepetidas(termo, VocabNota4);
				printf("A palavra se repete no doc4: %d vezes\n", numRepet[3]);
				numRepet[4] = checaPalavrasRepetidas(termo, VocabNota5);
				printf("A palavra se repete no doc5: %d vezes\n", numRepet[4]);
				printf("\n");
				
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
				
				printf("Numero de documentos que contem o termo: %d\n", numDocTermo);
				printf("\n");
				
				VocabNota1 = fopen("Arquivos/VocabularioNota1.txt","r");
			    VocabNota2 = fopen("Arquivos/VocabularioNota2.txt","r");
			    VocabNota3 = fopen("Arquivos/VocabularioNota3.txt","r");
			    VocabNota4 = fopen("Arquivos/VocabularioNota4.txt","r");
			    VocabNota5 = fopen("Arquivos/VocabularioNota5.txt","r");
				
				numPalavrasDoc[0] = contaNumPalavras(VocabNota1);
				numPalavrasDoc[1] = contaNumPalavras(VocabNota2);
				numPalavrasDoc[2] = contaNumPalavras(VocabNota3);
				numPalavrasDoc[3] = contaNumPalavras(VocabNota4);
				numPalavrasDoc[4] = contaNumPalavras(VocabNota5);
				
				int i = 0;
				for(i = 0; i < 5; i++){
					printf("Numero de palavras em cada documento = %d\n", numPalavrasDoc[i]);
				}
				
				IDF = calculaIDF(numDocTermo);
				printf("\n");
				printf("IDF = %f\n", IDF);
				printf("\n");
				
				for (i = 0; i < 5; i++){
					TF[i] = calculaTF(numRepet[i], numPalavrasDoc[i]);
					printf("TF %d = %f\n", i, TF[i]);
				}
				
				for (i = 0; i < 5; i++){
					tfIDF[i] = calculaTFIDF(TF[i], IDF);
				}	
					
				printf("\n");
				printf("VOCABULARIO | NOTA1 | NOTA2 | NOTA3 | NOTA4 | NOTA5\n");	
				printf("%s  |  ", termo);
				for (i = 0; i < 5; i++){
					printf("%.4f  |  ", tfIDF[i]);
				}
				printf("\n");
						
				fclose(VocabNota1);
				fclose(VocabNota2);
				fclose(VocabNota3);
				fclose(VocabNota4);
				fclose(VocabNota5);	
				
				break;
			case '4':
				printf("Para qual nota deseja exibir o TF-IDF?\n");
				printf("(1) - Nota 1");
		        printf("\n(2) - Nota 2");
		        printf("\n(3) - Nota 3");
		        printf("\n(4) - Nota 4");
		        printf("\n(5) - Nota 5");
				printf("\n");
				scanf("\n%c", &nota);
				
				if (nota == '1'){
					ArqNota = fopen("Arquivos/VocabularioNota1.txt","r");
				} else if (nota == '2'){
					ArqNota = fopen("Arquivos/VocabularioNota2.txt","r");
				} else if (nota == '3'){
					ArqNota = fopen("Arquivos/VocabularioNota3.txt","r");
				} else if (nota == '4'){
					ArqNota = fopen("Arquivos/VocabularioNota4.txt","r");
				}else if (nota == '5'){
					ArqNota = fopen("Arquivos/VocabularioNota5.txt","r");
				} else{
					break;
				}
				
				printf("Para qual termo deseja calcular o TF-IDF?\n");
				scanf("%s", &termo);
				printf("\n");
				
				numRepet[0] = checaPalavrasRepetidas(termo, ArqNota);
				printf("A palavra se repete no doc%c: %d vezes\n", nota,numRepet[0]);
				
				if (numRepet[0] > 0){
					numDocTermo++;
				}
				
				if (nota == '1'){
					ArqNota = fopen("Arquivos/VocabularioNota1.txt","r");
				} else if (nota == '2'){
					ArqNota = fopen("Arquivos/VocabularioNota2.txt","r");
				} else if (nota == '3'){
					ArqNota = fopen("Arquivos/VocabularioNota3.txt","r");
				} else if (nota == '4'){
					ArqNota = fopen("Arquivos/VocabularioNota4.txt","r");
				}else if (nota == '5'){
					ArqNota = fopen("Arquivos/VocabularioNota5.txt","r");
				} else{
					break;
				}
				
				numPalavrasDoc[0] = contaNumPalavras(ArqNota);
				printf("Numero de palavras no documento = %d\n", numPalavrasDoc[0]);
				
				IDF = calculaIDF(numDocTermo);
				printf("\n");
				printf("IDF = %f\n", IDF);
				printf("\n");
				
				TF[0] = calculaTF(numRepet[0], numPalavrasDoc[0]);
				printf("TF %c = %f\n", nota, TF[0]);
				
				
				tfIDF[0] = calculaTFIDF(TF[0], IDF);
							
				printf("\n");
				printf("VOCABULARIO | NOTA%c\n", nota);	
				printf("%s | %.4f", termo, tfIDF[0]);
				
				printf("\n");
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
