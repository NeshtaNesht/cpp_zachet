/*
 * index.cpp
 *
 *  Created on: 19 ��� 2020 �.
 *      Author: ������� �.�.
 */
#include <iostream>
#include <vector>
#include <ctime>

const int _MAX_VALUE_ = 10; // ������������ �������� ������������
const int _EXCELLENT_ = 10; // ���������� ������ ������� �� "�������"
const int _GOOD_ = 8; // ���������� ������ ������� �� "������"
const int _SATISF_ = 5; // ���������� ������ ������� �� "�����������������"

void gen(std::vector<int>* table) {
	// ����������� 10 ��������� �����
	for (int i = 0; i < _MAX_VALUE_; i++) {
		table->insert(table->end(), 1 + rand() % _MAX_VALUE_);
	}
}

int main() {
	std::srand(std::time(0));
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> answers;
	int countRight = 0;
	gen(&first);
	gen(&second);
	std::cout << "�������� ������ ������� ���������" << std::endl;
	for(int i = 1; i <= _MAX_VALUE_; i++) {
		// ��������� �� ���� ����������� � ������ ����������
		for(int n : answers) {
			if (n == (first[i-1] * second[i-1])) {
				// ���� ���������� ���� - ���������� ����� �����
				first[i-1] = rand() % _MAX_VALUE_;
				second[i-1] = rand() % _MAX_VALUE_;
			}
			std::cout << "������: " << n << std::endl;
		}
		// ������� ���������
		int result = first[i-1] * second[i-1];
		// ��������� ��������� � ������ �����������
		answers.push_back(result);
		int answer;
		std::cout << "������ ������ " << i << ": " << first[i-1] << " * " << second[i-1] << std::endl;
		std::cin >> answer;
		if (answer == result) {
			countRight++;
		}
	}

	std::cout << "���������� ������ ������� " << countRight << " �� " << _MAX_VALUE_ << std::endl;
	std::cout << "������: " <<
			(countRight == _EXCELLENT_ ?
			"�������" : countRight >= _GOOD_ ?
			"������" : countRight >= _SATISF_ ?
			"�����������������" : "�������������������") << std::endl;

	return 0;
}





