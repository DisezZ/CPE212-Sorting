#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <array>
#include <chrono>

// ## normal function
void runSortApp();
void printMainMenu();
void getElements(std::vector<int> &list);
void printElements(std::vector<int> &list, std::string when);
void validateSorting(std::vector<int> &list);

// ## insetion sort related function decalration ##
void insertionSort(std::vector<int> &list);
// ## selection sort related function decalration ##
void selectionSort(std::vector<int> &list);
// ## merge sort related function decalration ##
void mergeSort(std::vector<int> &list, uint32_t left, uint32_t right);
void merge(std::vector<int> &list, uint32_t left, uint32_t middle, uint32_t right);
// ## quick sort related function decalration ##
void quickSort(std::vector<int> &list, int low, int high);
int hoarePartition(std::vector<int> &list, int low, int high);
void swap(std::vector<int> &list, int swapOne, int swapTwo);

int main()
{
	runSortApp();
	return 0;
}

void runSortApp()
{
	std::vector<int> list;
	int option = 5;
	while (option != 0)
	{
		printMainMenu();
		std::cin >> option;
		if (option >= 1 && option <= 4)
		{
			getElements(list);
			printElements(list, "before");

			auto start = std::chrono::high_resolution_clock::now();
			if (option == 1)
				insertionSort(list);
			else if (option == 2)
				selectionSort(list);
			else if (option == 3)
				mergeSort(list, 0, list.size() - 1);
			else if (option == 4)
				quickSort(list, 0, list.size() - 1);
			auto stop = std::chrono::high_resolution_clock::now();
			
			printElements(list, "after");
			validateSorting(list);
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			std::cout << "Running time: " << duration.count() << " ms" << std::endl;
		}
		else if (option == 0)
			continue;
		else
		{
			std::cout << "Invalid option" << std::endl;
		}
	}
}

void printMainMenu()
{
	std::cout << "Please choose your sorting algorithm" << std::endl;
	std::cout << "1) Insertion sort" << std::endl;
	std::cout << "2) Selection sort" << std::endl;
	std::cout << "3) Merge sort" << std::endl;
	std::cout << "4) Quick sort" << std::endl;
	std::cout << "Enter your option (0 to exit): ";
}

void getElements(std::vector<int> &list)
{
	uint32_t size;
	std::cout << "Enter number of elements: ";
	std::cin >> size;
	list.resize(size);
	for (auto &i : list)
	{
		i = rand() % (static_cast<int>(pow(10, 6)) + 1);
	}
}

void printElements(std::vector<int> &list, std::string when)
{
	std::cout << "Elements of the array " << when << " sorting" << std::endl;
	for (auto &i : list)
		std::cout << i << " ";
	std::cout << std::endl;
}

void validateSorting(std::vector<int> &list)
{
	bool status = true;
	for (size_t i = 1; i < list.size(); ++i)
	{
		if (list[i] < list[i - 1])
		{
			status = false;
			std::cout << "Status:: error " << list[i - 1] << " " << list[i] << std::endl;
			break;
		}
	}
	if (status)
		std::cout << "Status:: ok" << std::endl;
}

// insertion sort part
void insertionSort(std::vector<int> &list)
{
	size_t i = 0;
	int j = 0;
	int key = 0;
	for(i = 1; i < list.size(); i++)
	{
		key = list[i];
		j = i-1;
		while((j >= 0) && (list[j] > key))
		{
			list[j+1] = list[j];
			j = j-1;
		}
		list[j+1] = key;
	}
}

// selection sort part
void selectionSort(std::vector<int> &list)
{
    int min = 0; //minimum value in the list
	for(size_t i=0; i<list.size(); i++)
    {
        min = i;
        for(size_t j=i+1; j<list.size();j++)
        {
            if(list[j]<list[min])
            min = j;
        }
        std::swap(list[i],list[min]);
    }
}

// merge sort part
void mergeSort(std::vector<int> &list, uint32_t left, uint32_t right)
{
	if (right > left)
	{
		uint32_t middle = static_cast<uint32_t>(floor((left + right) / 2));
		mergeSort(list, left, middle);
		mergeSort(list, middle + 1, right);
		merge(list, left, middle, right);
	}
}

void merge(std::vector<int> &list, uint32_t left, uint32_t middle, uint32_t right)
{
	std::vector<int> temp;
	uint32_t n1 = middle - left + 1;
	uint32_t n2 = right - middle;
	uint32_t i = 0, j = 0, k = 0;

	while (i < n1 && j < n2)
	{
		if (list[left + i] < list[middle + 1 + j])
		{
			temp.push_back(list[left + i]);
			i++;
		}
		else
		{
			temp.push_back(list[middle + 1 + j]);
			j++;
		}
	}
	if (i == n1)
	{
		while (j != n2)
		{
			temp.push_back(list[middle + 1 + j]);
			j++;
		}
	}
	else
	{
		while (i != n1)
		{
			temp.push_back(list[left + i]);
			i++;
		}
	}
	while (k != temp.size())
	{
		list[left + k] = temp[k];
		k++;
	}
}

// quick sort part
void quickSort(std::vector<int> &list, int low, int high)
{
	int pIndex = 0;

    if(low < high)  
    {
        pIndex = hoarePartition(list,low,high);
        quickSort(list,low,pIndex-1);
        quickSort(list,pIndex+1,high);
    }   
}

int hoarePartition(std::vector<int> &list, int low, int high)
{
    int pivot = 0;

    int firstIndex = low;
    int secondIndex = high+1;

    pivot = list[low];

    do
    {
        do
        {
            firstIndex++;
        } while((list[firstIndex] < pivot) && (firstIndex < high));
        do
        {
            secondIndex--;
        } while((list[secondIndex] > pivot) && (secondIndex > low));
        swap(list,firstIndex,secondIndex);

    } while(firstIndex < secondIndex);

    swap(list,firstIndex,secondIndex);
    swap(list,low,secondIndex);

    return secondIndex;
}

void swap(std::vector<int> &list, int swapOne, int swapTwo)
{
    int temp = 0;
    temp = list[swapOne];   
    list[swapOne] = list[swapTwo]; 
    list[swapTwo] = temp;
}