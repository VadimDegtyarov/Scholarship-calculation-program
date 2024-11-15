#include "Header.h"


void OutputInfo()
{
    system("cls");
    string line="";
    DataF.clear();
    DataF.seekg(0);
    while (getline(DataF, line)) 
    {
        infstud.push_back(line);
        
    }


    cout << setfill('-') << setw(116) << "" << endl;
    cout << "|" <<setw(15)<< "Имя студента" << setw(10) << "|" << setw(15) << "Средний балл" << setw(10) << "|" << setw(15) << "Группа" << setw(10) << "|" << setw(30) << "Форма обучения" << setw(10) << "|" << endl;
    cout << setfill('-') << setw(116) << "" << endl;


    for (int i = 0; i < infstud.size(); i += 4)
    {
        cout << "|" << setw(15) << infstud[i] << setw(10) << "|"; 
        cout << setw(15) << infstud[i + 1] << setw(10) << "|";
        cout << setw(15) << infstud[i + 2] << setw(10) << "|"; 
        cout << setw(30) << infstud[i + 3] << setw(10) << "|" << endl; 
    }


    cout << setfill('-') << setw(116) << "" << endl;
    
    infstud.clear();
    _getch();
    menuuser();
}
