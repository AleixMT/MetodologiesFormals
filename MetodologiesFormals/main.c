#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define N_MAX 10

typedef struct{
    unsigned int n; //nombre elements a la llista
    int elems[N_MAX]; //llista
}t_llista;

//elimina element de la llista ll que es troba en la posicio p
bool eliminaP (t_llista *ll){
    int p = 0, i = 0; //posicio
    printf("\nQuina posicio vols eliminar? ");
    scanf("%i", &p);
    printf("\np = %i\n", p);
    if((*ll).n!=0){ //si la llista no esta buida
        for (i=p; i<=N_MAX;i++){ //comencem a desplaçar des de la posicio
            (*ll).elems[p] = (*ll).elems[p+1]; //la posicio a eliminar pasa a ser la següent posicio, i aixi es va desplaçant fins el final
        }
        (*ll).n=(*ll).n-1;
        return true;
    }
    else return false; //la llista esta buida
}

void insereix(t_llista *ll, int e){
    int j,i=0;
    if((*ll).n!=0){
        while(e>(*ll).elems[i] && i<(*ll).n){
            i++;
        }
        for(j=(*ll).n; j>=i; j--){
            (*ll).elems[j+1]=(*ll).elems[j];
        }
    }
    (*ll).elems[i]=e;
    (*ll).n++;
}

void imprimeix(t_llista ll){
    int i;
    printf("\nElements de la llista:\n");
    for(i=0; i<ll.n; i++){
        printf("\t%i",ll.elems[i]);
    }
}

void omplirRandom(t_llista *ll){
    int e,i;
    for(i=0; i<N_MAX; i++){
        e = rand()%(N_MAX*100);
        insereix(&(*ll), e);
    }
}

int main()
{
    t_llista ll;
    ll.n=0;
    omplirRandom(&ll);
    //int e;
    imprimeix(ll);
    if (eliminaP(&ll)) printf("s'ha eliminat correctament.");
    else printf("nope.");
    imprimeix(ll);

    return 0;
}
