#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {  // functie de comparare
   return ( *(int*)a - *(int*)b );
}
/*
Am incercat sa pun in 2 sume numerele din array-ul 'a' astfel incat cele 2 medii din sume sa fie echilibrate si apropiate
Daca media din prima suma e mai mare, atunci clar ca ii vom aduga un numar mai mic pentru a-i scadea valoarea astfel incat sa fie apropiata de cealalata medie mai mica.
Pentru a face asta, am luat un array pe care l-am ordonat crescator si il parcurg descrescator atfel incat pe primele pozitii sa fie numerele cele mai mari.
Daca la final nu avem aceeasi medie, atunci e fals, in caz afirmativ, true
*/

int main()
{

    int a[] = {1,2,3,4,5,6,7,8};
    int n=8;

    qsort(a, 5, sizeof(int), cmpfunc); // sortare

    float suma1=a[n-1],contor1=1,suma2=a[n-2],contor2=1; // cele 2 sume + contoarele ( pentru cele 2 arrayuri

    for(int i=n-3;i>=0;i--)
    {
        if(contor1==contor2 && contor1==1) //  daca am cazul special de egalitate la inceput, vom pune in suma 2
        {
            suma2+=a[i];
            contor2++;
        }
        else if(suma1/contor1>=suma2/contor2) //  daca avem suma1 mai mare, atunci ii vom aduga un numar mai mic pentru a o scadea
        {
            suma1+=a[i];
            contor1++;
        }
        else if(suma1/contor1<suma2/contor2) // acelasi procedeu dar pentru caz invers
        {
            suma2+=a[i];
            contor2++;
        }
    }
    if(suma1/contor1==suma2/contor2 ) // daca la final avem media egala, avem true
        printf("True");
    else printf("False");

    return 0;
}
