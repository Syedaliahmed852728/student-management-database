#include <iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;
class myDate {
	unsigned int day, month, year;
public:
	myDate(unsigned int dd = 0, unsigned int mm = 0, unsigned int yy = 0) :
		day(dd), month(mm), year(yy) {}
	void setDate();
	void getDate();
};
void myDate::getDate() {
	cout << day << "/" << month << "/" << year;
}
void myDate::setDate() {
	do {
		cout << "day :- ";
		if ((cin >> day) && (day > 0 && day <= 31))
			break;
		else {
			cout << "enter the correct day" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (day <= 0 || day > 31);
	do {

		cout << "month :- ";
		if ((cin >> month) && (month > 0 && month <= 12))
			break;
		else {
			cout << "enter the correct month" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (month <= 0 || month > 12);
	do {
		cout << "year :- ";
		if ((cin >> year) && (year > 0 && year <= 2022))
			break;
		else {
			cout << "enter the correct year" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (year <= 0 || year > 2022);
	cout << endl;
}
class student {
	unsigned int regNo;
	string name;
	string fName;
	float CGPA;
	myDate DOB;
	myDate DOA;
public:
	student() {
		regNo = 0;
		name = "\0";
		fName = "\0";
		CGPA = 0.0;
	}
	void read();
	bool search(unsigned int);
	void display();
};

void deleteData(student* s, unsigned int& size, unsigned int regNo) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (s[i].search(regNo)) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		for (int i = index; i < size; i++) {
			s[i] = s[i + 1];
		}
		size--;
		cout << "Deleted !" << endl;
	}
	else
		cout << "data not found" << endl;
}
void student::display() {
	cout << setw(3) << regNo << setw(22) << name << setw(14) << fName << setw(13) << CGPA << setw(17);
	DOB.getDate(); cout << setw(17); DOA.getDate(); cout << endl;
}
bool student::search(unsigned int stuNo) {
	if (stuNo == regNo)
		return true;
	else
		return false;

}
void student::read() {
	cout << "Enter the registration Number" << endl;
	do {
		if (cin >> regNo)
			break;
		else {
			cout << "enter the correct registration Number" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (true);
	cout << "Enter the student Name" << endl;
	cin.ignore(1, '\0');
	getline(cin, name);
	cout << "Enter the student's Father Name" << endl;
	getline(cin, fName);
	cout << "Enter the student's CGPA" << endl;
	do {
		if (cin >> CGPA)
			break;
		else {
			cout << "enter the correct CGPA" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (true);
	cout << "Enter the student's Date of Birth" << endl;
	DOB.setDate();
	cout << "Enter the student's Date of Admission" << endl;
	DOA.setDate();
}
void menu() {
	cout << "                                      1.create the record       " << endl;
	cout << "                                      2.Append the record       " << endl;
	cout << "                                      3.display the record      " << endl;
	cout << "                                      4.search the record       " << endl;
	cout << "                                      5.delete the record       " << endl;
	cout << "                                      6.save the record         " << endl;
	cout << "                                      7.load the data           " << endl;
	cout << "                                      8.delete the record       " << endl;
}
int main()
{
	int max = 0;
	student* Stu;
	unsigned int size = 0;
	char option;
	int regNo, index = -1;
	ofstream infile;
	ifstream outfile;
	cout << "Enter the maximum number of student you want to create" << endl;
	do {
		if (cin >> max && (max > 0 && max <= 70)) {
			Stu = new student[max];
			break;
		}
		else {
			cout << "Enter the correct size between 0-70" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (true);

	do {
		menu();
		cout << endl;
		cout << "                                     chose the correct option" << endl;
		cin >> option;
		switch (option) {
		case '1':
			cout << "how many students you want to enter" << endl;
			do {
				if (cin >> size && (size > 0 && size < max))
					break;
				else {
					cout << "chose the size greater than 0 and less than maximum" << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			} while (true);
			for (int i = 0; i < size; i++) {
				cout << "                                enter the data of " << i + 1 << " student" << endl << endl;
				Stu[i].read();
			}
			break;
		case'2':
			cout << "enter the data of " << size + 1 << " student" << endl;
			Stu[size++].read();
			break;
		case '3':
			if (size != 0) {
				cout << "registration Number" << setw(8) << "Name" << setw(18) << "father Name" <<
					setw(11) << "CGPA" << setw(26) << "date of birth" << setw(26) << "date of admission"
					<< setw(14) << endl;
				for (int i = 0; i < size; i++) {
					Stu[i].display();
				}
			}
			else
				cout << "no data is present" << endl;
			break;
		case '4':
			cout << "Enter the registration Number You want to search" << endl;
			do {
				if (cin >> regNo)
					break;
				else {
					cout << "enter the correct registration Number" << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			} while (true);
			for (int i = 0; i < size; i++) {
				if (Stu[i].search(regNo)) {
					index = i;
					break;
				}
			}
			if (index != -1) {
				Stu[index].display();
			}
			else
				cout << "data not found" << endl;
			index = -1;
			break;
		case '5':
			if (size != 0) {
				cout << "Enter the registration Number You want to delete" << endl;
				do {
					if (cin >> regNo)
						break;
					else {
						cout << "enter the correct registration Number" << endl;
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
				} while (true);
				deleteData(Stu, size, regNo);
				break;
		case '6':
			if (size != 0) {
				infile.open("student.txt", ios::binary | ios::out);
				for (int i = 0; i < size; i++) {
					infile.write((char*)&Stu[i], sizeof(Stu[i]));
					cout << endl;
				}
				infile.close();
			}
			else
				cout << "no data is there to be written" << endl;
			break;
		case '7':
			int i = 0;
			outfile.open("student.txt", ios::binary | ios::in);
			while (true) {
				outfile.read((char*)&Stu[i], sizeof(Stu[i]));
				i++;
				if (outfile.eof())
					break;
				size++;
			}
			}
		}
	} while (true);
}

