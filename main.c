#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>
//-----------------------------------------------------------------------------
// Ініціалізація змінних для збереження певних даних
RECT rct;
int Round_X;
int Round_Y;
//-----------------------------------------------------------------------------
void Menu();
void Button();
void Info();
void Zastavka();
void Game();
void End_Game();
void Generation();
//-----------------------------------------------------------------------------
void End_Game() // інтерфейс меню - завершення гри
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t -------------------------------------------------\n");
    printf("\t\t\t\t|       THE END! YOU ARE SUCH A CLEVER BOY        |\n");
    printf("\t\t\t\t ------------------------------------------------- \n");
    printf("\n\n");
    printf("\n\t\t\t\tPress 1 to restart the game\n");
    printf("\n\t\t\t\tPress 2 to go to the menu\n");
    printf("\n\t\t\t\tPress 3 to quit the program\n");
    switch(getch())
    {
        case '1':
            system("cls");
            Game();
            break;
        case '2':
            system("cls");
            Menu();
            break;
        case '3':
            system("cls");
            exit(0);
        default :
            Button();
            End_Game();
    }
}
//-----------------------------------------------------------------------------
void Button() // інтерфейс меню для виводу повідомлення про неправильно натиснуту клавішу
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t -------------------------------------------------\n");
    printf("\t\t\t\t|          CHOOSE THE CORRECT BUTTON !!!          |\n");
    printf("\t\t\t\t ------------------------------------------------- \n");
    Sleep(750);
}
//-----------------------------------------------------------------------------
void Info() // інтерфейс меню для виводу правил гри
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t ------------------------------------------------\n");
    printf("\t\t\t\t|           Hi! In this game you need to         |\n");
    printf("\t\t\t\t|           look for hidden circle in the        |\n");
    printf("\t\t\t\t|           window with help of the sound.       |\n");
    printf("\t\t\t\t|           When the game start, use your        |\n");
    printf("\t\t\t\t|           mouse to click on Sound Game         |\n");
    printf("\t\t\t\t|           window. Be calm, because if you      |\n");
    printf("\t\t\t\t|           click too much, program will         |\n");
    printf("\t\t\t\t|           reply with a sum of sounds you       |\n");
    printf("\t\t\t\t|           clicked. Don't be scare of it!       |\n");
    printf("\t\t\t\t|           You should click every 1,5 seconds   |\n");
    printf("\t\t\t\t|           If you reach the hide circle you     |\n");
    printf("\t\t\t\t|           will win the game. For more          |\n");
    printf("\t\t\t\t|           information you can contact          |\n");
    printf("\t\t\t\t|           write a creator to his mail          |\n");
    printf("\t\t\t\t|                    Good luck!                  |\n");
    printf("\t\t\t\t ------------------------------------------------ \n");
    printf("\n\n");
    printf("\n\t\t\t\tPress 1 to go to the menu\n");
    printf("\n\t\t\t\tPress 2 to quit the program\n");
    switch(getch())
    {
        case '1':
            system("cls");
            Menu();
            break;
        case '2':
            system("cls");
            exit(0);
        default :
            Button();
            Info();
    }
}
//-----------------------------------------------------------------------------
void Zastavka() // інтерфейс меню - інформація стосовно роботи
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t -------------------------------------------------\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                _  GAME MAKING _                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                 Variant:  13                    |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|             Made by Yegor Maystrenko            |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                 group KV - 04                   |\n");
    printf("\t\t\t\t ------------------------------------------------- \n");
    printf("\n\n");
    printf("\n\t\t\t\tPress 1 to start the program\n");
    printf("\n\t\t\t\tPress 2 to quit the program\n");
    switch(getch())
    {
        case '1':
            system("cls");
            Menu();
            break;
        case '2':
            system("cls");
            exit(0);
        default :
            Button();
            Zastavka();
    }
}
//-----------------------------------------------------------------------------
void Menu() // інтерфейс меню - головне меню
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t\t -------------------------------------------------\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                    _ MENU _                     |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|            Press 1 to play the game             |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|            Press 2 to open game rules           |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|            Press 3 to go back                   |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|            Press 4 to quit completely           |\n");
    printf("\t\t\t\t ------------------------------------------------- \n");
    switch(getch())
    {
        case '1':
            system("cls");
            Game();
            break;
        case '2':
            system("cls");
            Info();
            break;
        case '3':
            system("cls");
            Zastavka();
            break;
        case '4':
            system("cls");
            exit(0);
        default :
            Button();
            Menu();
    }
}
//-----------------------------------------------------------------------------
void Generation()
{
    srand(time(NULL));
    Round_X = rand() % 650; // Генераціця центу кола для осі X
    Round_Y = rand() % 650; // Генераціця центу кола для осі Y
}
//-----------------------------------------------------------------------------
void WinShow(HDC dc) // Функція, яка створює зону для звукового сигналу для її пізнішої взаємодії з консоллю
{
    HDC memDC = CreateCompatibleDC(dc);
    HBITMAP memBM = CreateCompatibleBitmap(dc, rct.right - rct.left, rct.bottom - rct.top);
    SelectObject(memDC, memBM);
    SelectObject(memDC, GetStockObject(DC_BRUSH));
    SetDCBrushColor(memDC, RGB(0, 0, 0)); // Зафарбування певної області
    Rectangle(memDC, 0, 0, 700, 700);
    SelectObject(memDC, GetStockObject(DC_BRUSH));
    SetDCBrushColor(memDC, RGB(0, 0, 0)); // Зафарбування певної області
    SelectObject(memDC, GetStockObject(DC_PEN));
    Ellipse(memDC, Round_X - 15, Round_Y - 15, Round_X + 15, Round_Y + 15); // Побудова самого кола
    BitBlt(dc, 0, 0, rct.right - rct.left, rct.bottom - rct.top, memDC, 0, 0, SRCCOPY);
    DeleteDC(memDC);
    DeleteObject(memBM);
}
//-----------------------------------------------------------------------------
LRESULT WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    if(message == WM_DESTROY) // Завершення програми в разі закриття вікна
    {
        PostQuitMessage(0);
    }
    else if(message == WM_LBUTTONDOWN) // Пристосування для клацання мишкою
    {
        int Position_X = LOWORD(lparam);
        int Position_Y = HIWORD(lparam);
        double lengthX = abs(Round_X - Position_X);
        double lengthY = abs(Round_Y - Position_Y);
        double Distance = sqrt(lengthX*lengthX + lengthY*lengthY); //  Розрахунок відстані до шуканої області для визначення тональності
        Beep(50000 / Distance,500); // Подання звукового сигналу
        if ( Distance <= 13) // Якщо користувач знаходить місце розташування шуканої області вікно закривається
        {
            ShowWindow(hwnd, SW_HIDE);
            End_Game();
        }
    }
    else if(message == WM_SIZE)
    {
        GetClientRect(hwnd, &rct);
    }
    else
    {
        return DefWindowProcA(hwnd, message, wparam, lparam);
    }
}
//-----------------------------------------------------------------------------
void Game() {
    WNDCLASSA wcl;
    memset(&wcl, 0, sizeof(WNDCLASSA));
    wcl.lpszClassName = "Sound Game"; // Назва вікна
    wcl.lpfnWndProc = WndProc; // Функція для роботи з вікном
    RegisterClassA(&wcl);
    HWND hwnd;
    hwnd = CreateWindow("Sound Game", "Sound Game", WS_OVERLAPPEDWINDOW, 20, 20, 700, 700, NULL, NULL, NULL, NULL);
    HDC dc = GetDC(hwnd);
    ShowWindow(hwnd, SW_SHOWNORMAL);
    MSG msg;
    Generation();
   while (1) {
        if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) break; //  Завершення при натискані Есейпу
            DispatchMessage(&msg);
        }
        else
        {
            WinShow(dc);
        }

    }
}
//-----------------------------------------------------------------------------
int main()
{
    Zastavka();
    return 0;
}
//-----------------------------------------------------------------------------