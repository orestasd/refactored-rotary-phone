#include <iomanip>
#include <iostream>
#include <utility>
#include <time.h>
#include <Windows.h>
using namespace std;

const char LANG_LAIVAS = '*';
const char LANG_SAUTA = ' ';
const char LANG_PATAIK = 'X';
const char LANG_TUSC = '0';

class ZaidimoLenta;

class LaivasPagr
{
protected:
    int ilgis, LaivoEile, LaivoStulp;
    bool horizontaliai = true;
    bool *pataikymas;
public:
    virtual char toString() = 0;
    int getIlgis()
    {
        return ilgis;
    }
    bool arHorizontaliai()
    {
        return horizontaliai;
    }
    int getLaivoEile()
    {
        return LaivoEile;
    }
    int getLaivoStulp()
    {
        return LaivoStulp;
    }
    void nustatytiLaivoEile(int eile)
    {
        LaivoEile = eile;
    }
    void nustatytiLaivoStulpeli(int stulpelis)
    {
        LaivoStulp = stulpelis;
    }
    void nustatytiHorizontaluma(bool horizontalus)
    {
        horizontaliai = horizontalus;
    }
    virtual string getLaivoTipas() = 0;
    bool arGalimaPadetiLaiva(int eile, int stulpelis, bool horizontalus, ZaidimoLenta* zaidimoLenta);
    void kurPadetiLaiva(int eile, int stulpelis, bool horizontalus, ZaidimoLenta* zaidimoLenta);

    virtual bool laivuSaudymas(int eile, int stulpelis)
    {
        if (!this->arNuskendo())
        {
            if (this->horizontaliai)
            {
                pataikymas[stulpelis - this->LaivoStulp] = true;
                return true;
            }
            else
            {
                pataikymas[eile - this->LaivoEile] = true;
                return true;
            }
        }
    }

    bool arNuskendo()
    {
        for (int i = 0; i < getIlgis(); i++)
        {
            if (pataikymas[i] == false)
            {
                return false;
            }
        }
        return true;
    }
};

class Korvete : public LaivasPagr
{
public:
    Korvete()
    {
        ilgis = 2;
        pataikymas = new  bool[2];
        for (int i = 0; i < ilgis; i++)
        {
            pataikymas[i] = false;
        }
    }
    string getLaivoTipas()
    {
        return "Korvete";
    }
    char toString()
    {
        if (arNuskendo())
            return LANG_PATAIK;
        if (!arNuskendo())
            return LANG_LAIVAS;
    }
    int getIlgis()
    {
        return this->ilgis;
    }
};
class Minininkas : public LaivasPagr
{
public:
    Minininkas()
    {
        ilgis = 3;
        pataikymas = new  bool[3];
        for (int i = 0; i < ilgis; i++)
        {
            pataikymas[i] = false;
        }
    }
    string getLaivoTipas()
    {
        return "Minininkas";
    }
    char toString()
    {
        if (arNuskendo())
            return LANG_PATAIK;
        if (!arNuskendo())
            return LANG_LAIVAS;
    }
    int getIlgis()
    {
        return this->ilgis;
    }
};
class Lektuvnesis : public LaivasPagr
{
public:
    Lektuvnesis()
    {
        ilgis = 4;
        pataikymas = new  bool[4];
        for (int i = 0; i < ilgis; i++)
        {
            pataikymas[i] = false;
        }
    }
    string getLaivoTipas()
    {
        return "Lektuvnesis";
    }
    char toString()
    {
        if (arNuskendo())
            return LANG_PATAIK;
        if (!arNuskendo())
            return LANG_LAIVAS;
    }
    int getIlgis()
    {
        return this->ilgis;
    }
};

class TusciaLenta : public LaivasPagr
{
public:
    TusciaLenta()
    {
        ilgis = 1;
    }
    string getLaivoTipas()
    {
        return "tusciasLangelis";
    }
    bool kurSauti(int eile, int stulpelis)
    {
        return false;
    }
    bool arNuskendo()
    {
        return false;
    }
    char toString()
    {
        return LANG_TUSC;
    }
};

class ZaidimoLenta
{
private:
    LaivasPagr*** laivasPagr;
    int kiekKartuIssauta;
    int kiekKartuPataikyta;
    int kieklaivuNuskandinta;
public:
    ZaidimoLenta()
    {
        laivasPagr = new LaivasPagr **[10];
        for (int i = 0; i < 10; i++)
        {
            laivasPagr[i] = new LaivasPagr * [10];
        }
        kiekKartuIssauta = 0;
        kiekKartuPataikyta = 0;
        kieklaivuNuskandinta = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                laivasPagr[i][j] = new TusciaLenta();
            }
        }
    }
    void sudeliotiLaivus()
    {
        spausdintiLentai();
        LaivasPagr** LaivuSarasas = new LaivasPagr*[3];
        LaivuSarasas[0] = new Korvete();
        LaivuSarasas[1] = new Minininkas();
        LaivuSarasas[2] = new Lektuvnesis();
        for (int i = 0; i < 3; i++)
        {
            while (true)
            {
                cout << "Padeti laiva: " << "\"" << LaivuSarasas[i]->getLaivoTipas() << "\"" << " Kurio ilgis yra: " << LaivuSarasas[i]->getIlgis() << endl;
                int eile, stulpelis;
                bool horizontalus = false;
                cout << "Iveskite norima x kordinate: ";
                cin >> stulpelis;
                if (stulpelis > 10 || stulpelis < 1)
                {
                    spausdintiLentai();
                    cout << "Tokia kordinate negalima!" << endl;
                    continue;
                }
                stulpelis = stulpelis - 1;
                cout << "Iveskite norima y kordinate: ";
                cin >> eile;
                if (eile > 10 || eile < 1)
                {
                    spausdintiLentai();
                    cout << "Tokia kordinate negalima!" << endl;
                    continue;
                }
                eile = eile - 1;
                char kryptis;
                cout << "Norite padeti horizontaliai ar vertikaliai? (Zymeti h / v) ";
                cin >> kryptis;
                if (kryptis == 'h')
                    horizontalus = true;
                if (kryptis == 'v')
                    horizontalus = false;
                if (LaivuSarasas[i]->arGalimaPadetiLaiva(eile, stulpelis, horizontalus, this))
                {
                    LaivuSarasas[i]->kurPadetiLaiva(eile, stulpelis, horizontalus, this);
                    spausdintiLentai();
                    break;
                }
                else
                {
                    spausdintiLentai();
                    cout << "Negalima padeti laivo" << endl;
                }
            }
        }
    }
    void SudeliotiLaivusBetkokiaTvarka()
    {
        LaivasPagr** LaivuSarasas = new LaivasPagr * [3];
        LaivuSarasas[0] = new Korvete();
        LaivuSarasas[1] = new Minininkas();
        LaivuSarasas[2] = new Lektuvnesis();
        for (int i = 0; i < 3; i++)
        {
            while (true)
            {
                int x, y;
                bool horizontalus;
                x = (rand() % 10);
                y = (rand() % 10);
                horizontalus = (rand() % 2);
                if (LaivuSarasas[i]->arGalimaPadetiLaiva(x, y, horizontalus, this))
                {
                    LaivuSarasas[i]->kurPadetiLaiva(x, y, horizontalus, this);
                    system("cls");
                    for (int i = 0; i < 14; i++)
                    {
                        cout << endl;
                    }
                    cout << setw(68) << "Priesininkas pasistate laiva: " << LaivuSarasas[i]->getLaivoTipas() << endl;
                    break;
                }
            }
        }

    }
    bool yraUzimtas(int eile, int stulpelis)
    {
        if (eile < 0 || eile > 9 || stulpelis < 0 || stulpelis > 9)
        {
            return false;
        }
        else if (laivasPagr[eile][stulpelis]->getLaivoTipas() == "tusciasLangelis")
            return false;
        else
            return true;
    }
    bool kurSauti(int eile, int stulpelis)
    {
        kiekKartuIssauta++;
        if (laivasPagr[eile][stulpelis]->laivuSaudymas(eile, stulpelis))
        {
            kiekKartuPataikyta++;
            return true;
        }
        return false;
    }

    int getKiekKartuIssauta()
    {
        return kiekKartuIssauta;
    }

    int getKiekKartuPataikyta()
    {
        return kiekKartuPataikyta;
    }

    int getKieklaivuNuskandinta()
    {
        return kieklaivuNuskandinta;
    }
    bool ZaidimoPabaiga()
    {
        int kiekis = 0;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
            {
                if (laivasPagr[i][j]->arNuskendo())
                {
                    ++kiekis;
                }
            }
        return kiekis == 7;
    }

    LaivasPagr*** getLaivus()
    {
        return laivasPagr;
    }
    void spausdintiLentai()
    {
        system("cls");
        cout << "        Laivu statymas        " << endl;
        cout << "     1 2 3 4 5 6 7 8 9 10 " << endl;               // Laivu deliojimui
        cout << "   " << (char)218;
        for (int j = 0; j < 21; j++)
        {
            cout << (char)196;                      //charai lenteles sudarymui
        }
        cout << (char)191;
        cout << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << setw(2) << i + 1 << " " << (char)179 << " ";
            for (int j = 0; j < 10; j++)
            {
                cout << laivasPagr[i][j]->toString() << " ";
            }
            cout << (char)179;
            cout << endl;
        }
        cout << "   " << (char)192;
        for (int j = 0; j < 21; j++)
        {
            cout << (char)196;
        }
        cout << (char)217;
        cout << endl;
    }
    void spausdintiZaidimoLentai(ZaidimoLenta* priesininkas)
    {
        LaivasPagr*** priesininkoLaivai = priesininkas->getLaivus();
        system("cls");
        cout << "          Jusu lenta                        Priesininko lenta " << endl;
        cout << "     1 2 3 4 5 6 7 8 9 10                 1 2 3 4 5 6 7 8 9 10" << endl;
        cout << "   " << (char)218;
        for (int j = 0; j < 21; j++)
        {
            cout << (char)196;
        }
        cout << (char)191 << "              " << (char)218;
        for (int j = 0; j < 21; j++)
        {
            cout << (char)196;
        }
        cout << (char)191;
        cout << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << setw(2) << i + 1 << " " << (char)179 << " ";
            for (int j = 0; j < 10; j++)
            {
                cout << laivasPagr[i][j]->toString() << " ";
            }
            cout << (char)179;
            cout << "           ";
            cout << setw(2) << i + 1 << " " << (char)179 << " ";
            for (int j = 0; j < 10; j++)
            {
                cout << priesininkoLaivai[i][j]->toString() << " ";
            }
            cout << (char)179;
            cout << endl;
        }
        cout << "   " << (char)192;
        for (int j = 0; j < 21; j++)
        {
            cout << (char)196;
        }
        cout << (char)217 << "              " << (char)192;
        for (int j = 0; j < 21; j++)
        {
            cout << (char)196;
        }
        cout << (char)217 << endl;
    }
};

bool LaivasPagr::arGalimaPadetiLaiva(int eile, int stulpelis, bool horizontalus, ZaidimoLenta* zaidimoLenta)
{
    if (horizontalus)
    {
        if (stulpelis + getIlgis() > 10)
        {
            return false;
        }
        for (int stulpelis1 = stulpelis - 1; stulpelis1 <= stulpelis + getIlgis(); stulpelis1++)
        {
            if (zaidimoLenta->yraUzimtas(eile - 1, stulpelis1) || zaidimoLenta->yraUzimtas(eile, stulpelis1) || zaidimoLenta->yraUzimtas(eile + 1, stulpelis1))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        if (eile + getIlgis() > 10)
        {
            return false;
        }
        for (int eile1 = eile - 1; eile1 <= eile + getIlgis(); eile1++)
        {
            if (zaidimoLenta->yraUzimtas(eile1, stulpelis - 1) || zaidimoLenta->yraUzimtas(eile1, stulpelis) || zaidimoLenta->yraUzimtas(eile1, stulpelis + 1))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
void LaivasPagr::kurPadetiLaiva(int eile, int stulpelis, bool horizontalus, ZaidimoLenta* zaidimoLenta)
{
    nustatytiLaivoEile(eile);
    nustatytiLaivoStulpeli(stulpelis);
    nustatytiHorizontaluma(horizontalus);
    LaivasPagr*** laivasPagr = zaidimoLenta->getLaivus();
    if (horizontalus)
    {
        for (int i = stulpelis; i < stulpelis + getIlgis(); i++)
        {
            laivasPagr[eile][i] = this;
        }
    }
    else
    {
        for (int i = eile; i < eile + getIlgis(); i++)
        {
            laivasPagr[i][stulpelis] = this;
        }
    }
}


int  main()
{        
    ZaidimoLenta zaidejas;
    ZaidimoLenta priesininkas;
    cout << "@@@@@@@@@@@@@@@@ LAIVU MUSIS @@@@@@@@@@@@@@@" << endl;
    cout << "Jeigu norite pradeti, parasykite 'pradeti': ";
    string Zaisti;
    cin >> Zaisti;
    srand((unsigned int)time(NULL));
    if (Zaisti == "pradeti")
    {

        zaidejas.sudeliotiLaivus();
        priesininkas.SudeliotiLaivusBetkokiaTvarka();
        zaidejas.spausdintiZaidimoLentai(&priesininkas);
        while (!zaidejas.ZaidimoPabaiga() && !priesininkas.ZaidimoPabaiga())
        {
            bool ZaidejoEile = true;
            while (ZaidejoEile)
            {
                cout << "Iveskite y: ";
                int stulpelis;
                cin >> stulpelis;
                if (stulpelis > 10 || stulpelis < 1)
                {
                    zaidejas.spausdintiZaidimoLentai(&priesininkas);
                    cout << "Ivesta bloga koordinate." << endl;
                    continue;
                }
                stulpelis = stulpelis - 1;

                cout << "Iveskite x: ";
                int eilute;
                cin >> eilute;
                if (eilute > 10 || eilute < 1)
                {
                    zaidejas.spausdintiZaidimoLentai(&priesininkas);
                    cout << "Ivesta bloga koordinate." << endl;
                    continue;
                }
                eilute = eilute - 1;

                if (priesininkas.kurSauti(eilute, stulpelis))
                {

                    zaidejas.spausdintiZaidimoLentai(&priesininkas);
                    cout << "I jus pataike." << endl;
                    LaivasPagr*** ships = priesininkas.getLaivus();
                    if (ships[eilute][stulpelis]->arNuskendo())
                    {
                        cout << "Paskandinote laiva: " << ships[eilute][stulpelis]->getLaivoTipas() << endl;
                        ZaidejoEile = false;
                        break;
                    }
                    cout << "X = " << stulpelis + 1 << " Y = " << eilute + 1 << endl;
                    Sleep(1000);
                }
                else
                {
                    zaidejas.spausdintiZaidimoLentai(&priesininkas);
                    cout << "I jus pataike." << endl;
                    cout << "X = " << stulpelis + 1 << " Y = " << eilute + 1 << endl;
                    Sleep(1000);
                    ZaidejoEile = false;
                    break;
                }
            }
            bool enemyTurn = true;
            while (enemyTurn)
            {
                int eilute, stulpelis;
                eilute = (rand() % 10);
                stulpelis = (rand() % 10);
                if (zaidejas.kurSauti(eilute, stulpelis))
                {
                    zaidejas.spausdintiZaidimoLentai(&priesininkas);
                    cout << "I jus pataike." << endl;
                    LaivasPagr*** ships = priesininkas.getLaivus();
                    if (ships[eilute][stulpelis]->arNuskendo())
                    {
                        cout << "Paskandinote laiva: " << ships[eilute][stulpelis]->getLaivoTipas() << endl;
                        enemyTurn = false;
                        break;
                    }
                }
                else
                {
                    zaidejas.spausdintiZaidimoLentai(&priesininkas);
                    cout << "I jus pataike." << endl;
                    cout << "X = " << stulpelis + 1 << " Y = " << eilute + 1 << endl;
                    Sleep(1000);
                    ZaidejoEile = false;
                    break;
                }

            }
        }
    }
    else
    {
        system("CLS");
        cout << "Ivestas netinkamas pasirinkimas, programa nutraukiama";
        exit;
    }

    return 0;
}
