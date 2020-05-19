/*
 * index.cpp
 *
 *  Created on: 19 мая 2020 г.
 *      Author: Мурашов А.А.
 */
#include <iostream>
#include <vector>
#include <ctime>

const int _MAX_VALUE_ = 10; // Максимальное кол-во примеров
const int _EXCELLENT_ = 10; // Кол-во правильных ответов на оценку "отлично"
const int _GOOD_ = 8; // Кол-во правильных ответов на оценку "Хорошо"
const int _SATISF_ = 5; // Кол-во правильных ответов на оценку "удовлетворительно"

void gen(std::vector<int>* table) {
	// Сгенерим 10 случайных чисел
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
	std::cout << "Проверка знания таблицы умножения" << std::endl;
	for(int i = 1; i <= _MAX_VALUE_; i++) {
		// Пройдемся по всем ответам и найдем совпадения
		for(int n : answers) {
			if (n == (first[i-1] * second[i-1])) {
				// Если совпадения есть - генерируем новые числа
				first[i-1] = rand() % _MAX_VALUE_;
				second[i-1] = rand() % _MAX_VALUE_;
			}
			// std::cout << "Ответы: " << n << std::endl;
		}
		// Считаем ответ
		int result = first[i-1] * second[i-1];
		// Заносим ответ в вектор ответов
		answers.push_back(result);
		int answer;
		std::cout << "Решите пример " << i << ": " << first[i-1] << " * " << second[i-1] << std::endl;
		std::cin >> answer;
		if (answer == result) {
			countRight++;
		}
	}

	std::cout << "Количество верных ответов " << countRight << " из " << _MAX_VALUE_ << std::endl;
	std::cout << "Оценка: " <<
			(countRight == _EXCELLENT_ ?
			"Отлично" : countRight >= _GOOD_ ?
			"Хорошо" : countRight >= _SATISF_ ?
			"Удовлетворительно" : "Неудовлетворительно") << std::endl;

	return 0;
}





