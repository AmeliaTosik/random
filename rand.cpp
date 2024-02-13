#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include "rand.hpp"

using namespace std;

int main() {
    constexpr int rozmiar = 12;
    int tab[rozmiar];
    
    wypelnij(tab, rozmiar);
    wyswietl(tab, rozmiar);
    cout<<endl;
    sort_babelkowe(tab, rozmiar);
    wyswietl(tab, rozmiar);

    cout<<endl;

    wypelnij(tab, rozmiar);
    wyswietl(tab, rozmiar);
    cout<<endl;
    sort_scalanie(tab, 0, rozmiar);
    wyswietl(tab, rozmiar);

    cout<<endl;

    wypelnij(tab, rozmiar);
    wyswietl(tab, rozmiar);
    cout<<endl;
    sort_wstrzasanie(tab, 0, rozmiar);
    wyswietl(tab, rozmiar);
    
    cout<<endl;

    wypelnij(tab, rozmiar);
    wyswietl(tab, rozmiar);
    cout<<endl;
    sort_szybkie(tab, 0, rozmiar);
    wyswietl(tab, rozmiar);

    cout<<endl;

    wypelnij(tab, rozmiar);
    wyswietl(tab, rozmiar);
    cout<<endl;
    sort_wstawianie(tab, 0, rozmiar);
    wyswietl(tab, rozmiar);



    int liczba1 = 10;
    int liczba2 = 15;
    
    int tab2[rozmiar] = {1, 4, 8, 9, 10, 13, 14, 17, 19, 20, 23, 24};
    
    cout<<wysz_liniowe(tab2, rozmiar, liczba1);
    cout<<wysz_liniowe(tab2, rozmiar, liczba2);

    cout<<wysz_binarne(tab2, 0, rozmiar, liczba1);
    cout<<wysz_binarne(tab2, 0, rozmiar, liczba2);

    cout<<wysz_interpolacyjne(tab2, 0, rozmiar, liczba1);
    cout<<wysz_interpolacyjne(tab2, 0, rozmiar, liczba2);

    cout<<wysz_skokowe(tab2, rozmiar, liczba1);
    cout<<wysz_skokowe(tab2, rozmiar, liczba2);
};