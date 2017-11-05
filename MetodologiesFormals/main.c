/**Pràctica Medodologies de Programaciṕ
***Metodologies formals
***
***Aleix Mariné Tena
***Cristina Izquierdo Lozano
***Cristòfol Daudén Esmel
**/

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

/**
* Resum: reordena els elements de la llista ‘ll’
* Precondició: cert
* Postcondició: els elements de la llista estan ordenats
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
*/
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
void insereix(t_llista *ll, int e){
    int j,i=0;
    if((*ll).n<N_MAX){  //comprovem que el vector no estigui ple
        if((*ll).n!=0){ //si la llista està buida inserim l'element directament
            while(e>(*ll).elems[i] && i<(*ll).n){   //busquem la posició on va l'element
                i++;
            }
            for(j=(*ll).n; j>=i; j--){  //desplacem tots els elements de darrere de la posició on inserim
                (*ll).elems[j+1]=(*ll).elems[j];
            }
        }
        (*ll).elems[i]=e;   //inserim l'element
        (*ll).n++;  //augmentem el nombre d'elements en la llista
    }
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
    for(i=0; i<ll.n; i++){  //recorrem i imprimim tots els elements de la llista
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
    for(i=0; i<N_MAX; i++){ //recorrem totes les posicions de la llista
        e = rand()%(N_MAX*100);
        insereix(&(*ll), e);    //afegim un valor aleatori
    }
}

/**
* Resum: Omple la llista ‘ll’ amb elements aleatoris, fins a la meitat de la seva capacitat.
* Precondició: cert
* Postcondició: La llista ‘ll’ és plena
* Errors: no es defineixen
* Paràmetres:
* - ll és del tipus t_llista
*/
void omplirRandomMig(t_llista *ll){
    int e,i;
    for(i=0; i<N_MAX/2; i++){   //omplim la llista fins la meitat de la seva capacitat
        e = -rand()%(N_MAX*100);    //creem valors aleatòris negatius
        insereix(&(*ll), e);
    }
}

/**
* Resum: retorna cert si dins la llista ‘ll’ hi ha l’element ‘e’
* Precondició: fals
* Postcondició: fals si no el troba, cert si el troba
* Errors: no es defineixen
* Paràmetres:
* - ll, var
*/
bool HiEs(t_llista ll, int var){ //Algorisme de cerca dicotòmica per buscar un element
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

/**
* Resum: retorna la suma dels elements de la llista ‘ll’
* Precondició: cert
* Postcondició: suma de tots els elements de ‘ll’
* Errors: no es defineixen
* Paràmetres:
* - ll
*/
int suma(t_llista ll){
    int suma=0;
    int i;
    for(i=0; i<ll.n; i++){
        suma+=ll.elems[i];
    }
    return suma;
}

/**
* Resum: converteix a positius tots els elements de la llista ‘ll’
* Precondició: cert
* Postcondició: els elements negatius de ‘ll’ passen a positius i es reordena la llista
* Errors: no es defineixen
* Paràmetres:
* - ll
*/
void positiva(t_llista *ll){
    int i;
    for(i=0; i<(*ll).n;i++){
        if((*ll).elems[i]<0){
            (*ll).elems[i]=(*ll).elems[i]*(-1); //fem el mòdul dels elemts de la lista
        }
    }
    //reordenem la llista
    insercio(&(*ll));
}

/**
* Resum: Fusiona dues llistes sobre una llista destí
* Precondició: cert
* Postcondició: ‘lld’ conté els elements de les llistes origen, mantenint l’ordre
* Errors: la suma del nombre d’elements de les dues llistes supera N_MAX
* Paràmetres:
* - lld, ll1, ll2 són del tipus llista
*/
bool fusiona(t_llista ll1, t_llista ll2, t_llista *lld){
    //comprovem si caben els elemnts de les dos llistes en la tercera, sinó acaba la funció
    if((ll1.n+ll2.n)>N_MAX) return false;
    int i,j,k;
    int elem1, elem2;
    bool fi_ll1;
    bool fi_ll2;
    i=0;
    j=0;
    k=0;

    //comprovem si alguna de les llistes esta buida
    if(ll1.n>0){
        fi_ll1=false;
        elem1=ll1.elems[i];
    }
    if(ll2.n>0){
        fi_ll2=false;
        elem2=ll2.elems[j];
    }

    while(!fi_ll1 || !fi_ll2){
        if(!fi_ll1 && !fi_ll2){ //si hi ha elements en les dos llistes hem de mirar quin té l'element més petit
            if(elem1>elem2){    //cas en que l'element de la llista 2 és més petit
                (*lld).elems[k]=elem2;
                j++;
                if(j>=ll2.n){
                    fi_ll2=true;
                }
                else{
                    elem2=ll2.elems[j];
                }
            }
            else{   //cas en que l'element de la llista 1 és més petit
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
                if(!fi_ll1){    //si la llista 2 està buida, anem inserient els elements de la llista 1 de forma ordenada
                    (*lld).elems[k]=elem1;
                    i++;
                    if(i>=ll1.n){
                        fi_ll1=true;
                    }
                    else{
                        elem1=ll1.elems[i];
                    }
                }
                else{   //si la llista 1 està buida, anem inserient els elements de la llista 2 de forma ordenada
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
        (*lld).n++; //augmentem en 1 els elements en la nova llista
    }
    return true;
}

/**
* Resum: buida la llista ll
* Precondició: cert
* Postcondició: numero d'elements de la llista es 0
* Errors: no es defineixen
* Paràmetres:
* - ll
*/
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
    if (c < 48 || c > 57) printf ("\n\nOpcio incorrecta, torna-ho a intentar...");
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
                        assert(ll.n<N_MAX); //assert si la llista està plena
                        insereix(&ll, e);
                        imprimeix(ll);
                        break;
                case 2: printf("\nQuina posicio vols eliminar? (Vector amb %i elements) ", ll.n);
                        scanf("%i", &e);
                        assert(e <= ll.n); //assert si es major del nombre d'elements
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
                case 4: buida(&ll);break; //assert a si la llista ja es buida? ja te el treball fet, pa que mas?
                case 5: assert(ll.n>0);
                        printf("\nmida = %i", mida(ll));break; //assert si esta buida? la mida sera 0, ja es correcte
                case 6: assert(ll.n>0);
                        printf("\n\tSuma dels elements: %d",suma(ll)); //si esta buida no podem sumar els elements, pero igual, la suma seria 0?
                case 7: assert(ll.n>0); //assert si esta buida
                        positiva(&ll);
                        imprimeix(ll);
                        break;
                case 8: printf("\nInsereix l'element a cercar: ");
                        scanf("%d",&e);
                        bolea=HiEs(ll, e); //quin assert podriem posar aqui?
                        if(bolea) printf("\nL'element es troba en la llista");
                        else printf("\nL'element NO es troba en la llista");
                        break;
                case 9: assert(fusiona(ll1, ll2, &lld));
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
