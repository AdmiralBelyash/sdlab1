#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY


struct DynamicArray
{
private:

	bool _sorted = false;
	int* _array;
	int _growthFactor = 2;
	unsigned int _length = 0;
	unsigned int _capacity;

private:
	bool IsSorted();
	void ReSize();

public:

	DynamicArray(unsigned int capacity = 4);
	~DynamicArray();
	
	int GetLenght();
	
	int GetCapacity();

	void PushBack(int value);
	
	int InsertElement(unsigned int index, int value);
	
	void ShowArray();
	
	int RemoveElement(int index);
	
	void Sort();

	unsigned int LinearSearch(unsigned int start, unsigned int end, int value);

	unsigned int BinarySearch(int value);

};
#endif

