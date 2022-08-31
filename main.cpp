#include <iostream>
#include "main.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

#include "bianry_tree/a.h"


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

int init_goole_test() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}



void say_hello(){
    std::cout << "Hello, from algo!\n";
}

int main(int argc, char const *argv[])
{
    init_goole_test();
    say_hello();

    // 123全排列问题
    test_46();
    test_47();
    // test_46();

    printTree();
    return 0;
}
