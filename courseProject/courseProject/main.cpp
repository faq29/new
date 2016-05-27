#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct SUBD
{
	string nameOS;		//�������� ������������ �������
	string nameBD;		//�������� ����
	int minVZU;			//����������� ���������� ������
	int minOZU;			//����������� ������������ ������
	int count;			//���� �������� �� 1-��� ��������
};

void findElem(vector<SUBD> &t) {
	string s;
	cout << "������� ��� ������: ";
	cin.sync();
	getline(cin, s);
	for(int i = 0; i < t.size(); i++) {
		if(s == t[i].nameOS) {
			cout << "_________________________________________________________________________________________________________________" << endl;
			cout << "| �������� ��   | �������� ��  | ����������� ���������� ������ | ����������� ����������� ������ |    ���������  |" << endl;
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
	out << "| �������� ��   | �������� ��  | ����������� ���������� ������ | ����������� ����������� ������ |    ���������  |" << endl;
	for (int i = 0; i < t.size(); i++)
	{
		out << "_________________________________________________________________________________________________________________" << endl;
		out << "|" << setw(15) << t[i].nameOS << "|" << setw(14) << t[i].nameBD << "|" << setw(31) << t[i].minVZU << "|" << setw(32) << t[i].minOZU << "|" << setw(15) << t[i].count << "|" << endl;
	}
	out << "_________________________________________________________________________________________________________________" << endl;

	cout << "_________________________________________________________________________________________________________________" << endl;
	cout << "| �������� ��   | �������� ��  | ����������� ���������� ������ | ����������� ����������� ������ |    ���������  |" << endl;
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
		cout<<"������� ��: ";
		getline(cin, t[i].nameOS);
		cout<<"������� ��: ";
		getline(cin, t[i].nameBD);
		cout<<"������� ���: ";
		cin >> t[i].minVZU;
		cout<<"������� ���: ";
		cin >> t[i].minOZU;
		cout<<"������� ����: ";
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
	
	int n;						//���������� ����� � ���������\�������
	
	cout<<"������� ���������� ����� �������: ";
	cin >> n;

	vector<SUBD> t(n);			//������ ���������\�������

	input(t);
	
	output(t);
	int flag = 1;
	while(flag != 0){
		system("pause");
		system("cls");
		cout << "1 - ���������� �� 1 - ��� �������\n2 - ���������� �� 2 - ��� �������\n3 - ���������� �� 3 - ��� �������\n4 - ���������� �� 4 - ��� �������\n5 - ���������� �� 5 - ��� �������\n0 - ����� �� ����������" << endl;
		cout << "�������� ����������: ";
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