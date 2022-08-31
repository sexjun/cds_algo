```
              1
           2     3
        4   5  6  7
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/c00baebf8f8b455397f104195f5b164e.png)


前序遍历：pre_order:
`1 2 4 5 3 6 7 `
中序遍历：in_order:
`4 2 5 1 6 3 7 `
后序遍历：post_order:
`4 5 2 6 7 3 1 `
- 定义树
```c++
class binaryTree {
    public:
    int value;
    binaryTree* left;
    binaryTree* right;
    binaryTree() = default;
    binaryTree(int v):value(v) {
        left = right = nullptr;
    }
    ~binaryTree() {
        delete this->left;
        delete this->right;
        left = left = nullptr;
    }
};
```
- 构建树
```c++
binaryTree* buildTree() {
    //           1
    //        2     3
    //     4   5  6  7
    binaryTree* d = new binaryTree(1);
    d->left = new binaryTree(2);
    d->right = new binaryTree(3);

    d->left->left = new binaryTree(4);
    d->left->right = new binaryTree(5);

    d->right->left = new binaryTree(6);
    d->right->right = new binaryTree(7);
    return d;
}
```
- 前序遍历
```c++
void pre_order(const binaryTree* b) {
    if(b == nullptr) {
        return;
    }
    cout << b->value << " ";;
    pre_order(b->left);
    pre_order(b->right);
}
// output:
/*
preorder:
1 2 4 5 3 6 7
*/
```

- 测试代码
```c++
void printTree() {
    binaryTree* b = buildTree();
    cout << "pre_order:" << endl;
    pre_order(b);
    cout << endl;

    cout << "in_order:" << endl;
    in_order(b);
    cout << endl;

    cout << "post_order:" << endl;
    post_order(b);
    cout << endl;
    return;
}
```

[GitHub代码链接](https://github.com/sexjun/cds_algo/tree/master/bianry_tree)
