#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class PassGen {
public:
    void Main(){
        const char a[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
        const char A[] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
        const char symb[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
        const char symbol[] = { '!', '@', '#', '$', '%', '&', '?', '-', '_' };

        vector<char> symbols;
        int n;
        cout << "Lenght: ";
        cin >> n;

        int choise;
        cout << "Type (Big - 0, small - 1, 1&2 - 2): ";
        cin >> choise;
        if (choise == 0)
            symbols.insert(symbols.end(), A, A + sizeof(A));
        else
        {
            symbols.insert(symbols.end(), a, a + sizeof(a));
            if (choise == 2)
                symbols.insert(symbols.end(), A, A + sizeof(A));
        }

        cout << "Use numbers (NO - 0, YES - 1): ";
        cin >> choise;
        if (choise == 1)
            symbols.insert(symbols.end(), symb, symb + sizeof(symb));

        cout << "Symbols (NO - 0, YES - 1): ";
        cin >> choise;
        if (choise == 1)
            symbols.insert(symbols.end(), symbol, symbol + sizeof(symbol));

        int numbers;

        mt19937 gen{ random_device()() };
        uniform_int_distribution<> dist(0, symbols.size() - 1);
        for (int i = 0; i < n; i++)
            cout << symbols[dist(gen)];
        cout << endl;
    }
};


int main(){
    PassGen PWD;
    PWD.Main();
    system("pause");
}
