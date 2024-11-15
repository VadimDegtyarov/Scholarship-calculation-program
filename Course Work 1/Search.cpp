#include "Header.h"

void Search()
{
    system("cls");
    CONST int MMENU_SIZE = 4;


    string arrsearch[MMENU_SIZE] = { "�������� ������ ������ ��������:", "1.��������� ����� �������� �� ������", "2.��������� ����� �������� �� ����� ��������","3.��������� ����� �������� �� �����" };




    int active_menu = 1;
    while (true) {
        system("cls");
        int x = 40, y = 12;
        for (int i = 0; i < MMENU_SIZE; i++)
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
            cout << arrsearch[i] << endl;
        }
        GoToXY(x, y++);

        char ch = _getch();
        switch (ch) {
        case UP:
            if (active_menu == 1) {
                active_menu = MMENU_SIZE - 1;
            }
            else {
                active_menu--;
            }
            break;
            
        case DOWN:
            if (active_menu == MMENU_SIZE - 1) {
                active_menu = 1;
            }
            else {
                active_menu++;
            }

            break;

        case ESC:
            menuuser();
            break;

        case ENTER:
            if (active_menu == 1)
            {
                string sch, inputsch;
                infstud.clear();
                DataF.clear();
                DataF.seekg(0);
                bool check = false;
                while (getline(DataF, sch))
                {
                    infstud.push_back(sch);
                }
                while (!check)
                {
                    x = 40, y = 12;
                    system("cls");
                    GoToXY(x, y);
                    cout << "������� ������ ��������" << endl;
                    GoToXY(x, 13);
                    cin >> inputsch;
                    vector<int>srchgroup;
                    for (int i = 0; i < infstud.size(); i++)
                    {
                        if (inputsch == infstud[i])
                        {

                            srchgroup.push_back(i);

                        }
                        if (i == infstud.size() - 1)
                        {
                            system("cls");
                            x = 40, y = 12;
                            GoToXY(x, y);
                            cout << "������ ��������� �� ������ " << inputsch << ":" << endl;
                            check = true;
                            cout << setfill('-') << setw(116) << "" << endl;
                            cout << "|" << setw(15) << "��� ��������" << setw(10) << "|" << setw(15) << "������� ����" << setw(10) << "|" << setw(15) << "������" << setw(10) << "|" << setw(30) << "����� ��������" << setw(10) << "|" << endl;
                            cout << setfill('-') << setw(116) << "" << endl;


                            for (int i = 0; i < srchgroup.size(); i++)
                            {
                                cout << "|" << setw(15) << infstud[srchgroup[i] - 2] << setw(10) << "|";
                                cout << "|" << setw(15) << infstud[srchgroup[i] - 1] << setw(10) << "|";
                                cout << setw(15) << infstud[srchgroup[i]] << setw(10) << "|";
                                cout << setw(30) << infstud[srchgroup[i] + 1] << setw(10) << "|" << endl;
                            }


                            cout << setfill('-') << setw(116) << "" << endl;
                            _getch();
                            menuuser();
                        }
                    }
                    if (!check)
                    {
                        system("cls");
                        cout << "������ �������� � ���� ������ �� ����������,������� ������ ���" << endl;

                    }

                }
                infstud.clear();
            }
            else if (active_menu == 2)
            {
                int active_menu1 = 1;
                CONST int SIZEFORM = 3;
                string FormTeachsrch[SIZEFORM] = { "�������� ����� ��������:","���������� ����� ��������" ,"������� ����� ��������" };
                while (true)
                {
                    system("cls");
                    int x = 40, y = 12;
                    for (int i = 0; i < SIZEFORM; i++)
                    {
                        if (i == active_menu1)
                        {
                            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                            GoToXY(39, y);
                            cout << ">";
                        }
                        else
                            SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

                        GoToXY(x, y++);
                        cout << FormTeachsrch[i] << endl;
                    }
                    GoToXY(x, y++);

                    char ch = _getch();
                    switch (ch) {
                    case UP:
                        if (active_menu1 == 1)
                        {
                            active_menu1 = SIZEFORM - 1;
                        }
                        else
                        {
                            active_menu1--;
                        }
                        break;

                    case DOWN:
                        if (active_menu1 == SIZEFORM - 1)
                        {
                            active_menu1 = 1;
                        }
                        else
                        {
                            active_menu1++;
                        }

                        break;

                    case ESC:

                        menuuser();

                        break;

                    case ENTER:
                    {
                        string sch, inputsch;
                        if (active_menu1 == 1)
                        {
                            inputsch = "����� �������� ����������";
                        }
                        else if (active_menu1 == 2)
                        {
                            inputsch = "����� �������� �������";
                        }
                        infstud.clear();
                        DataF.clear();
                        DataF.seekg(0);
                        bool check = false;
                        while (getline(DataF, sch))
                        {
                            infstud.push_back(sch);
                        }
                        while (!check)
                        {
                            x = 40, y = 12;
                            system("cls");
                            vector<int>srchgroup;
                            for (int i = 0; i < infstud.size(); i++)
                            {
                                if (inputsch == infstud[i])
                                {

                                    srchgroup.push_back(i);

                                }
                                if (i == infstud.size() - 1)
                                {
                                    system("cls");
                                    x = 40, y = 12;
                                    GoToXY(x, y);
                                    cout << "��������, ��� " << inputsch << endl;
                                    check = true;
                                    cout << setfill('-') << setw(116) << "" << endl;
                                    cout << "|" << setw(15) << "��� ��������" << setw(10) << "|" << setw(15) << "������� ����" << setw(10) << "|" << setw(15) << "������" << setw(10) << "|" << setw(30) << "����� ��������" << setw(10) << "|" << endl;
                                    cout << setfill('-') << setw(116) << "" << endl;


                                    for (int i = 0; i < srchgroup.size(); i++)
                                    {
                                        cout << "|" << setw(15) << infstud[srchgroup[i] - 3] << setw(10) << "|";
                                        cout << setw(15) << infstud[srchgroup[i] - 2] << setw(10) << "|";
                                        cout << setw(15) << infstud[srchgroup[i] - 1] << setw(10) << "|";
                                        cout << setw(30) << infstud[srchgroup[i]] << setw(10) << "|" << endl;
                                    }


                                    cout << setfill('-') << setw(116) << "" << endl;
                                    cout << "\n" << "��� ����������� ������� ����� �������..." << endl;
                                    _getch();
                                    menuuser();
                                }
                            }
                            if (!check)
                            {
                                system("cls");
                                cout << "������ �������� � ���� ������ �� ����������,������� ������ ���" << endl;

                            }

                        }
                        infstud.clear();

                    }








                    }
                }
            }

            else if (active_menu == 3)
            {

                string sch, inputsch;
                infstud.clear();
                DataF.clear();
                DataF.seekg(0);
                bool check = false;
                while (getline(DataF, sch))
                {
                    infstud.push_back(sch);
                }
                while (!check)
                {
                    x = 40, y = 12;
                    system("cls");
                    GoToXY(x, y);
                    cout << "������� ��� ��������" << endl;
                    GoToXY(x, 13);
                    cin >> inputsch;
                    for (int i = 0; i < infstud.size(); i++)
                    {
                        if (inputsch == infstud[i])
                        {
                            system("cls");
                            x = 40, y = 12;
                            GoToXY(x, y);
                            cout << "������ �������� � ������ " << inputsch << ":" << endl;
                            check = true;
                            cout << setfill('-') << setw(116) << "" << endl;
                            cout << "|" << setw(15) << "��� ��������" << setw(10) << "|" << setw(15) << "������� ����" << setw(10) << "|" << setw(15) << "������" << setw(10) << "|" << setw(30) << "����� ��������" << setw(10) << "|" << endl;
                            cout << setfill('-') << setw(116) << "" << endl;
                            cout << "|" << setw(15) << infstud[i] << setw(10) << "|";
                            cout << setw(15) << infstud[i+1] << setw(10) << "|";
                            cout << setw(15) << infstud[i + 2] << setw(10) << "|";
                            cout << setw(30) << infstud[i + 3] << setw(10) << "|" << endl;
                            cout << setfill('-') << setw(116) << "" << endl;
                            cout << "\n" << "��� ����������� ������� ����� �������..." << endl;
                            _getch();
                            menuuser();
                        }
                    }
                    if (!check)
                    {
                        system("cls");
                        cout << "������ �������� � ���� ������ �� ����������,������� ������ ���" << endl;

                    }

                }
                infstud.clear();
            }

            break;
        }
    }
}
