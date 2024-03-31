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
				cout << "<div><span style='color:white;'>��������� ����:</span> <input type='file' name='file'></div>";
				cout << "<div><input type = 'submit' value = '���������' style='text-align:center;'></div>";
				cout << "</form><br>";
				char* data = nullptr;

                get_form_data(data);
				
                if (data != nullptr) {

                    char* tempFileName = nullptr;
                    size_t fileSize = 0;
                    if (get_form_file_info(tempFileName, &fileSize)) {
                        // ��������� ���� ��� ������
                        std::ifstream file(tempFileName, std::ios::binary);
                        if (file.is_open()) {
                            // ��������� ���������� �����
                            std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                            // ������� ���������� ����� �� ����
                            std::cout << "<h2>���������� ������������ �����:</h2>\n";
                            std::cout << "<pre>" << fileContent << "</pre>\n";
                            // ��������� ����
                            file.close();
                        }
                        else {
                            std::cerr << "������ �������� �����\n";
                        }
                        // ����������� ������, ���������� ��� ����� �����
                        free(tempFileName);
                    }
                    else {
                        std::cerr << "������ ��������� ���������� � ����������� �����\n";
                    }

                    // ����������� ������, ���������� ��� ����������� �����
                    free(data);

                    std::cout << "</body>\n</html>\n";
                }
                else 
                {
                    std::cerr << "������ ��������� ������ �����\n";
                }
			}
			else
				cout << line << endl;
		}
		delete[] line;
		f.close();
	}
}