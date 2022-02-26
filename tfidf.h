//
//  tfidf.h
//
//  Created by Lucas Gomes on 25/02/22.
//

#ifndef tfidf_h
#define tfidf_h

#include <stdio.h>

int checaPalavrasRepetidas(char *termo, FILE *VocabNota);

double calculaIDF(int numDocTermo);

int contaNumPalavras(FILE *VocabNota);

double calculaTF(int numRepet, int numPalavrasDoc);

double calculaTFIDF(double TF, double IDF);

#endif /* tfidf_h */
