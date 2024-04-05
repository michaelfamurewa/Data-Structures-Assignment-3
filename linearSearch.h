#include "iostream"
#include "vector"
#include "iterator"
#include "list"

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
