## 集成Glog

- 获取Glog代码
```shell
[submodule "third_party/glog"]
	path = third_party/glog
	url = https://github.com/google/glog.git

```
- Cmake集成

**源码方式：**

```shell
# 不知道为什么，不设置这个变量为OFF我就会编译报错。
set(WITH_GTEST OFF)
add_subdirectory(third_party/glog)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    glog::glog
)
```
**三方库方式：**

```shell
brew install glog
Warning: glog 0.5.0 is already installed and up-to-date'
```

- cmake

```shell

cmake_minimum_required (VERSION 3.16)
project (myproj VERSION 1.0)

find_package (glog 0.5.0 REQUIRED)

add_executable (myapp main.cpp)
target_link_libraries (myapp glog::glog)
```



## Glog使用


### 注意事项
- log保存文件的位置
除非另有说明，否则 glog 会写入文件名`/tmp/\<program name\>.\<hostname\>.\<user name\>.log.\<severity level\>.\<date\>-\<time\>.\<pid\> `（例如，` /tmp/hello_world.example.com.hamaji.log.INFO.20080709-222411.10474`）。默认情况下，glog除了日志文件之外，还会复制严重级别的日志消息ERROR或 FATAL标准错误（ ）。stderr

如果需要修改log保存的位置，可以设置变量：
```c++
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = "/Users/chendongsheng/github/algo/p_log/";
    LOG( INFO) << "Found " << 2 << " cookies";
```
`log` 就会保存在路径： `FLAGS_log_dir` 之下。

### Glog的各种设置
有很多设置项可以修改glog的输出， 如果安装了 Google gflags library ， 在c++代码中使用glog，直接设置变量值，则会直接影响。
```shell
option (WITH_GFLAGS "Use gflags" ON)
```
可以看到 `GLog` 的 `cmakelist` 默认是开启该库的，所以我们可以直接使用。

**有二种使用方式：**

1. 直接在代码中使用(修改全局变量后立即生效)
```c++
FLAGS_logtostderr = 1;
FLAGS_logtostderr = 0;
```

2. 命令行使用
```shell
./your_application --logtostderr=1
```

常用的设置项目：
1. `logtostderr (bool, default=false)`
将标准错误输出到控制台，而不是文件中。
2. `stderrthreshold (int, default=2, which is ERROR)`

将这些级别的日志，也保存到logerror文件中。
```
INFO, WARNING, ERROR, and FATAL
0, 1, 2, and 3
```

默认是2，就是error

3. `log_dir (string, default="")`

日志文件保存路径

### 详细API
- 默认四个LOG等级，只有FATAL, ERROR会打印在控制台，其它日志会在日志文件中保存。
```c++
// FATAL, ERROR, WARNING, and INFO.
// Make a bunch of macros for logging.  The way to log things is to stream
// things to LOG(<a particular severity level>).  E.g.,
//
//   LOG(INFO) << "Found " << num_cookies << " cookies";
//
```

- 缓存日志，而不是立刻报出。

```c++
// You can capture log messages in a string, rather than reporting them
// immediately:
//
//   vector<string> errors;
//   LOG_STRING(ERROR, &errors) << "Couldn't parse cookie #" << cookie_num;
//
// This pushes back the new error onto 'errors'; if given a NULL pointer,
// it reports the error via LOG(ERROR).
```
- 条件日志
```c++
// You can also do conditional logging:
//
//   LOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";
//
```

- 该语句每执行N次，打一次日志。

```c++
// You can also do occasional logging (log every n'th occurrence of an
// event):
//
//   LOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER << "th cookie";
//
// The above will cause log messages to be output on the 1st, 11th, 21st, ...
// times it is executed.  Note that the special google::COUNTER value is used
// to identify which repetition is happening.
//
```

- 打印前20次日志
```c++
// You can log messages the first N times your code executes a line. E.g.
//
//   LOG_FIRST_N(INFO, 20) << "Got the " << google::COUNTER << "th cookie";
//
// Outputs log messages for the first 20 times it is executed.
```
- debug模式的日志
特殊的“调试模式”日志记录宏仅在调试模式下有效，并且在非调试模式编译时被编译为无。使用这些宏可以避免由于过多的日志记录而减慢生产应用程序的速度。
```c++
// There are also "debug mode" logging macros like the ones above:
//
//   DLOG(INFO) << "Found cookies";
//
//   DLOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";
//
//   DLOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER << "th cookie";
//
// All "debug mode" logging is compiled away to nothing for non-debug mode
// compiles.
//
// We also have
//
//   LOG_ASSERT(assertion);
//   DLOG_ASSERT(assertion);
```
- 日志格式

```c++

// LOG LINE PREFIX FORMAT
//
// Log lines have this form:
//
//     Lyyyymmdd hh:mm:ss.uuuuuu threadid file:line] msg...
//
// where the fields are defined as follows:
//
//   L                A single character, representing the log level
//                    (eg 'I' for INFO)
//   yyyy             The year
//   mm               The month (zero padded; ie May is '05')
//   dd               The day (zero padded)
//   hh:mm:ss.uuuuuu  Time in hours, minutes and fractional seconds
//   threadid         The space-padded thread ID as returned by GetTID()
//                    (this matches the PID on Linux)
//   file             The file name
//   line             The line number
//   msg              The user-supplied message
//
// Example:
//
//   I1103 11:57:31.739339 24395 google.cc:2341] Command line: ./some_prog
//   I1103 11:57:31.739403 24395 google.cc:2342] Process id 24395
```
E20220904 13:54:02.124370 11612173 main.cpp:32] Found 2 cookies
E20220904 13:54:02.125782 11612173 main.cpp:33] Found 2 cookies
E20220904 13:54:02.125818 11612173 main.cpp:34] Found 2 cookies

## check宏

经常检查程序中的预期条件以尽早发现错误是一种很好的做法。 CHECK 宏提供了在不满足条件时中止应用程序的能力，类似于标准 C 库中定义的断言宏。
如果条件不成立，CHECK 会中止应用程序。
```
CHECK(fp->Write(x) == 4) << "Write failed!";
```

- `CHECK_EQ`
- `CHECK_NE`
- `CHECK_LE`
- `CHECK_LT`
- `CHECK_GE`
- `CHECK_GT`
如果参数之一是指针而另一个是 NULL，编译器会报告错误。要解决此问题，只需将 static_cast NULL 转换为所需指针的类型。

```c++
CHECK_EQ(some_ptr, static_cast<SomeType*>(NULL));
```
最好是直接使用： `CHECK_NOTNULL`
```c++
CHECK_NOTNULL(some_ptr);
some_ptr->DoSomething();
```

*字符串比较：**
- `CHECK_STREQ`
- `CHECK_STRNE`
- `CHECK_STRCASEEQ`
- `CHECK_STRCASENE`
CASE 版本不区分大小写。您可以安全地为此宏传递 NULL 指针。他们将 NULL 和任何非 NULL 字符串视为不相等。两个 NULL 相等

## verbose log
当您在寻找困难的错误时，完整的日志消息非常有用。但是，您可能希望忽略通常开发中过于冗长的消息。对于这种详细的日志记录，glog 提供了 VLOG 宏，它允许您定义自己的数字日志记录级别。 --v 命令行选项控制记录哪些详细消息：

```c++
VLOG(1) << "I’m printed when you run the program with --v=1 or higher";
VLOG(2) << "I’m printed when you run the program with --v=2 or higher"; << "I’m printed when you run the program with --v=1 or higher";
VLOG(2) << "I’m printed when you run the program with --v=2 or higher";
```

比如说 `VLOG（1）` 这个，当运行程序的时候，加上参数： `--v=1`, 则 就可以打印出来log，

当然，条件日志依旧可以使用。


## 设置日志格式
glog 支持通过接收用户提供的用于生成此类字符串的回调来更改附加到日志消息的前缀格式。该功能必须在编译时通过 WITH_CUSTOM_PREFIX 标志启用。
对于每个日志条目，将使用包含严重性、文件名、行号、线程 ID 和事件时间的 LogMessageInfo 结构调用回调。它还将获得对输出流的引用，其内容将添加到最终日志行中的实际消息之前。

```c++

/* This function writes a prefix that matches glog's default format.
 * (The third parameter can be used to receive user-supplied data, and is
 * NULL by default.)
 */
void CustomPrefix(std::ostream &s, const LogMessageInfo &l, void*) {
   s << l.severity[0]
   << setw(4) << 1900 + l.time.year()
   << setw(2) << 1 + l.time.month()
   << setw(2) << l.time.day()
   << ' '
   << setw(2) << l.time.hour() << ':'
   << setw(2) << l.time.min()  << ':'
   << setw(2) << l.time.sec() << "."
   << setw(6) << l.time.usec()
   << ' '
   << setfill(' ') << setw(5)
   << l.thread_id << setfill('0')
   << ' '
   << l.filename << ':' << l.line_number << "]";
}
```

- 使用方式：

```c++

InitGoogleLogging(argv[0], &CustomPrefix)
```
## 其他设置
- 性能
glog 提供的条件日志宏（例如，CHECK、LOG_IF、VLOG 等）经过精心实现，并且在条件为假时不执行右侧表达式。因此，以下检查可能不会牺牲您的应用程序的性能。
```c++
CHECK(obj.ok) << obj.CreatePrettyFormattedStringButVerySlow();
```
- 自定义异常退出
FATAL 严重级别消息或不满足的 CHECK 条件终止您的程序。您可以通过 InstallFailureFunction 更改终止的行为。
```c++
void YourFailureFunction() {
  // Reports something...
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  google::InstallFailureFunction(&YourFailureFunction);
}
```
- 自动清除日志

```c++
google::EnableLogCleaner(3); // keep your logs for 3 days
google::DisableLogCleaner();
```



## 学习资料

- [官网文档翻译版本](https://blog.csdn.net/horsee/article/details/125354437)
- [GitHub 英文原本文档](https://github.com/google/glog#user-guide)
- [代码内部注释说明](https://github.com/google/glog/blob/b70ea80433c2a8f20b832be97b90f1f82b0d29e9/src/glog/logging.h.in#L226)
