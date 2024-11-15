#include "Header.h"

void autorization()
{
    system("cls");

    bool Unpass = false;
    bool Unlogin = false;
    bool found = false;

    string line, line1;
    while (!Unlogin)
    {
        fs.clear();
        fs.seekg(0);
        string login = "";
        int x = 40, y = 12;

        GoToXY(x, y);
        cout << "Введите логин:" << endl;

        string Alogin;
        GoToXY(x, 13);
        cin >> Alogin;

        while (getline(fs, line))
        {
            login = line;

            if (Alogin == login)
            {
                found = true;
                Unlogin = true;
                system("cls");

                int x = 40, y = 12;
                GoToXY(x, y++);
                cout << "Введите пароль:" << endl;
                GoToXY(x, y++);
                string Apass = "";
                char ch;
                while ((ch = _getch()) != ENTER)
                {
                    if (ch == ESC)
                    {
                        Mainmenu();
                        return;
                    }
                    else if (ch == DOWN || ch == UP || ch == 76 || ch == 82)
                    {
                        cout << "\nОшибка" << endl;
                        return;
                    }
                    else if (ch != '\b')
                    {
                        Apass += ch;
                        cout << '*';
                    }
                    else if (!Apass.empty())
                    {
                        Apass.erase(Apass.size() - 1);
                        cout << "\b \b";
                    }
                }

                fs.clear();
                fs.seekg(0);
                int l = 0;
                int m = 1;
                
                string password = "";
                while (getline(fs, line1))
                {
                    if (l % 3 == 1 && Apass == line1 && Alogin == user[l / 3].login)
                    {

                        Unpass = true;
                        NUMOFUSER = l / 3;
                        system("cls");
                        GoToXY(x, y);
                        found = true;
                        cout << "Вы успешно вошли в аккаунт" << endl;
                        menuuser();
                        break;
                    }
                    l++;
                }

                if (!Unpass)
                {
                    system("cls");
                    GoToXY(x, y);
                    cout << "Неверно введен пароль" << endl;
                    _getch();
                }
            }
        }

        if (!found)
        {
            system("cls");
            GoToXY(x, y - 1);
            cout << "Данного пользователя не существует, попробуйте ввести другой логин" << endl;
            _getch();
        }
    }
}

