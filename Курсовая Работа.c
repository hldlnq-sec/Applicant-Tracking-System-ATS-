#define _CRT_SECURE_NO_WARNINGS

#include "Function.h"
#include <locale.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF8");

    createFilesAndInitData();

    int fchoice = -1;

    do
    {
        system("cls");

        PrintFileMenu();

        if (scanf("%d", &fchoice) != 1)
        {
            printf("\n\033[31m Ошибка: введите корректное число (пункт меню)! \033[0m\n");
            Sleep(1000);

            while (getchar() != '\n'); // Очистка буфера от мусора
            continue; // Переход на новую итерацию цикла
        }

        switch (fchoice)
        {
            int choice = -1;

            case 1:
            {
                do
                {
                    system("cls");

                    int kod = 1;

                    PrintMenu(kod);

                    if (scanf("%d", &choice) != 1)
                    {
                        printf("\n\033[31m Ошибка при считываниии действия с файлом! \033[0m\n");
                        Sleep(1000);

                        while (getchar() != '\n'); // Очистка буфера от мусора
                        continue; // Переход на новую итерацию цикла
                    }

                    switch (choice)
                    {
                        case 1: addVacancy(); break;
                        case 2: redactVacancy(); break;
                        case 3: deleteVacancy(); break;
                        case 4: printVacancies(); break;
                        case 5: binarySearchVacancyID(); break;
                        case 6: binarySearchVacancyTitle(); break;
                        case 7: sortVacanciesBySalaryQuick(); break;
                        case 8: sortVacanciesByDateSelection(); break;
                        case 9: matchVacancies(); break;
                        case 10: RecreateFileVacancies(); break;
                        case 0:
                        {
                            printf("\n\033[32m Возвращение в меню выбора файла... \033[0m\n");
                            Sleep(1000);
                            break;
                        }
                        default:
                        {
                            printf("\n\033[31m Некорректный выбор действия с файлом вакансий! \033[0m\n");
                            Sleep(1000);
                            break;
                        }
                    }

                } while (choice != 0);

                break;
            }

            case 2:
            {
                do
                {
                    system("cls");

                    int kod = 2;

                    PrintMenu(kod);

                    if (scanf("%d", &choice) != 1)
                    {
                        printf("\n\033[31m Ошибка при считываниии действия с файлом! \033[0m\n");
                        while (getchar() != '\n'); // Очистка буфера от мусора
                        continue;
                    }

                    switch (choice)
                    {
                        case 1: addPretender(); break;
                        case 2: redactPretender(); break;
                        case 3: deletePretender(); break;
                        case 4: printPretenders(); break;
                        case 5: binarySearchPretenderID(); break;
                        case 6: linearSearchPretenderSalary(); break;
                        case 7: sortPretendersByDateInsertion(); break;
                        case 8: statisticPretenders(); break;
                        case 9: RecreateFilePretenders(); break;
                        case 0:
                        {
                            printf("\n\033[32m Возвращение в меню выбора файла... \033[0m\n"); 
                            Sleep(1000);
                            break;
                        }
                        default:
                        {
                            printf("\n\033[31m Некорректный выбор действия с файлом соискателей! \033[0m\n");
                            Sleep(1000);
                            break;
                        }
                    }

                } while (choice != 0);

                break;
            }

            case 0:
            {
                printf("\n\033[32m Выход из программы... \033[0m\n");
                Sleep(1000);
                break;
            }

            default:
            {
                printf("\n\033[31m Ошибка: некорректный выбор файла для работы! \033[0m\n");
                Sleep(1000);
            }
        }
        
    } while (fchoice != 0);

    return 0;
}