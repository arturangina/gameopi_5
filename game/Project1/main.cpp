#include <iostream>
#include <windows.h>
using namespace std;

int startKrestikiNoliki();
int menu(int& refmoney, int& refeda, int& refson, int& refmood, int& refstudy);

void death(int& refmoney, int& refeda, int& refson, int& refmood, int& refstudy) {
    system("cls");
    int restart = 0;
    cout << "================================================================================================" << endl << "вы:" << endl;
    cout << " .....---." << endl;
    cout << "     |x.x|" << endl;
    cout << "     |   |" << endl;
    cout << "    //   \\\\" << endl;
    cout << "   (|     |)" << endl;
    cout << "  /'\\_   _/`\\" << endl;
    cout << "  \\___)=(___/" << endl;
    cout << "      | |" << "вы погибли на первом семетре бгту! какая жалость!" << endl;
    cout << "     / | \\" << endl;
    cout << "    /  |  \\" << endl;
    cout << "   |   |   |" << endl;
    cout << "   |   |   |" << endl;
    cout << "   \\__/ \\__/" << endl;
    cout << "\tПРИЧИНА СМЕРТИ:" << endl;
    if (refeda <= 0) {
        cout << "уровень еды опустился до нуля. хавай почаще!" << endl;
    }
    if (refson <= 0) {
        cout << "уровень сна опустился до нуля. надо почаще спать!" << endl;
    }
    if (refmood <= 0) {
        cout << "уровень настроения опустился до нуля. клеш рояль заскучал.." << endl;
    }cout << "при вводе 1, вы перезапустите игру (заново поступите, правда в угабуга политех, если, конечно, хватит судимостей...)" << endl;
    cout << "================================================================================================" << endl;
    cin >> restart;
    if (restart == 1) {
        refmoney = 0; refstudy = 0; refeda = 100; refmood = 100; refson = 100;
        menu(refmoney, refeda, refson, refmood, refstudy);
    }
    exit(0);
}

void cleanmenu() { system("cls"); }

int moneyerror = 0;
int studyerror = 0;
int vtoroedihanie = 0;

int menu(int& refmoney, int& refeda, int& refson, int& refmood, int& refstudy) {
    int a;
    cleanmenu();

    if (moneyerror == 1) { cout << "НЕТУ ДЕНЕГ - СОСЕШЬ ЛАПУ!!" << endl; }
    if (studyerror == 1) { cout << "У ТЕБЯ СЛИШКОМ МАЛЕНЬКИЙ УРОВЕНЬ УЧЕБЫ ДЛЯ ТАКОЙ РАБОТЫ" << endl; }
    if (vtoroedihanie == 2) {
        cout << "ты воспользовался вторым дыханием и остался жив, хотя должен был умереть. впредь будь осторожнее!" << endl << endl;
        vtoroedihanie = 0;
    }

    cout << "Цель игры: заполнить шкалу учебы до ста процентов! (ну или хотя бы выжить в первом семестре бгту - 15 процентов учебы...)" << endl;
    cout << "================================================================================================" << endl << "вы:" << endl;
    cout << " .....---." << endl;
    cout << "     |o_o|" << "\tШекели: " << refmoney << endl;
    cout << "     |   |" << endl;
    cout << "    //   \\\\" << "\tЕда: " << refeda << endl;
    cout << "   (|     |)" << endl;
    cout << "  /'\\_   _/`\\" << "\tСон: " << refson << endl;
    cout << "  \\___)=(___/" << endl;
    cout << "      | |" << endl;
    cout << "     / | \\" << "\tНастроение: " << refmood << endl;
    cout << "    /  |  \\" << endl;
    cout << "   |   |   |" << "\tучеба: " << refstudy << endl;
    cout << "   |   |   |" << endl;
    cout << "   \\__/ \\__/" << endl;
    cout << "предложенные действия: " << endl << endl;
    cout << "(1)работа                     (2)покушать:                         (3)поспать                  (4)настроение" << endl;
    cout << "1)раздавать листовки           1)хлеб с солью (5руб. +3% к еде)    1)покимарить на паре                         " << endl;
    cout << "2)работать кассиром(учеба>10)  2)чибупицца    (50руб. +10% к еде)  2)поспать два часа        1)пройтись по улице" << endl;
    cout << "3)работать в маке(учеба>40)    3)еда столовки (125руб. +25% к еде) 3)поспать пять часов      2)запустить дотку" << endl;
    cout << "                               4)пойти в мак  (250руб. +48% к еде) 4)поспать девять часов    3)отрываться не по детски" << endl;
    cout << "                               5)еда ресторана(400руб. +80% к еде) " << endl << endl << "111 - сделать лабу (+1 к учебе но от всех параметров отнимается 30)" << endl << endl;
    cout << "купить второе дыхание - 700руб. (вы не умираете если один из показателей опустится до нуля, для покупки ввести 123)" << endl;
    cout << "================================================================================================" << endl << endl;
    cout << "для выбора конкретного действия напишите категорию и пункт слитно | например ввод 11 это раздавать листовки итд | " << endl;

    moneyerror = 0;
    studyerror = 0;
    cin >> a;

    switch (a) {
        // работа
    case 11: { refmoney += 400; refeda -= 30; refson -= 27; refmood -= 25; break; }
    case 12: { if (refstudy > 10) { refmoney += 500; refeda -= 36; refson -= 31; refmood -= 31; } else { studyerror = 1; } break; }
    case 13: { if (refstudy > 50) { refmoney += 650; refeda -= 30; refson -= 39; refmood -= 35; } else { studyerror = 1; } break; }

           // еда
    case 21: { if (refmoney < 5) { moneyerror = 1; break; } refeda += 3;  refmoney -= 5;   break; }
    case 22: { if (refmoney < 50) { moneyerror = 1; break; } refeda += 10; refmoney -= 50;  break; }
    case 23: { if (refmoney < 125) { moneyerror = 1; break; } refeda += 25; refmoney -= 125; break; }
    case 24: { if (refmoney < 250) { moneyerror = 1; break; } refeda += 48; refmoney -= 250; break; }
    case 25: { if (refmoney < 400) { moneyerror = 1; break; } refeda += 80; refmoney -= 400; break; }

           // сон
    case 31: { refson += 20; refeda -= 5;  break; }
    case 32: { refson += 35; refeda -= 10; refmood -= 5;  break; }
    case 33: { refson += 59; refeda -= 15; refmood -= 10; break; }
    case 34: { refson += 80; refeda -= 20; refmood -= 15; break; }

           // настроение
    case 41: { refmood += 47; refeda -= 20; refson -= 17; /*убрал лишнее повторное -15*/ break; }
    case 42: { refmood += 67; refeda -= 26; refson -= 21; /*убрал лишнее повторное -21*/ break; }
    case 43: { refmood += 90; refeda -= 33; refson -= 29; break; }

           // учеба
    case 111: { refstudy += 1; refeda -= 30; refmood -= 30; refson -= 30; break; }

            // второе дыхание
    case 123: { vtoroedihanie = 1; refmoney -= 700; break; }

            // крестики-нолики
    case 1234: {
        int ge = startKrestikiNoliki();
        if (ge == 0) { refmoney += 200; }      // победа ноликов — награда
        else if (ge == 1) { refmood -= 20; }   // победа крестиков — штраф
        break;
    }

    default: {
        return menu(refmoney, refeda, refson, refmood, refstudy);
    }
    }

    // второе дыхание спасает на нуле один раз
    if (vtoroedihanie == 1 && (refeda <= 0 || refson <= 0 || refmood <= 0)) {
        refeda = 60; refson = 60; refmood = 60;
        vtoroedihanie = 2;
        return menu(refmoney, refeda, refson, refmood, refstudy);
    }

    // смерть
    if (refeda <= 0) { death(refmoney, refeda, refson, refmood, refstudy); }
    if (refson <= 0) { death(refmoney, refeda, refson, refmood, refstudy); }
    if (refmood <= 0) { death(refmoney, refeda, refson, refmood, refstudy); }

    // кап значений до 100
    if (refeda > 100)  refeda = 100;
    if (refson > 100)  refson = 100;
    if (refmood > 100) refmood = 100;

    // победа в первом семестре
    if (refstudy == 15) { return 1; }

    // цикл меню
    return menu(refmoney, refeda, refson, refmood, refstudy);
}

int main() {
    setlocale(LC_ALL, "ru");

    // масштаб консоли
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX font = { sizeof(font) };
    GetCurrentConsoleFontEx(hConsole, FALSE, &font);
    font.dwFontSize.Y = 24; // было 16, стало 24
    SetCurrentConsoleFontEx(hConsole, FALSE, &font);

    int Money = 0, Eda = 100, Son = 100, Mood = 100, Study = 0;

    int result = menu(Money, Eda, Son, Mood, Study);
    if (result == 1) {
        system("cls");
        cout << "Поздравляем!! вы выжили в первом семестре бгту! вы прошли игру!";
    }

    return 0;
}
