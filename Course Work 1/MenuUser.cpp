    #include"Header.h"


void menuuser()
    {
        ConsoleCursorVisible(false, 100);
        int num = NUMOFUSER;
        vector <string> menu;
        if (!user[num].isadmin)
        {
            menu = { "Меню:", "1.Вывести данные о студентах","2.Выполнить поиск студента","3.Выполнить сортитровку студентов","4.Рассчитать стипендию студента","5.Вернуться в главное меню" };
        }
        else if (user[num].isadmin)
        {
            menu = { "Меню:", "1.Ввести данные о студенте", "2.Вывести данные о студентах","3.Выполнить поиск студента","4.Выполнить сортитровку студентов","5.Рассчитать стипендию студента","6.Изменить данные пользователей","7.Вернуться в главное меню"};
        }
        int active_menu = 1;
        while (true) {
            system("cls");
            int x = 40, y = 12;
            for (int i = 0; i < menu.size(); i++)
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
                cout << menu[i] << endl;
                }
            GoToXY(x, y++);

            char ch = _getch();
            switch (ch) {
            case UP:
                if (active_menu == 1) {
                    active_menu = menu.size() - 1;
                }
                else {
                    active_menu--;
                }
                break;

            case DOWN:
                if (active_menu == menu.size()- 1) {
                    active_menu = 1;
                }
                else {
                    active_menu++;
                }

                break;

            case ESC:
                Mainmenu();
                break;

            case ENTER:
                if (user[num].isadmin)
                {
                    if (active_menu == 1)
                    {
                        InputInfo();
                    }
                    if (active_menu == 2)
                    {
                        OutputInfo();
                    }
                    else if (active_menu == 3)
                    {
                        Search();
                    }
                    else if (active_menu == 4)
                    {
                        system("cls");
                        Sort();

                    }
                    else if (active_menu == 5)
                    {
                        Schship();
                    }

                    else if (active_menu == 6)
                    {
                        ChangeStud();
                    }
                    else if (active_menu == 7)
                    {
                        Mainmenu();
                    }
                } 
                    
                else
                {
                if (active_menu == 1)
                {
                    OutputInfo();
                }

                else if (active_menu == 2)
                {

                    Search();
                }
                else if (active_menu == 3)
                {
                    system("cls");
                    Sort();

                }
                else if (active_menu == 4)
                {
                    Schship();
                }
                else if (active_menu == 5)
                {

                    Mainmenu();
                }
                }
                break;
            }

        }
    }