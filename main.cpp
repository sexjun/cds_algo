#include <iostream>
#include "main.h"
#include <iostream>
#include <vector>
#include "bianry_tree/a.h"

void say_hello(){
    std::cout << "Hello, from algo!\n";
}

int main(int argc, char const *argv[])
{
    say_hello();
    // 123全排列问题
    test_46();
    test_47();
    // test_46();

    printTree();
    return 0;
}
