#include <iostream>
#include <vector>
#include <random>

using namespace std;

void QuickSort(vector<int> &arr, int left, int right)
{
    // 재귀 종료 조건 (배열 크기가 1인 경우)
    if (left >= right)
        return;

    // 랜덤 pivot 선택
    random_device rd;                                // 하드웨어 엔트로피 기반 난수 생성
    mt19937 gen(rd());                               // Mersenne Twister 엔진 사용
    uniform_int_distribution<int> dist(left, right); // 균등 분포
    int pivotIndex = dist(gen);

    // 피봇을 배열의 왼쪽으로 이동
    swap(arr[pivotIndex], arr[left]);
    int pivot = arr[left];
    int leftPartition = left + 1;
    int rightPartition = right;

    // 배열을 순회하며 비교
    while (leftPartition < rightPartition)
    {
        if (arr.at(leftPartition) > pivot && arr.at(rightPartition) < pivot)
        {
            swap(arr[leftPartition], arr[rightPartition]);
            leftPartition++;
            rightPartition--;
        }
        else if (arr.at(leftPartition) < pivot && arr.at(rightPartition) < pivot)
        {
            leftPartition++;
        }
        else if (arr.at(leftPartition) > pivot && arr.at(rightPartition) > pivot)
        {
            rightPartition--;
        }
        else
        {
            leftPartition++;
            rightPartition--;
        }
    }

    if (arr[rightPartition] <= pivot)
    {
        swap(arr[rightPartition], arr[left]);
        pivotIndex = rightPartition;
    }
    else
    {
        swap(arr[rightPartition - 1], arr[left]);
        pivotIndex = rightPartition - 1;
    }

    QuickSort(arr, left, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, right);
}

int main()
{
    // 배열 A
    vector<int> arr = {6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14};

    // 정렬 전 출력
    cout << "정렬 전 : ";
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;

    QuickSort(arr, 0, arr.size() - 1);

    // 정렬 후 출력
    cout << "정렬 후 : ";
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}