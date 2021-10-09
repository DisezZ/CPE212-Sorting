/***************************************
 * quick sort
 * Create  by job
 ***************************************
 */
#include<iostream>
#include <ctime>
#include <chrono>
#include <time.h>

int hoarePartition(int* list, int low, int high);
void swap(int* listOfArray, int swapOne, int swapTwo);
void quickSort(int* list, int low, int high);

using namespace std::chrono;
using namespace std;
int main()
{   
    chrono::steady_clock sc;
    int* randList;
    int arraySize = 0;
    double totalTime = 0;
    double average = 0;

    srand(time(0));
    while(arraySize >= 0)
    {
        std::cout <<"Enter the number of elements:";
        std::cin >>arraySize;
        if(arraySize >= 0)
        {
            for(int l=0; l<5; l++)
            {
                randList  = new int[arraySize];
                for(int i=0; i<arraySize; i++)
                {
                    randList[i] = rand() % arraySize;
                }
                std::cout << "Elements of the array before sorting\n";
                /*
                for(int i=0; i<arraySize; i++)
                {
                    std::cout <<randList[i]<<"\t";
                }
                */
                auto start = sc.now(); 
                quickSort(randList,0,arraySize-1);
                auto end = sc.now(); 
                std::cout << "\nElements of the array after sorting\n";
                /*
                for(int i=0; i<arraySize; i++)
                {
                    std::cout <<randList[i]<<"\t";
                }
                */
                auto time_span = static_cast<chrono::duration<double>>(end - start);
                /*double runtime = duration_cast<microseconds>(duration).count();*/
                std::cout << "This sort took " <<time_span.count()<< " microseconds.\n\n";
                totalTime = totalTime + time_span.count();
                delete[] randList;
            }
            average = totalTime / 5;
            std::cout <<"Average runing time of n:"<<arraySize<<
            " \nAverage:"<<average<<"\n";
        }
    }
}
void swap(int* listOfArray, int swapOne, int swapTwo)
{
    int temp = 0;
    temp = listOfArray[swapOne];   
    listOfArray[swapOne] = listOfArray[swapTwo]; 
    listOfArray[swapTwo] = temp;
}
int hoarePartition(int* list, int low, int high)
{
    int pivot = 0;
    int loopCount = 0;

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

void quickSort(int* list, int low, int high)
{
    int pIndex = 0;

    if(low < high)  
    {
        pIndex = hoarePartition(list,low,high);
        quickSort(list,low,pIndex-1);
        quickSort(list,pIndex+1,high);
    }   
}