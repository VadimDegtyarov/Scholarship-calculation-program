#include "Header.h"

void Sort()
{
    CONST int MMENU_SIZE = 4;
    int active_menu = 1;
    string typesort[] = {"Выберите способ сортировки","1.Выполнить сортитровку студента по группе","2.Выполнить сортировку студента по форме обучения","3.Выполнить сортировку студента по имени" };
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
            cout << typesort[i] << endl;
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
                system("cls");
                string line = "";
                int student_count = 0;

                DataF.clear();
                DataF.seekg(0);
                while (getline(DataF, line)) 
                {
                    infstud.push_back(line);
                }

                vector<vector<string>> studData;
                for (int i = 0; i < infstud.size(); i += 4)
                {
                    vector<string> studInfo = { infstud[i], infstud[i + 1], infstud[i + 2], infstud[i + 3] };
                    studData.push_back(studInfo);
                }
                sort(studData.begin(), studData.end(), [](const vector<string>& a, const vector<string>& b)
                    { 
                        if (a[2] != b[2])
                        {
                            return a[2] > b[2];
                        }
                        else
                        {
                            return a[0] < b[0];
                        }
                    });

                    cout << setfill('-') << setw(116) << "" << endl;
                    cout << "|" << setw(15) << "Имя студента" << setw(10) << "|" << setw(15) << "Средний балл" << setw(10) << "|" << setw(15) << "Группа" << setw(10) << "|" << setw(30) << "Форма обучения" << setw(10) << "|" << endl;
                cout << setfill('-') << setw(116) << "" << endl;

                for (const auto& studInfo : studData)
                {
                    cout << "|" << setw(15) << studInfo[0] << setw(10) << "|";
                    cout << setw(15) << studInfo[1] << setw(10) << "|";
                    cout << setw(15) << studInfo[2] << setw(10) << "|";
                    cout << setw(30) << studInfo[3] << setw(10) << "|" << endl;
                }

                cout << setfill('-') << setw(116) << "" << endl;

                infstud.clear();
                _getch();
                menuuser();
            }
            else if (active_menu == 2)
            {
                system("cls");
                string line = "";
                int student_count = 0;

                DataF.clear();
                DataF.seekg(0);
                while (getline(DataF, line)) 
                {
                    infstud.push_back(line);
                }

                vector<vector<string>> studData;
                for (int i = 0; i < infstud.size(); i += 4)
                {
                    vector<string> studInfo = { infstud[i], infstud[i + 1], infstud[i + 2], infstud[i + 3] };
                    studData.push_back(studInfo);
                }

                sort(studData.begin(), studData.end(), [](const vector<string>& a, const vector<string>& b)
                    {
                       
                        int cmp = a[3].compare(b[3]);
                        if (cmp != 0)
                        {
                            return cmp < 0;
                        }
                        else
                        {
                            
                            return a[0] < b[0];
                        }
                    });

                cout << setfill('-') << setw(116) << "" << endl;
                cout << "|" << setw(15) << "Имя студента" << setw(10) << "|" << setw(15) << "Средний балл" << setw(10) << "|" << setw(15) << "Группа" << setw(10) << "|" << setw(30) << "Форма обучения" << setw(10) << "|" << endl;
                cout << setfill('-') << setw(116) << "" << endl;

                for (const auto& studInfo : studData)
                {
                    cout << "|" << setw(15) << studInfo[0] << setw(10) << "|";
                    cout << setw(15) << studInfo[1] << setw(10) << "|";
                    cout << setw(15) << studInfo[2] << setw(10) << "|";
                    cout << setw(30) << studInfo[3] << setw(10) << "|" << endl;
                }

                cout << setfill('-') << setw(116) << "" << endl;

                infstud.clear();
                _getch();
                menuuser();

            }

            else if (active_menu == 3)
            {
                system("cls");
                string line = "";
                int student_count = 0;

                DataF.clear();
                DataF.seekg(0);
                while (getline(DataF, line))
                {
                    infstud.push_back(line);
                }

                vector<vector<string>> studData;
                for (int i = 0; i < infstud.size(); i += 4)
                {
                    vector<string> studInfo = { infstud[i], infstud[i + 1], infstud[i + 2] , infstud[i + 3] };
                    studData.push_back(studInfo);
                }

                sort(studData.begin(), studData.end(), [](const vector<string>& a, const vector<string>& b)
                    {
                        
                        int cmp = a[0].compare(b[0]);
                        if (cmp != 0)
                        {
                            return cmp < 0;
                        }
                        else
                        {
                            
                            return a[2] < b[2];
                        }
                    });

                cout << setfill('-') << setw(116) << "" << endl;
                cout << "|" << setw(15) << "Имя студента" << setw(10) << "|" << setw(15) << "Средний балл" << setw(10) << "|" << setw(15) << "Группа" << setw(10) << "|" << setw(30) << "Форма обучения" << setw(10) << "|" << endl;
                cout << setfill('-') << setw(116) << "" << endl;

                for (const auto& studInfo : studData)
                {
                    cout << "|" << setw(15) << studInfo[0] << setw(10) << "|";
                    cout << setw(15) << studInfo[1] << setw(10) << "|";
                    cout << setw(15) << studInfo[2] << setw(10) << "|";
                    cout << setw(30) << studInfo[3] << setw(10) << "|" << endl;
                }

                cout << setfill('-') << setw(116) << "" << endl;

                infstud.clear();
                _getch();
                menuuser();

            }

            break;
        }
    }

}