#include "iostream"
#include "vector"

using namespace std;

template<typename type>
int linear_search(vector<type>& items, type target, int index){
// Begin the search from the end of the array and work backwards
    if(index >= items.size())
        return -1;

    if(target == items[index])
        return index;
    else
        return linear_search(items,target,index-1);
}

void insertionSort(vector<int> &list){
    int i, j, temp;
    // Compare our current index with the one to the right of it and update accordingly
    for(i = 0; i < list.size(); i++){
        temp = list[i];
        j = i - 1;
        while(j >= 0 && list[j] > temp){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = temp;
    }
}