#include <iostream>
#include <cstdlib>
 
using namespace std;
 
int main()
{
    srand((unsigned) time(NULL));
    constexpr int rozmiar = 12;
    int tab[rozmiar];
    for(int i = 0; i <= rozmiar; i++){
        int random  = rand() % 25 + 1;
        tab[i] = random;
    }
}