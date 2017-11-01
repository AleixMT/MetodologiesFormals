#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N_MAX 10

typedef struct{
    unsigned int n;
    int elems[N_MAX];
}t_llista;

void insercio(t_llista *ll)
{
    int i, j, temp;
    for (i = 1; i < (*ll).n; i++)
    {
        temp = (*ll).elems[i];
        j = i - 1;
        while ((*ll).elems[j] > temp && j >= 0)
        {
            (*ll).elems[j+1] = (*ll).elems[j];
            j--;
        }
        (*ll).elems[j+1] = temp;
    }
}

bool insereix(t_llista *ll, int e){
    int j,i=0;
    bool inserit=true;
    if((*ll).n<N_MAX){
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
    else{
        inserit=false;
    }
    return inserit;
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
        e = -rand()%(N_MAX*100);
        insereix(&(*ll), e);
    }
}

void omplirRandomMig(t_llista *ll){
    int e,i;
    for(i=0; i<N_MAX/2; i++){
        e = -rand()%(N_MAX*100);
        insereix(&(*ll), e);
    }
}
/*Cerca dicotòmica, ja que treballem amb una llista ordenada*/
bool HiEs(t_llista ll, int var){
    int inf=0;
    int sup=ll.n-1;
    int cent;
    bool trobat=false;

    while(inf<=sup && !trobat){
        cent=(sup-inf)/2+inf;
        if(ll.elems[cent]==var){
            trobat=true;
        }
        else{
            if(ll.elems[cent]>var){
                sup=cent-1;
            }
            else inf = cent+1;
        }
    }
    return trobat;
}

int suma(t_llista ll){
    int suma=0;
    int i;
    for(i=0; i<ll.n; i++){
        suma+=ll.elems[i];
    }
    return suma;
}

void positiva(t_llista *ll){
    int i;
    for(i=0; i<(*ll).n;i++){
        if((*ll).elems[i]<0){
            (*ll).elems[i]=(*ll).elems[i]*(-1);
        }
    }
    //reordenem la llista
    insercio(&(*ll));
}

bool fusiona(t_llista ll1, t_llista ll2, t_llista *lld){
    if((ll1.n+ll2.n)>N_MAX) return false;
    int i,j,k;
    int elem1, elem2;
    bool fi_ll1;
    bool fi_ll2;
    i=0;
    j=0;
    k=0;

    if(ll1.n>0){
        fi_ll1=false;
        elem1=ll1.elems[i];
    }
    if(ll2.n>0){
        fi_ll2=false;
        elem2=ll2.elems[j];
    }

    while(!fi_ll1 || !fi_ll2){
        if(!fi_ll1 && !fi_ll2){
            if(elem1>elem2){
                (*lld).elems[k]=elem2;
                j++;
                if(j>=ll2.n){
                    fi_ll2=true;
                }
                else{
                    elem2=ll2.elems[j];
                }
            }
            else{
                (*lld).elems[k]=elem1;
                i++;
                if(i>=ll1.n){
                    fi_ll1=true;
                }
                else{
                    elem1=ll1.elems[i];
                }
            }
        }
        else{
                if(!fi_ll1){
                    (*lld).elems[k]=elem1;
                    i++;
                    if(i>=ll1.n){
                        fi_ll1=true;
                    }
                    else{
                        elem1=ll1.elems[i];
                    }
                }
                else{
                    (*lld).elems[k]=elem2;
                    j++;
                    if(j>=ll2.n){
                        fi_ll2=true;
                    }
                    else{
                        elem2=ll2.elems[j];
                    }
                }
        }
        k++;
        (*lld).n++;
    }
    return true;
}

int main()
{
    t_llista ll;
    ll.n=0;
    bool bolea;
    int elem;

    omplirRandom(&ll);
    bolea=insereix(&ll, 1); /*Prova per veure si controla l'inserció quan la llista ja esta plena*/
    if(bolea) printf("\nL'element s'ha inserit correctament");
    else printf("\nLa llista ja està plena");
    imprimeix(ll);
    positiva(&ll);
    imprimeix(ll);
    printf("\nInsereix l'element a cercar: ");
    scanf("%d",&elem);
    bolea=HiEs(ll, elem);
    if(bolea) printf("\nL'element es troba en la llista");
    else printf("\nL'element NO es troba en la llista");
    printf("\n\tSuma dels elements: %d",suma(ll));

    t_llista ll1, ll2, lld;
    ll1.n=0;
    ll2.n=0;
    lld.n=0;
    omplirRandomMig(&ll1);
    omplirRandomMig(&ll2);
    imprimeix(ll1);
    imprimeix(ll2);
    bolea=fusiona(ll1, ll2, &lld);
    if(bolea) printf("\nS'han fusionat bé les llistes");
    else printf("\nNO s'han pogut fusionar les llistes");
    imprimeix(lld);
    positiva(&lld);
    imprimeix(lld);
    bolea=fusiona(ll, ll2, &lld);
    if(bolea) printf("\nS'han fusionat bé les llistes");
    else printf("\nNO s'han pogut fusionar les llistes");
    return 0;
}
