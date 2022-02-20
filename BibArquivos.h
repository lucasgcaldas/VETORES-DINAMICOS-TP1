//
//  BibArquivos.h
//  Arquivos
//
//  Created by Nilton Correia da Silva on 27/02/21.
//

#ifndef BibArquivos_h
#define BibArquivos_h

#include <stdio.h>

//Aberturas/criação de arquivos:
FILE *Arquivo_AbreLeitura(char *PNomeArquivo);
FILE *Arquivo_Novo(char *PNomeArquivo);


//Exibições de conteúdos de arquivos
int Arquivo_MostraConteudo(FILE *parq);
int Arquivo_ProximaPalavra(FILE *parq, char *ppalavra);


#endif /* BibArquivos_h */
