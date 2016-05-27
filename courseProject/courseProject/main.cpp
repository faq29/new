#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct SUBD
{
	string nameOS;		//название Операционной системы
	string nameBD;		//название СУБД
	int minVZU;			//минимальная внутренняя память
	int minOZU;			//минимальная операционная память
	int count;			//цена лицензии на 1-ого человека
};

void findElem(vector<SUBD> &t) {
	string s;
	cout << "Введите для поиска: ";
	cin.sync();
	getline(cin, s);
	for(int i = 0; i < t.size(); i++) {
		if(s == t[i].nameOS) {
			cout << "_________________________________________________________________________________________________________________" << endl;
			cout << "| Название ОС   | Название БД  | Минимальная внутренняя память | Минимальная оперативная память |    Стоимость  |" << endl;
			cout << "_________________________________________________________________________________________________________________" << endl;
			cout << "|" << setw(15) << t[i].nameOS << "|" << setw(14) << t[i].nameBD << "|" << setw(31) << t[i].minVZU << "|" << setw(32) << t[i].minOZU << "|" << setw(15) << t[i].count << "|" << endl;
			break;
		}
	}
}

void output(vector<SUBD> t) {
	ofstream out;
	out.open("text.txt");
	out << "_________________________________________________________________________________________________________________" << endl;
	out << "| Название ОС   | Название БД  | Минимальная внутренняя память | Минимальная оперативная память |    Стоимость  |" << endl;
	for (int i = 0; i < t.size(); i++)
	{
		out << "_________________________________________________________________________________________________________________" << endl;
		out << "|" << setw(15) << t[i].nameOS << "|" << setw(14) << t[i].nameBD << "|" << setw(31) << t[i].minVZU << "|" << setw(32) << t[i].minOZU << "|" << setw(15) << t[i].count << "|" << endl;
	}
	out << "_________________________________________________________________________________________________________________" << endl;

	cout << "_________________________________________________________________________________________________________________" << endl;
	cout << "| Название ОС   | Название БД  | Минимальная внутренняя память | Минимальная оперативная память |    Стоимость  |" << endl;
	for (int i = 0; i < t.size(); i++)
	{
		cout << "_________________________________________________________________________________________________________________" << endl;
		cout << "|" << setw(15) << t[i].nameOS << "|" << setw(14) << t[i].nameBD << "|" << setw(31) << t[i].minVZU << "|" << setw(32) << t[i].minOZU << "|" << setw(15) << t[i].count << "|" << endl;
	}
	cout << "_________________________________________________________________________________________________________________" << endl;
}

void input(vector<SUBD> &t) {
	for (int i = 0; i < t.size(); i++)
	{
		cin.sync();
		cout<<"Введите ОС: ";
		getline(cin, t[i].nameOS);
		cout<<"Введите БД: ";
		getline(cin, t[i].nameBD);
		cout<<"Введите ВЗУ: ";
		cin >> t[i].minVZU;
		cout<<"Введите ОЗУ: ";
		cin >> t[i].minOZU;
		cout<<"Введите цену: ";
		cin >> t[i].count;

		system("cls");
	}
}

void sortByNameOS(vector<SUBD> &t) {
	for(int i = 0; i < t.size(); i++) {
		for(int j = 0; j < t.size() - 1; j++) {
			if(t[j].nameOS > t[j + 1].nameOS) {
				SUBD temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}

void sortByNameBD(vector<SUBD> &t) {
	for(int i = 0; i < t.size(); i++) {
		for(int j = 0; j < t.size() - 1; j++) {
			if(t[j].nameBD > t[j + 1].nameBD) {
				SUBD temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}

void sortByVZU(vector<SUBD> &t) {
	for(int i = 0; i < t.size(); i++) {
		for(int j = 0; j < t.size() - 1; j++) {
			if(t[j].minVZU > t[j + 1].minVZU) {
				SUBD temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}

void sortByOZU(vector<SUBD> &t) {
	for(int i = 0; i < t.size(); i++) {
		for(int j = 0; j < t.size() - 1; j++) {
			if(t[j].minOZU > t[j + 1].minOZU) {
				SUBD temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}

void sortByCount(vector<SUBD> &t) {
	for(int i = 0; i < t.size(); i++) {
		for(int j = 0; j < t.size() - 1; j++) {
			if(t[j].count > t[j + 1].count) {
				SUBD temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}


int main() {
	setlocale(0, "");
	
	int n;						//количество строк в структуре\таблице
	
	cout<<"Введите количество строк таблицы: ";
	cin >> n;

	vector<SUBD> t(n);			//вектор структуры\таблицы

	input(t);
	
	output(t);
	int flag = 1;
	while(flag != 0){
		system("pause");
		system("cls");
		cout << "1 - сортировка по 1 - ому столбцу\n2 - сортировка по 2 - ому столбцу\n3 - сортировка по 3 - ему столбцу\n4 - сортировка по 4 - ому столбцу\n5 - сортировка по 5 - ому столбцу\n0 - выход из сортировки" << endl;
		cout << "Выберите сортировку: ";
		cin >> flag;
		if(flag == 1) {
			sortByNameOS(t);
			output(t);
		}
		else if(flag == 2) {
			sortByNameBD(t);
			output(t);
		}
		else if(flag == 3) {
			sortByVZU(t);
			output(t);
		}
		else if(flag == 4) {
			sortByOZU(t);
			output(t);
		}
		else if(flag == 5) {
			sortByCount(t);
			output(t);
		}
	}
	
	cout<<"\n\n";
	
	output(t);

	findElem(t);

	system("pause");
	return 0;
}