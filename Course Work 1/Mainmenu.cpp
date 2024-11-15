#include "Header.h"

int wherey() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

void GoToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, { x,y });
}
void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}



void Mainmenu()
{
    fs.clear();
    fs.seekg(0);
    string sravn;
    bool checkfileflag=false;
    vector<string>sravnfile;



    if (fs.peek() == EOF)
    {
        checkfileflag = true;
    }
    while (getline(fs, sravn))
    {
        if (checkfileflag)
        {
           
            break;
        }
        sravnfile.push_back(sravn);
    }
    for (int i = 0; i < sravnfile.size()-1; i++)
    {
        if (checkfileflag)
        {
            break;
        }
        cout << sravnfile[i] << endl;
        userinstruct.login = sravnfile[i];
        i++;
        cout << sravnfile[i] << endl;
        userinstruct.changelogin = sravnfile[i];
        i++;
        cout << sravnfile[i] << endl;
        if (sravnfile[i] == "0") { userinstruct.isadmin = false; }
        else if (sravnfile[i] == "1"){ userinstruct.isadmin = true; }
        user.push_back(userinstruct);
    }






    const int MENU_SIZE = 4;
    string Mainmenu[] = { "Меню:", "1. Регистрация", "2. Войти","3.Закончить работу" };
    int active_menu = 1;
    while (true) {
        system("cls");
        int x = 40, y = 12;
        for (int i = 0; i < MENU_SIZE; i++)
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
                active_menu = MENU_SIZE - 1;
            }
            else {
                active_menu--;
            }
            break;

        case DOWN:
            if (active_menu == MENU_SIZE - 1) 
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
                registration();
            else if (active_menu == 2) {
                system("cls");
                if (checkfileflag)
                {
                    const int size = 2;
                    string arr[size] = { "Да", "Нет" };
                    int active_menu1 = 0;
                    while (true)
                    {
                        system("cls");
                        int x = 40, y = 12;

                        GoToXY(35, 5);
                        cout << "Отсутствуют зарегистрированные пользователи" << endl;
                        GoToXY(45, 6);
                        cout << "Желаете зарегистрировать?" << endl;
                        for (int i = 0; i < size; i++)
                        {
                            if (i == active_menu1 && arr[i] == "Нет")
                            {
                                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                                GoToXY(57, y);
                                cout << ">";
                            }
                            else if (i == active_menu1 && arr[i] == "Да")
                            {
                                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                                GoToXY(47, y);
                                cout << ">";
                            }
                            else
                            {
                                SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                            }




                            GoToXY(x += 10, y);
                            cout << arr[i] << endl;
                        }
                        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        GoToXY(x, y++);
                        char ch1 = _getch();
                        switch (ch1)
                        {
                        case UP:
                            if (active_menu1 == 0)
                            {
                                active_menu1 = size - 1;
                            }
                            else {
                                active_menu1--;
                            }
                            break;

                        case DOWN:
                        {
                            if (active_menu1 == size - 1)
                            {
                                active_menu1 = 0;
                            }
                            else
                            {
                                active_menu1++;
                            }
                            break;
                        }
                        case ESC:
                            exit(0);
                            break;

                        case ENTER:
                        {
                            if (active_menu1 == 0)
                            {
                                registration();
                            }
                            else if (active_menu1 == 1)
                            {
                                system("cls");
                                cout << "К сожалению программа не может работать без пользователей" << endl;
                                exit(0);
                            }
                        }
                        }
                    }


                }
                
                
                    autorization();
                
            }
            else if (active_menu == 3)
            {
                system("cls");
                GoToXY(40, 13);
                cout << "Работа завершена." << endl;
                exit(0);

            }
            break;
        }
    }
}



int NUMOFUSER;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

vector<users> user;
vector<students> info;
vector<string> student;
users userinstruct;
students infoinstruct;
fstream DataF;
fstream fs;
vector<string> infstud;
    int main() {

        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        SetConsoleTitle(L"Приложение для подсчета стипендии");
        ConsoleCursorVisible(false, 100);
        int SIZEUSER;

        string path = "Users.txt", Data = "Data.txt";
        DataF.open(Data, fstream::in | fstream::out | fstream::app);
        fs.open(path, fstream::in | fstream::out | fstream::app);


        Mainmenu();


        fs.close();
        DataF.close();
        return 0;
    }
