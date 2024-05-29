// SP_PR2_Task6_V12(2).cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "SP_PR2_Task6_V12(2).h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // Имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SPPR2TASK6V122, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SPPR2TASK6V122));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wc;
    HBRUSH hbr = CreateSolidBrush(RGB(204, 255, 255));

    wc.cbSize = sizeof(WNDCLASSEX);

    wc.style          = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc    = WndProc;
    wc.cbClsExtra     = 0;
    wc.cbWndExtra     = 0;
    wc.hInstance      = hInstance;
    wc.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SPPR2TASK6V122));
    wc.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszMenuName   = MAKEINTRESOURCEW(IDC_SPPR2TASK6V122);
    wc.lpszClassName  = szWindowClass;
    wc.hIconSm        = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    wc.hbrBackground = hbr;

    return RegisterClassExW(&wc);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной
   wcscpy_s(szTitle, MAX_LOADSTRING, L"Индивидуальное задание 6");
   
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      200, 200, 600, 600,
       nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hListBox; // Список, куда заностся строки из полей.
    static HWND hChoiceButton; // Кнопка выбор
    static HWND hExitButton; // Кнопка выход
   
    static HWND hEdit1; // Поле ввода 1
    static HWND hEdit2; // Поле ввода 2
    static HWND hEdit3; // Поле ввода 3
    static HWND hEdit4; // Поле ввода 4
    static HWND hEditsArray[4] {hEdit1, hEdit2, hEdit3, hEdit4};
  
    // Чек-боксы выбора строк.
    static HWND hCheckBox1; 
    static HWND hCheckBox2;
    static HWND hCheckBox3;
    static HWND hCheckBox4;
    static HWND hChekBoxesArray[4]{ hCheckBox1, hCheckBox2, hCheckBox3, hCheckBox4};

    #define IDC_LISTBOX 150
    #define IDC_BTN_Choice 151

    #define IDC_EDIT1 155
    #define IDC_EDIT2 156
    #define IDC_EDIT3 157
    #define IDC_EDIT4 158
    static int IDC_EditsArray[4]{ IDC_EDIT1, IDC_EDIT2, IDC_EDIT3, IDC_EDIT4 };

    #define IDC_CHECKBOX1 165
    #define IDC_CHECKBOX2 166
    #define IDC_CHECKBOX3 167
    #define IDC_CHECKBOX4 168
    static int IDC_CheckBoxArray[4]{ IDC_CHECKBOX1, IDC_CHECKBOX2, IDC_CHECKBOX3, IDC_CHECKBOX4 };

    TCHAR pszTextBuff[500];

    

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                MessageBox(hWnd, _T("Выполнил Поляк А. А"), _T("О программе"),
                    MB_OK | MB_ICONINFORMATION);
                break;

            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;

            case IDCANCEL:
                DestroyWindow(hWnd);
                break;

            //Нажаите на конопку Выбор
            case IDC_BTN_Choice:

                for (int i = 0; i < 4; i++) {
                    // Получение состояния всех CheckBox
                   LRESULT res =  SendMessage(hChekBoxesArray[i], BM_GETCHECK, 0, 0);
                   // Если в CheckBox стоит установлен флажок
                   if (res == BST_CHECKED) {
                       // Получение текста из соответствующего поля ввода
                       int cch = SendMessage(hEditsArray[i], WM_GETTEXT,
                           (WPARAM)500, (LPARAM)pszTextBuff);
                       if (cch != 0) {
                           // Добавления текста в список.
                           int cch2 = SendMessage(hListBox, LB_ADDSTRING,
                               (WPARAM)0, (LPARAM)pszTextBuff);
                           if(cch2 == LB_ERR) MessageBox(hWnd, 
                               TEXT("Ошибка добавления"), TEXT(""), MB_OK);
                       }
                       // Очищение буфера
                       memset(pszTextBuff, 0, 500);

                   // CheckBox без флажка или с соответствующим пустым полем ввода пропускаются                      
                   }

                }
                break;

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CREATE:
        {
        // Окно списка
        hListBox = CreateWindowEx(
            0L, _T("ListBox"), _T("Список"),
            WS_CHILD | WS_BORDER | WS_VISIBLE,
            270, 50, 300, 300, hWnd,
            (HMENU)IDC_LISTBOX, hInst, NULL);
         if (hListBox == 0) return -1;

         //Кнопка выбора
         hChoiceButton = CreateWindowEx(
             0L, _T("Button"), _T("Выбор"),
             WS_CHILD | WS_BORDER | WS_VISIBLE,
             20, 480, 80, 24, hWnd,
             (HMENU)IDC_BTN_Choice, hInst, NULL);
         if (hChoiceButton == 0) return -1;

         // Кнопка выход
         hChoiceButton = CreateWindowEx(
             0L, _T("Button"), _T("Выход"),
             WS_CHILD | WS_BORDER | WS_VISIBLE,
             494, 480, 80, 24, hWnd,
             (HMENU)IDCANCEL, hInst, NULL);
         if (hChoiceButton == 0) return -1;

         //Чек-боксы и поля ввода.
         int posY = 100;
         for (int i = 0; i < 4; i++) {
             //Поля ввода
             hEditsArray[i] = CreateWindowEx(
                 0L, _T("Edit"), _T("Введите текст"),
                 WS_CHILD | WS_BORDER | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL,
                 60, posY, 190, 30, hWnd,
                 (HMENU)IDC_EditsArray[i], hInst, NULL);
             if (hEditsArray[i] == 0) return -1;
             
             // Чек-боксы
             hChekBoxesArray[i] = CreateWindowEx(
                 0, _T("Button"), _T(""),
                 WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX  | BS_FLAT,
                 20, posY, 20, 20, hWnd,
                 (HMENU)IDC_CheckBoxArray[i], hInst, NULL);
             if (hChekBoxesArray[i] == 0) return -1;
                     
             posY += 50;
         }

        }
        return 0;
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


