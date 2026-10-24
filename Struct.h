#pragma once

#define MAX_STRING 150
#define MAX_NAME 80
#define MAX_BUFFER 50
#define Sleep_time 2000

typedef struct
{
	int day;
	int month;
	int year;
} Date;

typedef struct
{
	int ID;
	char title[MAX_NAME];
	char company[MAX_NAME];
	double salary;
	char requests[MAX_STRING];
	Date CreationDate;
} Vacancy;

typedef struct
{
	int ID;
	char FullName[MAX_NAME];
	char skills[MAX_STRING];
	double salary;
	Date RegisterDate;
} Pretender;