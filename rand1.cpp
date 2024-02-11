#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
 
using namespace std;
 
void wypelnij(int tab[], int r) {
    srand((unsigned) time(NULL));
    for(int i = 0; i <= r; i++) {
        int ran = rand() % 25 + 1;
        tab[i] = ran;
    };
};

void wyswietl(int tab[], int r) {
    for(int i = 0; i <= r; i++) {
        cout<<tab[i]<<" ";
    };
};
 
void sort_babelkowe(int tab[], int r) {
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

void sort_wstrzasanie(int tab[], int r) {
    int i, j, k;
	for(i = 0; i < r;) {
		for(j = i+1; j < r; j++) {
			if(tab[j] < tab[j-1]) {
				swap(tab[j], tab[j-1])
            };
        };

		r--;
 
		for(k = r-1; k > i; k--) {
			if(tab[k] < tab[k-1]) {
				swap(tab[k], tab[k-1])
            };
		};

		i++;
	};
};

void sort_szybkie(int tab[], int l, int r) {
    int i = l;
    int j = r;
    int x = tab[(l + r) / 2];

    do {
        while(tab[i] < x) {
            i++;
        };
       
        while(tab[j] > x) {
            j--;
        };
       
        if(i <= j) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        };
    } while(i <= j);
   
    if(l < j) sort_szybkie(tab, l, j);
   
    if(r > i) sort_szybkie(tab, i, r);
};

void sort_wstawianie(int tab[], int r) {
    int i, j, x;
    
    for(i = 1; i <= r; i++) {
        x = tab[i];
        j = i - 1;

        while(j >= 0 && tab[j] > x) {
            tab[j + 1] = tab[j];
            j = j - 1;
        };
        
        tab[j + 1] = x;
    };
};

int wysz_liniowe(int tab[], int r, int x) {
    int index = -1;

    for(int i=0; i<=r; i++) {
        if(tab[i] == x) {
            index = i;
            break;
        };
    };

    return index;
};

int wysz_binarne(int tab[], int pocz, int kon, int x) {
    int index = -1;

    while(pocz <= kon) {
        int i = pocz +(kon - pocz) / 2;

        if(tab[i] == x) {
            index = i;
            break;
        };
        
        if(tab[i] < x) {
            pocz = i + 1;
        }
        else {
            kon = i - 1;
        };
    };

    return index;
};

int wysz_interpolacyjne(int tab[], int pocz, int kon, int x) {  
    int index = -1; 
    int koniec = kon - 1;
  
    while (pocz <= koniec && tab[pocz] <= x && x <= tab[koniec]) { 
        
        index = pocz + ((x - tab[pocz]) * (koniec - pocz)) / (tab[koniec] - tab[pocz]);
        
        if(tab[index] == x) {
            return index;
        }
        else if(tab[index] < x) {
            pocz = index + 1;
        }
        else {
            koniec = index - 1;
        };
    };
    
    return -1;
};

int wysz_skokowe(int tab[], int r, int x) {
    
    int step = sqrt(r);
    int index = 0;
    
    while(tab[min(step, r)-1] < x) {
        index = step;
        step += sqrt(r);
        
        if (index >= r){
            return -1;
        };
    };
 
    while(tab[index] < x) {
        index++;

        if(index == min(step, r)) {
            return -1;
        };
    };

    if(tab[index] == x) {
        return index;
    };
 
    return -1;
};
 
int main()
{
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