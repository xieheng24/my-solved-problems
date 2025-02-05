#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
	string name;
	int year;
	int month;
	int day;
	int inputOrder; 
};

bool compare(const Student &a, const Student &b) {
	if (a.year != b.year) {
		return a.year < b.year;
	} else if (a.month != b.month) {
		return a.month < b.month; 
	} else if (a.day != b.day) {
		return a.day < b.day; 
	} else {
		return a.inputOrder > b.inputOrder; 
	}
}

int main() {
	int n;
	cin >> n;
	vector<Student> students(n);
	
	for (int i = 0; i < n; ++i) {
		std::cin >> students[i].name >> students[i].year >> students[i].month >> students[i].day;
		students[i].inputOrder = i; 
	}
	
	sort(students.begin(), students.end(), compare);
	
	for (const auto &student : students) {
		cout << student.name << endl;
	}
	
	return 0;
}
