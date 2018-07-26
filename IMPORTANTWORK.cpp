// IMPORTANTWORK.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip> 
#include <Windows.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
struct base_data
{
	string number_phone;// номер телефона
	string name; // имя
	string surname; // фамилия
	string patronymic; // отчество
	string mail; // почта
	string street; // улица
	string date; // дата рождения
	int j;// номер сотрудника;
	base_data*next; // ссылка на следущий
	base_data*prev; // ссылка на предыдущий
};
void show(base_data*begin)//вывод
{
	std::system("cls");
	if (begin != NULL)
	{
		cout << "|" << setw(3) << "№" << setw(2) << "|"
			<< setw(12) << "Фамилия" << setw(2) << "|"
			<< setw(12) << "Имя" << setw(2) << "|"
			<< setw(15) << "Отчество" << setw(2) << "|"
			<< setw(12) << "Дата(Г/М/Ч)" << setw(2) << "|"
			<< setw(10) << "Номер" << setw(2) << "|"
			<< setw(17) << "Улица" << setw(2) << "|"
			<< setw(25) << "Email" << setw(2) << "|" << endl;
		cout << "|____|_____________|_____________|________________|_____________|___________|__________________|__________________________|" << endl;
	}
	while (begin != NULL)
	{
		cout << "|" << setw(3) << begin->j << setw(2) << "|"
			<< setw(12) << begin->surname << setw(2) << "|"
			<< setw(12) << begin->name << setw(2) << "|"
			<< setw(15) << begin->patronymic << setw(2) << "|"
			<< setw(12) << begin->date << setw(2) << "|"
			<< setw(10) << begin->number_phone << setw(2) << "|"
			<< setw(17) << begin->street << setw(2) << "|"
			<< setw(25) << begin->mail << setw(2) << "|" << endl;
		cout << "|____|_____________|_____________|________________|_____________|___________|__________________|__________________________|" << endl;
		begin = begin->next;
	}
};
string proverka(string searchname)//проверка ввода
{
	char tj[11] = "0123456789";
	int count = searchname.length();
	for (int i = 0; i <count; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (searchname[i] == tj[j])
			{
				cout << "Исправте пожалуйста: ";
				cin >> searchname;
				count = searchname.length();
				i = -1;
				break;
			}
		}
	}
	return searchname;
}
void show_test(base_data*begin)//показать одного сотрудника
{
	cout << "==========================================================================================================================" << endl;
	cout << "|" << setw(3) << "№" << setw(2) << "|"
		<< setw(12) << "Фамилия" << setw(2) << "|"
		<< setw(12) << "Имя" << setw(2) << "|"
		<< setw(15) << "Отчество" << setw(2) << "|"
		<< setw(12) << "Дата(Г/М/Ч)" << setw(2) << "|"
		<< setw(10) << "Номер" << setw(2) << "|"
		<< setw(17) << "Улица" << setw(2) << "|"
		<< setw(25) << "Email" << setw(2) << "|" << endl;
	cout << "|____|_____________|_____________|________________|_____________|___________|__________________|__________________________|" << endl;
	cout << "|" << setw(3) << begin->j << setw(2) << "|"
		<< setw(12) << begin->surname << setw(2) << "|"
		<< setw(12) << begin->name << setw(2) << "|"
		<< setw(15) << begin->patronymic << setw(2) << "|"
		<< setw(12) << begin->date << setw(2) << "|"
		<< setw(10) << begin->number_phone << setw(2) << "|"
		<< setw(17) << begin->street << setw(2) << "|"
		<< setw(25) << begin->mail << setw(2) << "|" << endl;
	cout << "|____|_____________|_____________|________________|_____________|___________|__________________|__________________________|" << endl;

};
void search_nname(base_data*begin, base_data*end)//поиск по первой букве имени
{
	if (begin == NULL || end == NULL)
	{
		cout << "Ошибка. Список пустой" << endl;
		system("cls");
		return;
	}
	cout << "ВВедите букву на которую начинается имя: ";
	string searchname;;
	cin >> searchname;
	char tj[11] = "0123456789";
	for (int i = 0; i <1; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (searchname[0] == tj[j])
			{
				cin >> searchname;
				j = -1;
				i = -1;
			}
		}
	}
	string temp;
	while (begin != NULL)
	{
		temp = begin->name;
		if (temp[0] == searchname[0])
		{
			show_test(begin);
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");
	return;
};
void search_ssurname(base_data*begin, base_data*end)// поиск по первой букве фамилии
{
	if (begin == NULL || end == NULL)
	{
		cout << "Ошибка. Список пустой" << endl;
		system("cls");
		return;
	}
	cout << "ВВедите букву на которую начинается фамилия: ";
	string searchname;;
	cin >> searchname;
	string temp;
	char tj[11] = "0123456789";
	for (int i = 0; i <1; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (searchname[0] == tj[j])
			{
				cin >> searchname;
				j = -1;
				i = -1;
			}
		}
	}
	while (begin != NULL)
	{
		temp = begin->surname;

		if (temp[0] == searchname[0])
		{
			show_test(begin);
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");
	return;
};
void search_number(base_data*begin, base_data*end) // ищем мобильный номер
{
	if (begin == NULL || end == NULL)//он пустой
	{
		system("cls");
		show(begin);
		return;
	}
	cout << "ВВедите номер мобильного телефона: ";
	string search_num;
	cin >> search_num;
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "Такого номера нету в базе" << endl;
			return;
		}
		if (begin->number_phone == search_num)
		{
			show_test(begin);
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");
};
void search_name(base_data*begin, base_data*end) // ищем имя
{
	if (begin == NULL || end == NULL)
	{
		cout << "Ошибка. Список пустой" << endl;
		system("cls");
		return;
	}
	cout << "ВВедите имя: ";
	string searchname;;
	cin >> searchname;
	searchname = proverka(searchname);
	while (begin != NULL)
	{
		if (begin->name == searchname)
		{
			show_test(begin);
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");
	return;
};
void search_surname(base_data*begin, base_data*end) // ищем фамилию
{
	if (begin == NULL || end == NULL)
	{
		cout << "Ошибка. Список пустой" << endl;
		system("cls");
		return;
	}
	cout << "ВВедите фамилию: ";
	string searchname;;
	cin >> searchname;
	searchname = proverka(searchname);
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "Такой фамилии нету в базе" << endl;
			return;
		}
		if (begin->name == searchname)
		{
			show_test(begin);
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");
};
void search_patronymic(base_data*begin, base_data*end) // ищем отчество
{
	if (begin == NULL || end == NULL)
	{
		cout << "Ошибка. Список пустой" << endl;
		system("cls");
		return;
	}
	cout << "ВВедите отчество: ";
	string searchname;
	cin >> searchname;
	searchname = proverka(searchname);
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "Такого отчества нету в базе" << endl;
			return;
		}
		if (begin->patronymic == searchname)
		{
			show_test(begin);
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");

};
void search_mail(base_data*begin, base_data*end) // ищем почту
{
	if (begin == NULL || end == NULL)
	{
		cout << "Ошибка. Список пустой" << endl;
		system("cls");
		return;
	}
	cout << "Ведите e-mail адресс : ";
	string search_num;
	cin >> search_num;
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "Такой почты не нашлось" << endl;
			return;
		}
		if (begin->mail == search_num)
		{
			show_test(begin);
			return;
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");

};
void search_street(base_data*begin, base_data*end) // ищем улицу
{
	if (begin == NULL || end == NULL)
	{
		cout << "Ошибка. Список пустой" << endl;
		system("cls");
		return;
	}
	cout << "ВВедите улицу: ";
	string searchname;
		cin.ignore();
	getline(cin, searchname);
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "Такой улицы не нашлось" << endl;
			return;
		}
		if (begin->street == searchname)
		{
			show_test(begin);
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");
};
void search_data(base_data*begin, base_data*end)// ищем дату рождения
{
	if (begin == NULL || end == NULL)
	{
		cout << "Ошибка. Список пустой" << endl;
		system("cls");
		return;
	}
	cout << "Ведите дату(Г/М/Ч): ";
	string search_num;
	cin >> search_num;
	while (begin != NULL)
	{
		if (begin->date == search_num)
		{
			show_test(begin);
		}
		begin = begin->next;
	}
	cout << endl;
	system("PAUSE");
	return;
};
void sort_name(base_data**begin, base_data**end) // сортировка по имени
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	else
	{
		base_data*temp, *temp1;
		while ((*begin)->next != NULL)
		{
			if ((*begin)->name > (*begin)->next->name && (*begin)->next != NULL)
			{
				temp = (*begin);
				temp1 = (*begin)->next->next;
				*begin = (*begin)->next;
				(*begin)->next = temp;
				(*begin)->prev = temp->prev;
				temp->next = temp1;
				temp->prev = (*begin);
				if (temp1 != NULL)
				{
					temp1->prev = temp;
				}
				if ((*begin)->prev != NULL)
				{
					(*begin) = (*begin)->prev;
					(*begin)->next = temp->prev;
				}
				while ((*begin)->prev != NULL)
				{
					*begin = (*begin)->prev;
				}
			}
			else
			{
				*begin = (*begin)->next;
			}
		}
		while ((*begin)->prev != NULL) // бегин на начало списка
		{
			*begin = (*begin)->prev;
		}
		while ((*end)->next != NULL)
		{
			(*end) = (*end)->next;
		}
	}
	
};
void sort_surname(base_data**begin, base_data**end) // сортировка по фамилии
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	else
	{
		base_data*temp, *temp1;
		while ((*begin)->next != NULL)
		{
			if ((*begin)->surname > (*begin)->next->surname && (*begin)->next != NULL)
			{
				temp = (*begin);
				temp1 = (*begin)->next->next;
				*begin = (*begin)->next;
				(*begin)->next = temp;
				(*begin)->prev = temp->prev;
				temp->next = temp1;
				temp->prev = (*begin);
				if (temp1 != NULL)
				{
					temp1->prev = temp;
				}
				if ((*begin)->prev != NULL)
				{
					(*begin) = (*begin)->prev;
					(*begin)->next = temp->prev;
				}
				while ((*begin)->prev != NULL)
				{
					*begin = (*begin)->prev;
				}
			}
			else
			{
				*begin = (*begin)->next;
			}
		}
		while ((*begin)->prev != NULL) // бегин на начало списка
		{
			*begin = (*begin)->prev;
		}
		while ((*end)->next != NULL)
		{
			(*end) = (*end)->next;
		}
	}
	
};
void sort_patronomic(base_data**begin, base_data**end) // сортировка по отчеству
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	else
	{
		base_data*temp, *temp1;
		while ((*begin)->next != NULL)
		{
			if ((*begin)->patronymic > (*begin)->next->patronymic && (*begin)->next != NULL)
			{
				temp = (*begin);
				temp1 = (*begin)->next->next;
				*begin = (*begin)->next;
				(*begin)->next = temp;
				(*begin)->prev = temp->prev;
				temp->next = temp1;
				temp->prev = (*begin);
				if (temp1 != NULL)
				{
					temp1->prev = temp;
				}
				if ((*begin)->prev != NULL)
				{
					(*begin) = (*begin)->prev;
					(*begin)->next = temp->prev;
				}
				while ((*begin)->prev != NULL)
				{
					*begin = (*begin)->prev;
				}
			}
			else
			{
				*begin = (*begin)->next;
			}
		}
		while ((*begin)->prev != NULL) // бегин на начало списка
		{
			*begin = (*begin)->prev;
		}
		while ((*end)->next != NULL)
		{
			(*end) = (*end)->next;
		}
	}
	
};
void sort_date(base_data**begin, base_data**end) // сортировка по дате рождения
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	else
	{
		base_data*temp, *temp1;
		while ((*begin)->next != NULL)
		{
			if ((*begin)->date > (*begin)->next->date && (*begin)->next != NULL)
			{
				temp = (*begin);
				temp1 = (*begin)->next->next;
				*begin = (*begin)->next;
				(*begin)->next = temp;
				(*begin)->prev = temp->prev;
				temp->next = temp1;
				temp->prev = (*begin);
				if (temp1 != NULL)
				{
					temp1->prev = temp;
				}
				if ((*begin)->prev != NULL)
				{
					(*begin) = (*begin)->prev;
					(*begin)->next = temp->prev;
				}
				while ((*begin)->prev != NULL)
				{
					*begin = (*begin)->prev;
				}
			}
			else
			{
				*begin = (*begin)->next;
			}
		}
		while ((*begin)->prev != NULL) // бегин на начало списка
		{
			*begin = (*begin)->prev;
		}
		while ((*end)->next != NULL)
		{
			(*end) = (*end)->next;
		}
	}
	
};
void add_employee(base_data**end, base_data**begin, int &k) // добавить сотрудника
{
	ofstream fout("base_reserv.txt", ios_base::app);//файл для записи
	int c = 0;
	cout << "Введите количество сотрудников которое хотите добавить в базу: ";
	cin >> c;
	if (c == 0)
	{
		return;
	}
	if (*end == NULL || (*begin) == NULL)// если список пустой
	{
		if ((*begin) == NULL)
		{
			(*begin) = new base_data;
		}
		(*end) = (*begin);
		(*end)->prev = NULL;
		base_data*temp = NULL;
		for (int i = 0; i < c; i++)
		{
			cout << "Сотрудник №" << k << endl;
			(*end)->j = k;
			fout << k << endl;
			k++;
			cout << "Фамилия: ";
			cin >> (*end)->surname;
			(*end)->surname = proverka((*end)->surname);
			fout << (*end)->surname <<endl;
			cout << "Имя: ";
			cin >> (*end)->name;
			(*end)->name = proverka((*end)->name);
			fout << (*end)->name <<endl;
			cout << "Отечство: ";
			cin >> (*end)->patronymic;
			(*end)->patronymic = proverka((*end)->patronymic);
			fout << (*end)->patronymic << endl;
			cout << "Дата рождения(Г/М/Ч): ";
			cin >> (*end)->date;
			fout << (*end)->date <<endl;
			cout << "Мобильный номер: ";
			cin >> (*end)->number_phone;
			fout << (*end)->number_phone <<endl;
			cout << "Улица/дом: ";
			cin.ignore();
			getline(cin,(*end)->street);
			fout << (*end)->street <<endl;
			cout << "Email: ";
			cin >> (*end)->mail;
			fout << (*end)->mail << " " << endl;
			if (i == c - 1)
			{
				(*end)->next = NULL;
				(*end)->prev = temp;
			}
			else
			{
				(*end)->next = new base_data;
				temp = *end;
				*end = (*end)->next;
				(*end)->prev = temp;
			}
		}
		show(*begin);
		fout.close();
		return;
	}
	else
	{
		(*end)->next = new base_data;
		base_data*temp = *end;
		*end = (*end)->next;
		(*end)->prev = temp;
		for (int i = 0; i < c; i++)
		{
			std::cout << "Сотрудник №" << k << endl;
			(*end)->j = k;
			fout << k <<endl;
			k++;
			std::cout << "Фамилия: ";
			std::cin >> (*end)->surname;
			(*end)->surname = proverka((*end)->surname);
			fout << (*end)->surname << " ";
			std::cout << "Имя: ";
			std::cin >> (*end)->name;
			(*end)->name = proverka((*end)->name);
			fout << (*end)->name <<endl;
			std::cout << "Отечство: ";
			std::cin >> (*end)->patronymic;
			(*end)->patronymic = proverka((*end)->patronymic);
			fout << (*end)->patronymic << endl;
			std::cout << "Дата рождения(Г/М/Ч): ";
			std::cin >> (*end)->date;
			fout << (*end)->date << endl;
			std::cout << "Мобильный номер: ";
			std::cin >> (*end)->number_phone;
			fout << (*end)->number_phone <<endl;
			std::cout << "Улица/дом: ";
			cin.ignore();
			std::getline(cin,(*end)->street);
			fout << (*end)->street <<endl;
			std::cout << "Email: ";
			std::cin >> (*end)->mail;
			fout << (*end)->mail << endl;
			if (i == c - 1)
			{
				(*end)->next = NULL;
			}
			else
			{
				(*end)->next = new base_data;
				temp = *end;
				*end = (*end)->next;
			}
			(*end)->prev = temp;
		}
		show(*begin);
		fout.close();
		return;
	}
};
void remove_employee(base_data**begin, base_data**end) // удалить с базы
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	base_data *start = (*begin);
	int i;
	cout << "Удалить из базы человека под номером: ";
	cin >> i;
	while ((*begin)->j != i) // ставим указатель на нужный нам элемент
	{
		*begin = (*begin)->next;
		if ((*begin) == NULL)
		{
			(*begin) = start;
			return;
		}
	}
	if ((*begin)->next == NULL && (*begin)->prev == NULL)// удаление первого и последнего
	{
		base_data * temp = *begin;
		temp = *begin;
		delete temp;
		*begin = NULL;
		*end = NULL;
		return;
	}
	if ((*begin)->prev == NULL && (*begin)->next != NULL)// удаление первого
	{
		base_data * temp = *begin;
		*begin = (*begin)->next;
		delete temp;
		(*begin)->prev = NULL;
		return;
	}
	if ((*begin)->next == NULL && (*begin)->prev != NULL)// удаление последнего
	{
		base_data *temp = *begin;
		*begin = (*begin)->prev;
		(*begin)->next = NULL;
		(*end) = (*begin);
		(*begin) = start;
		delete temp;
		return;
	}
	if ((*begin)->next != NULL && (*begin)->prev != NULL)// удаление в середине
	{
		base_data *del = *begin;
		base_data * temp = (*begin)->next;
		base_data * temp1 = (*begin)->prev;
		temp->prev = temp1;
		temp1->next = temp;
		delete del;
		(*begin) = start;
		return;
	}
};
void restore_data(base_data**end, base_data**begin)
{
	ifstream fin("base_reserv.txt", ios_base::app);
	FILE *s = fopen("base_reserv.txt", "rb");
	fseek(s, 0, SEEK_END);
	long file_size = ftell(s);
	fclose(s);
	if (file_size == 0)
	{
		return;
	}
	if (*end == NULL || (*begin) == NULL)// если список пустой
	{
		if ((*begin) == NULL)
		{
			(*begin) = new base_data;
		}
		(*end) = (*begin);
		(*end)->prev = NULL;
		base_data*temp = NULL;
		while (!fin.eof())
		{
		
		fin>> (*end)->j >>
		(*end)->surname >> 
		(*end)->name >> 
		(*end)->patronymic >> 
		(*end)->date >> 
		(*end)->number_phone;
		fin.ignore();
		getline(fin, (*end)->street);
		fin >> (*end)->mail;
			if (!fin.eof())
			{
				(*end)->next = new base_data;
				temp = *end;
				*end = (*end)->next;
				(*end)->prev = temp;
			}
		}
	
			temp = (*end);
			(*end) = (*end)->prev;
			delete temp;
			(*end)->next = NULL;
			fin.close();
			return;
	}
	/*else
	{
		(*end)->next = new base_data;
		base_data*temp = *end;
		*end = (*end)->next;
		(*end)->prev = temp;
		while (!fin.eof())
		{

			fin >> (*end)->j >> (*end)->surname >> (*end)->name >> (*end)->patronymic >> (*end)->date >> (*end)->number_phone >> (*end)->street >> (*end)->mail;
			if (!fin.eof())
			{
				(*end)->next = new base_data;
				temp = *end;
				*end = (*end)->next;
				(*end)->prev = temp;
			}
		}
		temp = (*end);
		(*end) = (*end)->prev;
		delete temp;
		(*end)->next = NULL;
		fin.close();
		return;
	}*/
};
void correct_number(base_data*begin, int&k)// корректировка нумерации после изминений
{
	k = 1;
	while (begin != NULL)
	{
		begin->j = k;
		k++;
		begin = begin->next;
	}
}
void correct_pepople(base_data*begin)// редактировать данные сотрудника
{
	int m = 1;
	int c;
	cout << "Введите номер сотрудника у которого нужно изменить данные: ";
	cin >> c;
	while (begin->j != c)
	{
		begin = begin->next;
	}
	show_test(begin);
	while (m != 0)
	{
		cout << "Изменить имя - 1\n"
			<< "Изменить фамилию - 2\n"
			<< "Изменить Отчество -3\n"
			<< "Изменить дату-4\n"
			<< "Изменить e-mail - 5\n"
			<< "Изменить адресс - 6\n"
			<< "Изменить номер - 7\n"
			<< "exit - 0" << endl;
		cin >> m;
		switch (m)
		{
		case(1):
		{
			cout << "Введите имя ";
			cin >> begin->name;
			show_test(begin);
			break;
		}
		case(2):
		{
			cout << "Введите фамилию: ";
			cin >> begin->surname;
			show_test(begin);
			break;
		}
		case(3):
		{
			cout << "Введите отчество: ";
			cin >> begin->patronymic;
			show_test(begin);
			break;
		}
		case(4):
		{
			cout << "Введите дату родждения(Г/М/Ч): ";
			cin >> begin->date;
			show_test(begin);
			break;
		}
		case(5):
		{
			cout << "Введите e-mail: ";
			cin >> begin->mail;
			show_test(begin);
			break;
		}
		case(6):
		{
			cout << "Введите адресс: ";
			cin.ignore();
			getline(cin, begin->street);
			show_test(begin);
			break;
		}
		case(7):
		{
			cout << "Введите номер: ";
			cin >> begin->number_phone;
			show_test(begin);
			break;
		}
		}
	}
	cout << endl;
	system("PAUSE");
}
void backup(base_data*begin) // запись обновленной базы
{
	ofstream fout("base_reserv.txt", ios_base::trunc);
	while (begin != NULL)
	{
		fout << begin->j <<endl;
		fout << begin->surname <<endl;
		fout << begin->name <<endl;
		fout << begin->patronymic <<endl;
		fout << begin->date <<endl;
		fout << begin->number_phone <<endl;
		fout << begin->street << endl;
		fout << begin->mail <<endl;
		begin = begin->next;
	}
	fout.close();
}
void del(base_data**begin)//освобождение памяти
{
	while ((*begin) != NULL)
	{
		base_data*temp = (*begin);
		temp = (*begin);
		*begin = (*begin)->next;
		delete temp;
	}
	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = GetLargestConsoleWindowSize( hStdout );
	crd.X-=4;
	crd.Y-=4;
	SMALL_RECT sr = {0,0,crd.X-1, crd.Y-1};
	SetConsoleScreenBufferSize(hStdout,crd);
	SetConsoleWindowInfo(hStdout,true,&sr);*/
	system("color F0");
	SetConsoleCP(1251); //русский текст
	SetConsoleOutputCP(1251);// русский текст
	int j = 1;
	base_data *begin = NULL;// начало списка;
	base_data *end = NULL; // конец списка;
	restore_data(&end, &begin);
	correct_number(begin, j);
	show(begin);
	string l = "1";
	while (l != "0")
	{
		cout << "Для добавления нажмите - 1\n"
			<< "Для удаления сотрудника из базы нажмите - 2\n"
			<< "Для поиска по номеру телефона нажмите - 3\n"
			<< "Для поиска по  имени  нажмите - 4\n"
			<< "Для поиска по фамилии нажмите - 5\n"
			<< "Для поиска по отчеству нажмите - 6\n"
			<< "Для поиска по  email нажмите - 7\n"
			<< "Для поиска по улице нажмите - 8\n"
			<< "Для поиска по дате рождения нажмите - 9\n"
			<< "Для сортировки по имени нажмите - 10\n"
			<< "Для сортировки по  фамилии нажмите - 11\n"
			<< "Для сортировки по отчеству нажмите - 12\n"
			<< "Для сортировки по дате нажмите - 13\n"
			<< "Найти все имена которые начинаются на заданую букву - 14\n"
			<< "Найти все Фамилии которые начинаются на заданую букву - 15\n"
			<< "Редактировать данные сотрудника нажмите - 16\n"
			<< " Сделать резервную копию - 3223\n" 
			<< " Для выхода с базы нажмите - 0."<< endl;
		cout << "Ваш выбор: ";
		cin >> l;
		while (l != "1"&&l != "2"&&l != "3"&&l != "4"&&l != "5"&&l != "6"&&
			l != "7"&&l != "8"&&l != "9"&&l != "10"&&l != "11"&&l != "12"&&
			l != "13"&&l != "14"&&l != "15"&&l != "16"&&l != "3223"&&l != "0"&&l != "17")//проверка
		{
			cout << "Попробуйте еще раз:" << endl;
			cin >> l;
		}
		switch (stoi(l))
		{
		case(1):
		{
			add_employee(&end, &begin, j);
			break;
		}
		case(2):
		{
			remove_employee(&begin, &end);
			correct_number(begin, j);
			show(begin);
			break;
		}
		case(3):
		{
			show(begin);
			search_number(begin, end);// поиск по номеру телефона
			break;
		}
		case(4):
		{
			show(begin);
			search_name(begin, end); // поиск по имени
			break;
		}
		case(5):
		{
			show(begin);
			search_surname(begin, end); // по фамилии
			break;
		}
		case(6):
		{
			show(begin);
			search_patronymic(begin, end); // по отчеству

			break;
		}
		case(7):
		{
			show(begin);
			search_mail(begin, end);
			break;
		}
		case(8):
		{
			show(begin);
			search_street(begin, end);
			break;
		}
		case(9):
		{
			show(begin);
			search_data(begin, end);
			break;
		}
		case(10):
		{
			sort_name(&begin, &end);
			correct_number(begin, j);
			show(begin);
			break;
		}
		case(11):
		{
			sort_surname(&begin, &end);
			correct_number(begin, j);
			show(begin);
			break;
		}
		case(12):
		{
			sort_patronomic(&begin, &end);
			correct_number(begin, j);
			show(begin);
			break;
		}
		case(13):
		{
			sort_date(&begin, &end);
			correct_number(begin, j);
			show(begin);
			break;
		}
		case(14):
		{
			show(begin);
			search_nname(begin, end);
			break;
		}
		case(15):
		{
			show(begin);
			search_ssurname(begin, end);
			break;
		}
		case(16):
		{

			correct_pepople(begin);
			show(begin);
			break;
		}
		case(3223):
		{
			show(begin);
			backup(begin);
			break;
		}
		}
	}
	del(&begin);
	std::system("PAUSE");
	return 0;
}
