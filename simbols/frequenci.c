#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "frequenci.h"

struct no
{
	struct no *ant;
	struct simbolo dados;
	struct no *prox;
};

typedef struct no No;

Lista* nova_lista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;
}

int add_final(Lista* li, struct  simbolo sb){
	if(li ==NULL) return 0;
	No *node = (No*) malloc(sizeof(No));
	if(node ==NULL) return 0;
	node->dados = sb;
	node->prox = NULL;
	node->dados.ocorrencia = 1;
	if((*li) == NULL){
		node->ant =NULL;
		*li = node;
	}else{
		No *auxi = *li;
		while(1){
			if (auxi->dados.caractere == node->dados.caractere)
			{
				auxi->dados.ocorrencia++;
				return 1;
			}
			if(auxi->prox == NULL)
				break;
			auxi = auxi->prox;
		}
		auxi->prox = node;
		node->ant = auxi;
	}
	return 1;
}

void imprime_lista(Lista* li, int n_char){
	if(li != NULL){
		No *aux = *li;
		printf("Simbolo | Freq. Abs. | Freq. Rel.| Cod. ASCII\n");
		uint8_t ascii;
		while(aux != NULL){
			ascii = aux->dados.caractere;
			printf("%c \t\t %d \t %d/%d \t\t %u\n", aux->dados.caractere, aux->dados.ocorrencia, aux->dados.ocorrencia, n_char, ascii);
			aux = aux->prox;
		}
		printf("-------------------------------------------------\n");
		printf("Total \t\t %d\n", n_char); 
	} 
}

void dell_lista(Lista* li){
	if(li != NULL){
		No* node;
		while((*li) != NULL){
			node = *li;
			*li = (*li)->prox;
			free(node);
		}
		free(li);
	}
}


int main(int argc, char const *argv[])
{
	FILE *file;
	file = fopen(argv[1], "r");
	char c[2];
	int x, cont = 0;
	
	Lista *li;
	li = nova_lista();
	struct simbolo a;

	while(fgets(c, 2, file) != NULL){
		a.caractere = c[0];
		x = add_final(li, a);
		cont++;
	}

	imprime_lista(li, cont);
	dell_lista(li);
  fclose(file);
	return 0;
}

