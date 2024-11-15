#include "Header.h"


void InputInfo()
{
    system("cls");

    infstud.clear();
    int x = 40, y = 12;
    GoToXY(x, y++);
    cout << "Введите Имя студента" << endl;
    GoToXY(x, y++);
    cin >> infoinstruct.Name;
    infstud.push_back(infoinstruct.Name);

    GoToXY(x, y++);
    cout << "Введите средний балл студента" << endl;
    GoToXY(x, y++);
    bool flagscore = true, flagscore1 = true;
    bool isNumeric = true;
    while (flagscore && flagscore1)
    {
       
        cin >> infoinstruct.scores;

        isNumeric = true; 

        for (int i = 0; i < infoinstruct.scores.size(); i++)
        {
            if (!isdigit(infoinstruct.scores[i]))
            {
                isNumeric = false;
                break;
            }
           
        }

        if (!isNumeric)
        {
            GoToXY(x, y++);
            cout << "Средний бал должен быть числом" << endl;
            continue;
        }
        else
        {
            flagscore1 = false;
        }

        int score = stoi(infoinstruct.scores);
        if (score > 10 || score < 1)
        {
            GoToXY(x, y++);
            cout << "Средний балл должен находиться в диапазоне от 1 до 10" << endl;
            flagscore = true; flagscore1 = true;
             isNumeric = true;
        }
        else
        {
            infstud.push_back(infoinstruct.scores);
        }
        
    }
        
    
    
    

    


    GoToXY(x, y++);
    cout << "Введите группу студента" << endl;
    GoToXY(x, y++);
    cin >> infoinstruct.group;
    infstud.push_back(infoinstruct.group);

    GoToXY(x, y++);


    int active_menu = 1;
    CONST int SIZEFORM = 3;
    string FormTeach[SIZEFORM]={ "Выберите форму обучения:","Бесплатная форма обучения" ,"Платная форма обучения" };
    while (true) {
        system("cls");
        int x = 40, y = 12;
        for (int i = 0; i < SIZEFORM; i++)
        {
            if (i == active_menu)
            {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                GoToXY(39, y);
                cout << ">";
            }
            else
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

            GoToXY(x, y++);
            cout << FormTeach[i] << endl;
        }
        GoToXY(x, y++);

        char ch = _getch();
        switch (ch) {
        case UP:
            if (active_menu == 1) 
            {
                active_menu = SIZEFORM - 1;
            }
            else 
            {
                active_menu--;
            }
            break;

        case DOWN:
            if (active_menu == SIZEFORM - 1) 
            {
                active_menu = 1;
            }
            else 
            {
                active_menu++;
            }

            break;

        case ESC:

            exit(0);

            break;

        case ENTER:
            if (active_menu == 1)
            {
                infoinstruct.FormOfEducation = true;
                
            }
            else if (active_menu == 2)
            {
                infoinstruct.FormOfEducation = false;
            }
            if (infoinstruct.FormOfEducation)
            {
                infstud.push_back("Форма обучения Бесплатная");
            }
            else
            {
                infstud.push_back("Форма обучения Платная");
            }
            DataF.clear();
            for (int i = 0; i < infstud.size(); i++)
            {
                DataF << infstud[i] << endl;
            }

            infstud.clear();
            infoinstruct.Name = "";
            infoinstruct.group = "";
            system("cls");
            GoToXY(30, y);
            cout << "Данные успешно введены,нажмите любую клавишу для продолжения" << endl;

            _getch();
            menuuser();

            break;
        }
    }

}