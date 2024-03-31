#include "queue.h"
#include <string.h>

void enqueue(queue& q, client elem)
{
	auto* new_el = new queue_elem;
	new_el->elem = elem;
	new_el->prev = q.last;
	if (q.last) q.last->next = new_el;
	q.last = new_el;
	if (!q.first) q.first = new_el;
}

bool dequeue(queue& q, client& elem)
{
	if (!q.first) return false;
	elem = q.first->elem;
	queue_elem* del = q.first;
	q.first = q.first->next;
	if (q.first) q.first->prev = nullptr;
	else q.last = nullptr;
	delete del;
	return true;
}

void clear(queue& q)
{
	queue_elem* curr = q.first;
	while (curr)
	{
		const auto* del = curr;
		curr = curr->next;
		delete del;
	}
	q.first = q.last = nullptr;
}
