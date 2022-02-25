//
//  geraVocab.c
//
//  Created by Arthur D'Assumpção on 25/02/22.
//

#include "geraVocab.h"

int gerarVocabulario(FILE *Nota, FILE *VocabNota){
	
	char linha[100000];
	char *pt;
    
    while((fgets(linha, 100000, Nota) != NULL)) {
		pt = strtok(linha," ,.!\"");
		while(pt){
			if (strlen(pt) > 3){
    			fputs(pt, VocabNota);
    			fputs("\n", VocabNota);
			}
		  pt = strtok(NULL," ,.!\"");
		}	
    }

	fclose(Nota);
    fclose(VocabNota);
    
    return 0;
}
