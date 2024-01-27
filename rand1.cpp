#include <iostream>
#include <cstdlib>
 
using namespace std;
 
void wypelnij(int r, int tab[]) {
    srand((unsigned) time(NULL));
    for(int i = 0; i <= r; i++) {
        int ran = rand() % 25 + 1;
        tab[i] = ran;
    };
};

void wyswietl(int r, int tab[]) {
    for(int i = 0; i <= r; i++) {
        cout<<tab[i]<<" ";
    };
};
 
void sort_babelkowe(int r, int tab[]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<r-i; j++) {
            if(tab[j]>tab[j+1]) {
                swap(tab[j],tab[j+1]);
            };
        };
    };
};
 
void scal(int tab[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
 
    int L[n1], M[n2];
 
    for (int i = 0; i < n1; i++) {
        L[i] = tab[p + i];
    };
    
    for (int j = 0; j < n2; j++) {
        M[j] = tab[q + 1 + j];
    };
 
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
 
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            tab[k] = L[i];
            i++;
        }
            
        else {
            tab[k] = M[j];
            j++;
        };
            
        k++;
    };
 
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    };
 
    while (j < n2) {
        tab[k] = M[j];
        j++;
        k++;
    };
};
 
void sort_scalanie(int tab[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        sort_scalanie(tab, l, m);
        sort_scalanie(tab, m + 1, r);   
        
        scal(tab, l, m, r);
    };
};
 
int main()
{
    constexpr int rozmiar = 12;
    int tab[rozmiar];
    
    wypelnij(rozmiar,tab);
    wyswietl(rozmiar,tab);
    
    cout<<endl;
    
    sort_babelkowe(rozmiar, tab);
    wyswietl(rozmiar,tab);

    cout<<endl;

    wypelnij(rozmiar,tab);
    wyswietl(rozmiar,tab);
    
    cout<<endl;
    
    sort_scalanie(tab, 0, rozmiar);
    wyswietl(rozmiar,tab);
}