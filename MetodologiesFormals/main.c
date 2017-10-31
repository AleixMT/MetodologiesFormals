#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#define N_MAX 10

typedef struct{
    unsigned int n; //nombre elements a la llista
    int elems[N_MAX]; //llista
}t_llista;

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
bool eliminaP (t_llista *ll, int p){
    int i = 0; //iterador
    if((*ll).n!=0){ //si la llista no esta buida
        for (i=p; i<=N_MAX;i++){ //comencem a desplaçar des de la posicio
            (*ll).elems[i] = (*ll).elems[i+1]; //la posicio a eliminar pasa a ser la següent posicio, i aixi es va desplaçant fins el final
        }
        (*ll).n=(*ll).n-1;
        return true;
    }
    else return false; //la llista esta buida
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
bool eliminaV (t_llista *ll, int e){
    int i = 0, p = 0; //iterador i posicio
    if((*ll).n!=0){ //si la llista no esta buida
        for (i=0;i<=N_MAX;i++){ //fem una cerca del valor
            if ((*ll).elems[i] == e){
                p=i; //guardem la posicio on es troba el valor
            }
        }
        for (i=p; i<=N_MAX;i++){ //comencem a desplaçar des de la posicio
            (*ll).elems[i] = (*ll).elems[i+1]; //la posicio a eliminar pasa a ser la següent posicio, i aixi es va desplaçant fins el final
        }
        (*ll).n=(*ll).n-1;
        return true;
    }
    else return false; //la llista esta buida
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
* Resum: Afegeix a la llista ‘ll’ l'element ‘e’
* Precondició: cert
* Postcondició: s'afegeix l'element ‘e’ a la llista ‘ll’ i
* no es modifica si ‘ll’ és buida o bé ‘e’ no s’ha trobat
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
* - e és del tipus enter
*/
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

/**
* Resum: Menú per a seleccionar la funció desitjada
* Precondició: cert
* Postcondició: no es modifica res
* Errors: no es defineixen
*/
int opcio(){
    int c = 0;
    while (1){ //bucle infinit
    printf ("\nQue vols fer?\n1.-Insereix\n2.-Eliminar posicio\n3.-Eliminar valor\n4.-Buida\n5.-Mida\n6.-Suma\n7.-Convertir els valors a positius\n8.-Buscar element a la llista\n9.-Fusionar llistes\n10.-Sortir\t\t->");
    c = getche();
    if (c < 49 || c > 56) printf ("\n\nOpcio incorrecta, torna-ho a intentar...");
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
    t_llista ll;
    ll.n=0;
    int e = 0;
    omplirRandom(&ll);
    imprimeix(ll);
    //fer amb asserts lo de comprovar els errors
   // if (eliminaP(&ll)) printf("s'ha eliminat correctament.");
    //else printf("nope.");
    while (true)
        {
            switch (opcio())
            {
                case 1: printf("\n\nQuin valor vols inserir?");
                        scanf("%i", &e);
                        insereix(&ll, e);
                        imprimeix(ll);
                        break;
                case 2: printf("\nQuina posicio vols eliminar? (Vector amb %i elements) ", (ll).n);
                        scanf("%i", &e);
                        eliminaP(&ll, e);
                        imprimeix(ll);
                        break;
                case 3: printf("\nQuin valor vols eliminar?");
                        scanf("%i", &e);
                        eliminaV(&ll, e);
                        imprimeix(ll);
                        break;
                //case 4: buida(&ll);break;
                case 5: printf("\nmida = %i", mida(ll));break;
                //case 6: suma(ll);break;
                //case 7: positiva(ll);
                //case 8: hies(ll, e);
                //case 9: fusiona(ll, ll1, ll2);
                case 10: return 0;
        }
        printf ("\n\n");//intros
        }
    return 0;
}
