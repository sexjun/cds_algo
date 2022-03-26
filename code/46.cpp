#include "main.h"



#include<vector>
#include<string>
#include<list>
#include <forward_list>

using namespace std;

std::vector<vector<int> > res;
std::vector<int> temp;

void backtrace(vector<bool> &used, vector<int>& array, int deepth) {
    if(deepth == array.size()) {
        res.push_back(temp);
        return;
    }

    for(int i = 0; i < array.size(); i++) {
        if(used[i]) {
            continue;
        }
        used[i] = true;
        temp.push_back(array[i]);
        backtrace(used, array, deepth + 1);
        used[i] = false;
        temp.pop_back();
    }
    return;
}

vector<vector<int> > permute(std::vector<int> array) {
    
    vector<bool> used(array.size(), false);
    backtrace(used, array, 0);
    return res;
}

void test_46() {
    std::cout << "46:全排列：" << std::endl;
    vector<int> array = {1, 2, 3};
    vector<vector<int> > reslut = permute(array);
    for(auto i : reslut) {
        cout << "[";
        for(auto j : i) {
            cout << j;
        }
        cout << "], ";
    }
}