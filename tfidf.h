//
//  tfidf.h
//
//  Created by Lucas Gomes on 25/02/22.
//

#ifndef tfidf_h
#define tfidf_h

#include <stdio.h>

int checaPalavrasRepetidas(char *termos[], FILE *VocabNota, int n);

int geraDiferentesPalavras(FILE *VocabNota, FILE *SemRepeticao);

int calculaIDF(int numDocTermo, int n);

int calculaTF(int numRepet[4], int numPalavrasDoc[4], int n);

int calculaTFIDF(int TF[4], int IDF, int n);

#endif /* tfidf_h */
