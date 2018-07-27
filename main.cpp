#include <iostream>
#include <sstream>
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


template <class Number>
Number getInputNumber(std::string message, Number &inputNumber)
{
    std::string inputString;
    std::stringstream sString;
    

    cout << message;
    cin  >> inputString;
    sString << inputString;
    sString >> inputNumber;
    return inputNumber;
}

// ================== Menu =================//
int menu() 
{
    system("clear");
    cout << "            " << "\e[1;31m" << "69~ " << "\e[0m" << "Exit!" << endl;
    cout << "            " << "\e[1;31m" << "1~ " << "\e[0m" << "Create new constant " << endl;    
    cout << "            " << "\e[1;31m" << "2~ " << "\e[0m" << "Change constant " << endl;  
    cout << "            " << "\e[1;31m" << "3~ " << "\e[0m" << "Add node to this constant " << endl;  
    cout << "            " << "\e[1;31m" << "4~ " << "\e[0m" << "Calculate constant value with x" << endl;  
    cout << "            " << "\e[1;31m" << "5~ " << "\e[0m" << "Find equation with y " << endl;
    cout << "            " << "\e[1;31m" << "6~ " << "\e[0m" << "Show constant " << endl; 
    cout << "            " << "\e[1;31m" << "7~ " << "\e[0m" << "List of constant " << endl; 

    int chooseInt;
    std::string message = "Your choose [\e[1;34m" +  nowCons->name + "\e[0;m]~ ";
    getInputNumber(message, chooseInt);
    return chooseInt;
} 

inline void wait()
{
    cin.ignore(1000, '\n');
    while(true)
    {
        char k = getchar();
        if (k == '\n')
            break;
    }

}

bool remove(std::string &input, std::string str) 
{
    for (int i=0; i != input.length(); i++) 
    {
        if (input[i] == str[0])
        {
            int n = i;
            int k = i;
            for (int j=1; j != str.length(); j++) 
            {
                n++;
                if (input[n] != str[j]) 
                {
                    break;
                }
                if (j == str.length()-1) 
                {
                    input.erase(k, str.length());
                    return true;
                }
            }
        }
    }
    return false;
}; 
// ================== Hàm main ==================== //
int main() 
{
    while (true) 
    {
        int choose = menu();
        if (choose == 69)
            exit(0);

        // Thêm hàm số
        else if (choose == 1) 
        {
            std::string name;
            cout << "Enter name of constant: ";
            cin.ignore();
            getline(cin, name);
            createNewCons(name);
        }

        // Thay đổi hàm số
        else if (choose == 2) 
        {
            for (int i = 0; i < listCons.size(); i++)
            {
                cout << " " << i << ". " <<listCons[i]->name << endl;
            }
            int c;
            getInputNumber("Enter number of constant: ", c);
            if (c >= 0 && c < listCons.size())
            {
                nowCons = listCons[c];
            }
        }

        // Thêm node vào hàm số
        else if (choose == 3) 
        {
            float a;
            int n;

            getInputNumber("Enter A: ", a);
            getInputNumber("Enter n: ", n);

            node* no = new node(a, n);
            addNode(nowCons, no);
            printCons(nowCons);
            wait();
        }

        // Tính giá trị y tại x 
        else if (choose == 4)
        {
            float x;
            getInputNumber("Enter x: ", x);
            printConsWithPar(nowCons, x);
            wait();
        }

        // Tìm nghiệm với tham số y
        else if (choose == 5) 
        {
            float y;
            getInputNumber("Enter y: ", y);
            float x = findEquation(nowCons, y);
            printCons(nowCons);
            cout << " = " << y << endl;
            cout << "=> x = " << x << endl;
            wait();
        }

        // In hàm số
        else if (choose == 6) 
        {
            printCons(nowCons);
            wait();
        }

        // Hiển thị các hàm số
        else if (choose == 7)
        {
            for (int i = 0; i < listCons.size(); i++)
            {
                cout << " " << i << ". " <<listCons[i]->name << ": ";
                printCons(listCons[i]);
                cout << endl;
            }
            wait();
        }
    }
    return 0;
}
