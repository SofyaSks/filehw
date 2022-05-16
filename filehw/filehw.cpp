#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;


// �������� ������� �29

bool overwrite(string path, string str = "Null Empty Nothing") {
	ifstream in;
	in.open(path, ios::in);
	string str2;
	if (in.is_open()) {
		cout << "������������ ������... \n";
		while (!in.eof()) {
			ofstream out;
			out.open(path, ios::out);
			str2 = "";
			out << str << "\n";
			out.close();

			getline(in, str2);
			cout << str2 << endl;
			in.close();
		}
		return true;
	}
	else
	return false;
}

// �������� ������� �28

void fillarr(int arr[], int size, int X, int Y) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (Y - X) + X;
}

template <typename T> void showarr(T arr[], int size) {
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

void resizearr(int arr[], int len1, int len2 ) {
	fillarr(arr, len1, 10, 100);
	fillarr(arr, len2, 10, 100);
	showarr(arr, len1);
	cout << "����� ������ � ������� " << len2 << ": ";
	showarr(arr, len2);
}
	
	



		int main() {
			setlocale(LC_ALL, "ru");

			// �������� ������� �29

			cout << "�������� ������� �29\n\n";

			// ������ 1

			ofstream out;
			string path = "file.txt";
			out.open(path, ios::out);

			if (out.is_open()) {
				cout << "���� ������ ��� ������. \n";
				string str;
				cout << "(����� ��������� ������� end)\n";
				do {
					cout << "������� ������: \n";
					getline(cin, str);
					out << str << "\n";
				} while (str != "end");
			}
			else
				cout << "������ �������� �����.\n";
			out.close();


			ifstream in;
			in.open(path, ios::in);
			if (in.is_open()) {
				cout << "\n���� ������ ��� ������. \n";
				while (!in.eof()) {
					string str1;
					getline(in, str1);
					cout << str1 << endl;
				}
			}
			else
				cout << "������ �������� �����.\n";
			in.close();
			// ������ 2
			overwrite(path);
			remove("file.txt");

			// �������� ������� �28

			cout << "\n\n�������� ������� �28\n\n";

			// ������ 1

			int l1, l2;
			cout << "������� ����� ������� �������: ";
			cin >> l1;
			cout << "������� ����� ������� �������: ";
			cin >> l2;
			int* A = new int[l1];
			int* B = new int[l2];
			int* C = new int[l1 + l2];

			cout << "������ �:\n";
			fillarr(A, l1, 10, 100);
			showarr(A, l1);
		
			cout << "������ B:\n";
			fillarr(B, l2, 10, 100);
			showarr(B, l2);

			cout << "������ C:\n";
			for (int i = 0; i < l1; i++)
				C[i] = A[i];
			for (int i = l1; i < l1 + l2; i++)
				C[i] = B[i - l1];
			showarr(C, l1+l2);
			
			delete[] A;
			delete[] B;

			// ������ 2
			cout << "������� ����� �������: ";
			int length1;
			cin >> length1;
			int* arr = new int[length1];
			cout << "������� ����� ����� �������: ";
			int length2;
			cin >> length2;
			cout << "����������� ������ � ������ " << length1 << ": ";
			resizearr(arr, length1, length2);

			return 0;
		}