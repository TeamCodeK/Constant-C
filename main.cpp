#include <iostream>
#include <vector>
#include "constant.h"

using namespace std;

constant* nowCons = new constant();

std::vector<constant*> listCons;

void createNewCons(std::string nameI) 
{
    constant* Cons = new constant();
    Cons->name = nameI;
    listCons.push_back(Cons);
    nowCons = Cons;
}

// ================== Menu =================//
int menu() 
{
    system("clear");
    cout << "            " << "\e[1;31m" << "0~ " << "\e[0m" << "Exit!" << endl;
    cout << "            " << "\e[1;31m" << "1~ " << "\e[0m" << "Create new constant " << endl;    
    cout << "            " << "\e[1;31m" << "2~ " << "\e[0m" << "Change constant " << endl;  
    cout << "            " << "\e[1;31m" << "3~ " << "\e[0m" << "Add node to this constant " << endl;  
    cout << "            " << "\e[1;31m" << "4~ " << "\e[0m" << "Calculate constant value with x" << endl;  
    cout << "            " << "\e[1;31m" << "5~ " << "\e[0m" << "Find equation with y " << endl;
    cout << "            " << "\e[1;31m" << "6~ " << "\e[0m" << "Show constant " << endl; 
    
    int choose;
    cout << "Your choose" << "[" << "\e[1;34m" <<  nowCons->name<< "\e[0m" << "]~ ";
    cin >> choose;
    return choose;
} 

inline void wait() {
    cin.ignore(1000, '\n');
    while(true) {
        char k = getchar();
        if (k == '\n')
            break;
    }

}

// ================== Hàm main ==================== //
int main() 
{
    while (true) 
    {
        int choose = menu();
        if (choose == 0)
            exit(0);
        else if (choose == 1) 
        {
            std::string name;
            cout << "Enter name of constant: ";
            cin >> name;
            createNewCons(name);
        }
        else if (choose == 2) 
        {
            for (int i = 0; i < listCons.size(); i++)
            {
                cout << " " << i << ". " <<listCons[i]->name << endl;
            }
            int c;
            cout << "Enter number of constant: ";
            cin >> c;
            if (c >= 0 && c < listCons.size())
            {
                nowCons = listCons[c];
            }
        }
        else if (choose == 3) 
        {
            float a;
            int n;
            cout << "Enter A: ";
            cin >> a;
            cout << "Enter n: ";
            cin >> n;
            node* no = new node(a, n);
            addNode(nowCons, no);
            printCons(nowCons);
            wait();
        }
        else if (choose == 4)
        {
            float x;
            cout << "Enter value x: ";
            cin >> x;
            printConsWithPar(nowCons, x);
            wait();
        }
        else if (choose == 5) 
        {
            float y;
            cout << "Enter value y: ";
            cin >> y;
            float x = findEquation(nowCons, y);
            printCons(nowCons);
            cout << " = " << y << endl;
            cout << "=> x = " << x << endl;
            wait();
        }
        else if (choose == 6) 
        {
            printCons(nowCons);
            wait();
        }
    }
    return 0;
}
