#include "main.h"
#include<algorithm>
class algo_47{
public:
    void test();
protected:
private:
    std::vector<vector<int> > res;
    std::vector<int> temp;
    vector<vector<int> >& permute(std::vector<int> array);
    void backtrace(vector<bool> &used, vector<int>& array, int deepth);
};

void algo_47::test() {
    std::cout << "47:全排列：[1,1,3,2]" << std::endl;
    vector<int> array = {1, 1, 3, 2};
    algo_47 algo_47;
    vector<vector<int> > reslut = algo_47.permute(array);
    for(auto i : reslut) {
        cout << "[";
        for(auto j : i) {
            cout << j;
        }
        cout << "], ";
    }
    cout << endl;
}

void algo_47::backtrace(vector<bool> &used, vector<int>& array, int deepth) {
    if(deepth == array.size()) {
        res.push_back(temp);
        return;
    }

    for(int i = 0; i < array.size(); i++) {
        if(used[i]) {
            continue;
        }
        // 这里使用used[i - 1] 和 !used[i - 1]都可以算出正确的的解。
        //      但是使用used[i - 1]时间复杂度更低
        //      [1a, 1b, 3]  当处理1b的时候发现1a还未使用，这说明1a已经处理完成放入队列了，这个时候不需要在处理1b了，所以continue。
        if(i > 0 && !used[i - 1] && array[i] == array[i - 1]) {
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

vector<vector<int> >& algo_47::permute(std::vector<int> array) {
    vector<bool> used(array.size(), false);
    std::sort(array.begin(), array.end());
    backtrace(used, array, 0);
    return this->res;
}

void test_47() {
    algo_47 a;
    a.test();
}