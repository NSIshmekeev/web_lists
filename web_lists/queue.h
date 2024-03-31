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

/// \brief Добавление элемента в очередь
/// \param q Ссылка на очередь, в которую нужно добавить элемент
void enqueue(queue& q, float elem);

/// \brief Извлечение элемента из очереди и возврат значения удаленного элемента
/// \param q Ссылка на очередь, из которой извлекается значение
bool dequeue(queue& q, float& elem);

/// \brief Удаление всех элементов очереди из памяти
/// \param q Удаляемая очередь
void clear(queue& q);
