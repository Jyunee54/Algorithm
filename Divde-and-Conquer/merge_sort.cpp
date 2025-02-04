#include <iostream>
#include <vector>

using namespace std;

// 두 개의 정렬된 벡터를 병합하는 함수
vector<int> Merge(vector<int> &left, vector<int> &right){
    vector<int> result;
    int i = 0, j = 0;

    // 두 벡터를 비교하며 정렬
    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // 남아 있는 요소 추가
    while(i < left.size()){
        result.push_back(left[i]);
        i++;
    }
    while(j < right.size()){
        result.push_back(right[j]);
        j++;
    }
    return result;
}

// 합병 정렬 구현
vector<int> MergeSort(vector<int> &vec, int p,  int q){
    if(p >= q) {
        return {vec[p]};    // 단일 요소를 벡터로 반환
    }

    int k = (p+q)/2;
    vector<int> left = MergeSort(vec, p, k);
    vector<int> right = MergeSort(vec, k+1, q);

    return Merge(left, right);  // 병합된 정렬된 벡터 반환
}

int main(){
    vector<int> vec = {37, 10, 22, 30, 35, 13, 25, 24};

    // 정렬 전 벡터 출력
    cout << "정렬 전: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // 정렬된 벡터 반환
    vector<int> sortedVec = MergeSort(vec, 0, vec.size() - 1);

    // 정렬 후 벡터 출력
    cout << "정렬 후: ";
    for (int num : sortedVec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}