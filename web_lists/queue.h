#pragma once

struct client
{
	char* name = new char[50];
	bool gender;
	int age;
	char* work = new char[50];
	int salary;
	bool target;

};

struct queue_elem
{
	client elem;
	queue_elem* next = nullptr;
	queue_elem* prev = nullptr;
};

struct queue
{
	queue_elem* first = nullptr;
	queue_elem* last = nullptr;
};

/// \brief ���������� �������� � �������
/// \param q ������ �� �������, � ������� ����� �������� �������
void enqueue(queue& q, float elem);

/// \brief ���������� �������� �� ������� � ������� �������� ���������� ��������
/// \param q ������ �� �������, �� ������� ����������� ��������
bool dequeue(queue& q, float& elem);

/// \brief �������� ���� ��������� ������� �� ������
/// \param q ��������� �������
void clear(queue& q);
