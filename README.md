# cds_algo

## 回溯算法
### 46、不重复数字的排列组合
- t
### 47、有重复数字的排列组合

```c++
if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
    continue;
}
perm.emplace_back(nums[i]);
vis[i] = 1;
backtrack(nums, ans, idx + 1, perm);
vis[i] = 0;
perm.pop_back();
```
当前处理的是索引为 i 的元素把，那么 i - 1 的元素肯定是被遍历过的吧，而遍历索引为 i 的元素是从遍历 i - 1 元素回溯过来的吧

这个时候 used[i - 1] = false，表示的是这个 i - 1 是已经被访问过的，而不是正在访问，如果是正在访问的话，那么是 true，如果是回溯后，就会设置为 false

所以说，用汉字描述就是 i - 1 元素已经被访问过了，用代码的话就是 !used[i - 1]

> backtrack调用完以后，vis[i]被设为0，也就是说在下次循环开始，vis[i-1]为0代表它已经被访问过了。
