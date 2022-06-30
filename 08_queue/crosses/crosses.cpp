#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<char> mundial ({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'});

    int gols_time_mandante {}, gols_time_visitante {};
    
    while(mundial.size() != 1) {
        cin >> gols_time_mandante >> gols_time_visitante;

        char time_mandante = mundial.front();
        mundial.pop();

        char time_visitante = mundial.front();
        mundial.pop();
        
        if(gols_time_mandante > gols_time_visitante)
            mundial.push(time_mandante);
        else
            mundial.push(time_visitante);
    }

    cout << "O time campeao é:" << mundial.front();
}