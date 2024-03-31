#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
#include "cgi.h"
using namespace std;


void main()
{
	cout << "Content-type: text/html; charset=windows-1251\n\n";

	ifstream f("2.tmpl");
	if (f.is_open()) {
		char* line = new char[4096];
		while (!f.eof()) {
			f.getline(line, 4096);
			if (!strcmp(line, "<!--CONTENT-->"))
			{
				cout << "<form action='3.cgi' method='post' enctype='multipart/form-data'>\n";
				cout << "<div><span style='color:white;'>Загрузить файл:</span> <input type='file' name='file'></div>";
				cout << "<div><input type = 'submit' value = 'Отправить' style='text-align:center;'></div>";
				cout << "</form><br>";
				char* data = nullptr;

                get_form_data(data);
				
                if (data != nullptr) {

                    char* tempFileName = nullptr;
                    size_t fileSize = 0;
                    if (get_form_file_info(tempFileName, &fileSize)) {
                        // Открываем файл для чтения
                        std::ifstream file(tempFileName, std::ios::binary);
                        if (file.is_open()) {
                            // Считываем содержимое файла
                            std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                            // Выводим содержимое файла на сайт
                            std::cout << "<h2>Содержимое загруженного файла:</h2>\n";
                            std::cout << "<pre>" << fileContent << "</pre>\n";
                            // Закрываем файл
                            file.close();
                        }
                        else {
                            std::cerr << "Ошибка открытия файла\n";
                        }
                        // Освобождаем память, выделенную для имени файла
                        free(tempFileName);
                    }
                    else {
                        std::cerr << "Ошибка получения информации о загруженном файле\n";
                    }

                    // Освобождаем память, выделенную для содержимого файла
                    free(data);

                    std::cout << "</body>\n</html>\n";
                }
                else 
                {
                    std::cerr << "Ошибка получения данных файла\n";
                }
			}
			else
				cout << line << endl;
		}
		delete[] line;
		f.close();
	}
}