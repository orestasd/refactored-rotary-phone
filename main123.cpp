#include <bits/stdc++.h>
#include "LaivasZaidime.cpp"

using namespace std;

const char LANG_LAIVAS = '*';
const char LANG_SAUTA = ' ';
const char LANG_PATAIK = 'X';
const char LANG_TUSC = '0';

class LaivasPagr{
    protected:
            int ilgis, kiekis;
    public:
            LaivasPagr(int ilgis, int kiekis) : ilgis(ilgis), kiekis(kiekis){}
};

class Korvete : public LaivasPagr{
    public:
            Korvete(int ilgis, int kiekis): LaivasPagr(1, 3){}
};
class Minininkas : public LaivasPagr{
    public:
            Minininkas(int ilgis, int kiekis): LaivasPagr(2, 2){}
};
class Lektuvnesis : public LaivasPagr{
    public:
            Lektuvnesis(int ilgis, int kiekis): LaivasPagr(3, 2){}
};

class ZaidimoLenta {
    public: 
            int zaidimoLenta[10][10];


};

void spausdintiLenta(int zaidLaukas[10][10]);//this shit        Lenta su laivais
void spausdintiZaidimoLenta(int priesoLaukas[10][10]); //this  shit      Lenta be laivu
int PradetiZaidima();

int  main()
{
    
    list<LaivasPagr> laivas;

    cout<<"@@@@@@@@@Pradzios@@@@@@@@tekstas@@@@@@@@"<<endl;
    cout<<"Jeigu norite pradeti, parasykite 'pradeti': ";
    string Zaisti;
    cin >> Zaisti;
    if(Zaisti == "pradeti")
    {   
        PradetiZaidima();
    }
    else
    {
        system("CLS");
        cout<<"Ivestas netinkamas pasirinkimas, programa nutraukiama";
        exit;
    }

    return 0;
}

void spausdintiLenta(int zaidLaukas[10][10]) //need to fix this shit Atspausdinti zaidimo lenta su laivais
{ 
    cout << "   0|1|2|3|4|5|6|7|8|9" << endl << endl;
    for(int i=0; i<10; i++)  //eile
    {
        for(int j=0; j<10; j++)  //stulpeliai
        {
            if(j==0)
            {
                cout << i << "  " ; //atspausdina eilutes skaiciu ir tarpa po juo
            }
            cout << zaidLaukas[i][j]; // reikia sita paimt is klases
            if(j!=9)
            {
                cout << "|";
            }
        }
        cout << endl; //pereina i nauja eilute
    }
    cout << endl;
}
void spausdintiZaidimoLenta(int priesoLaukas[10][10]) //Lenta Zaidimui, kurioje nesimato laivu
{
    cout << "   0|1|2|3|4|5|6|7|8|9" << endl << endl;
    for(int i=0; i<10; i++)  //eile
    {
        for(int j=0; j<10; j++)  //stulpeliai
        {
            if(j==0)
            {
                cout << i << "  " ; //atspausdina eilutes skaiciu ir tarpa
            }
            if(priesoLaukas[i][j]==LANG_LAIVAS)  //jeigu tame plote pataike, pazymima
            {
                cout << LANG_PATAIK;
            } else if(priesoLaukas[i][j]==LANG_TUSC)  //jeigu  tame plote nepataike, pazymima
            {
                cout << LANG_SAUTA;
            }
            if(j!=9)
            {
                cout << "|";
            }
        }
        cout << endl; //nauja eilute
    }
    cout << endl;
}
int PradetiZaidima() //Zaidimo  pradzia
{
    bool vykstaZaidimas=true;
    int eile=0, stulp0, spejimas=0, pataikymas=0, prasovimas=0, nuskandinti=0, plotas=0;




}// Zaidimo pabaiga



 
