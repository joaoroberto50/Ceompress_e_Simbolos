#include <stdlib.h>

struct simbolo{
    char caractere;
    int ocorrencia;
};

typedef struct no* Lista;

Lista* nova_lista();

int add_final(Lista* li, struct simbolo sb);

void imprime_lista(Lista* li, int n_char);

void dell_lista(Lista* li);

