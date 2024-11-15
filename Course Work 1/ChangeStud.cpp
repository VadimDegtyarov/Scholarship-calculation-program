#include "Header.h"



void ChangeStud()
{
    vector<string> Mainmenu = { "Данные какого пользователя Изменить?", };
    for (int i = 1; i < user.size(); i++) {
        Mainmenu.push_back(user[i].login);
    }
    int active_menu = 1;
    while (true) {
        system("cls");
        int x = 40, y = 12;
        for (int i = 0; i < Mainmenu.size(); i++)
        {
            if (i == active_menu)
            {
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                GoToXY(35, y);
                cout << ">";
            }
            else
                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

            GoToXY(x, y++);
            cout << Mainmenu[i] << endl;
        }
        GoToXY(x, y++);

        char ch = _getch();
        switch (ch) {
        case UP:
            if (active_menu == 1)
            {
                active_menu = Mainmenu.size() - 1;
            }
            else {
                active_menu--;
            }
            break;

        case DOWN:
            if (active_menu == (Mainmenu.size() - 1))
            {
                active_menu = 1;
            }
            else
            {
                active_menu++;
            }

            break;

        case ESC:
            menuuser();
            break;

        case ENTER:
        {
            system("cls");
            ConsoleCursorVisible(0, true);
            for (int i = 0; i < Mainmenu.size(); i++) {
                if (user[active_menu].login == Mainmenu[i])
                {
                    vector<string> student = { "Какие данные хотите изменить?","Логин","Пароль","Наличие прав администратора" };
                    int active_menu_2 = 1;
                    while (true) {
                        system("cls");
                        int x = 40, y = 12;
                        for (int i = 0; i < student.size(); i++)
                        {
                            if (i == active_menu_2)
                            {
                                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                GoToXY(35, y);
                                cout << ">";
                            }
                            else
                                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

                            GoToXY(x, y++);
                            cout << student[i] << endl;
                        }
                        GoToXY(x, y++);

                        char ch = _getch();
                        switch (ch)
                        {
                        case UP:
                            if (active_menu_2 == 1)
                            {
                                active_menu_2 = student.size() - 1;
                            }
                            else {
                                active_menu_2--;
                            }
                            break;

                        case DOWN:
                            if (active_menu_2 == (student.size() - 1))
                            {
                                active_menu_2 = 1;
                            }
                            else
                            {
                                active_menu_2++;
                            }

                            break;

                        case ESC:
                            menuuser();
                            break;

                        case ENTER:
                        {
                            if (active_menu_2 == 1)
                            {
                                string& changelogin = user[active_menu].login;
                                const int maxSize = 20;
                                int currentPos = changelogin.size();
                                string line2 = "";
                                fs.clear();
                                fs.seekg(0);
                                string newlogin = changelogin;
                                while (true) {
                                    system("cls");
                                    cout << "Введите новый логин (до " << maxSize << " символов): ";
                                    cout << changelogin;

                                    char ch = _getch();

                                    if (ch == ESC) {
                                        ChangeStud();
                                        return;
                                    }
                                    else if (ch == ENTER) {
                                        break;
                                    }
                                    else if (ch == DOWN || ch == UP || ch == 76 || ch == 82) {
                                        cout << "\nОшибка" << endl;
                                        return;
                                    }
                                    else if (ch == '\b') {
                                        if (currentPos > 0) {
                                            currentPos--;
                                            changelogin.erase(currentPos, 1);
                                        }
                                    }
                                    else if (changelogin.size() < maxSize) {
                                        changelogin.insert(currentPos, 1, ch);
                                        currentPos++;
                                    }
                                }
                                int str = 0;
                                fs.seekg(0);
                                fs.clear();
                                fs.close();
                                string path = "Users.txt", Data = "Data.txt";

                                fs.open(path, fstream::in | fstream::out);

                                user[active_menu].login = changelogin;
                                while (str < user.size())
                                {
                                    fs << user[str].login << endl;
                                    fs << user[str].changelogin << endl;
                                    fs << user[str].isadmin << endl;
                                    str++;
                                }

                                fs.close();
                                fs.open(path, fstream::in | fstream::out | fstream::app);



                                system("cls");
                                GoToXY(0, wherey());
                                cout << "Логин изменен успешно!" << endl;
                                Sleep(1000);
                                ChangeStud();
                            }
                            if (active_menu_2 == 2)
                            {
                                string& changepass = user[active_menu].changelogin;
                                const int maxSize = 20;
                                int currentPos = changepass.size();
                                string line2 = "";
                                fs.clear();
                                fs.seekg(0);
                                string newlogin = changepass;
                                while (true) {
                                    system("cls");
                                    cout << "Введите новый пароль (минимум до " << maxSize << " символов): ";
                                    cout << changepass;

                                    char ch = _getch();

                                    if (ch == ESC) {
                                        ChangeStud();
                                        return;
                                    }
                                    else if (ch == ENTER) {
                                        break;
                                    }
                                    else if (ch == DOWN || ch == UP || ch == 76 || ch == 82) {
                                        cout << "\nОшибка" << endl;
                                        return;
                                    }
                                    else if (ch == '\b') {
                                        if (currentPos > 0) {
                                            currentPos--;
                                            changepass.erase(currentPos, 1);
                                        }
                                    }
                                    else if (changepass.size() < maxSize) {
                                        changepass.insert(currentPos, 1, ch);
                                        currentPos++;
                                    }
                                }
                                int str = 0;
                                fs.seekg(0);
                                fs.clear();
                                fs.close();
                                string path = "Users.txt", Data = "Data.txt";

                                fs.open(path, fstream::in | fstream::out);

                                user[active_menu].changelogin = changepass;
                                while (str < user.size())
                                {
                                    fs << user[str].login << endl;
                                    fs << user[str].changelogin << endl;
                                    fs << user[str].isadmin << endl;
                                    str++;
                                }

                                fs.close();
                                fs.open(path, fstream::in | fstream::out | fstream::app);



                                system("cls");
                                GoToXY(0, wherey());
                                cout << "Пароль изменен успешно!" << endl;
                                Sleep(1000);
                                ChangeStud();
                            }
                            if (active_menu_2 == 3)
                            {
                                vector<string> student1 = { "Данный пользователь админ?","Да","Нет" };
                                int active_menu_3 = 1;
                                while (true) {
                                    system("cls");
                                    int x = 40, y = 12;
                                    for (int i = 0; i < student1.size(); i++)
                                    {
                                        if (i == active_menu_3)
                                        {
                                            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                            GoToXY(35, y);
                                            cout << ">";
                                        }
                                        else
                                            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

                                        GoToXY(x, y++);
                                        cout << student1[i] << endl;
                                    }
                                    GoToXY(x, y++);

                                    char ch = _getch();
                                    switch (ch)
                                    {
                                    case UP:
                                        if (active_menu_3 == 1)
                                        {
                                            active_menu_3 = student1.size() - 1;
                                        }
                                        else {
                                            active_menu_3--;
                                        }
                                        break;

                                    case DOWN:
                                        if (active_menu_3 == (student1.size() - 1))
                                        {
                                            active_menu_3 = 1;
                                        }
                                        else
                                        {
                                            active_menu_3++;
                                        }

                                        break;

                                    case ESC:
                                        menuuser();
                                        break;

                                    case ENTER:
                                    {
                                        if (active_menu_3 == 1)
                                        {
                                            int str = 0;
                                            fs.seekg(0);
                                            fs.clear();
                                            fs.close();
                                            string path = "Users.txt", Data = "Data.txt";

                                            fs.open(path, fstream::in | fstream::out);

                                            user[active_menu].isadmin = 1;
                                            while (str < user.size())
                                            {
                                                fs << user[str].login << endl;
                                                fs << user[str].changelogin << endl;
                                                fs << user[str].isadmin << endl;
                                                str++;
                                            }

                                            fs.close();
                                            fs.open(path, fstream::in | fstream::out | fstream::app);
                                            cout << "Данные пользователя изменены" << endl;
                                            Sleep(2000);
                                            ChangeStud();
                                        }
                                        else if (active_menu_3 == 2)
                                        {
                                            int str = 0;
                                            fs.seekg(0);
                                            fs.clear();
                                            fs.close();
                                            string path = "Users.txt", Data = "Data.txt";

                                            fs.open(path, fstream::in | fstream::out);

                                            user[active_menu].isadmin = 0;
                                            while (str < user.size())
                                            {
                                                fs << user[str].login << endl;
                                                fs << user[str].changelogin << endl;
                                                fs << user[str].isadmin << endl;
                                                str++;
                                            }

                                            fs.close();
                                            fs.open(path, fstream::in | fstream::out | fstream::app);
                                            cout << "Данные пользователя изменены" << endl;
                                            Sleep(2000);
                                            ChangeStud();
                                            
                                        }


                                    }
                                    }
                                }
                            }



                        }

                        }

                    }
                    break;
                }
            }
        }
        }
    }
}