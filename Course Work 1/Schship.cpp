#include"Header.h"
void Schship()
{
    int x = 40, y = 12;
    bool flag = false;
    string schcheck,namestud;
    float score;
    float schship = 112.58;
    DataF.clear();
    DataF.seekg(0);
    while (getline(DataF, schcheck)) 
    {
        infstud.push_back(schcheck);
    }
    system("cls");
    GoToXY(x, y);
    cout << "Введите имя студента,чью стипендию хотите узнать" << endl;
    GoToXY(x, 13);
    cin.ignore();
    cin >> namestud;
    for (int i = 0; i < infstud.size(); i++)
    {   
        if (namestud == infstud[i])
        {
            flag = true;
            if (infstud[i + 3] == "Форма обучения Бесплатная")
            {
                system("cls");
                GoToXY(x, 13);
                score = stof(infstud[i + 1]);
                if (score >= 6 && score < 7)
                {
                    cout << "Стипендия студента с именем " << infstud[i] << " Составляет " << schship << endl;
                }
                else if (score >= 7 && score < 8)
                {
                    schship *= 1.1;
                    cout << "Стипендия студента с именем " << infstud[i] << " Составляет " << schship << endl;
                }
                else if (score >= 8 && score < 9)
                {
                    schship *= 1.3;
                    cout << "Стипендия студента с именем " << infstud[i] << " Составляет " << schship << endl;
                }
                else if (score >= 9 && score <= 10)
                {
                    schship *= 1.5;
                    cout << "Стипендия студента с именем " << infstud[i] << " Составляет " << schship << endl;
                }
                else
                {
                    GoToXY(x, 14);
                    cout << "Данный студент не получает стипендию" << endl;
                }
            }
            else
            {
                cout <<"Данный студент не получает стипендию" << endl;
            }

            _getch();

            break;
        }
    }
    if (!flag)
    {
        system("cls");
        GoToXY(40, 12);
        cout << "Данного студента не существует" << endl;
        _getch();

    }
        

}