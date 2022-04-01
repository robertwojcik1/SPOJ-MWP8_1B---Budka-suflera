#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void przypiszWyrazyZOryginalnegoTekstuDoWektora ( string oryginalnyTekst, vector<string>& wektorOryginalnyTekst )
{
    string wyrazOryginalny = "";

    for ( int i = 0; i < oryginalnyTekst.length(); i++ )
    {
        if ( oryginalnyTekst[i] == 32 )
        {
            wektorOryginalnyTekst.push_back( wyrazOryginalny );
            wyrazOryginalny = "";
            continue;
        }
        else if ( i == oryginalnyTekst.length() - 1 )
        {
            wyrazOryginalny += oryginalnyTekst[i];
            wektorOryginalnyTekst.push_back( wyrazOryginalny );
        }
        wyrazOryginalny += oryginalnyTekst[i];
    }
}

void przypiszWyrazyZZapisanegoTekstuDoWektora ( string zapisanyTekst, vector<string>& wektorZapisanyTekst )
{
    string wyrazZapisany = "";

    for ( int i = 0; i < zapisanyTekst.length(); i++ )
    {
        if ( zapisanyTekst[i] == 32 )
        {
            wektorZapisanyTekst.push_back( wyrazZapisany );
            wyrazZapisany = "";
            continue;
        }
        else if ( i == zapisanyTekst.length() - 1 )
        {
            wyrazZapisany += zapisanyTekst[i];
            wektorZapisanyTekst.push_back( wyrazZapisany );
        }
        wyrazZapisany += zapisanyTekst[i];
    }
}

void przypiszPominieteWyrazyDoWektora ( int pominieteWyrazy, vector<string>& wektorOryginalnyTekst, vector<string>& wektorZapisanyTekst, vector<string>& wektorPominietychWyrazow )
{
    if ( pominieteWyrazy > 0 )
    {
        for ( int i = 0; i < wektorOryginalnyTekst.size(); i++ )
        {
            if( wektorZapisanyTekst.size() > 0 )
            {
                if( wektorZapisanyTekst.front() == wektorOryginalnyTekst[i] )
                {
                    wektorZapisanyTekst.erase(wektorZapisanyTekst.begin() );
                }
                else
                {
                    wektorPominietychWyrazow.push_back( wektorOryginalnyTekst[i] );
                }
            }
            else
            {
                wektorPominietychWyrazow.push_back( wektorOryginalnyTekst[i] );
            }
        }
    }
}

void wydrukujPominieteWyrazy ( vector<string>& wektorPominietychWyrazow )
{
    for ( int i = 0; i < wektorPominietychWyrazow.size(); i++ )
    {
        cout << wektorPominietychWyrazow[i] << endl;
    }
}

int main()
{
    vector<string> wektorOryginalnyTekst;
    vector<string> wektorZapisanyTekst;
    vector<string> wektorPominietychWyrazow;
    string oryginalnyTekst = "";
    string zapisanyTekst = "";
    int pominieteWyrazy = 0;

    getline (cin, oryginalnyTekst);
    getline ( cin, zapisanyTekst);

    przypiszWyrazyZOryginalnegoTekstuDoWektora( oryginalnyTekst, wektorOryginalnyTekst );
    przypiszWyrazyZZapisanegoTekstuDoWektora( zapisanyTekst, wektorZapisanyTekst );

    pominieteWyrazy = wektorOryginalnyTekst.size() - wektorZapisanyTekst.size();
    cout << pominieteWyrazy << endl;

    przypiszPominieteWyrazyDoWektora( pominieteWyrazy, wektorOryginalnyTekst, wektorZapisanyTekst, wektorPominietychWyrazow );

    sort( wektorPominietychWyrazow.begin(), wektorPominietychWyrazow.end() );
    wydrukujPominieteWyrazy ( wektorPominietychWyrazow );

    return 0;
}
