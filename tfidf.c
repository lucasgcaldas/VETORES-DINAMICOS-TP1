//
//  tfidf.c
//
//  Created by Lucas Gomes on 25/02/22.
//

#include "tfidf.h"

int checaPalavrasRepetidas(char *termos[], FILE *VocabNota, int n){
    int igual[5] = {0, 0, 0, 0, 0};
	char linha[100000];
	char *pt;
	int i = 0;
	
    while((fgets(linha, 100000, VocabNota) != NULL)) {
    	pt = strtok(linha, "\n");
    	for(i = 0; i < n; i++){
			if(strcmp(termos[i], pt) == 0){
				igual[i]++;
			}
		}
    }
	
	return igual;
}

int geraDiferentesPalavras(FILE *VocabNota, FILE *SemRepeticao){
	char linha[100000];
	char *pt;
	int repete = 0;
	int count = 0;
	
 	while((fgets(linha, 50, VocabNota) != NULL)) {
 		pt = strtok(linha, " ");
//		printf("pt = %s\n", pt);
//		repete = checaPalavrasRepetidas(pt, VocabNota, SemRepeticao);
		printf("repete: %d\n", repete);
//		if (repete == 0){
//			fputs(pt, SemRepeticao)
//		}
		count++;
//		pt = strtok(linha, " ");
//		printf("pt 2 = %s\n", pt);
//		fseek(VocabNota,0,SEEK_SET);
//		memset(pt, 0, 100);
	}
		
	printf("count: %d", count);
	
	fclose(VocabNota);
	fclose(SemRepeticao);
	
	return 0;
}

int calculaIDF(int numDocTermo, int n){
	int totalDoc = 5;
	float IDF = 0;
	
	IDF = log10(totalDoc/numDocTermo);
	
	return IDF;
}

int calculaTF(int numRepet[4], int numPalavrasDoc[4], int n){
	int i = 0;
	int TF[n];
	
	for(i = 0; i < n; i++){
		TF[i] = numRepet[i] / numPalavrasDoc[i];
	}
}

int calculaTFIDF(int TF[4], int IDF, int n){
	int i = 0;
	float tfIDF[n]; 
	for(i = 0; i < n; i++){
		tfIDF[i] = TF[i] / IDF;
		printf("%f    ", tfIDF[i]);
	}
}
