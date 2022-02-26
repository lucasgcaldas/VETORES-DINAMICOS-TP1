//
//  tfidf.c
//
//  Created by Lucas Gomes on 25/02/22.
//

#include "tfidf.h"

int checaPalavrasRepetidas(char *termo, FILE *VocabNota){
    int igual = 0;
	char linha[100000];
	char *pt;
	int i = 0;
	
    while((fgets(linha, 100000, VocabNota) != NULL)) {
    	pt = strtok(linha, "\n");
    	
		if(strcmp(termo, pt) == 0){
			igual++;
		}
    }
	
	return igual;
}

double calculaIDF(int numDocTermo){
	int totalDoc = 5;
	float IDF = 0;
	
	IDF = log10(totalDoc/numDocTermo);
	
	return IDF;
}

int contaNumPalavras(FILE *VocabNota){
	char linha[100000];
	char *pt;
	int count = 0;
	
	while((fgets(linha, 50, VocabNota) != NULL)) {
		pt = strtok(linha, "");
 		count++;
 	}
 	
 	return count;
}

double calculaTF(int numRepet, int numPalavrasDoc){
	
	return 1000.0 * numRepet / numPalavrasDoc; // valor multiplicado por 1000 para nao perder a precisao
}


double calculaTFIDF(double TF, double IDF){

	return TF * IDF;
}
