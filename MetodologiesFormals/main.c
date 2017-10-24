#include <stdio.h>
#include <stdlib.h>
#define N_MAX 10

typedef struct{
    unsigned int n;
    int elems[N_MAX];
}t_llista;

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
    imprimeix(ll);
    return 0;
}
