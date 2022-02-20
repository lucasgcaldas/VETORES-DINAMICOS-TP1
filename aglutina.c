//
//  aglutina.c
//
//  Created by Lucas Gomes Caldas on 19/02/22.
//

#include "aglutina.h"

void gerarCorpusTextual(FILE *AR){
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
        
		pt = strtok(NULL,",");
        nota = *pt;
        
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
