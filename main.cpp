#include <iostream>

struct dyrr
{
	int number;
	int capacity;
	int* data;
};

void DyrrInit(dyrr* a)
{
	a->number = 0;
	a->capacity = 10;
	a->data = (int*)malloc(sizeof(int) * a->capacity);
}

void DyrrPushEnd(int obj, dyrr* a)
{
	if (a->number >= a->capacity)
	{
		int* new_data = (int*)malloc(sizeof(int) * (a->capacity *= 2));
		if (new_data == nullptr) return;
		memcpy(new_data, a->data, a->capacity / 2 * sizeof(int));
		free(a->data);
		a->data = new_data;
	}
	*(a->data + a->number++) = obj;
}

void DumpDyrr(const dyrr* a)
{
	std::cout << "Number " << a->number << '\n';
	std::cout << "Capacity " << a->capacity << '\n';
	std::cout << "Data ";
	for (int i = 0; i < a->capacity; i++)
	{
		std::cout << a->data[i] << ' ';
	}
	std::cout << '\n' << '\n';
}

int main()
{
	dyrr a;
	DyrrInit(&a);
	for (int i = 0; i < 22; i++)
	{
		DyrrPushEnd(i, &a);
	}
	DumpDyrr(&a);
}