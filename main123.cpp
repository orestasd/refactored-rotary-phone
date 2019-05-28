#include <bits/stdc++.h>

using namespace std;

const char LANG_LAIVAS = '*';
const char LANG_SAUTA = ' ';
const char LANG_PATAIK = 'X';
const char LANG_TUSC = '0';

class ZaidimoLenta
{
private:
    LaivasPagr ***laivasPagr;
    int kiekKartuIssauta;
    int kiekKartuPataikyta;
    int kieklaivuNuskandinta;
public:
    ZaidimoLenta()
    {
        laivasPagr = new LaivasPagr **[10];
        for (int i = 0; i < 10; i++)
        {
            laivasPagr[i] = new LaivasPagr*[10];
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
        LaivasPagr** LaivuSarasas = new LaivasPagr * [3];
        LaivuSarasas[0] = new Korvete();
        LaivuSarasas[1] = new Minininkas();
        LaivuSarasas[2] = new Lektuvnesis();
        for (int i = 0; i < 3; i++)
        {
            while (true)
            {
                cout << "Padeti laiva: " << "\"" << LaivuSarasas[i]->getLaivoTipas()<<"\"" << " Kurio ilgis yra: " << LaivuSarasas[i]->getIlgis() << endl;
                int eile, stulpelis;
                bool horizontalus = false;
                cout << "Iveskite norima x kordinate: ";
                cin >> stulpelis;
                if (stulpelis > 10 || stulpelis < 1 )
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
        LaivasPagr** LaivuSarasas = new LaivasPagr *[3];
        LaivuSarasas[0] = new Korvete();
        LaivuSarasas[1] = new Minininkas();
        LaivuSarasas[2] = new Lektuvnesis();
        for (int i = 0; i < 3; i++)
        {
            while (true)
            {

                srand((unsigned int)time(NULL));
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
                    cout << setw(68) <<"Priesininkas pasistate laiva: " << LaivuSarasas[i]->getLaivoTipas() << endl;
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
        if (laivasPagr[eile][stulpelis]->getLaivoTipas() == "tusciasLangelis")
            return false;
        return true;
    }
    bool kurSauti(int eile, int stulpelis)
    {
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
        int count = 0;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
            {
                if (laivasPagr[i][j]->arNuskendo())
                {
                    ++count;
                }
            }
        return count == 20;
    }

    LaivasPagr*** getLaivus()
    {
        return laivasPagr;
    }
    void spausdintiLentai()
    {
        system("cls");
        cout << "        Laivu statymas        " << endl;
        cout << "   x 1 2 3 4 5 6 7 8 9 10 " << endl;
        cout << " y " << (char)218;
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
        cout << "   x 1 2 3 4 5 6 7 8 9 10               x 1 2 3 4 5 6 7 8 9 10 " << endl;
        cout << " y " << (char)218;
        for (int j = 0; j < 21; j++)
        {
            cout << (char)196;
        }
        cout << (char)191 << "            y " << (char)218;
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

class LaivasPagr
{
protected:
    int ilgis, LaivoEile, LaivoStulp;
    bool horizontaliai = true;
    bool pataikymas = true;
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
    string getLaivoTipas()
    {
        return string();
    }
    bool arGalimaPadetiLaiva(int eile, int stulpelis, bool horizontalus, ZaidimoLenta *ZaidimoLenta)
    {
        if (horizontalus)
        {
            if (stulpelis + getIlgis() > 10)
            {
                return false;
            }
            for (int stulpelis1 = stulpelis - 1; stulpelis1 <= stulpelis + getIlgis(); stulpelis1++)
            {
                if (ZaidimoLenta->yraUzimtas(eile - 1, stulpelis1) || ZaidimoLenta->yraUzimtas(eile, stulpelis1) || ZaidimoLenta->yraUzimtas(eile + 1, stulpelis1))
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
                if (ZaidimoLenta->yraUzimtas(eile1, stulpelis - 1) || ZaidimoLenta->yraUzimtas(eile1, stulpelis) || ZaidimoLenta->yraUzimtas(eile1, stulpelis + 1))
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    void kurPadetiLaiva(int eile, int stulpelis, bool horizontalus, ZaidimoLenta *ZaidimoLenta)
    {
        nustatytiLaivoEile(eile);
        nustatytiLaivoStulpeli(stulpelis);
        nustatytiHorizontaluma(horizontalus);
        LaivasPagr*** laivasPagr = ZaidimoLenta->getLaivus();
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

    bool laivuSaudymas(int eile, int stulpelis)
    {
        return false;
    }

    bool arNuskendo()
    {
        return false;
    }
};

class Korvete : public LaivasPagr
{
public:
    Korvete()
    {
        ilgis = 1;
        pataikymas = new  bool[1];
    }
    string getLaivoTipas()
    {
        return "Korvete";
    }
    char toString()
    {
        if(arNuskendo())
            return LANG_PATAIK;
        if (!arNuskendo())
            return LANG_SAUTA;
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
        ilgis = 2;
        pataikymas = new  bool[2];
    }
    string getLaivoTipas()
    {
        return "Minininkas";
    }
    char toString()
    {
        if(arNuskendo())
            return LANG_PATAIK;
        if (!arNuskendo())
            return LANG_SAUTA;
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
        ilgis = 3;
        pataikymas = new  bool[3];
    }
    string getLaivoTipas()
    {
        return "Lektuvnesis";
    }
    char toString()
    {
        if(arNuskendo())
            return LANG_PATAIK;
        if (!arNuskendo())
            return LANG_SAUTA;
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
        ilgis=1;
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
        return '.';
    }
};

int  main()
{
    cout<<"@@@@@@@@@Pradzios@@@@@@@@tekstas@@@@@@@@"<<endl;
    cout<<"Jeigu norite pradeti, parasykite 'pradeti': ";
    string Zaisti;
    cin >> Zaisti;
    if(Zaisti == "pradeti")
    {
        ZaidimoLenta zaidejas;
        ZaidimoLenta priesininkas;
        zaidejas.SudeliotiLaivusBetkokiaTvarka();
        priesininkas.SudeliotiLaivusBetkokiaTvarka();
        zaidejas.spausdintiZaidimoLentai(&priesininkas);
    }
    else
    {
        system("CLS");
        cout<<"Ivestas netinkamas pasirinkimas, programa nutraukiama";
        exit;
    }

    return 0;
}





