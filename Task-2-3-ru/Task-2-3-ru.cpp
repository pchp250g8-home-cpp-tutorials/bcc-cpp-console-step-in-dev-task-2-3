#include <iostream>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
    // Инициализация переменных
    int direction = 0;  // 0: направление неизвестно, 1: вверх, -1: вниз
    unsigned int changes = 0;    // Счетчик смен направления
    int new_direction = direction;  // Новое направление
    unsigned int prev, current; // номера этажей, где лифт останавливался
    bool b_done = false; // флаговая переменная условие выхода из цикла
    // Установка русской локали для терминала Windows 11
	system("chcp 1251 >nul");// 1-й способ. Выплнить внешнюю команду.
    // 2 - й способ. Вызов библиотечной функции.
	setlocale(LC_ALL, "russian.1251");
    // 3 - й способ. Создать переменную типа локали
    std::locale rus_locale = std::locale("russian.1251");
    // 3 - й способ. Выбор кодировки(локали) терминала
    std::cout.imbue(std::locale::global(rus_locale));
    // Ввод данных
    std::cout << "Введите номера этажей, на которых останавливался лифт.\r\n";
    std::cout << "0 - конец ввода данных.\r\n";
    // Считываем первый этаж
    std::cin >> prev;
    b_done = (prev == 0);  // флаговая переменная условие выхода из цикла
    while (!b_done)
    {
        std::cin >> current;  // Вводим остальные этажи
        b_done = (current == 0);  // Выходим из цикла, если введен 0
        // Если этажи совпадают, направление не меняется,
        // просто пропускаем
        if (!b_done && current != prev)
        {
            // Определяем новое текущее направление
            // между prev и current
            new_direction = 1;
            if (current > prev)
            {
                new_direction = -1;
            }
        }
        // Если до этого направление уже было известно (не 0)
        // и оно не совпадает с новым направлением, значит произошла смена
        if (!b_done && direction != 0 && new_direction != direction)
        {
            changes += 1;
        }
        // Обновляем историю для следующего шага
        direction = new_direction;
        prev = current;
    }
    // Вывод информации на экран
    std::cout << "Количество смен направления лифтом: " << changes << "\r\n";
    // Задержка вывода на экран до нажатия клавиши "Ввод"
    std::cin.ignore();
    std::cin.get();
	return 0;
}
