#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <array>
#include <chrono>

using namespace std; //ใส่ไว้แทน std::out

int main() //selectionSort
{
    vector<int> a1; //ประกาศเวคเตอร์ประเภท int ชื่อ a1 เก็บค่าทุกอย่าง
    int ipt = 0; //เก็บค่าก่อนส่ง input แต่ละตัวเข้ามาใน vector a1
    int min = 0; //ค่าน้อยสุดชั่วคราว

    cout << "Doing selection sort\n" << endl;

//Input value to vector
    while(ipt>=0)
    {
        cout << "Please add input (-1 to break): ";
        cin>>ipt;
        if(ipt<0)
        {
            break;
        }
        else
        {
            a1.push_back(ipt);
        }
    }

//Print all input from vector
    cout << "\nList of input : ";
    for(int i=0; i<a1.size(); i++) //i รันตั้งแต่ 0 จนถึง ขนาดของ a1
    {
        cout << a1[i] << " ";
    }

//Let's selection sorting
    for(int i=0; i<a1.size(); i++)
    {
        min = i;
        for(int j=i+1; j<a1.size();j++)
        {
            if(a1[j]<a1[min])
            min = j;
        }
        swap(a1[i],a1[min]);
    }

//Print all input from vector
    cout << "\nAfter selection sort : ";
    for(int i=0; i<a1.size(); i++) //i รันตั้งแต่ 0 จนถึง ขนาดของ a1
    {
        cout << a1[i] << " ";
    }

//return (ปล่อยนางไว้ อย่าไปยุ่งกับนางนะกร)
    return 0;
}