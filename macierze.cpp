//============================================================================
// Name        : macierze.cpp
// Author      : Krzysztof
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
int globOst = 0;
int numerWierszag = 0;
int numerKolumnyg = 0;

void wypelnijWiersz (int **tab, int numerWiersza, int numerKolumny, int ostatniWyraz, bool czyOdTylu, int iloscPow, int stala){
	if(czyOdTylu == true){
		for(int i = numerKolumnyg; i >= iloscPow; i--){
				tab[numerWiersza][i] = ostatniWyraz;
				ostatniWyraz++;
				numerKolumnyg = i;
				if(numerWierszag >stala || numerKolumnyg > stala){
					break;
				}
		}
		globOst = ostatniWyraz;
	}
	else{
		for(int i = numerKolumny; i < iloscPow; i++){
			tab[numerWiersza][i] = ostatniWyraz;
			ostatniWyraz++;
			numerKolumnyg = i;
			if(numerWierszag >stala || numerKolumnyg > stala){
				break;
			}
		}
		globOst = ostatniWyraz;
	}
}
void wypelnijKolumne (int **tab, int numerWiersza, int numerKolumny, int ostatniWyraz, bool czyOdTylu, int iloscPow, int stala){
	if(czyOdTylu == true){
		for(int i = numerWierszag; i >= iloscPow; i--){
			tab[i][numerKolumny] = ostatniWyraz;
			ostatniWyraz++;
			numerWierszag = i;
			if(numerWierszag >stala || numerKolumnyg > stala){
				break;
			}
		}
		globOst = ostatniWyraz;
	}else{
		for(int i = numerWiersza; i < iloscPow; i++){
				tab[i][numerKolumny] = ostatniWyraz;
				ostatniWyraz++;
				numerWierszag = i;
				if(numerWierszag >stala || numerKolumnyg > stala){
					break;
			}
		}
		globOst = ostatniWyraz;
	}
}

void wypelnij (int **tab, int stalaGot){
	wypelnijWiersz(tab, numerWierszag, numerKolumnyg,globOst, false, stalaGot, stalaGot);
	int i = 0;
	while(globOst< (stalaGot*stalaGot)){
		numerWierszag++;
		wypelnijKolumne(tab, numerWierszag, numerKolumnyg,globOst, false, stalaGot-i, stalaGot);
		numerKolumnyg--;
		wypelnijWiersz(tab, numerWierszag, numerKolumnyg,globOst, true, i, stalaGot);
		numerWierszag--;
		wypelnijKolumne(tab, numerWierszag, numerKolumnyg,globOst, true, i+1, stalaGot);
		numerKolumnyg++;
		wypelnijWiersz(tab, numerWierszag, numerKolumnyg,globOst, false, stalaGot-i - 1, stalaGot);
		i++;
	}
}

int main(int argc, char*argv[]){
	cout<<"Please enter the width and high of the matrix"<<endl;
	int stala;
	cin>>stala;
	int **tab = new int*[stala];
	for(int i = 0; i < stala; i++){
		tab[i] = new int[10];
	}
	wypelnij(tab, stala);
	for(int i = 0; i < stala; i++){
		for(int j = 0; j < stala; j++){
			cout<<" "<<tab[i][j]<<" ";
		}
		cout<<""<<endl;
	}
	return 0;
}


