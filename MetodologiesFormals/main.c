#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <assert.h>
#define N_MAX 10

typedef struct{
    unsigned int n; //nombre elements a la llista
    int elems[N_MAX]; //llista
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

/**
* Resum: Afegeix a la llista ‘ll’ l'element ‘e’
* Precondició: cert
* Postcondició: s'afegeix l'element ‘e’ a la llista ‘ll’ i
* no es modifica si ‘ll’ és buida o bé ‘e’ no s’ha trobat
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
* - e és del tipus enter
*/
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

/**
* Resum: Elimina l'element de la llista ‘ll’ de la posició ‘p’
* Precondició: cert
* Postcondició: ‘ll’ perd l'element de la posició ‘p’ i
* no es modifica si ‘ll’ és buida o bé ‘p’ no s’ha trobat
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
* - p és del tipus enter
*/
void eliminaP (t_llista *ll, int p){
    int i = 0; //iterador
    if((*ll).n!=0){ //si la llista no esta buida
        for (i=p; i<=N_MAX;i++){ //comencem a desplaçar des de la posicio
            (*ll).elems[i] = (*ll).elems[i+1]; //la posicio a eliminar pasa a ser la següent posicio, i aixi es va desplaçant fins el final
        }
        (*ll).n=(*ll).n-1;
    }
}

/**
* Resum: Elimina el valor de la llista ‘ll’ que té per valor ‘e’
* Precondició: cert
* Postcondició: ‘ll’ perd tots els elements que tenen per valor ‘e’ i
* no es modifica si ‘ll’ és buida o bé ‘e’ no s’ha trobat
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
* - e és del tipus enter
*/
void eliminaV (t_llista *ll, int e){
    int i = 0, p = 0; //iterador i posicio
    bool trobat = false;
    for (i=0;(i<=N_MAX) && (!trobat);i++){ //fem una cerca del valor
        if ((*ll).elems[i] == e){
            p=i; //guardem la posicio on es troba el valor
            trobat = true;
        }
    }
    for (i=p; i<=N_MAX;i++){ //comencem a desplaçar des de la posicio
        (*ll).elems[i] = (*ll).elems[i+1]; //la posicio a eliminar pasa a ser la següent posicio, i aixi es va desplaçant fins el final
    }
    (*ll).n=(*ll).n-1;
}

/**
* Resum: Retorna el número d'elements de la llista ‘ll’
* Precondició: cert
* Postcondició: no modifica res
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
*/
int mida (t_llista ll){
    return ll.n;
}


/**
* Resum: Imprimeix per pantalla la llista ‘ll’
* Precondició: cert
* Postcondició: no modifica res
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
*/

void imprimeix(t_llista ll){
    int i;
    printf("\nElements de la llista:\n");
    for(i=0; i<ll.n; i++){
        printf("\t%i",ll.elems[i]);
    }
}

/**
* Resum: Omple la llista ‘ll’ amb elements aleatoris.
* Precondició: cert
* Postcondició: La llista ‘ll’ és plena
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
*/
void omplirRandom(t_llista *ll){
    int e,i;
    for(i=0; i<N_MAX; i++){
        e = rand()%(N_MAX*100);
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
/*Cerca dicotÃ²mica, ja que treballem amb una llista ordenada*/
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

void buida (t_llista *ll){
    (*ll).n=0; //posem el punter a la primera posicio, ignorem la resta de valors
}

/**
* Resum: Menú per a seleccionar la funció desitjada
* Precondició: cert
* Postcondició: no es modifica res
* Errors: no es defineixen
*/
int opcio(){
    int c = 0;
    while (1){ //bucle infinit
    printf ("\nQue vols fer?\n0.-Sortir\n1.-Insereix\n2.-Eliminar posicio\n3.-Eliminar valor\n4.-Buida\n5.-Mida\n6.-Suma\n7.-Convertir els valors a positius\n8.-Buscar element a la llista\n9.-Fusionar llistes\t\t->");
    c = getche();
    if (c < 48 || c > 56) printf ("\n\nOpcio incorrecta, torna-ho a intentar...");
    else break;
    }
    return (c - 48);
}

/**
* Resum: Programa principal per a cridar als diferents mètodes
* Precondició: cert
* Postcondició: no es modifica res
* Errors: no es defineixen
*/

int main()
{
    int e = 0;
    bool bolea;
    t_llista ll;
    ll.n=0;
    omplirRandom(&ll);
    imprimeix(ll);
    t_llista ll1, ll2, lld;
    ll1.n=0;
    ll2.n=0;
    lld.n=0;
    omplirRandomMig(&ll1);
    omplirRandomMig(&ll2);
    while (true)
        {
            switch (opcio())
            {
                case 1: printf("\n\nQuin valor vols inserir?");
                        scanf("%i", &e);
                        //assert(); mirar si es un int?! el c agafara el codi ascii del caracter en cas de que no ho sigui...
                        //NO CAL QUE SIGUIN BOOLEANS, S'HA DE CONTROLAR AMB ELS ASSERTS, NO AMB BOOLS
                        bolea=insereix(&ll, e); /*Prova per veure si controla l'inserciÃ³ quan la llista ja esta plena*/
                        if(bolea) printf("\nL'element s'ha inserit correctament");
                        else printf("\nLa llista ja estÃ  plena");
                        imprimeix(ll);
                        break;
                case 2: printf("\nQuina posicio vols eliminar? (Vector amb %i elements) ", ll.n);
                        scanf("%i", &e);
                        assert(e <= ll.n);
                        eliminaP(&ll, e);
                        imprimeix(ll);
                        break;
                case 3: printf("\nQuin valor vols eliminar?");
                        scanf("%i", &e);
                        int i = 0;
                        bool trobat = false;
                        if(ll.n!=0){ //si la llista no esta buida
                            for (i=0;i<=N_MAX;i++){ //fem una cerca del valor
                                if ((ll).elems[i] == e){
                                    trobat = true; //s'ha trobat el valor
                                }
                            }
                        }
                        assert(trobat == true ); //si no troba el valor no deixa seguir
                        eliminaV(&ll, e);
                        imprimeix(ll);
                        break;
                case 4: buida(&ll);break;
                case 5: printf("\nmida = %i", mida(ll));break;
                case 6: printf("\n\tSuma dels elements: %d",suma(ll));
                case 7: positiva(&ll);
                        imprimeix(ll);
                        break;
                case 8: printf("\nInsereix l'element a cercar: ");
                        scanf("%d",&e);
                        bolea=HiEs(ll, e);
                        //idem, no cal boolea, s'ha de controlar amb asserts
                        if(bolea) printf("\nL'element es troba en la llista");
                        else printf("\nL'element NO es troba en la llista");
                        break;
                case 9: bolea=fusiona(ll1, ll2, &lld);
                        if(bolea) printf("\nS'han fusionat be les llistes");
                        else printf("\nNO s'han pogut fusionar les llistes");
                        imprimeix(ll1);
                        imprimeix(ll2);
                        imprimeix(lld);
                        break;
                case 0: return 0;
        }
        printf ("\n\n");//intros
       }
    return 0;
}
