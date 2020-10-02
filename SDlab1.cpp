#include <iostream>
#include <string>
#include <windows.h>

#include "DynamicArray.h"


using namespace std;

int InputInt()
{
	while (true)
	{
		string inputValue;
		int number;
		size_t length;
		getline(cin, inputValue);
		
		try 
		{
			number = stoi(inputValue, &length);

			if (length == inputValue.length())
				return number;
		}
		catch (exception) {}

		cout << inputValue << " is not a number" << endl;
	}
}

int InputIndex() 
{
	while (true) 
	{
		int i = InputInt();

		if (i >= 0)
			return i;

		cout << "Number should not be lesser than 0" << std::endl;
	}
}

int main()
{
	DynamicArray dynamicArray;
	int count = 0;

	for (;;)
	{
		cout << "***************** Instruction set *****************" << endl;

		cout << "Lenght = " << dynamicArray.GetLenght() << endl;
		cout << "Capacity = " << dynamicArray.GetCapacity() << endl;
		dynamicArray.ShowArray();

		cout << "[1 - Add Element]" << endl;
		cout << "[2 - Insert Element]" << endl;
		cout << "[3 - Remove Element]" << endl;
		cout << "[4 - Linear search]" << endl;
		cout << "[5 - Binary search]" << endl;
		cout << "[6 - Insertion Sort]" << endl;
		cout << "[7 - Exit]" << endl;

		cout << "Please, choose one options: ";
		count = InputIndex();
		cout << endl;

		switch (count)
		{
			case 1:
			{
				cout << "Amount of iterations: ";
				int amount = InputIndex();

				for (int i = 1; i <= amount; ++i)
				{
					dynamicArray.PushBack(InputInt());
				}

				cout << endl;
				system("pause");
				break;
			}
			
			case 2:
			{
				unsigned int index = InputIndex();
				int value = InputInt();
				dynamicArray.InsertElement(index, value);
				cout << endl;
				system("pause");
				break;
			}
			case 3:
			{
				cout << "Input Index, please: ";
				unsigned int index = InputIndex();

				if (dynamicArray.RemoveElement(index) == -1) {
					cout << "Invalid index\n";
				}

				cout << endl;
				system("pause");
				break;
			}
			case 4:
			{
				cout << "Enter the number to search: ";
				int number = InputInt();
				unsigned int index = dynamicArray.LinearSearch(0, dynamicArray.GetLenght() - 1, number);
				if (index == dynamicArray.GetLenght())
				{
					cout << "Not found" << endl;
				}
				else
				{
					cout << "Number is on this index: " << index;
				}
			
				cout << endl;
				system("pause");
				break;
			}
			case 5:
			{
				cout << "Enter the number to search: ";
				int number = InputInt();
				unsigned int index = dynamicArray.BinarySearch(number);
				if (index == dynamicArray.GetLenght())
				{
					cout << "Not found" << endl;
				}
				else
				{
					cout << "Number is on this index: " << index;
				}
				cout << endl;
				system("pause");
				break;
			}
			case 6:

				dynamicArray.Sort();
				break;

			case 7:

				return 0;
				break;

			default:

				cout << "No such option in menu" << endl;
				system("pause");
				break;
		}
		system("cls");
	}
}

