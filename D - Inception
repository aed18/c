#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
    std::list <std::string> lista;
    std::vector <string> answer;
    int t = 0; 
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        std::string a, p;
        cin >> a;
        if (a == "Sleep")
        {
            cin >> p;
            lista.push_back(p);
        }
        else if (a == "Test") 
        {
            if(lista.empty())answer.push_back("Not in a dream");
            else 
            {
                answer.push_back(lista.back());
            }
        }
        else if (!(lista.empty()) && a == "Kick") lista.pop_back();
    }

    for(auto ans: answer)
    {
        cout << ans<<endl;
    }
    
}
