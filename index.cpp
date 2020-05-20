/*
 * index.cpp
 *
 *  Created on: 19 мая 2020 г.
 *      Author: Мурашов А.А.
 *      Задача 1
 *			Написать программу, проверяющую знание таблицы умножения. Программа
 *			должна случайным образом генерировать десять примеров, которые не
 *			должны повторяться. В конце работы программа должна выводить результат
 *			проверки (количество правильных и неправильных ответов) и оценку по
 *			шкале «Отлично – Хорошо – Удовлетворительно – Неудовлетворительно».
 *			Для генерации случайных чисел использовать только возможности библиотеки
 *			C++, функции библиотеки языка C (такие как rand(), srand(), time())
 *			использовать нельзя.
 *
 *
 */
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

const int _MAX_VALUE_ = 10; // Максимальное кол-во примеров
const int _EXCELLENT_ = 10; // Кол-во правильных ответов на оценку "отлично"
const int _GOOD_ = 8; // Кол-во правильных ответов на оценку "Хорошо"
const int _SATISF_ = 5; // Кол-во правильных ответов на оценку "удовлетворительно"
const int RND_MAX = 32767;

int genNumber() {
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);
	std::random_device rd;
	std::mt19937 gen(rd());
	//gen.seed(in_time_t);
	std::uniform_int_distribution<int> uid(1, _MAX_VALUE_);
	return uid(gen);
}

void genVector(std::vector<int>* table, std::vector<int>* table2) {
	// Сгенерим 10 случайных чисел
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);
	//std::random_device rd;
	std::mt19937 gen(in_time_t);
	std::uniform_int_distribution<int> uid(1, _MAX_VALUE_);

	std::generate(table->begin(), table->begin() + table->size(), [&uid, &gen]() -> int { return uid(gen); });
	std::generate(table2->begin(), table2->begin() + table2->size(), [&uid, &gen]() -> int { return uid(gen); });
}

int main() {
	std::vector<int> first(_MAX_VALUE_);
	std::vector<int> second(_MAX_VALUE_);
	std::vector<int> answers;
	int countRight = 0;
	genVector(&first, &second);
	std::cout << "Проверка знания таблицы умножения" << std::endl;
	for(int i = 1; i <= _MAX_VALUE_; i++) {
		// Пройдемся по всем ответам и найдем совпадения
		for(int n : answers) {
			if (n == (first[i-1] * second[i-1])) {
				// Если совпадения есть - генерируем новые числа
				first[i-1] = genNumber() % _MAX_VALUE_;
				second[i-1] = genNumber() % _MAX_VALUE_;
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





