#include <iostream>
#include <cstdlib>
 
using namespace std;
 
void wypelnij(int r, int tab[]){
    srand((unsigned) time(NULL));
    for(int i = 0; i <= r; i++){
        int ran = rand() % 25 + 1;
        tab[i] = ran;
    } ;
};
void wyswietl(int r, int tab[]){
    for(int i = 0; i <= r; i++){
        cout<<tab[i]<<" ";
    };
};
 
void sort_babelkowe(int r, int tab[]){
    for(int i=0; i<r; i++){
        for(int j=0; j<r-i; j++)
            if(tab[j]>tab[j+1]){
                swap(tab[j],tab[j+1]);
            };
    };
};
 
int main()
{
    constexpr int rozmiar = 12;
    
    int tab[rozmiar];
    
    wypelnij(rozmiar,tab);
    wyswietl(rozmiar,tab);
    
    cout<<endl;
    
    sort_babelkowe(rozmiar,tab);
    wyswietl(rozmiar,tab);
}