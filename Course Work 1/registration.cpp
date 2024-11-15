#include"Header.h"

void registration()
{
    int x = 40, y = 12;

    vector<string> reg = { "Введите логин:" ,"Введите пароль" };
    string linech;
    bool chlog = false, chpass = false;
    fs.clear();
    fs.seekg(0);
    int i = 0;
    userinstruct.login = "0";
    userinstruct.changelogin = "0";
    user.push_back(userinstruct);
    for (int i = 0; i <reg.size(); i++)
    {
        system("cls");
        GoToXY(x, y++);
        cout << reg[i] << endl;
        while (!chlog)
        {
           
            if (i == 0)
            {
                system("cls");
                GoToXY(x, 12);
                cout << reg[i] << endl;
                GoToXY(x, 13);
                string inputuser;
                cin >> inputuser;

                for (int j = 0; j < user.size(); j++)
                {
                    if (inputuser == user[j].login)
                    {
                        system("cls");
                        GoToXY(x, 12);
                        cout << "Данный логин уже используется,выберите другой" << endl;
                        GoToXY(x, 13);
                        cout << "Для продолжения нажмите любую клавишу..." << endl;
                        _getch();
                        break;
                    }
                    else if (j == user.size() - 1&& inputuser != user[j].login)
                    {
                        userinstruct.login = inputuser;
                        chlog = true;
                        i++;
                        break;
                        
                    }
                }

            }
        }
        while (!chpass)
        {
            if (i == 1)
            {
                system("cls");
                GoToXY(x, 12);
                cout << reg[i] << endl;
                GoToXY(x, 13);
                string password = "";
                char ch;
               
                while ((ch = _getch()) != ENTER) {
                    if (ch == ESC) {
                        Mainmenu();
                        return;
                    }
                    else if (ch == DOWN || ch == UP || ch == 76 || ch == 82) {
                        cout << "\nОшибка" << endl;
                        return;
                    }
                    else if (ch != '\b') {
                        password += ch;
                        cout << '*';
                    }
                    else if (!password.empty()) {
                        password.erase(password.size() - 1);
                        cout << "\b \b";
                    }
                }
               password;

                for (int j = 0; j < user.size(); j++)
                {

                    if (password.size() < 8)
                    {
                        GoToXY(x, y++);
                        cout << "Пароль слишком короткий,введите пароль больше 8 символов" << endl;
                        _getch();
                        break;
                    }
                    else if (j == user.size() - 1 && password != user[j].changelogin)
                    {
                        userinstruct.changelogin = password;
                        chpass = true;
                        i++;
                        break;

                    }
                }

            }
        }

        fs.clear();
        user.push_back(userinstruct);
        for (int i = 0; i < user.size(); i++)
        {
            fs << user[i].login << endl;
            fs << user[i].changelogin << endl;
            fs << user[i].isadmin << endl;
        }   


        GoToXY(x, y++);
        cout << "Нажмите ENTER для продолжения" << endl;

        GoToXY(x, y + 2);
        cout << "Регистрация прошла успешно!" << endl;

        char ch;
        while (true) {
            ch = _getch();
            if (ch == ENTER) {
                Mainmenu();
            }
        }
     

    }
}
