#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Struct.h"
#include <io.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>  // Для _getch() в Windows

void PrintFileMenu(void)
{
    printf("\033[33m========= Система подбора вакансий =========\033[0m\n");
    printf("\033[33m--------------------------------------------\033[0m\n");
    printf("\033[33mВыберите с каким файлом вы хотите работать:\033[0m\n");
    printf("1) Файл с вакансиями\n");
    printf("2) Файл соискателей\n");
    printf("0) Завершение работы программы\n");
    printf("\033[33m--------------------------------------------\033[0m\n");
    printf("\033[33mВаш выбор => \033[0m");
}

void PrintMenu(int kod)
{
    switch (kod)
    {
    case 1:
    {
        printf("\033[33m============== Меню файла \"vacancies.bit\" ==============\033[0m\n");
        printf("\033[33m--------------------------------------------------------\033[0m\n");
        printf("1) добавить вакансию\n");
        printf("2) редактировать вакансию\n");
        printf("3) удалить вакансию\n");
        printf("4) распечатать все вакансии\n");
        printf("5) поиск вакансии по идентификатору (бинарный)\n");
        printf("6) поиск вакансии по названию (бинарный поиск)\n");
        printf("7) сортировать вакансии по зарплате (быстрая сортировка)\n");
        printf("8) сортировать вакансии по дате (сортировка выборкой)\n");
        printf("9) подборка вакансии\n");
        printf("10) пересоздать файл вакансий\n");
        printf("0) выход в меню выбора файла\n");
        printf("\033[33m--------------------------------------------------------\033[0m\n");
        printf("\033[33mВаш выбор => \033[0m");
        break;
    }

    case 2:
    {
        printf("\033[33m============== Меню файла \"pretenders.bit\" ==============\033[0m\n");
        printf("\033[33m---------------------------------------------------------\033[0m\n");
        printf("1) добавить соискателя\n");
        printf("2) редактировать соискателя\n");
        printf("3) удалить соискателя\n");
        printf("4) распечатать всех соискателей\n");
        printf("5) поиск соискателя по идентификатору (бинарный)\n");
        printf("6) поиск соискателей по зарплате (линейный)\n");
        printf("7) сортировать соискателей по дате (сортировка вставками)\n");
        printf("8) статистика по соискателям\n");
        printf("9) пересоздать файл соискателей\n");
        printf("0) выход в меню выбора файла\n");
        printf("\033[33m---------------------------------------------------------\033[0m\n");
        printf("\033[33mВаш выбор => \033[0m");
        break;
    }
    }
}

void PrintMenuRedactVacancy(void)
{
    printf("\033[33m======== Меню редактирования вакансии ========\033[0m\n");
    printf("\033[33m----------------------------------------------\033[0m\n");
    printf("1) Изменить должность вакансии\n");
    printf("2) Изменить название компании тркдоустройщика\n");
    printf("3) Изменить требуемую зарплату вакансии\n");
    printf("4) Изменить требования вакансии\n");
    printf("5) Изменить дату вакансии\n");
    printf("0) выход в меню работы с файлом вакансий\n");
    printf("\033[33m----------------------------------------------\033[0m\n");
    printf("\033[33mВаш выбор => \033[0m");
}

void PrintMenuRedactPretender(void)
{
    printf("\033[33m==== Меню редактирования соискателя ====\033[0m\n");
    printf("\033[33m----------------------------------------\033[0m\n");
    printf("1) Изменить ФИО соискателя\n");
    printf("2) Изменить ожидаемую зарплату\n");
    printf("3) Изменить навыки соискателя\n");
    printf("4) Изменить дату регистрации соискателя\n");
    printf("0) выход в меню работы с файлом вакансий\n");
    printf("\033[33m----------------------------------------\033[0m\n");
    printf("\033[33mВаш выбор => \033[0m");
}

void createFilesAndInitData(void)
{
    FILE* fVacancies = fopen("vacancies.bit", "rb");
    if (fVacancies == NULL)
    {
        printf("\033[32mИнициальзация файла вакансий. Автозаполнение...\033[0m\n");
        fVacancies = fopen("vacancies.bit", "wb");

        Vacancy initialisationVacancies[25] =
        {
            {1, "Junior C Developer", "EmbeddedTech", 60000, "C, Linux, Git, Data Structures, Debugging", {10,1,2026}},
            {2, "Backend Java Developer", "FinCore", 140000, "Java, Spring, PostgreSQL, REST API, Docker", {12,1,2026}},
            {3, "Frontend React Developer", "WebVision", 120000, "JavaScript, React, HTML, CSS, TypeScript", {15,1,2026}},
            {4, "Fullstack Developer", "CloudSoft", 160000, "JavaScript, Node.js, React, MongoDB, Docker", {18,1,2026}},
            {5, "DevOps Engineer", "SkyNetOps", 180000, "Linux, Docker, Kubernetes, AWS, CI/CD", {20,1,2026}},
            {6, "Data Scientist", "DataMind", 200000, "Python, Pandas, NumPy, Machine Learning, TensorFlow", {22,1,2026}},
            {7, "QA Automation Engineer", "QualityFirst", 110000, "Selenium, Java, Testing, CI/CD, Git", {25,1,2026}},
            {8, "C++ Developer", "GameForge", 150000, "C++, STL, OOP, Multithreading, Git", {28,1,2026}},
            {9, "Cybersecurity Analyst", "SecureIT", 170000, "Networking, Linux, SIEM, Penetration Testing, Python", {1,2,2026}},
            {10, "Mobile iOS Developer", "AppHouse", 145000, "Swift, iOS, REST API, Git, UI/UX", {3,2,2026}},
            {11, "Mobile Android Developer", "AppHouse", 145000, "Kotlin, Android, REST API, Git, Firebase", {5,2,2026}},
            {12, "Golang Backend Developer", "MicroTech", 170000, "Go, Microservices, Docker, PostgreSQL, Redis", {7,2,2026}},
            {13, "Rust Systems Developer", "SafeSystems", 190000, "Rust, Linux, Multithreading, Networking, Git", {9,2,2026}},
            {14, "Python Backend Developer", "WebCore", 150000, "Python, Django, PostgreSQL, REST API, Docker", {10,2,2026}},
            {15, "Cloud Engineer", "CloudSoft", 175000, "AWS, Azure, Terraform, Kubernetes, Linux", {12,2,2026}},
            {16, "UI/UX Designer", "DesignPro", 100000, "Figma, UI/UX, Prototyping, User Research, Adobe XD", {14,2,2026}},
            {17, "Business Analyst IT", "FinCore", 130000, "SQL, Requirements Analysis, UML, Jira, Communication", {15,2,2026}},
            {18, "Data Engineer", "DataMind", 185000, "Python, ETL, Airflow, PostgreSQL, Spark", {16,2,2026}},
            {19, "Machine Learning Engineer", "AI Labs", 210000, "Python, PyTorch, TensorFlow, ML, Deep Learning", {18,2,2026}},
            {20, "Frontend Angular Developer", "WebVision", 120000, "Angular, TypeScript, HTML, CSS, REST API", {20,2,2026}},
            {21, "Site Reliability Engineer", "SkyNetOps", 190000, "Linux, Kubernetes, Monitoring, CI/CD, Bash", {21,2,2026}},
            {22, "Blockchain Developer", "CryptoTech", 200000, "Solidity, Ethereum, Smart Contracts, JavaScript, Web3", {23,2,2026}},
            {23, "1C Developer", "BizSoft", 110000, "1C, SQL, Accounting Systems, Integration, Git", {24,2,2026}},
            {24, "Flutter Developer", "AppHouse", 135000, "Flutter, Dart, REST API, Firebase, Git", {25,2,2026}},
            {25, "Technical Support Engineer", "HelpDeskPro", 90000, "Windows, Linux, Networking, Troubleshooting, Customer Support", {26,2,2026}}
        };

        fwrite(initialisationVacancies, sizeof(Vacancy), 25, fVacancies);

        fclose(fVacancies);
    }
    else fclose(fVacancies);

    FILE* fPretenders = fopen("pretenders.bit", "rb");
    if (fPretenders == NULL)
    {
        printf("\033[32mИнициальзация файла соискателей. Автозаполнение...\033[0m\n");
        fPretenders = fopen("pretenders.bit", "wb");

        Pretender initialisationPretenders[40] =
        {
            {1, "Ivan Petrov", "C, Linux, Git, Data Structures", 65000, {5,1,2026}},
            {2, "Anna Smirnova", "Java, Spring, PostgreSQL, REST API, Docker", 150000, {6,1,2026}},
            {3, "Dmitry Volkov", "JavaScript, React, TypeScript, HTML, CSS", 125000, {7,1,2026}},
            {4, "Olga Sokolova", "Python, Django, PostgreSQL, Docker, REST API", 155000, {8,1,2026}},
            {5, "Sergey Ivanov", "Linux, Docker, Kubernetes, AWS, CI/CD", 185000, {9,1,2026}},
            {6, "Maria Kuznetsova", "Python, Pandas, NumPy, Machine Learning, TensorFlow", 210000, {10,1,2026}},
            {7, "Alexey Morozov", "C++, STL, OOP, Multithreading, Git", 155000, {11,1,2026}},
            {8, "Elena Orlova", "Selenium, Java, Testing, Git, CI/CD", 115000, {12,1,2026}},
            {9, "Roman Lebedev", "Swift, iOS, REST API, UI/UX, Git", 150000, {13,1,2026}},
            {10, "Tatiana Volkova", "Kotlin, Android, Firebase, REST API, Git", 150000, {14,1,2026}},
            {11, "Maksim Pavlov", "Go, Microservices, Docker, PostgreSQL, Redis", 175000, {15,1,2026}},
            {12, "Kirill Andreev", "Rust, Linux, Networking, Multithreading, Git", 195000, {16,1,2026}},
            {13, "Natalia Fedorova", "Figma, UI/UX, Prototyping, Adobe XD, User Research", 105000, {17,1,2026}},
            {14, "Andrey Nikitin", "SQL, UML, Requirements Analysis, Jira, Communication", 135000, {18,1,2026}},
            {15, "Viktor Smirnov", "Python, ETL, Airflow, Spark, PostgreSQL", 190000, {19,1,2026}},
            {16, "Alina Romanova", "Angular, TypeScript, HTML, CSS, REST API", 125000, {20,1,2026}},
            {17, "Denis Kozlov", "Solidity, Ethereum, Smart Contracts, JavaScript, Web3", 205000, {21,1,2026}},
            {18, "Pavel Zaitsev", "1C, SQL, Accounting Systems, Integration", 115000, {22,1,2026}},
            {19, "Irina Belova", "Flutter, Dart, Firebase, REST API, Git", 140000, {23,1,2026}},
            {20, "Oleg Markov", "Windows, Linux, Networking, Troubleshooting, Customer Support", 95000, {24,1,2026}},
            {21, "Artem Sidorov", "Java, Spring Boot, MySQL, REST API, Docker", 145000, {25,1,2026}},
            {22, "Polina Egorova", "Python, Flask, MongoDB, Git, Linux", 140000, {26,1,2026}},
            {23, "Egor Pavlenko", "C#, .NET, ASP.NET, SQL Server, Azure", 160000, {27,1,2026}},
            {24, "Kristina Belova", "Vue.js, JavaScript, HTML, CSS, REST API", 120000, {28,1,2026}},
            {25, "Nikita Orlov", "Bash, Linux, Docker, CI/CD, Monitoring", 150000, {29,1,2026}},
            {26, "Yulia Tarasova", "Python, PyTorch, Deep Learning, Computer Vision, NumPy", 220000, {30,1,2026}},
            {27, "Stepan Makarov", "Go, Kubernetes, AWS, Terraform, Linux", 185000, {31,1,2026}},
            {28, "Veronika Smirnova", "Manual Testing, QA, Jira, Test Cases, SQL", 90000, {1,2,2026}},
            {29, "Timur Akhmetov", "C++, Unreal Engine, OOP, Git, Algorithms", 160000, {2,2,2026}},
            {30, "Lidia Morozova", "Swift, iOS, UIKit, REST API, Git", 155000, {3,2,2026}},
            {31, "Ruslan Gromov", "Kotlin, Android, MVVM, REST API, Firebase", 150000, {4,2,2026}},
            {32, "Mikhail Sorokin", "Rust, Systems Programming, Linux, Git, Networking", 200000, {5,2,2026}},
            {33, "Svetlana Petrova", "Figma, UI Design, Prototyping, UX Research, Adobe XD", 110000, {6,2,2026}},
            {34, "Vadim Kravtsov", "SQL, Power BI, Data Analysis, Excel, Reporting", 125000, {7,2,2026}},
            {35, "Georgy Klimov", "Python, FastAPI, Docker, PostgreSQL, Redis", 160000, {8,2,2026}},
            {36, "Anastasia Volkova", "React, Next.js, TypeScript, HTML, CSS", 135000, {9,2,2026}},
            {37, "Ilya Voronin", "Cybersecurity, Linux, Networking, SIEM, Python", 175000, {10,2,2026}},
            {38, "Daria Melnikova", "Flutter, Dart, Mobile Development, REST API, Git", 145000, {11,2,2026}},
            {39, "Konstantin Frolov", "1C, ERP Systems, SQL, Integration, Accounting", 120000, {12,2,2026}},
            {40, "Yaroslav Denisov", "Technical Support, Windows Server, Linux, Networking, Troubleshooting", 95000, {13,2,2026}}
        };

        fwrite(initialisationPretenders, sizeof(Pretender), 40, fPretenders);

        fclose(fPretenders);
    }
    else fclose(fPretenders);

    FILE* fReport = fopen("report.txt", "r");
    if (fReport == NULL)
    {
        printf("\033[32mИнициальзация файла для отчетов...\033[0m\n");
        fReport = fopen("report.txt", "w");
    }
    else fclose(fReport);
}

//----------------------------------------------------------------------------

Date InsertDate(void)
{
    Date newDate;
    printf("\033[33mВведите дату (дд мм гггг) => \033[0m");
    if (scanf("%2d %2d %4d", &newDate.day, &newDate.month, &newDate.year) != 3)
    {
        printf("\033[31mОшибка ввода даты!\033[0m\n");
        while (getchar() != '\n');
        free(&newDate);
        Sleep(1000);
    }
    else return newDate;
}

int CompareDates(Date Date1, Date Date2)
{
    if (Date1.year != Date2.year) return Date1.year - Date2.year;
    else if (Date1.month != Date2.month) return Date1.month - Date2.month;
    else return Date1.day - Date2.day;
}

//------------------------------------------------------------------------------

void RecreateFileVacancies(void)
{
    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fVacancies = fopen("vacancies.bit", "wb");

    if (fVacancies)
    {
        fprintf(fReport, "\nФайл вакансий успешно пересоздан!\n");
        printf("\n\033[32mФайл вакансий успешно пересоздан!\033[0m\n");
        Sleep(1000);
        fclose(fVacancies);
    }
    else
    {
        printf("\033[31mОшибка при попытке пересоздать файл \"vacancies.bit\"!\033[0m\n");
        Sleep(1000);
        return;
    }

    fclose(fReport);
}

void RecreateFilePretenders(void)
{
    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fPretenders = fopen("pretenders.bit", "wb");

    if (fPretenders)
    {
        fprintf(fReport, "\nФайл соискателей успешно пересоздан!\n");
        printf("\n\033[32mФайл стискателей успешно пересоздан!\033[0m\n");
        Sleep(1000);
        fclose(fPretenders);
    }
    else
    {
        printf("\033[31m Ошибка при потпытке пересоздать файл \"pretenders.bit\"! \033[0m\n");
        Sleep(1000);
        return;
    }

    fclose(fReport);
}

//----------------------------------------------------------------------------

void printVacancies(void)
{
    FILE* fVacancies = fopen("vacancies.bit", "rb");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m\n");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m \n");
        Sleep(1000);
        exit(1);
    }

    Vacancy temp;

    fprintf(fReport, "%-3s | %-25s | %-15s | %-10s | %-9s\n", "ID", "Должность", "Компания", "ЗП", "Дата");
    printf("\033[33m%-3s | %-25s | %-15s | %-10s | %-9s\n", "ID", "Должность", "Компания", "ЗП", "Дата\033[0m");
    while (fread(&temp, sizeof(Vacancy), 1, fVacancies))
    {
        fprintf(fReport, "%-3d | %-25.25s | %-15.15s | %-10.2lf | %02d.%02d.%04d\n", temp.ID, temp.title, temp.company, temp.salary, temp.CreationDate.day, temp.CreationDate.month, temp.CreationDate.year);
        printf("%-3d | %-25.25s | %-15.15s | %-10.2lf | %02d.%02d.%04d\n", temp.ID, temp.title, temp.company, temp.salary, temp.CreationDate.day, temp.CreationDate.month, temp.CreationDate.year);
        printf("\n");
    }

    printf("\n\033[32m Нажмите любую кнопку для очистки консоли... \033[0m\n");

    char key = _getch(); // Ждет нажатия любой клавиши

    fclose(fVacancies);
    fclose(fReport);
}

void printPretenders(void)
{
    FILE* fPretenders = fopen("pretenders.bit", "rb");
    if (fPretenders == NULL)
    {
        printf("\033[31mОшибка открытия файла \"pretenders.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    Pretender temp;

    fprintf(fReport, "\n%-3s | %-20s | %-10s | %-9s | %s\n", "ID", "ФИО", "ЗП", "Дата", "Навыки");
    printf("\n\033[33m%-3s | %-20s | %-10s | %-9s | %s\n", "ID", "ФИО", "ЗП", "Дата", "Навыки\033[0m");
    while (fread(&temp, sizeof(Pretender), 1, fPretenders))
    {
        fprintf(fReport, "%03d | %20s | %10lf | %02d.%02d.%04d | %s\n", temp.ID, temp.FullName, temp.salary, temp.RegisterDate.day, temp.RegisterDate.month, temp.RegisterDate.year, temp.skills);
        printf("%03d | %20s | %10lf | %02d.%02d.%04d | %s\n", temp.ID, temp.FullName, temp.salary, temp.RegisterDate.day, temp.RegisterDate.month, temp.RegisterDate.year, temp.skills);
        printf("\n");
    }

    printf("\n\033[32m Нажмите любую кнопку для очистки консоли... \033[0m\n");

    char key = _getch(); // Ждет нажатия любой клавиши

    fclose(fPretenders);
    fclose(fReport);
}

//----------------------------------------------------------------------------

void quickSortVacanciesID(FILE* fVacancies, int low, int high)
{
    if (low >= high) return;

    int i = low;
    int j = high;
    Vacancy pivot, vi, vj;

    int mid = low + (high - low) / 2;
    fseek(fVacancies, mid * sizeof(Vacancy), SEEK_SET);
    fread(&pivot, sizeof(Vacancy), 1, fVacancies);

    while (i <= j)
    {
        fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
        fread(&vi, sizeof(Vacancy), 1, fVacancies);
        while (vi.ID < pivot.ID)
        {
            i++;
            fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
            fread(&vi, sizeof(Vacancy), 1, fVacancies);
        }

        fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
        fread(&vj, sizeof(Vacancy), 1, fVacancies);
        while (vj.ID > pivot.ID)
        {
            j--;
            fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
            fread(&vj, sizeof(Vacancy), 1, fVacancies);
        }

        if (i <= j)
        {
            if (i < j)
            {
                fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
                fwrite(&vj, sizeof(Vacancy), 1, fVacancies);

                fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
                fwrite(&vi, sizeof(Vacancy), 1, fVacancies);

                fflush(fVacancies);
            }
            i++;
            j--;
        }
    }

    if (low < j) quickSortVacanciesID(fVacancies, low, j);
    if (i < high) quickSortVacanciesID(fVacancies, i, high);
}

void quickSortPretendersID(FILE* fPretenders, int low, int high)
{
    if (low >= high) return;

    int i = low;
    int j = high;
    Pretender pivot, vi, vj;

    int mid = low + (high - low) / 2;
    fseek(fPretenders, mid * sizeof(Pretender), SEEK_SET);
    fread(&pivot, sizeof(Pretender), 1, fPretenders);

    while (i <= j)
    {
        fseek(fPretenders, i * sizeof(Pretender), SEEK_SET);
        fread(&vi, sizeof(Pretender), 1, fPretenders);
        while (vi.ID < pivot.ID)
        {
            i++;
            fseek(fPretenders, i * sizeof(Pretender), SEEK_SET);
            fread(&vi, sizeof(Pretender), 1, fPretenders);
        }

        fseek(fPretenders, j * sizeof(Pretender), SEEK_SET);
        fread(&vj, sizeof(Pretender), 1, fPretenders);
        while (vj.ID > pivot.ID)
        {
            j--;
            fseek(fPretenders, j * sizeof(Pretender), SEEK_SET);
            fread(&vj, sizeof(Pretender), 1, fPretenders);
        }

        if (i <= j)
        {
            if (i < j)
            {
                fseek(fPretenders, i * sizeof(Pretender), SEEK_SET);
                fwrite(&vj, sizeof(Pretender), 1, fPretenders);

                fseek(fPretenders, j * sizeof(Pretender), SEEK_SET);
                fwrite(&vi, sizeof(Pretender), 1, fPretenders);

                fflush(fPretenders); // Обязательный сброс буфера!
            }
            i++;
            j--;
        }
    }

    if (low < j) quickSortPretendersID(fPretenders, low, j);
    if (i < high) quickSortPretendersID(fPretenders, i, high);
}

void quickSortVacanciesTitle(FILE* fVacancies, int low, int high)
{
    if (low >= high) return;

    int i = low;
    int j = high;
    Vacancy pivot, vi, vj;

    int mid = low + (high - low) / 2;
    fseek(fVacancies, mid * sizeof(Vacancy), SEEK_SET);
    fread(&pivot, sizeof(Vacancy), 1, fVacancies);

    while (i <= j)
    {
        fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
        fread(&vi, sizeof(Vacancy), 1, fVacancies);
        // Сравнение строк через strcmp
        while (strcmp(vi.title, pivot.title) < 0)
        {
            i++;
            fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
            fread(&vi, sizeof(Vacancy), 1, fVacancies);
        }

        fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
        fread(&vj, sizeof(Vacancy), 1, fVacancies);
        while (strcmp(vj.title, pivot.title) > 0)
        {
            j--;
            fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
            fread(&vj, sizeof(Vacancy), 1, fVacancies);
        }

        if (i <= j)
        {
            if (i < j)
            {
                fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
                fwrite(&vj, sizeof(Vacancy), 1, fVacancies);

                fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
                fwrite(&vi, sizeof(Vacancy), 1, fVacancies);

                fflush(fVacancies);
            }
            i++;
            j--;
        }
    }

    if (low < j) quickSortVacanciesTitle(fVacancies, low, j);
    if (i < high) quickSortVacanciesTitle(fVacancies, i, high);
}

void quickSortVacanciesSalary(FILE* fVacancies, int low, int high)
{
    if (low >= high) return;

    int i = low;
    int j = high;
    Vacancy pivot, vi, vj;

    int mid = low + (high - low) / 2;
    fseek(fVacancies, mid * sizeof(Vacancy), SEEK_SET);
    fread(&pivot, sizeof(Vacancy), 1, fVacancies);

    while (i <= j)
    {
        fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
        fread(&vi, sizeof(Vacancy), 1, fVacancies);
        while (vi.salary < pivot.salary)
        {
            i++;
            fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
            fread(&vi, sizeof(Vacancy), 1, fVacancies);
        }

        fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
        fread(&vj, sizeof(Vacancy), 1, fVacancies);
        while (vj.salary > pivot.salary)
        {
            j--;
            fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
            fread(&vj, sizeof(Vacancy), 1, fVacancies);
        }

        if (i <= j)
        {
            if (i < j)
            {
                fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
                fwrite(&vj, sizeof(Vacancy), 1, fVacancies);

                fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
                fwrite(&vi, sizeof(Vacancy), 1, fVacancies);

                fflush(fVacancies);
            }
            i++;
            j--;
        }
    }

    if (low < j) quickSortVacanciesSalary(fVacancies, low, j);
    if (i < high) quickSortVacanciesSalary(fVacancies, i, high);
}

void sortVacanciesBySalaryQuick(void)
{
    FILE* fVacancies = fopen("vacancies.bit", "r+b");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fVacancies, 0, SEEK_END);
    int quantity = ftell(fVacancies) / sizeof(Vacancy);

    if (quantity > 1)
    {
        quickSortVacanciesSalary(fVacancies, 0, quantity - 1);
    }

    fprintf(fReport, "\nСортировка по зарплате (быстрая сортировка) завершена.");
    printf("\n\033[312mСортировка по зарплате (быстрая сортировка) завершена.\033[0m\n");
    Sleep(1000);

    fclose(fVacancies);
    fclose(fReport);
}

void sortVacanciesByDateSelection(void)
{
    FILE* fVacancies = fopen("vacancies.bit", "r+b");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fVacancies, 0, SEEK_END);
    int quantity = ftell(fVacancies) / sizeof(Vacancy);

    for (int i = 0; i < quantity - 1; i++)
    {
        int min_index = i;
        Vacancy vac1, vac2;

        for (int j = i + 1; j < quantity; j++)
        {
            fseek(fVacancies, min_index * sizeof(Vacancy), SEEK_SET);
            fread(&vac1, sizeof(Vacancy), 1, fVacancies);
            fseek(fVacancies, j * sizeof(Vacancy), SEEK_SET);
            fread(&vac2, sizeof(Vacancy), 1, fVacancies);

            if (CompareDates(vac1.CreationDate, vac2.CreationDate) < 0)
                min_index = j;
        }

        if (i != min_index)
        {
            fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
            fread(&vac1, sizeof(Vacancy), 1, fVacancies);
            fseek(fVacancies, min_index * sizeof(Vacancy), SEEK_SET);
            fread(&vac2, sizeof(Vacancy), 1, fVacancies);

            fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
            fwrite(&vac2, sizeof(Vacancy), 1, fVacancies);
            fseek(fVacancies, min_index * sizeof(Vacancy), SEEK_SET);
            fwrite(&vac1, sizeof(Vacancy), 1, fVacancies);
        }
    }

    fprintf(fReport, "\nСортировка вакансий (выборкой) по дате завершена!\n");
    printf("\n\033[32mСортировка вакансий (выборкой) по дате завершена!\033[0m\n");
    Sleep(1000);

    fclose(fVacancies);
    fclose(fReport);
}

void sortPretendersByDateInsertion(void)
{
    FILE* fPretenders = fopen("pretenders.bit", "r+b");
    if (fPretenders == NULL)
    {
        printf("\033[31mОшибка открытия файла \"pretenders.bit\"!\033[0m\n");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m\n");
        fclose(fPretenders);
        Sleep(1000);    
        exit(1);
    }

    fseek(fPretenders, 0, SEEK_END);
    long fileSize = ftell(fPretenders);
    int quantity = (int)(fileSize / sizeof(Pretender));

    // Если записей меньше двух, сортировать нечего
    if (quantity < 2)
    {
        fclose(fPretenders);
        fclose(fReport);
        printf("\n\033[32mНедостаточно данных для сортировки.\033[0m\n");
        Sleep(1000);
        return;
    }

    // Классический алгоритм сортировки вставками для файла
    for (int i = 1; i < quantity; i++)
    {
        Pretender pret_1, pret_2;

        // 1. Читаем текущий элемент, который нужно вставить (опорный)
        fseek(fPretenders, i * sizeof(Pretender), SEEK_SET);
        fread(&pret_1, sizeof(Pretender), 1, fPretenders);

        int location = i - 1;

        // 2. Читаем элемент слева для первичного сравнения
        fseek(fPretenders, location * sizeof(Pretender), SEEK_SET);
        fread(&pret_2, sizeof(Pretender), 1, fPretenders);

        // 3. Сдвигаем элементы вправо, пока не найдем место для pret_1
        while (location >= 0 && CompareDates(pret_1.RegisterDate, pret_2.RegisterDate) < 0)
        {
            // Сдвигаем pret_2 на одну позицию вправо
            fseek(fPretenders, (location + 1) * sizeof(Pretender), SEEK_SET);
            fwrite(&pret_2, sizeof(Pretender), 1, fPretenders);

            // ИСПРАВЛЕНО: Сброс буфера после записи!
            fflush(fPretenders);

            location--;

            // ИСПРАВЛЕНО: Если есть куда двигаться дальше, читаем следующий элемент слева!
            if (location >= 0)
            {
                fseek(fPretenders, location * sizeof(Pretender), SEEK_SET);
                fread(&pret_2, sizeof(Pretender), 1, fPretenders);
            }
        }

        // 4. Вставляем сохраненный опорный элемент (pret_1) на освободившееся место
        fseek(fPretenders, (location + 1) * sizeof(Pretender), SEEK_SET);
        fwrite(&pret_1, sizeof(Pretender), 1, fPretenders);
        fflush(fPretenders); // Очистка буфера перед новой итерацией
    }

    fprintf(fReport, "\nСортировка соискателей (вставками) по дате завершена!\n");
    printf("\n\033[32mСортировка соискателей (вставками) по дате завершена!\033[0m\n");
    Sleep(1000);

    fclose(fPretenders);
    fclose(fReport);
}

//----------------------------------------------------------------------------

void linearSearchPretenderSalary(void)
{
    FILE* fPretenders = fopen("pretenders.bit", "rb");
    if (fPretenders == NULL)
    {
        printf("\033[31mОшибка открытия файла \"pretenders.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    double targetSalary;
    printf("\033[33mВведите желаемую зарплату для поиска => \033[0m");
    if ((scanf("%lf", &targetSalary) != 1) || (targetSalary < 0))
    {
        printf("\033[31mОшибка ввода желаемой зарплаты!\033[0m");
        while (getchar() != '\n');
        fclose(fPretenders);
        Sleep(1000);
        return;
    }

    Pretender temp;
    int found = 0;

    fprintf(fReport, "\nРезультаты поиска соискателей с желаемой зарплатой %10.2lf:\n", targetSalary);
    printf("\n\033[33mРезультаты поиска соискателей с желаемой зарплатой %10.2lf:\033[0m\n", targetSalary);
    Sleep(1000);

    while (fread(&temp, sizeof(Pretender), 1, fPretenders))
    {
        if (temp.salary - targetSalary > 0.0) //нужно учитывать дробную часть при сравнении чисел с плавающей точкой? и надо ли выводить соискателей, у которых зп выше или ниже?
        {
            fprintf(fReport, "\nНайден подходящий соискатель => %20s (ID %03d)\n", temp.FullName, temp.ID);
            printf("\033[33mНайден подходящий соискатель =>\033[0m %20s (ID %03d)\n", temp.FullName, temp.ID);
            found = 1;
        }
    }

    if (!found)
    {
        fprintf(fReport, "\nСоискатели с желаемой зарплатой %lf не найдены.\n", targetSalary);
        printf("\0333mСоискатели с желаемой зарплатой %lf не найдены.\033[0m\n", targetSalary);
    }

    Sleep(1000);

    fclose(fPretenders);
    fclose(fReport);
}

void binarySearchVacancyTitle(void)
{
    FILE* fVacancies = fopen("vacancies.bit", "r+b");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fVacancies, 0, SEEK_END);
    int quantity = ftell(fVacancies) / sizeof(Vacancy);

    if (quantity > 1)
    {
        quickSortVacanciesTitle(fVacancies, 0, quantity - 1);
    }

    fprintf(fReport, "\nБыстрая сортировка вакансий по названию завершена!\n");
    printf("\n\033[32mБыстрая сортировка вакансий по названию завершена!\033[0m\n");
    Sleep(1000);

    char TitleToSearch[MAX_STRING];
    int low = 0, high = quantity - 1, mid, found = 0;
    Vacancy buffer;

    printf("\033[31mВведите название должности вакансии для поиска => \033[0m");
    // Перед первым fgets после scanf обязательно нужно очистить остаточный '\n'
    // Если это первый ввод строки после ввода пункта меню:
    while (getchar() != '\n');
    fgets(TitleToSearch, MAX_STRING, stdin);

    while (low <= high)
    {
        mid = (low + high) / 2;
        fseek(fVacancies, mid * sizeof(Vacancy), SEEK_SET);
        fread(&buffer, sizeof(Vacancy), 1, fVacancies);
        int count = strcmp(buffer.title, TitleToSearch);
        if (count == 0)
        {
            if (!found)
            {
                fprintf(fReport, "Список вакансий по вашему запросу (ID - Должность - Компания - ЗП - Дата)\n");
                printf("\033[33mСписок вакансий по вашему запросу (ID - Должность - Компания - ЗП - Дата)\033[0m");
            }

            fprintf(fReport, "%-3d %-25.25s %-15.15s %-10.2lf %02d.%02d.%04d\n", buffer.ID, buffer.title, buffer.company, buffer.salary, buffer.CreationDate.day, buffer.CreationDate.month, buffer.CreationDate.year);
            printf("%-3d %-25.25s %-15.15s %-10.2lf %02d.%02d.%04d\n", buffer.ID, buffer.title, buffer.company, buffer.salary, buffer.CreationDate.day, buffer.CreationDate.month, buffer.CreationDate.year);
            printf("\n");
            found = 1;
        }
        else if (count > 0) high = mid - 1;
        else low = mid + 1;
    }

    if (!found)
    {
        fprintf(fReport, "\nПодходящих вакансий не найдено.");
        printf("\n\033[33mПодходящих вакансий не найдено.\033[0m\n");
    }

    Sleep(1000);

    fclose(fVacancies);
    fclose(fReport);
}

int binarySearchVacancyID(void)
{
    FILE* fVacancies = fopen("vacancies.bit", "r+b");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fVacancies, 0, SEEK_END);
    int quantity = ftell(fVacancies) / sizeof(Vacancy);

    if (quantity > 1)
    {
        quickSortVacanciesID(fVacancies, 0, quantity - 1);
    }

    int ID_delete = -1;
    int low = 0, high = quantity - 1, mid, found = 0;
    Vacancy buffer;


    printf("\033[33mВведите ID вакансии => \033[0m");

    if (scanf("%d", &ID_delete) != 1)
    {
        printf("\033[31mОшибка ввода ID вакансии!\033[0m");
        while (getchar() != '\n');
        fclose(fVacancies);
        Sleep(1000);
        return;
    }

    while (low <= high)
    {
        mid = (low + high) / 2;
        fseek(fVacancies, mid * sizeof(Vacancy), SEEK_SET);
        fread(&buffer, sizeof(Vacancy), 1, fVacancies);
        if (buffer.ID == ID_delete)
        {
            fclose(fVacancies);
            return mid;
        }
        else if (buffer.ID > ID_delete) high = mid - 1;
        else low = mid + 1;
    }

    if (!found)
    {
        printf("\n\033[32mПодходящих вакансий не найдено.\033[0m\n");
        fclose(fVacancies);
        Sleep(1000);
        return -1;
    }
}

int binarySearchPretenderID(void)
{
    FILE* fPretenders = fopen("pretenders.bit", "r+b");
    if (fPretenders == NULL)
    {
        printf("\033[31mОшибка открытия файла \"pretenders.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fPretenders, 0, SEEK_END);
    int quantity = ftell(fPretenders) / sizeof(Pretender);

    if (quantity > 1) quickSortPretendersID(fPretenders, 0, quantity - 1);
    int ID_delete = -1;
    int low = 0, high = quantity - 1, mid, found = 0;
    Pretender buffer;


    printf("\033[33mВведите ID соискателя => \033[0m");

    if (scanf("%d", &ID_delete) != 1)
    {
        printf("\033[31mОшибка ввода ID соискателя !\033[0m");
        while (getchar() != '\n');
        fclose(fPretenders);
        Sleep(1000);
        return -1;
    }

    while (low <= high)
    {
        mid = (low + high) / 2;
        fseek(fPretenders, mid * sizeof(Pretender), SEEK_SET);
        fread(&buffer, sizeof(Pretender), 1, fPretenders);
        if (buffer.ID == ID_delete)
        {
            fclose(fPretenders);
            found = 1;
            return mid;
        }
        else if (buffer.ID > ID_delete) high = mid - 1;
        else low = mid + 1;
    }

    if (!found)
    {
        printf("\n\033[32mПодходящих соискателей не найдено.\033[0m\n");
        Sleep(1000);
        fclose(fPretenders);
        return -1;
    }
}

//------------------------------------------------------------------------------------------------------------------------------

void matchVacancies(void)
{
    sortVacanciesByDateSelection();

    int size_buffer = 0;
    double reqSalary;
    char skill[MAX_STRING];

    printf("\033[33mВведите минимальную желаемую зарплату => \033[0m");
    if ((scanf("%lf", &reqSalary) != 1) || (reqSalary < 0))
    {
        printf("\033[31mНекорректный ввод желаемой зарплаты!\033[0m");
        while (getchar() != '\n');
        Sleep(1000);
        return;
    }

    printf("\033[33mВведите ключевые навыки => \033[0m");
    while (getchar() != '\n');
    fgets(skill, MAX_STRING, stdin);
    skill[strcspn(skill, "\n")] = '\0'; // Удаление \n

    FILE* fVacancies = fopen("vacancies.bit", "rb");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    Vacancy buffer;

    fprintf(fReport, "Подбор вакансий с ЗП свыше %.2lf и требуемыми навыками: %s\n", reqSalary, skill);
    printf("\033[33mПодбор вакансий с ЗП свыше %.2lf и требуемыми навыками: %s\033[0m\n", reqSalary, skill);

    while (fread(&buffer, sizeof(Vacancy), 1, fVacancies))
    {
        if ((reqSalary <= buffer.salary) && (strstr(buffer.requests, skill)))
        {
            fprintf(fReport, "%d. %s - %s (Предположительная зарплата => %lf)\n", ++size_buffer, buffer.company, buffer.title, buffer.salary);
            printf("%d. %s - %s (Предположительная зарплата => %lf)\n", ++size_buffer, buffer.company, buffer.title, buffer.salary);
        }
    }

    if (!size_buffer)
    {
        fprintf(fReport, "\nПодходящих вакансий не найдено!\n");
        printf("\n\033[32mПодходящих вакансий не найдено!\033[0m\n");
    }

    Sleep(1000);

    fclose(fVacancies);
    fclose(fReport);
}

void statisticPretenders(void)
{
    FILE* fPretenders = fopen("pretenders.bit", "rb");
    if (fPretenders == NULL)
    {
        printf("\033[31mОшибка открытия файла \"pretenders.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    Date targetDate = InsertDate();
    char targetSkills[MAX_STRING];
    printf("\033[33mВведите требуемые навыки (через запятую) => \033[0m");
    while (getchar() != '\n');
    fgets(targetSkills, MAX_STRING, stdin);
    Pretender temp;
    int count = 0;

    fprintf(fReport, "\nСоискатели, зарегистрированные после %02d.%02d.%04d:\n", targetDate.day, targetDate.month, targetDate.year);
    printf("\n\033[33mСоискатели, зарегистрированные после %02d.%02d.%04d:\033[0m\n", targetDate.day, targetDate.month, targetDate.year);
    while (fread(&temp, sizeof(Pretender), 1, fPretenders))
    {
        if (CompareDates(temp.RegisterDate, targetDate) > 0 && strstr(temp.skills, targetSkills))
        {
            fprintf(fReport, "%20s (ID %03d) - Зарегистрирован: %02d.%02d.%04d - Требования: %s\n", temp.FullName, temp.ID, temp.RegisterDate.day, temp.RegisterDate.month, temp.RegisterDate.year, temp.skills);
            printf("%20s (ID %03d) - Зарегистрирован: %02d.%02d.%04d - Требования: %s\n", temp.FullName, temp.ID, temp.RegisterDate.day, temp.RegisterDate.month, temp.RegisterDate.year, temp.skills);
            count++;
        }
    }

    if (count == 0)
    {
        fprintf(fReport, "\nНет соискателей с соответствующими навыками, зарегистрированных после %02d.%02d.%04d.\n", targetDate.day, targetDate.month, targetDate.year);
        printf("\n\033[32mНет соискателей с соответствующими навыками, зарегистрированных после %02d.%02d.%04d.\033[0m\n", targetDate.day, targetDate.month, targetDate.year);
    }
    else
    {
        fprintf(fReport, "\nВсего соискателей с соответсвующими навыками, зарегистрированных после %02d.%02d.%04d: %d\n", targetDate.day, targetDate.month, targetDate.year, count);
        printf("\n\033[32mВсего соискателей с соответсвующими навыками, зарегистрированных после %02d.%02d.%04d: %d\033[0m\n", targetDate.day, targetDate.month, targetDate.year, count);
    }

    Sleep(1000);

    fclose(fPretenders);
    fclose(fReport);
}

//------------------------------------------------------------------------------------------------------------------------------

void deleteVacancy(void)
{
    int pos_to_delete = binarySearchVacancyID();

    if (pos_to_delete < 0) return;

    FILE* fVacancies = fopen("vacancies.bit", "r+b");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[32mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fVacancies, 0, SEEK_END);
    int quantity = ftell(fVacancies) / sizeof(Vacancy);
    Vacancy buffer;

    for (int i = pos_to_delete + 1; i < quantity; i++)
    {
        fseek(fVacancies, i * sizeof(Vacancy), SEEK_SET);
        fread(&buffer, sizeof(Vacancy), 1, fVacancies);

        buffer.ID--;

        fseek(fVacancies, (i - 1) * sizeof(Vacancy), SEEK_SET);
        fwrite(&buffer, sizeof(Vacancy), 1, fVacancies);
    }

    fflush(fVacancies);

    _chsize(_fileno(fVacancies), (quantity - 1) * sizeof(Vacancy));

    fprintf(fReport, "\nВакансия была удалена.\n");
    printf("\n\033[32mВакансия была удалена.\033[0m\n");

    fclose(fVacancies);
    fclose(fReport);
}

void deletePretender(void)
{
    int pos_to_delete = binarySearchPretenderID();

    if (pos_to_delete < 0) return;

    FILE* fPretenders = fopen("pretenders.bit", "r+b");
    if (fPretenders == NULL)
    {
        printf("\033[31mОшибка открытия файла \"pretenders.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fPretenders, 0, SEEK_END);
    int quantity = ftell(fPretenders) / sizeof(Pretender);
    Pretender buffer;

    for (int i = pos_to_delete + 1; i < quantity; i++)
    {
        fseek(fPretenders, i * sizeof(Pretender), SEEK_SET);
        fread(&buffer, sizeof(Pretender), 1, fPretenders);

        buffer.ID--;

        fseek(fPretenders, (i - 1) * sizeof(Pretender), SEEK_SET);
        fwrite(&buffer, sizeof(Pretender), 1, fPretenders);
    }

    fflush(fPretenders);

    _chsize(_fileno(fPretenders), (quantity - 1) * sizeof(Pretender));

    fprintf(fReport, "\nСоискатель был удален.\n");
    printf("\n\033[32mСоискатель был удален.\033[0m\n");

    Sleep(1000);

    fclose(fPretenders);
    fclose(fReport);
}

//

void redactVacancy(void)
{
    int pos_to_delete = binarySearchVacancyID();

    if (pos_to_delete < 0) return;

    FILE* fVacancies = fopen("vacancies.bit", "r+b");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }
    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    int edit_choice = -1;

    do
    {
        Vacancy vac_to_edit;
        fseek(fVacancies, pos_to_delete * sizeof(Vacancy), SEEK_SET);
        fread(&vac_to_edit, sizeof(Vacancy), 1, fVacancies);


        printf("\n%-3d %-25.25s %-15.15s %-10.2lf %02d.%02d.%04d\n", vac_to_edit.ID, vac_to_edit.title, vac_to_edit.company, vac_to_edit.salary, vac_to_edit.CreationDate.day, vac_to_edit.CreationDate.month, vac_to_edit.CreationDate.year);

        PrintMenuRedactVacancy();

        if (scanf("%d", &edit_choice) != 1)
        {
            printf("\n\033[31mОшибка при считывании действия с вакансией!\033[0m\n");
            Sleep(1000);
            while (getchar() != '\n');
        }

        switch (edit_choice)
        {
        case 1:
        {
            printf("\033[33mВведите название должности => \033[0m");
            while (getchar() != '\n');
            fgets(vac_to_edit.title, MAX_NAME, stdin);

            fseek(fVacancies, pos_to_delete * sizeof(Vacancy), SEEK_SET);
            fwrite(&vac_to_edit, sizeof(Vacancy), 1, fVacancies);

            fprintf(fReport, "\nОтредактирована вакансия => %-3d %-25.25s %-15.15s %-10.2lf %02d. %02d. %04d\n", vac_to_edit.ID, vac_to_edit.title, vac_to_edit.company, vac_to_edit.salary, vac_to_edit.CreationDate.day, vac_to_edit.CreationDate.month, vac_to_edit.CreationDate.year);
            break;
        }

        case 2:
        {
            printf("\033[33mВведите название компании трудоустройщика => \033[0m");
            while (getchar() != '\n');
            fgets(vac_to_edit.company, MAX_NAME, stdin);

            fseek(fVacancies, pos_to_delete * sizeof(Vacancy), SEEK_SET);
            fwrite(&vac_to_edit, sizeof(Vacancy), 1, fVacancies);

            fprintf(fReport, "\nОтредактирована вакансия => %-3d %-25.25s %-15.15s %-10.2lf %02d. %02d. %04d\n", vac_to_edit.ID, vac_to_edit.title, vac_to_edit.company, vac_to_edit.salary, vac_to_edit.CreationDate.day, vac_to_edit.CreationDate.month, vac_to_edit.CreationDate.year);
            break;
        }

        case 3:
        {
            printf("\033[33mВведите предположительную зарплату специалиста => \033[0m");
            if ((scanf("%lf", &vac_to_edit.salary) != 1) || (&vac_to_edit.salary < 0))
            {
                printf("\033[31mОшибка ввода зарплаты!\033[0m");
                while (getchar() != '\n');
                fclose(fVacancies);
                Sleep(1000); return;
            }

            fseek(fVacancies, pos_to_delete * sizeof(Vacancy), SEEK_SET);
            fwrite(&vac_to_edit, sizeof(Vacancy), 1, fVacancies);

            fprintf(fReport, "\nОтредактирована вакансия => %-3d %-25.25s %-15.15s %-10.2lf %02d. %02d. %04d\n", vac_to_edit.ID, vac_to_edit.title, vac_to_edit.company, vac_to_edit.salary, vac_to_edit.CreationDate.day, vac_to_edit.CreationDate.month, vac_to_edit.CreationDate.year);
            break;
        }

        case 4:
        {
            printf("\033[33mВведите требования (через запятую) => \033[0m");
            while (getchar() != '\n');
            fgets(vac_to_edit.requests, MAX_STRING, stdin);

            fseek(fVacancies, pos_to_delete * sizeof(Vacancy), SEEK_SET);
            fwrite(&vac_to_edit, sizeof(Vacancy), 1, fVacancies);

            fprintf(fReport, "\nОтредактирована вакансия => %-3d %-25.25s %-15.15s %-10.2lf %02d. %02d. %04d\n", vac_to_edit.ID, vac_to_edit.title, vac_to_edit.company, vac_to_edit.salary, vac_to_edit.CreationDate.day, vac_to_edit.CreationDate.month, vac_to_edit.CreationDate.year);
            break;
        }

        case 5:
        {
            vac_to_edit.CreationDate = InsertDate();

            fseek(fVacancies, pos_to_delete * sizeof(Vacancy), SEEK_SET);
            fwrite(&vac_to_edit, sizeof(Vacancy), 1, fVacancies);

            fprintf(fReport, "\nОтредактирована вакансия => %-3d %-25.25s %-15.15s %-10.2lf %02d. %02d. %04d\n", vac_to_edit.ID, vac_to_edit.title, vac_to_edit.company, vac_to_edit.salary, vac_to_edit.CreationDate.day, vac_to_edit.CreationDate.month, vac_to_edit.CreationDate.year);
            break;
        }

        case 0:
        {
            printf("\n\033[33mВыход в меню работы с файлом...\033[0m\n");
            Sleep(1000);
            break;
        }

        default:
        {
            printf("\n\033[31mНекорректный выбор пункта меню редактирования вакансии!\033[0m\n");
            Sleep(1000);
        }
        }
    } while (edit_choice != 0);

    fclose(fVacancies);
    fclose(fReport);
}

void redactPretender(void)
{
    int pos_to_redact = binarySearchPretenderID();

    if (pos_to_redact < 0) return;

    FILE* fPretenders = fopen("pretenders.bit", "r+b");
    if (fPretenders == NULL)
    {
        printf("\033[31mОшибка открытия файла \"pretenders.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }
    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    int edit_choice = -1;

    do
    {
        Pretender pret_to_edit;
        fseek(fPretenders, pos_to_redact * sizeof(Pretender), SEEK_SET);
        fread(&pret_to_edit, sizeof(Pretender), 1, fPretenders);

        printf("\n%03d %20s %10lf %02d.%02d.%04d %s\n", pret_to_edit.ID, pret_to_edit.FullName, pret_to_edit.salary, pret_to_edit.RegisterDate.day, pret_to_edit.RegisterDate.month, pret_to_edit.RegisterDate.year, pret_to_edit.skills);

        PrintMenuRedactPretender();

        if (scanf("%d", &edit_choice) != 1)
        {
            printf("\n\033[31mОшибка при считывании действия с соискателем!\033[0m\n");
            Sleep(1000);
            while (getchar() != '\n');
        }

        switch (edit_choice)
        {
            case 1:
            {
                printf("\033[33mВведите ФИО соискателя => \033[0m");
                while (getchar() != '\n');
                fgets(pret_to_edit.FullName, MAX_NAME, stdin);

                fseek(fPretenders, pos_to_redact * sizeof(Pretender), SEEK_SET);
                fwrite(&pret_to_edit, sizeof(Pretender), 1, fPretenders);

                fprintf(fReport, "Отредактирован соискатель => %03d %20s %10lf %02d.%02d.%04d %s", pret_to_edit.ID, pret_to_edit.FullName, pret_to_edit.salary, pret_to_edit.RegisterDate.day, pret_to_edit.RegisterDate.month, pret_to_edit.RegisterDate.year, pret_to_edit.skills);
                break;
            }

            case 2:
            {
                printf("\033[33mВведите навыки соискателя => \033[0m");
                while (getchar() != '\n');
                fgets(pret_to_edit.skills, MAX_STRING, stdin);

                fseek(fPretenders, pos_to_redact * sizeof(Pretender), SEEK_SET);
                fwrite(&pret_to_edit, sizeof(Pretender), 1, fPretenders);

                fprintf(fReport, "\nОтредактирован соискатель => %03d %20s %10lf %02d.%02d.%04d %s\n", pret_to_edit.ID, pret_to_edit.FullName, pret_to_edit.salary, pret_to_edit.RegisterDate.day, pret_to_edit.RegisterDate.month, pret_to_edit.RegisterDate.year, pret_to_edit.skills);
                break;
            }

            case 3:
            {
                printf("\033[33mВведите желаемую зарплату соискателя => \033[0m");
                if ((scanf("%lf", &pret_to_edit.salary) != 1) || (pret_to_edit.salary < 0))
                {
                    printf("\033[31mОшибка ввода желаемой зарплаты!\033[0m");
                    Sleep(1000);
                    while (getchar() != '\n');
                    fclose(fPretenders);
                }

                fseek(fPretenders, pos_to_redact * sizeof(Pretender), SEEK_SET);
                fwrite(&pret_to_edit, sizeof(Pretender), 1, fPretenders);

                fprintf(fReport, "\nОтредактирован соискатель => %03d %20s %10lf %02d.%02d.%04d %s\n", pret_to_edit.ID, pret_to_edit.FullName, pret_to_edit.salary, pret_to_edit.RegisterDate.day, pret_to_edit.RegisterDate.month, pret_to_edit.RegisterDate.year, pret_to_edit.skills);
                break;
            }

            case 4:
            {
                pret_to_edit.RegisterDate = InsertDate();

                fseek(fPretenders, pos_to_redact * sizeof(Pretender), SEEK_SET);
                fwrite(&pret_to_edit, sizeof(Pretender), 1, fPretenders);

                fprintf(fReport, "\nОтредактирован соискатель => %03d %20s %10lf %02d.%02d.%04d %s\n", pret_to_edit.ID, pret_to_edit.FullName, pret_to_edit.salary, pret_to_edit.RegisterDate.day, pret_to_edit.RegisterDate.month, pret_to_edit.RegisterDate.year, pret_to_edit.skills);
                break;
            }

            case 0:
            {
                printf("\n\033[32mВыход в меню работы с файлом...\033[0m\n");
                Sleep(1000);
                break;
            }

            default:
            {
                printf("\n\033[31mНекорректный выбор пункта меню редактирования вакансии!\033[0m\n");
                Sleep(1000);
            }
        }
    } while (edit_choice != 0);

    fclose(fPretenders);
    fclose(fReport);
}

//----------------------------------------------------------------------------

void addVacancy(void)
{
    FILE* fVacancies = fopen("vacancies.bit", "r+b");
    if (fVacancies == NULL)
    {
        printf("\033[31mОшибка открытия файла \"vacancies.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fVacancies, 0, SEEK_END);
    int quantity = ftell(fVacancies) / sizeof(Vacancy);

    if (quantity > 1)
    {
        quickSortVacanciesID(fVacancies, 0, quantity - 1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    Vacancy newVacancy;
    int nextID = 1;

    if (quantity > 0) {
        Vacancy lastVacancy;

        fseek(fVacancies, (quantity - 1) * sizeof(Vacancy), SEEK_SET);
        fread(&lastVacancy, sizeof(Vacancy), 1, fVacancies);

        nextID = lastVacancy.ID + 1;
    }

    newVacancy.ID = nextID;

    printf("\n\033[33m--- Добавление вакансии ---\n");
    printf("Сгенерирован уникальный ID => %d\033[0m\n", newVacancy.ID);

    printf("\033[33mВведите название должности => \033[0m");
    while (getchar() != '\n');
    fgets(newVacancy.title, MAX_NAME, stdin);
    newVacancy.title[strcspn(newVacancy.title, "\n")] = '\0'; // Удаление \n

    printf("\033[33mВведите название компании трудоустройщика => \033[0m");
    fgets(newVacancy.company, MAX_NAME, stdin);
    newVacancy.company[strcspn(newVacancy.company, "\n")] = '\0'; // Удаление \n

    printf("\033[33mВведите предположительную зарплату специалиста => \033[0m");
    if ((scanf("%lf", &newVacancy.salary) != 1) || (newVacancy.salary < 0))
    {
        printf("\033[31mОшибка ввода зарплаты!\033[0m");

        while (getchar() != '\n');

        fclose(fVacancies);

        Sleep(1000);
        return;
    }


    printf("\033[33mВведите требования (через запятую) => \033[0m");
    while (getchar() != '\n');
    fgets(newVacancy.requests, MAX_STRING, stdin);

    newVacancy.CreationDate = InsertDate();

    fwrite(&newVacancy, sizeof(Vacancy), 1, fVacancies);
    fprintf(fReport, "\nСоздана новая вакансия => %-3d %-25.25s %-15.15s %-10.2lf %02d. %02d. %04d\n", newVacancy.ID, newVacancy.title, newVacancy.company, newVacancy.salary, newVacancy.CreationDate.day, newVacancy.CreationDate.month, newVacancy.CreationDate.year);

    fclose(fVacancies);
    fclose(fReport);
}

void addPretender(void)
{
    FILE* fPretenders = fopen("pretenders.bit", "r+b");
    if (fPretenders == NULL)
    {
        printf("\033[31mОшибка открытия файла \"pretenders.bit\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    fseek(fPretenders, 0, SEEK_END);
    int quantity = ftell(fPretenders) / sizeof(Pretender);

    if (quantity > 1)
    {
        quickSortPretendersID(fPretenders, 0, quantity - 1);
    }

    FILE* fReport = fopen("report.txt", "a");
    if (fReport == NULL)
    {
        printf("\033[31mОшибка открытия файла \"report.txt\"!\033[0m");
        Sleep(1000);
        exit(1);
    }

    Pretender newPretender;
    int nextID = 1;

    if (quantity > 0) {
        Pretender lastPretender;

        fseek(fPretenders, (quantity - 1) * sizeof(Pretender), SEEK_SET);
        fread(&lastPretender, sizeof(Pretender), 1, fPretenders);

        nextID = lastPretender.ID + 1;
    }

    newPretender.ID = nextID;

    printf("\n\033[33m--- Добавление соискателя ---\033[0m\n");
    printf("\033[33mСгенерирован уникальный ID => %d\033[0m\n", newPretender.ID);

    printf("\033[33mВведите ФИО соискателя => \033[0m");
    fgets(newPretender.FullName, MAX_NAME, stdin);
    newPretender.FullName[strcspn(newPretender.FullName, "\n")] = '\0'; // Удаление \n

    printf("\033[33mВведите навыки соискателя => \033[0m");
    fgets(newPretender.skills, MAX_STRING, stdin);
    newPretender.skills[strcspn(newPretender.skills, "\n")] = '\0'; // Удаление \n

    printf("\033[33mВведите желаемую зарплату соискателя => \033[0m");
    if (scanf("%lf", &newPretender.salary) != 1)
    {
        printf("\033[31mОшибка ввода желаемой зарплаты!\033[0m");
        Sleep(1000);
        while (getchar() != '\n');
        fclose(fPretenders);
    }


    newPretender.RegisterDate = InsertDate();

    fwrite(&newPretender, sizeof(Pretender), 1, fPretenders);
    fprintf(fReport, "Создан новый соискатель => %03d %20s %10lf %02d.%02d.%04d %s", newPretender.ID, newPretender.FullName, newPretender.salary, newPretender.RegisterDate.day, newPretender.RegisterDate.month, newPretender.RegisterDate.year, newPretender.skills);

    fclose(fPretenders);
    fclose(fReport);
}