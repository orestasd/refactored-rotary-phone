#include <bits/stdc++.h>


using namespace std;


void editBoatInfo(int priesoLaukas[][10], int eile, int stulp, int ilgis, char puse, list<LaivasPagr> laivas, int tipas)
//This function creates the boat objects
{
    switch(tipas)
    {
        case 1:
            if(puse =='h')
            {
                list<LaivasPagr> eile1 (5);
                //  put coordinate data into the vectors using at()
                for (int i=0; i<eile1.size(); ++i)
                {
                    eile1.at(i)=eile;
                }
                vector<int> stulp1 (5);
                for (int i=0; i<c1.size(); ++i)
                {
                    stulp1.at(i)=stulp;
                    stulp1++;
                }
            //Aircraft Carrier
            Boat carrierBoat('h', 5, r1, c1, 0, "Aircraft Carrier");
            boatList.push_back(carrierBoat);
            }
            else if(d=='v')
            {
                vector<int> r1 (5);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (5);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Aircraft Carrier
            Boat carrierBoat('v', 5, r1, c1, 0, "Aircraft Carrier");
            boatList.push_back(carrierBoat);
            }
            break;
        case 2:
            if(d=='h')
            {
                vector<int> r1 (4);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (4);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Battleship 1
            Boat battleship1Boat('h', 4, r1, c1, 0, "Battleship 1");
            boatList.push_back(battleship1Boat);
            }
            else if(d=='v')
            {
                vector<int> r1 (4);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (4);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Battleship 1
            Boat battleship1Boat('v', 4, r1, c1, 0, "Battleship 1");
            boatList.push_back(battleship1Boat);
        }
        break;
        case 3:
            if(d=='h')
            {
                vector<int> r1 (4);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (4);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Battleship 2
            Boat battleship2Boat('h', 4, r1, c1, 0, "Battleship 2");
            boatList.push_back(battleship2Boat);
            }
            else if(d=='v')
            {
                vector<int> r1 (4);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (4);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Battleship 2
            Boat battleship2Boat('v', 4, r1, c1, 0, "Battleship 2");
            boatList.push_back(battleship2Boat);
            }
            break;
        case 4:
            if(d=='h')
            {
                vector<int> r1 (3);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (3);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
             //Destroyer 1
             Boat destroyer1Boat('h', 3, r1, c1, 0, "Destroyer 1");
             boatList.push_back(destroyer1Boat);
             }
             else if(d=='v')
             {
                vector<int> r1 (3);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (3);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
             //Destroyer 1
             Boat destroyer1Boat('v', 3, r1, c1, 0, "Destroyer 1");
             boatList.push_back(destroyer1Boat);
             }
             break;
        case 5:
        if(d=='h')
        {
            vector<int> r1 (3);
            for (int i=0; i<(int)r1.size(); ++i)
            {
                r1.at(i)=r;
            }
            vector<int> c1 (3);
            for (int i=0; i<(int)c1.size(); ++i)
            {
                c1.at(i)=c;
                c++;
            }
        //Destroyer 2
        Boat destroyer2Boat('h', 3, r1, c1, 0, "Destroyer 2");
        boatList.push_back(destroyer2Boat);
        }
        else if(d=='v')
        {
            vector<int> r1 (3);
            for (int i=0; i<(int)r1.size(); ++i)
            {
                r1.at(i)=r;
                r++;
            }
            vector<int> c1 (3);
            for (int i=0; i<(int)c1.size(); ++i)
            {
                c1.at(i)=c;
            }
            //Destroyer 2
            Boat destroyer2Boat('v', 3, r1, c1, 0, "Destroyer 2");
            boatList.push_back(destroyer2Boat);
        }
            break;
        case 6:
            if(d=='h')
            {
                vector<int> r1 (3);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (3);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Destroyer 3
            Boat destroyer3Boat('h', 3, r1, c1, 0, "Destroyer 3");
            boatList.push_back(destroyer3Boat);
            }
            else if(d=='v')
            {
                vector<int> r1 (3);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (3);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Destroyer 3
            Boat destroyer3Boat('v', 3, r1, c1, 0, "Destroyer 3");
            boatList.push_back(destroyer3Boat);
            }
            break;
        case 7:
            if(d=='h')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Submarine1
            Boat submarine1Boat('h', 2, r1, c1, 0, "Submarine 1");
            boatList.push_back(submarine1Boat);
            }
            else if(d=='v')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Submarine 1
            Boat submarine1Boat('v', 2, r1, c1, 0, "Submarine 1");
            boatList.push_back(submarine1Boat);
            }
            break;
        case 8:
            if(d=='h')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Submarine 2
            Boat submarine2Boat('h', 2, r1, c1, 0, "Submarine 2");
            boatList.push_back(submarine2Boat);
            }
            else if(d=='v')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Submarine 2
            Boat submarine2Boat('v', 2, r1, c1, 0, "Submarine 2");
            boatList.push_back(submarine2Boat);
            }
            break;
        case 9:
            if(d=='h')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                    c++;
                }
            //Submarine 3
            Boat submarine3Boat('h', 2, r1, c1, 0, "Submarine 3");
            boatList.push_back(submarine3Boat);
            }
            else if(d=='v')
            {
                vector<int> r1 (2);
                for (int i=0; i<(int)r1.size(); ++i)
                {
                    r1.at(i)=r;
                    r++;
                }
                vector<int> c1 (2);
                for (int i=0; i<(int)c1.size(); ++i)
                {
                    c1.at(i)=c;
                }
            //Submarine 3
            Boat submarine3Boat('v', 2, r1, c1, 0, "Submarine 3");
            boatList.push_back(submarine3Boat);
            }
            break;
        case 10:
        if(d=='h')
        {
            vector<int> r1 (2);
            for (int i=0; i<(int)r1.size(); ++i)
            {
                r1.at(i)=r;
            }
            vector<int> c1 (2);
            for (int i=0; i<(int)c1.size(); ++i)
            {
                c1.at(i)=c;
                c++;
            }
        //Submarine 4
        Boat submarine4Boat('h', 2, r1, c1, 0, "Submarine 4");
        boatList.push_back(submarine4Boat);
        }
        else if(d=='v')
        {
            vector<int> r1 (2);
            for (int i=0; i<(int)r1.size(); ++i)
            {
                r1.at(i)=r;
                r++;
            }
            vector<int> c1 (2);
            for (int i=0; i<(int)c1.size(); ++i)
            {
                c1.at(i)=c;
            }
        //Submarine 4
        Boat submarine4Boat('v', 2, r1, c1, 0, "Submarine 4");
        boatList.push_back(submarine4Boat);
        }
        break;
    }
}