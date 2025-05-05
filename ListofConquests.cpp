#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
int main()
{
	int t = 0;
	cin >> t;
	std::map<string, int> cantidad;
	for(int i= 0; i<t; i++)
	{
		string country, rest;
		cin >> country;
		std::getline(cin, rest);
		cantidad[country]++;
	}
	
	for(auto mapa : cantidad)
	{
		cout << mapa.first << " " << mapa.second << endl;
	}
}
