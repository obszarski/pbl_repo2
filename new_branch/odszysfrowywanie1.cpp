#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const string alfabet_M="a¹bcædeêfghijklmnñoópqrstuvwxyzŸ¿";
const string alfabet_m="A¥BCÆDEÊFGHIJKLMNÑOÓPQRSTUVWXYZ¯";

int main()
{
    int liczniki[35];
    string napis;

    for(int i = 0; i < 35; i++)
        liczniki[i]=0;
    
	ifstream wejscie("zliczanie.txt");
	
	while (!wejscie.eof())
    {
        getline(wejscie,napis);
        for(int i = 0; i < napis.size(); i++)
        {
            int y = alfabet_M.find(napis[i]);
            
            if(y >= 0 && y < 35)
                liczniki[y]++;
                
            int x = alfabet_m.find(napis[i]);
            
            if(x >= 0 && x < 35)
                liczniki[x]++;
        }
    }
    wejscie.close();
    ofstream wyjscie("wyniki_czestosci.txt");

    for(int i = 0; i < 35; i++)
    {
        wyjscie << alfabet_m[i] << " " << liczniki[i] << endl;
    }

    wyjscie.close();
    cout<< "wyniki w pliku wyniki_czestosci.txt" << endl;

    return 0;
}
