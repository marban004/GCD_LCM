#include <iostream>
#include <cmath>
#include <windows.h>
#include <map>
#include <iomanip>
#include <future>
#include <string>
#include <sstream>
//#include <format>
//#include <ostream>

#define TRUE 1
#define FALSE 0
#define EXIT_OK 0
#define RED 12
#define WHITE 15
#define GREEN 2
#define BLUE 1

using namespace std;

/*
HANDLE u;

int isPrime(int number)
{
int result = TRUE;
int i;
for(i = 2; i <= (int)sqrt((double)number); i ++)
    if (number % i == 0)
        {
        result = FALSE;
        break;
        }
return result;
}



int GetNextPrime(int prevprime)
{
int i;
for(i = prevprime+1;  !isPrime(i) ;i ++)
    if (isPrime(i))
    {
        break;
    }
return i;
}*/

/*void GeneratePrimeSequence(int number, map<int, int>* PrimeSeq)
{
    int counter = 0;
    int prime = 0;
    for(int i = 1; i<= number; i = prime)

    {
        counter = 0;
        prime = GetNextPrime(i);
        while ( number > 1 )
        {
            if (number % prime == 0)
            {
                number /= prime;
                counter ++;
            }
            else
                break;
        }
        PrimeSeq -> insert(make_pair(prime, counter));
    }
}*/
/*
void PrintPrimeSequence(map<int, int>* PrimeSeq)
{
    for(auto &ele: *PrimeSeq)
    {
        printf("%d[%d] \n", ele.first, ele.second);
    }
}
*/
/*int NWWSeq(map<int, int>* Value1PrimeSeq, map<int, int>* Value2PrimeSeq)
{
int NWW = 1;
if(Value1PrimeSeq -> size() < Value2PrimeSeq -> size())
{
    map<int, int>* PrimeSeqTemp = Value1PrimeSeq;
    Value1PrimeSeq = Value2PrimeSeq;
    Value2PrimeSeq = PrimeSeqTemp;
}

for(auto &ele: *Value1PrimeSeq)
{
    if(ele.second < (*Value2PrimeSeq)[ele.first])
    {
        NWW *= pow(ele.first, (*Value2PrimeSeq)[ele.first]);
    }
    else
    {
        NWW *= pow(ele.first,ele.second);
    }
}
return NWW;
}*/

/*int NWDSeq(map<int, int>* Value1PrimeSeq, map<int, int>* Value2PrimeSeq)
{
int NWD = 1;
if(Value1PrimeSeq -> size() < Value2PrimeSeq -> size())
{
    map<int, int>* PrimeSeqTemp = Value1PrimeSeq;
    Value1PrimeSeq = Value2PrimeSeq;
    Value2PrimeSeq = PrimeSeqTemp;
}

for(auto &ele: *Value1PrimeSeq)
{
    if(ele.second > (*Value2PrimeSeq)[ele.first])
    {
        NWD *= pow(ele.first, (*Value2PrimeSeq)[ele.first]);
    }
    else
    {
        NWD *= pow(ele.first,ele.second);
    }
}
return NWD;
}*/

/*
void ShowMenu()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
    cout << left << setfill('-') << setw(59) << "+Wybierz opcje" << "+" << endl;
    cout << left << setfill(' ') << setw(59) << "|1.Wylicz NWW i NWD" << "|" << endl;
    cout << left << setfill(' ') << setw(59) << "|2.Wypisz rozklad na czynniki pierwsze" << "|" << endl;
    cout << left << setfill(' ') << setw(59) << "|3.Wyjdz z programu" << "|" << endl;
    cout << left << setfill(' ') << setw(59) << "|" << "|" << endl;
    cout << left << setfill(' ') << setw(59) << "|Wybor:" << "|" << endl;
    cout << left << setfill('-') << setw(59) << "+" << "+" << endl;
}
*/
/*
int GetOption()
{
        int option=0;
        stringstream ss1;
        string input = "";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{7,5});
        getline(cin,input,'\n');
        ss1 << input;
        ss1 >> option;
        return option;
}*/

class View
{
    HANDLE u;
    public:
    View()
    {
        u = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(u, WHITE + 16*BLUE);
    }

    void ShowMenu()
    {
        system("CLS");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        cout << left << setfill('-') << setw(59) << "+Wybierz opcje" << "+" << endl;
        cout << left << setfill(' ') << setw(59) << "|1.Wylicz NWW i NWD" << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|2.Wypisz rozklad na czynniki pierwsze" << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|3.Wyjdz z programu" << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|" << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|Wybor: " << "|" << endl;
        cout << left << setfill('-') << setw(59) << "+" << "+" << endl;
    }

    void PrintPrimeSequence(map<int, int>* PrimeSeq)
    {
        system("CLS");
        int i = 1;
        cout << left << setfill('-') << setw(59) << "+"  << "+" << endl;
        for(auto &ele: *PrimeSeq)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,i});
            printf("|%d[%d] ", ele.first, ele.second);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{59,i});
            cout<<"|"<<endl;
            i++;
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,i});
        cout << left << setfill(' ') << setw(59) << "|Wcisnij enter aby kontynuowac"  << "|" << endl;
        cout << left << setfill('-') << setw(59) << "+"  << "+" << endl;
    }

    void PrintInputPrompt()
    {
        system("CLS");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        cout << left << setfill('-') << setw(59) << "+Wpisz wartosc (liczba naturalna, wieksz od 0)" << "+" << endl;
        cout << left << setfill(' ') << setw(59) << "|Wartosc: " << "|" << endl;
        cout << left << setfill('-') << setw(59) << "+" << "+" << endl;
    }

    void PrintConfirmation()
    {
        system("CLS");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        cout << left << setfill('-') << setw(59) << "+" << "+" << endl;
        cout << left << setfill(' ') << setw(59) << "|Wartosc przyjeta" << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|Wcisnij enter aby kontynuwac" << "|" << endl;
        cout << left << setfill('-') << setw(59) << "+" << "+" << endl;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,4});
    }

    void PrintNWWNWD(int NWW, int NWD, int Value1, int Value2)
    {
        system("CLS");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        cout << left << setfill('-') << setw(59) << "+" << "+" << endl;
        cout << left << setfill(' ') << setw(59) << "|liczba 1: " << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|liczba 2: " << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|NWW wprowadzonych liczb: " << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|NWD wprowadzonych liczb: " << "|" << endl;
        cout << left << setfill(' ') << setw(59) << "|Wcisnij enter by kontynuowac " << "|" << endl;
        cout << left << setfill('-') << setw(59) << "+" << "+" << endl;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{11,1});
        cout<<Value1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{11,2});
        cout<<Value2;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{25,3});
        cout<<NWW;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{25,4});
        cout<<NWD;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,7});
    }
};

class Model
{

    public:
    Model()
    {

    }

    void GeneratePrimeSequence(int number, map<int, int>* PrimeSeq)
    {
        int counter = 0;
        int prime = 0;
        for(int i = 1; i<= number; i = prime)

        {
            counter = 0;
            prime = GetNextPrime(i);
            while ( number > 1 )
            {
                if (number % prime == 0)
                {
                    number /= prime;
                    counter ++;
                }
                else
                    break;
            }
            PrimeSeq -> insert(make_pair(prime, counter));
        }
    }

    int NWWSeq(map<int, int>* Value1PrimeSeq, map<int, int>* Value2PrimeSeq)
    {
        int NWW = 1;
        if(Value1PrimeSeq -> size() < Value2PrimeSeq -> size())
        {
            map<int, int>* PrimeSeqTemp = Value1PrimeSeq;
            Value1PrimeSeq = Value2PrimeSeq;
            Value2PrimeSeq = PrimeSeqTemp;
        }

        for(auto it = Value1PrimeSeq -> begin(); it != Value1PrimeSeq -> end(); it++)
    {
        if(it -> second < (*Value2PrimeSeq)[it -> first])
        {
            NWW *= pow(it -> first, (*Value2PrimeSeq)[it -> first]);
        }
        else
        {
            NWW *= pow(it -> first,it -> second);
        }
    }
        return NWW;
    }

    int NWDSeq(map<int, int>* Value1PrimeSeq, map<int, int>* Value2PrimeSeq)
    {
    int NWD = 1;
    if(Value1PrimeSeq -> size() < Value2PrimeSeq -> size())
    {
        map<int, int>* PrimeSeqTemp = Value1PrimeSeq;
        Value1PrimeSeq = Value2PrimeSeq;
        Value2PrimeSeq = PrimeSeqTemp;
    }

    for(auto it = Value1PrimeSeq -> begin(); it != Value1PrimeSeq -> end(); it++)
    {
        if(it -> second > (*Value2PrimeSeq)[it -> first] )
        {
            NWD *= pow(it -> first, (*Value2PrimeSeq)[it -> first]);
        }
        else
        {
            NWD *= pow(it -> first,it -> second);
        }
    }
        return NWD;
    }

    private:
    int isPrime(int number)
    {
    int result = TRUE;
    int i;
    for(i = 2; i <= (int)sqrt((double)number); i ++)
        if (number % i == 0)
            {
            result = FALSE;
            break;
            }
    return result;
    }

    int GetNextPrime(int prevprime)
    {
    int i;
    for(i = prevprime+1; /* !isPrime(i) */;i ++)
        if (isPrime(i))
        {
            break;
        }
    return i;
    }
};

class Controller
{
    bool End = false;
    int option = 0;
    View* view = nullptr;
    Model* model = nullptr;
public:
    Controller(View* view, Model* model)
    {
       this -> view = view;
       this -> model = model;
    }

    int Start()
    {
        option = 0;
        while(option <= 0 || option > 3)
        {
        view -> ShowMenu();
        option = GetOption();
        }
        return option;
    }

    void Option1(int* Value1, int* Value2, map<int, int>* PrimeSeq1, map<int, int>* PrimeSeq2)
    {
        while(*Value1 <= 0)
        {
            view -> PrintInputPrompt();
            *Value1 = GetValue();
        }
        view -> PrintConfirmation();
        getchar();

        while(*Value2 <= 0)
        {
            view -> PrintInputPrompt();
            *Value2 = GetValue();
        }
        view -> PrintConfirmation();
        getchar();
        model ->GeneratePrimeSequence(*Value1, PrimeSeq1);
        model ->GeneratePrimeSequence(*Value2, PrimeSeq2);
        view -> PrintNWWNWD((model -> NWWSeq(PrimeSeq1, PrimeSeq2)),(model -> NWDSeq(PrimeSeq1, PrimeSeq2)), *Value1, *Value2);
        *Value1 = 0;
        *Value2 = 0;
        (*PrimeSeq1).clear();
        (*PrimeSeq2).clear();
        getchar();

    }

    void Option2(int* Value1, map<int, int>* PrimeSeq1)
    {
        while(*Value1 <= 0)
        {
            view -> PrintInputPrompt();
            *Value1 = GetValue();
        }
        view -> PrintConfirmation();
        getchar();
        model -> GeneratePrimeSequence(*Value1, PrimeSeq1);
        view -> PrintPrimeSequence(PrimeSeq1);
        *Value1 = 0;
        (*PrimeSeq1).clear();
        getchar();
    }

    int GetValue()
    {
        int Value = 0;
        stringstream ss1;
        string input = "";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{10,1});
        getline(cin,input,'\n');
        ss1 << input;
        ss1 >> Value;
        ss1.clear();
        ss1.str("");
        return Value;
    }

    int GetOption()
    {
        int option=0;
        stringstream ss1;
        string input = "";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{8,5});
        getline(cin,input,'\n');
        ss1 << input;
        ss1 >> option;
        ss1.clear();
        ss1.str("");
        return option;
    }

    bool GetEnd()
    {
        return this -> End;
    }

    void SetEnd()
    {
        End = true;
    }
};

int main()
{
int Value1=0;
int Value2=0;

map<int, int> Value1PrimeSeq;
map<int, int> Value2PrimeSeq;
View view;
Model model;
Controller controller = Controller(&view, &model);

while(!controller.GetEnd())
{
    switch(controller.Start())
    {
    case 1:
        controller.Option1(&Value1, &Value2, &Value1PrimeSeq, &Value2PrimeSeq);
    break;
    case 2:
        controller.Option2(&Value1, &Value1PrimeSeq);
    break;
    case 3:
        controller.SetEnd();
    }
}

return EXIT_OK;
}
