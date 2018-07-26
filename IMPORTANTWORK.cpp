// IMPORTANTWORK.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	string number_phone;// ����� ��������
	string name; // ���
	string surname; // �������
	string patronymic; // ��������
	string mail; // �����
	string street; // �����
	string date; // ���� ��������
	int j;// ����� ����������;
	base_data*next; // ������ �� ��������
	base_data*prev; // ������ �� ����������
};
void show(base_data*begin)//�����
{
	std::system("cls");
	if (begin != NULL)
	{
		cout << "|" << setw(3) << "�" << setw(2) << "|"
			<< setw(12) << "�������" << setw(2) << "|"
			<< setw(12) << "���" << setw(2) << "|"
			<< setw(15) << "��������" << setw(2) << "|"
			<< setw(12) << "����(�/�/�)" << setw(2) << "|"
			<< setw(10) << "�����" << setw(2) << "|"
			<< setw(17) << "�����" << setw(2) << "|"
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
string proverka(string searchname)//�������� �����
{
	char tj[11] = "0123456789";
	int count = searchname.length();
	for (int i = 0; i <count; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (searchname[i] == tj[j])
			{
				cout << "�������� ����������: ";
				cin >> searchname;
				count = searchname.length();
				i = -1;
				break;
			}
		}
	}
	return searchname;
}
void show_test(base_data*begin)//�������� ������ ����������
{
	cout << "==========================================================================================================================" << endl;
	cout << "|" << setw(3) << "�" << setw(2) << "|"
		<< setw(12) << "�������" << setw(2) << "|"
		<< setw(12) << "���" << setw(2) << "|"
		<< setw(15) << "��������" << setw(2) << "|"
		<< setw(12) << "����(�/�/�)" << setw(2) << "|"
		<< setw(10) << "�����" << setw(2) << "|"
		<< setw(17) << "�����" << setw(2) << "|"
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
void search_nname(base_data*begin, base_data*end)//����� �� ������ ����� �����
{
	if (begin == NULL || end == NULL)
	{
		cout << "������. ������ ������" << endl;
		system("cls");
		return;
	}
	cout << "������� ����� �� ������� ���������� ���: ";
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
void search_ssurname(base_data*begin, base_data*end)// ����� �� ������ ����� �������
{
	if (begin == NULL || end == NULL)
	{
		cout << "������. ������ ������" << endl;
		system("cls");
		return;
	}
	cout << "������� ����� �� ������� ���������� �������: ";
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
void search_number(base_data*begin, base_data*end) // ���� ��������� �����
{
	if (begin == NULL || end == NULL)//�� ������
	{
		system("cls");
		show(begin);
		return;
	}
	cout << "������� ����� ���������� ��������: ";
	string search_num;
	cin >> search_num;
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "������ ������ ���� � ����" << endl;
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
void search_name(base_data*begin, base_data*end) // ���� ���
{
	if (begin == NULL || end == NULL)
	{
		cout << "������. ������ ������" << endl;
		system("cls");
		return;
	}
	cout << "������� ���: ";
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
void search_surname(base_data*begin, base_data*end) // ���� �������
{
	if (begin == NULL || end == NULL)
	{
		cout << "������. ������ ������" << endl;
		system("cls");
		return;
	}
	cout << "������� �������: ";
	string searchname;;
	cin >> searchname;
	searchname = proverka(searchname);
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "����� ������� ���� � ����" << endl;
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
void search_patronymic(base_data*begin, base_data*end) // ���� ��������
{
	if (begin == NULL || end == NULL)
	{
		cout << "������. ������ ������" << endl;
		system("cls");
		return;
	}
	cout << "������� ��������: ";
	string searchname;
	cin >> searchname;
	searchname = proverka(searchname);
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "������ �������� ���� � ����" << endl;
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
void search_mail(base_data*begin, base_data*end) // ���� �����
{
	if (begin == NULL || end == NULL)
	{
		cout << "������. ������ ������" << endl;
		system("cls");
		return;
	}
	cout << "������ e-mail ������ : ";
	string search_num;
	cin >> search_num;
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "����� ����� �� �������" << endl;
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
void search_street(base_data*begin, base_data*end) // ���� �����
{
	if (begin == NULL || end == NULL)
	{
		cout << "������. ������ ������" << endl;
		system("cls");
		return;
	}
	cout << "������� �����: ";
	string searchname;
		cin.ignore();
	getline(cin, searchname);
	while (begin != NULL)
	{
		if (begin == NULL)
		{
			cout << "����� ����� �� �������" << endl;
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
void search_data(base_data*begin, base_data*end)// ���� ���� ��������
{
	if (begin == NULL || end == NULL)
	{
		cout << "������. ������ ������" << endl;
		system("cls");
		return;
	}
	cout << "������ ����(�/�/�): ";
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
void sort_name(base_data**begin, base_data**end) // ���������� �� �����
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
		while ((*begin)->prev != NULL) // ����� �� ������ ������
		{
			*begin = (*begin)->prev;
		}
		while ((*end)->next != NULL)
		{
			(*end) = (*end)->next;
		}
	}
	
};
void sort_surname(base_data**begin, base_data**end) // ���������� �� �������
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
		while ((*begin)->prev != NULL) // ����� �� ������ ������
		{
			*begin = (*begin)->prev;
		}
		while ((*end)->next != NULL)
		{
			(*end) = (*end)->next;
		}
	}
	
};
void sort_patronomic(base_data**begin, base_data**end) // ���������� �� ��������
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
		while ((*begin)->prev != NULL) // ����� �� ������ ������
		{
			*begin = (*begin)->prev;
		}
		while ((*end)->next != NULL)
		{
			(*end) = (*end)->next;
		}
	}
	
};
void sort_date(base_data**begin, base_data**end) // ���������� �� ���� ��������
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
		while ((*begin)->prev != NULL) // ����� �� ������ ������
		{
			*begin = (*begin)->prev;
		}
		while ((*end)->next != NULL)
		{
			(*end) = (*end)->next;
		}
	}
	
};
void add_employee(base_data**end, base_data**begin, int &k) // �������� ����������
{
	ofstream fout("base_reserv.txt", ios_base::app);//���� ��� ������
	int c = 0;
	cout << "������� ���������� ����������� ������� ������ �������� � ����: ";
	cin >> c;
	if (c == 0)
	{
		return;
	}
	if (*end == NULL || (*begin) == NULL)// ���� ������ ������
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
			cout << "��������� �" << k << endl;
			(*end)->j = k;
			fout << k << endl;
			k++;
			cout << "�������: ";
			cin >> (*end)->surname;
			(*end)->surname = proverka((*end)->surname);
			fout << (*end)->surname <<endl;
			cout << "���: ";
			cin >> (*end)->name;
			(*end)->name = proverka((*end)->name);
			fout << (*end)->name <<endl;
			cout << "��������: ";
			cin >> (*end)->patronymic;
			(*end)->patronymic = proverka((*end)->patronymic);
			fout << (*end)->patronymic << endl;
			cout << "���� ��������(�/�/�): ";
			cin >> (*end)->date;
			fout << (*end)->date <<endl;
			cout << "��������� �����: ";
			cin >> (*end)->number_phone;
			fout << (*end)->number_phone <<endl;
			cout << "�����/���: ";
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
			std::cout << "��������� �" << k << endl;
			(*end)->j = k;
			fout << k <<endl;
			k++;
			std::cout << "�������: ";
			std::cin >> (*end)->surname;
			(*end)->surname = proverka((*end)->surname);
			fout << (*end)->surname << " ";
			std::cout << "���: ";
			std::cin >> (*end)->name;
			(*end)->name = proverka((*end)->name);
			fout << (*end)->name <<endl;
			std::cout << "��������: ";
			std::cin >> (*end)->patronymic;
			(*end)->patronymic = proverka((*end)->patronymic);
			fout << (*end)->patronymic << endl;
			std::cout << "���� ��������(�/�/�): ";
			std::cin >> (*end)->date;
			fout << (*end)->date << endl;
			std::cout << "��������� �����: ";
			std::cin >> (*end)->number_phone;
			fout << (*end)->number_phone <<endl;
			std::cout << "�����/���: ";
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
void remove_employee(base_data**begin, base_data**end) // ������� � ����
{
	if ((*begin) == NULL || (*end) == NULL)
	{
		system("cls");
		return;
	}
	base_data *start = (*begin);
	int i;
	cout << "������� �� ���� �������� ��� �������: ";
	cin >> i;
	while ((*begin)->j != i) // ������ ��������� �� ������ ��� �������
	{
		*begin = (*begin)->next;
		if ((*begin) == NULL)
		{
			(*begin) = start;
			return;
		}
	}
	if ((*begin)->next == NULL && (*begin)->prev == NULL)// �������� ������� � ����������
	{
		base_data * temp = *begin;
		temp = *begin;
		delete temp;
		*begin = NULL;
		*end = NULL;
		return;
	}
	if ((*begin)->prev == NULL && (*begin)->next != NULL)// �������� �������
	{
		base_data * temp = *begin;
		*begin = (*begin)->next;
		delete temp;
		(*begin)->prev = NULL;
		return;
	}
	if ((*begin)->next == NULL && (*begin)->prev != NULL)// �������� ����������
	{
		base_data *temp = *begin;
		*begin = (*begin)->prev;
		(*begin)->next = NULL;
		(*end) = (*begin);
		(*begin) = start;
		delete temp;
		return;
	}
	if ((*begin)->next != NULL && (*begin)->prev != NULL)// �������� � ��������
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
	if (*end == NULL || (*begin) == NULL)// ���� ������ ������
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
void correct_number(base_data*begin, int&k)// ������������� ��������� ����� ���������
{
	k = 1;
	while (begin != NULL)
	{
		begin->j = k;
		k++;
		begin = begin->next;
	}
}
void correct_pepople(base_data*begin)// ������������� ������ ����������
{
	int m = 1;
	int c;
	cout << "������� ����� ���������� � �������� ����� �������� ������: ";
	cin >> c;
	while (begin->j != c)
	{
		begin = begin->next;
	}
	show_test(begin);
	while (m != 0)
	{
		cout << "�������� ��� - 1\n"
			<< "�������� ������� - 2\n"
			<< "�������� �������� -3\n"
			<< "�������� ����-4\n"
			<< "�������� e-mail - 5\n"
			<< "�������� ������ - 6\n"
			<< "�������� ����� - 7\n"
			<< "exit - 0" << endl;
		cin >> m;
		switch (m)
		{
		case(1):
		{
			cout << "������� ��� ";
			cin >> begin->name;
			show_test(begin);
			break;
		}
		case(2):
		{
			cout << "������� �������: ";
			cin >> begin->surname;
			show_test(begin);
			break;
		}
		case(3):
		{
			cout << "������� ��������: ";
			cin >> begin->patronymic;
			show_test(begin);
			break;
		}
		case(4):
		{
			cout << "������� ���� ���������(�/�/�): ";
			cin >> begin->date;
			show_test(begin);
			break;
		}
		case(5):
		{
			cout << "������� e-mail: ";
			cin >> begin->mail;
			show_test(begin);
			break;
		}
		case(6):
		{
			cout << "������� ������: ";
			cin.ignore();
			getline(cin, begin->street);
			show_test(begin);
			break;
		}
		case(7):
		{
			cout << "������� �����: ";
			cin >> begin->number_phone;
			show_test(begin);
			break;
		}
		}
	}
	cout << endl;
	system("PAUSE");
}
void backup(base_data*begin) // ������ ����������� ����
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
void del(base_data**begin)//������������ ������
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
	SetConsoleCP(1251); //������� �����
	SetConsoleOutputCP(1251);// ������� �����
	int j = 1;
	base_data *begin = NULL;// ������ ������;
	base_data *end = NULL; // ����� ������;
	restore_data(&end, &begin);
	correct_number(begin, j);
	show(begin);
	string l = "1";
	while (l != "0")
	{
		cout << "��� ���������� ������� - 1\n"
			<< "��� �������� ���������� �� ���� ������� - 2\n"
			<< "��� ������ �� ������ �������� ������� - 3\n"
			<< "��� ������ ��  �����  ������� - 4\n"
			<< "��� ������ �� ������� ������� - 5\n"
			<< "��� ������ �� �������� ������� - 6\n"
			<< "��� ������ ��  email ������� - 7\n"
			<< "��� ������ �� ����� ������� - 8\n"
			<< "��� ������ �� ���� �������� ������� - 9\n"
			<< "��� ���������� �� ����� ������� - 10\n"
			<< "��� ���������� ��  ������� ������� - 11\n"
			<< "��� ���������� �� �������� ������� - 12\n"
			<< "��� ���������� �� ���� ������� - 13\n"
			<< "����� ��� ����� ������� ���������� �� ������� ����� - 14\n"
			<< "����� ��� ������� ������� ���������� �� ������� ����� - 15\n"
			<< "������������� ������ ���������� ������� - 16\n"
			<< " ������� ��������� ����� - 3223\n" 
			<< " ��� ������ � ���� ������� - 0."<< endl;
		cout << "��� �����: ";
		cin >> l;
		while (l != "1"&&l != "2"&&l != "3"&&l != "4"&&l != "5"&&l != "6"&&
			l != "7"&&l != "8"&&l != "9"&&l != "10"&&l != "11"&&l != "12"&&
			l != "13"&&l != "14"&&l != "15"&&l != "16"&&l != "3223"&&l != "0"&&l != "17")//��������
		{
			cout << "���������� ��� ���:" << endl;
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
			search_number(begin, end);// ����� �� ������ ��������
			break;
		}
		case(4):
		{
			show(begin);
			search_name(begin, end); // ����� �� �����
			break;
		}
		case(5):
		{
			show(begin);
			search_surname(begin, end); // �� �������
			break;
		}
		case(6):
		{
			show(begin);
			search_patronymic(begin, end); // �� ��������

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
