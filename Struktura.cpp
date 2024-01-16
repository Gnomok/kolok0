#include <iostream>
#include <cstring>
#include <exception>
using namespace std;
using trescTekstowa = char[500];

enum TypZadania {
	latwe = 0,
	podstawowe = 1,
	ambitne = 2,
};

enum Przedmiot {
	matematyka = 0,
	programowanie = 1,
	praceDomowe = 2,
};

struct Zadanie
{
	trescTekstowa tresc;
	int liczbaPunktow;
	TypZadania typZadania; //0 - łatwe, 1 - podstawowe, 2 - ambitne
	Przedmiot przedmiot; //0 - matematyka, 1 - programowanie, 2 - prace domowe\

	void wypel(){
		cin.ignore();
		cout << "Zapolni tres \n";
		cin.getline(tresc, sizeof(tresc));
		cout << "Punkty szybko \n";
		cin >> liczbaPunktow;
		cout << "Jakie typ zadania szybko \n";
		int a;
		cin >> a;
		switch (a)
		{
		case 0:
			typZadania = latwe;
			break;
		
		case 1:
			typZadania = podstawowe;
			break;

		case 2:
			typZadania = ambitne;
			break;
		}
		cout << "Jaki przedmmiot szybko\n";
		cin >> a;
		switch (a)
		{
		case 0:
			przedmiot = matematyka;
			break;
		
		case 1:
			przedmiot = programowanie;
			break;

		case 2:
			przedmiot = praceDomowe;
			break;
		}
	}
	void wypis(){
		cout << "tresc to:" << tresc << endl;
		cout << "punkty to:" << liczbaPunktow << endl;

		cout << "typ zadania to:" << endl;
		switch (typZadania)
		{
		case 0:
			cout << "latwe\n";
			break;
		case 1:
			cout << "podstawowe\n";
			break;
		case 2:
			cout << "ambitne\n";
			break;
		
		}
		cout << "Przedmiot to:" << endl;

		switch (przedmiot)
		{
		case 0:
			cout << "matematyka\n";
			break;
		case 1:
			cout << "programowanie\n";
			break;
		case 2:
			cout << "zadanie domowe\n";
			break;
		
		}

	}
};





 TypZadania zadaniaONajdluzszejTresci(Zadanie* tablica, Przedmiot przedmiot, size_t length)
 // Funkcja przyjmuje tablice zadan i przedmiot 
 // Ma wyznaczyć jakiego typu jest zadnie z tego przedmiotu,
 // które ma najdluzsza tresc
 // UWAGA: funkcja zawiera bledy czasu kompilacji i czasu wykonania
 {
 	TypZadania typZadania; 
 	int maxDlugosc = 0;
 	for (size_t i = 0; i < length; i++)
 	{
 		if (tablica[i].przedmiot == przedmiot)
 		{
 			if(sizeof(tablica[i].tresc) > maxDlugosc);
 			{
 				maxDlugosc = sizeof(tablica[i].tresc);
 				typZadania = tablica[i].typZadania;
				
 			}
 		}
 	}
	if(maxDlugosc==0){throw domain_error("sasat");};
	return typZadania;
 }
void test1(){
	try {size_t length = 7;
	 Zadanie zadania[] = {
	 	{"Oblicz srednia", 2, latwe, matematyka},
	 	{"Znajdz x w rownaniu", 5, podstawowe, matematyka},
	 	{"Pokoloruj drwala... proceduralnie", 30, ambitne, programowanie},
	 	{"Oblicz całke", 10, podstawowe, matematyka},
	 	{"Wynies smieci", 1, latwe, praceDomowe},
		{"Kup flaszke dla profesora", 10, ambitne, matematyka},
		{"Napisz program komputerowy", 20, ambitne, programowanie}
		};
		if(zadaniaONajdluzszejTresci(zadania, matematyka, length) == latwe){
			cout<<"CORRECT\n";
		}
		else{
			cout<<"NOT CORRECT\n";
		}}
		catch(...){
			cout << "ERROR";
		}
	}
void test2(){
	try {size_t length = 7;
	 Zadanie zadania[] = {
	 	{"Oblicz srednia", 2, latwe, matematyka},
	 	{"Znajdz x w rownaniu", 5, podstawowe, matematyka},
	 	{"Pokoloruj drwala... proceduralnie", 30, ambitne, programowanie},
	 	{"Oblicz całke", 10, podstawowe, matematyka},
	 	{"Wynies smieci", 1, latwe, praceDomowe},
		{"Kup flaszke dla profesora", 10, ambitne, matematyka},
		{"Napisz program komputerowy", 20, ambitne, programowanie}
		};
		zadaniaONajdluzszejTresci(zadania, praceDomowe, length);}
		catch(domain_error){
			cout<<"CORRECT\n";
		}
		catch(...){
			cout << "ERROR";
		}
		cout<<"NOT CORRECT";
}
int main()
{
	// Zadanie zadania[] = {
	// 	{"Oblicz srednia", 2, 0, 0},
	// 	{"Znajdz x w rownaniu", 5, 1, 0},
	// 	{"Pokoloruj drwala... proceduralnie", 30, 2, 1},
	// 	{"Oblicz całke", 10, 1, 0},
	// 	{"Wynies smieci", 1, 0, 2},
	// 	{"Kup flaszke dla profesora", 10, 2, 0},
	// 	{"Napisz program komputerowy", 20, 2, 1}
	// };

	// cout << zadaniaONajdluzszejTresci(zadania, 1) << endl;
Zadanie zadanie;
	// zadanie.wypel();
	// zadanie.wypis();

	test1();
	test2();
	

}

