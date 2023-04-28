#include <iostream>
#include <fstream> //File stream
//Библиотека позволяющая работать с файловой системой компьютера
#include <string>

bool statistic(std::string word) {
	std::ofstream out;
	out.open("stats.txt",std::ios::app);
	
	if (out.is_open()) {
		out << word <<' '<<word.length()<<'\n';
		out.close();
		return true;
	}

	return false;


}

bool print_file(std::string file_path) {
	std::ifstream in;
	in.open(file_path);
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		in.close();
		std::cout << std::endl;
		return true;

	}
	return false;
}

bool clear_file(std::string file_path) {
	std::ofstream out;
	out.open(file_path);
	if (out.is_open()) {
		out.close();
		return true;
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	std::string path = "file.txt";


	//Класс ofstream
	/*
	std::ofstream out; //Объект класса ofstream для записи данных в файл
	out.open(path,std::ios::app);// открытие файла в режиме app 
	//или std::ofstream out(path);

	if (out.is_open()) { //проверка файла на открытие
		std::cout << "Файл открыт для записи.\n";
		std::string str;
		std::cout << "Введите строку ->";		
		std::getline(std::cin, str);
		out << str <<'\n';//добавление информации в файл
		std::cout << "Запись добавлена в файл.\n";
	}
	else
		std::cout << "Ошибка открытия файла\n";

	//Возможные причины ошибок при открытии файла
	//1. Неправильный синтаксис указаия  пути к файлу
	//2. Нет доступа к файлу
	//3. Файл открыт другим объектом или приложением

	out.close();//закрытие файла и очистка объекта out
		*/
	//Класс ifstream
	/*
	std::ifstream in;
	in.open(path);


	if (in.is_open()) {
		std::cout << "Файл открыт для чтения \n";
		std::cout << "Содержимое файла:\n";
		std::string file_text;
		//Посимвольное считывание 
		//char sym;
		//while (in.get(sym))
			//только вывод
			//std::cout << sym;
			//Вывод и сохранение в строке 
			//file_text += sym;
		//std::cout << file_text;
		
		//Пословное считывание 
		//while (!in.eof()) {
			//std::string tmp;
		//	in >> tmp;
		//	file_text += tmp +'\n';
		//}
		//std::cout << file_text << std::endl;

		//Построчное считывание 
		std::string line;
		while (std::getline(in, line)) {
			file_text += line +'\n';
		}
		std::cout << file_text;
	}
	else
		std::cout << "Ошибка открытия файла.\n";





	//Возможные причины ошибок при открытии файла
	//1. Неправильный синтаксис указания пути файла
	//2. Нет доступа к файлу
	//3. Файла не существует
	in.close();
	*/
	//Удаление файла
	/*
	if (remove(path.c_str())==0)
		std::cout << "Файл \"" << path << "\" удален\n";
	else
		std::cout << "Ошибка удаления файла\n";
	//Возможные причины ошибок при удалении файла
	//1. Неправильный синтаксис указания пути файла
	//2. Нет доступа к файлу
	//3. Файла не существует
	//4. Файл открыт
	*/

	//Задача 1. Слова в файл

	std::cout << "Задача 1.\n";
	int action;

		do {
			std::cout << "Выберите действие:\n";
			std::cout << "1. Добавление статистики в файл\n";
			std::cout << "2. вывод файла\n";
			std::cout << "3.Очистка файла\n";
			std::cout << "4. Завершение работы\n";
			std::cout << "Введите номер действия ->";
			std::cin >> action;
			std::string str1;
			switch (action) {
			case 1:
				std::cout << "Введите строку ->";
				std::cin.ignore();
				std::getline(std::cin, str1);

				if (statistic(str1)) {
					std::cout << "Запись добавлена в файл\n\n";
				}
				else
					std::cout << "Ошибка выполнения функции\n\n";
				break;
			case 2:
				std::cout << "Содержимое файла:\n";
				print_file("stats.txt");
				break;
			case 3:
				clear_file("stats.txt");
				std::cout << "Файл очищен\n\n";
				break;
			case 4:
				std::cout << "Программа завершена\n";
				break;
			default:
				std::cout << "Ошибка ввода\n\n";
			}
	} while (action!=4);
	
	system("pause");



	return 0;
}