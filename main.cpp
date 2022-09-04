#include <iostream>
#include "main.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <glog/logging.h>

#include "bianry_tree/a.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

static int init_goole_test() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

static void init_glog(char const *argv[]) {
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = "/Users/chendongsheng/github/algo/log/";
    return;
}



void say_hello(){
    std::cout << "Hello, from algo!\n";
}

int main(int argc, char const *argv[])
{

    init_goole_test();
    init_glog(argv);
    LOG(ERROR) << "Found " << 2 << " cookies";
    // say_hello();

    // // 123全排列问题
    // test_46();
    // test_47();
    // // test_46();

    // printTree();
    cout << "test dev";
    return 0;
}
