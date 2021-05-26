// Перевірити, чи елементи списку – впорядковані за не спаданням.
#include <iostream>
#include <Windows.h>
#include <time.h>

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

using namespace std;
void insert(Elem*& L, Info value);
bool check(Elem* L);
void Print(Elem* L);


int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
    Elem* L = NULL;
    Info num;
    for (int i = 1; i <= 10; i++) {
        num = 1 + rand() % 10;
        insert(L, num);
    }
    cout << endl;
    Print(L);
    if (check(L)) { // перевірка на те, як елементи впорядковані
        cout << "Елементи впорядковані не за спаданням!" << endl << endl; // якщо елементи не впорядковані за спаданням
    }
    else {
        cout << "Елементи впорядковані за спаданням!" << endl << endl;  // якщо елементи впорядковані за спаданням
    }

}


void insert(Elem*& L, Info value) 
{
    Elem* tmp = new Elem; 
    tmp->info = value;
    if (L != NULL) 
    {
        Elem* T = L; 
        while (T->link != L) 
            T = T->link;
        T->link = tmp;
    }
    else 
    {
        L = tmp;
    }
    tmp->link = L;
}

bool check(Elem* L) {
    Elem* start = L;
    Info value = L->info;
    while (L->link != start)
    {
        L = L->link;
        if (L->info <= value) { 
            value = L->info;
        }
        else {
            return true;  
        }
    }
    return false; 
}


void Print(Elem* L) {
    if (L == NULL)
        return;
    Elem* first = L;
    cout << L->info << " ";
    while (L->link != first)
    {
        L = L->link;
        cout << L->info << " ";
    }
    cout << endl;
}