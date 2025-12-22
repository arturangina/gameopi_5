#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int STR = 3, COL = 3;
int gameend = -1;

void vivod(int setka[][COL]);
int konec(int setka[][COL]);
void hodnolikov(int setka[][COL], int& rvvod);
void hodkrestikov(int setka[][COL], int& rvvod);
int game(int setka[][COL], int& rvvod);

int konec(int setka[STR][COL]) {
    system("CLS");
    vivod(setka);
    cout << "КОНЕЦ ИГРЫ" << endl;
    if (gameend == 0) cout << "ПОБЕДА НОЛИКОВ! ВЫ ПОБЕДИЛИ" << endl;
    if (gameend == 1) cout << "ПОБЕДА КРЕСТИКОВ, вы проиграли" << endl;
    cout << "\nнажмите 1 чтобы вернуться" << endl;
    int s; cin >> s;
    return gameend;
}

void proverka(int setka[STR][COL]) {
    // диагонали
    if (setka[0][0] == setka[1][1] && setka[1][1] == setka[2][2]) {
        if (setka[1][1] == 10) gameend = 0; else gameend = 1;
        konec(setka);
    }
    if (setka[0][2] == setka[1][1] && setka[1][1] == setka[2][0]) {
        if (setka[1][1] == 10) gameend = 0; else gameend = 1;
        konec(setka);
    }
    // строки
    for (int i = 0; i < STR; i++) {
        if (setka[i][0] == setka[i][1] && setka[i][1] == setka[i][2]) {
            if (setka[i][0] == 10) gameend = 0; else gameend = 1;
            konec(setka);
        }
    }
    // столбцы
    for (int j = 0; j < COL; j++) {
        if (setka[0][j] == setka[1][j] && setka[1][j] == setka[2][j]) {
            if (setka[0][j] == 10) gameend = 0; else gameend = 1;
            konec(setka);
        }
    }
}

int game(int setka[STR][COL], int& rvvod) {
    if (gameend != -1) return gameend; // игра закончена
    proverka(setka);
    if (gameend != -1) return gameend;

    system("CLS");
    hodkrestikov(setka, rvvod);
    vivod(setka);
    proverka(setka);
    if (gameend != -1) return gameend;

    hodnolikov(setka, rvvod);
    return game(setka, rvvod);
}

void hodnolikov(int setka[STR][COL], int& rvvod) {
    int access = 0;
    cin >> rvvod;
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            if ((rvvod == setka[i][j]) && (setka[i][j] != 10) && (setka[i][j] != 11)) {
                setka[i][j] = 10; // нолик
                access = 1;
                break;
            }
        }
        if (access == 1) break;
    }
}

void hodkrestikov(int setka[STR][COL], int& rvvod) {
    int randomvalue = rand() % 9 + 1; // от 1 до 9
    int access = 0;
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            if ((randomvalue == setka[i][j]) && (setka[i][j] != 10) && (setka[i][j] != 11)) {
                setka[i][j] = 11; // крестик
                access = 1;
                break;
            }
        }
        if (access == 1) break;
    }
    if (access == 0) hodkrestikov(setka, rvvod); // если клетка занята — пробуем снова
}

void vivod(int setka[STR][COL]) {
    cout << "    вы:           одногруппник:    " << endl;
    cout << " .....---.           [|||]  " << endl;
    cout << "     |o_o|           |0_-|" << endl;
    cout << "     |   |           |   |" << endl;
    cout << "    //   \\\\         // : \\\\" << endl;
    cout << "   (|     |)       (|  :  |)" << endl;
    cout << "  /'\\_   _/`\\     /'\\_ : _/`\\" << endl;
    cout << "  \\___)=(___/     \\___)=(___/" << endl;
    cout << "      | |             | |" << endl;
    cout << "     / | \\           /.|.\\" << endl;
    cout << "    /  |  \\         / _|_ \\" << endl;
    cout << "   |   |   |       |_  |  _|" << endl;
    cout << "   |   |   |       | __|__ |" << endl;
    cout << "   \\__/ \\__/       \\__/ \\__/" << endl;

    cout << "БИТВА КРЕСТИКИ НОЛИКИ НА ШЕКЕЛИ :O :O :O :O     :-o" << endl;
    cout << "введите число куда хотите поставить нолик" << endl;
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            if (setka[i][j] == 10) cout << "О\t";
            else if (setka[i][j] == 11) cout << "X\t";
            else cout << setka[i][j] << "\t";
        }
        cout << endl;
    }
}

int startKrestikiNoliki() {
    setlocale(LC_ALL, "ru");
    srand((unsigned)time(NULL));
    int k = 1, vvod;
    int& rvvod = vvod;
    int setka[STR][COL];
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++, k++) {
            setka[i][j] = k;
        }
    }
    gameend = -1; // сброс состояния
    int result = game(setka, rvvod);
    return result;
}
