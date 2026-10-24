#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Struct.h"

//

void createFilesAndInitData(void);

//

void PrintMenu(int);

void PrintFileMenu(void);

void PrintMenuRedactVacancy(void);

void PrintMenuRedactPretender(void);

//

Date InsertDate(void);

int CompareDates(Date Date1, Date Date2);

//

void addVacancy(void);

void addPretender(void);

//

void RecreateFileVacancies(void);

void RecreateFilePretenders(void);

//

void printVacancies(void);

void printPretenders(void);

//

void linearSearchPretenderSalary(void);

void binarySearchVacancyTitle(void);

int binarySearchVacancyID(void);

int binarySearchPretenderID(void);

//

void quickSortVacanciesSalary(FILE*, int, int);

void quickSortVacanciesTitle(FILE*, int, int);

void sortVacanciesByDateSelection(void);

void sortPretendersByDateInsertion(void);

//

void matchVacancies(void);

void statisticPretenders(void);

//

void deleteVacancy(void);

void deletePretender(void);

//

void redactVacancy(void);

void redactPretender(void);