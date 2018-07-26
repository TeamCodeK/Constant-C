#include <iostream>
#include <math.h>

using namespace std;


// ================= Định nghĩa các node trong biểu thức ================= //
struct node 
{
    float a;
    float x;
    int n;
    node * pNext;
    node(float a = 0, int n = 0): a(a), n(n), x(0), pNext(NULL) {};

}; typedef struct node node;

float getValue(node* nodeInput, float x) 
{
    if (nodeInput != NULL) 
    {
        return (nodeInput->a*pow(x, nodeInput->n));
    }
};

void showNode(node* nodeInput) 
{
    if (nodeInput != NULL) 
    {
        cout << "A: " << nodeInput->a << " " << "n: " << nodeInput->n << " " << endl;  
    }
};

// ================= Định nghĩa cấu tạo biểu thức ================== // 
struct constant 
{
    std::string name = " ";
    node* pHead = new node();

}; typedef struct constant constant;

bool addNode(constant* &constantInput, node* &nodeInput) 
{
    if (constantInput == NULL || nodeInput == NULL)
        return false;
    
    nodeInput->pNext = constantInput->pHead;
    constantInput->pHead = nodeInput;
    return true;
};

float F(constant* constantInput,float x) 
{
    if (constantInput != NULL) 
    {
        float outValue = 0.;
        node* pHead = constantInput->pHead;
        while (pHead != NULL) 
        {
            outValue += getValue(pHead, x);

            pHead = pHead->pNext;
        }
        return outValue;
    }
};

float* findRegionOfEquation(constant* constantInput, float yI) 
{
    float y = F(constantInput, 0.) - yI;
    float x = 1.;
    float _y, __y;
    float* a = new float(2);
    while (x < 1000) 
    {
        x *= 1.00001;
        _y  = F(constantInput, x) - yI;
        __y = F(constantInput, (-x)) - yI;
        if (_y*y < 0) 
        {
            a[0] = 0;
            a[1] = x;
            return a;
        }
        else if (__y*y < 0) 
        {
            a[0] = 0;
            a[1] = -x;
            return a;
        }
    }
    return NULL;
};

float findEquation(constant* constantInput, float yI) 
{
    float* a = findRegionOfEquation(constantInput, yI);
    if (a == NULL) {
        return -434513245.0;
    }
    float x_ = (a[0]+a[1])/2;
    if (a != NULL) 
    {
        float y, _y, __y;
        while ((roundf(F(constantInput, x_) * 10000)/10000) != yI) 
        {
            y   = F(constantInput, x_)   - yI;
            _y  = F(constantInput, a[0]) - yI;
            __y = F(constantInput, a[1]) - yI;
            if (_y*y < 0) {
                a[1] = x_;
                x_ = (a[0]+a[1])/2;
            }
            else if (__y*y < 0) {
                a[0] = x_;
                x_ = (a[0]+a[1])/2;
            }
            cout << x_ << endl;
        }
    }
    delete a;
    return x_;
}

void printCons(constant* constantInput) 
{
    cout << "\e[1;37m";
    if (constantInput != NULL) 
    {
        node* pHead = constantInput->pHead;
        while (pHead != NULL)
        {
            if (pHead->n == 0) 
                cout << pHead->a << " + ";
            else if (pHead->n == 1)
                cout << pHead->a << "x + ";
            else 
                cout << pHead->a << "x^" << pHead->n << " + ";

            pHead = pHead->pNext;
        }  
    }
    cout << "0 ";
    cout << "\e[0m";
};

void printConsWithPar(constant* constantInput, float x)
{
    cout << "\e[1;37m";
    cout << "F(" << x << ") " << "( ";
    printCons(constantInput);
    cout << "\e[1;37m";
    cout << " ) = "<< "\e[1;31m" << F(constantInput, x);
    cout << "\e[0m";
}


