# 第12章 动态内存：

## 练习 12.1：
## 练习 12.2：
[StrBlob](ex12_02.h)
## 练习 12.6：
[Code](ex12_06.cpp)
##练习 12.7：
[Code](ex12_07.cpp)
##练习 12.8：
>下面的函数是否有错误？如果有，解释错误原因。

```c++
bool b() {
	int* p = new int;
	return p;
}
```
返回值不应该是布尔，应该是int*。

## 练习 12.9：

> 解释下面代码执行的结果：

```c++
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shard<int>(100);
r2 = q2;
```

r和q指向同一个值为42的int，r原来指向的值为100的int已经不可访问但没有释放；r2原来指向的引用递减为0，对象被销毁，q2的引用计数递增。

## 练习 12.14：

[Code](ex12_14.cpp)

## 练习 12.15：

[Code](ex12_15.cpp)

## 练习 12.16：

> 如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种错误的程序，观察编译器如何诊断这种错误。

[Code](ex12_16.cpp)

clang++:

```sh
ex12_16.cpp:8:21: error: call to deleted constructor of 'unique_ptr<int>'
    unique_ptr<int> p2(p1);
                    ^  ~~
/usr/bin/../lib/gcc/armv6l-unknown-linux-gnueabihf/6.3.1/../../../../include/c++/6.3.1/bits/unique_ptr.h:359:7: note:
      'unique_ptr' has been explicitly marked deleted here
      unique_ptr(const unique_ptr&) = delete;
      ^
ex12_16.cpp:10:8: error: overload resolution selected deleted operator '='
    p3 = p1;
    ~~ ^ ~~
/usr/bin/../lib/gcc/armv6l-unknown-linux-gnueabihf/6.3.1/../../../../include/c++/6.3.1/bits/unique_ptr.h:360:19: note:
      candidate function has been explicitly deleted
      unique_ptr& operator=(const unique_ptr&) = delete;
                  ^
/usr/bin/../lib/gcc/armv6l-unknown-linux-gnueabihf/6.3.1/../../../../include/c++/6.3.1/bits/unique_ptr.h:252:7: note:
      candidate function not viable: no known conversion from 'unique_ptr<int>' to
      'std::unique_ptr<int, std::default_delete<int> > &&' for 1st argument
      operator=(unique_ptr&& __u) noexcept
      ^
/usr/bin/../lib/gcc/armv6l-unknown-linux-gnueabihf/6.3.1/../../../../include/c++/6.3.1/bits/unique_ptr.h:272:2: note:
      candidate function [with _Up = int, _Ep = std::default_delete<int>] not viable:
      no known conversion from 'unique_ptr<int>' to 'unique_ptr<int,
      std::default_delete<int> > &&' for 1st argument
        operator=(unique_ptr<_Up, _Ep>&& __u) noexcept
        ^
/usr/bin/../lib/gcc/armv6l-unknown-linux-gnueabihf/6.3.1/../../../../include/c++/6.3.1/bits/unique_ptr.h:281:7: note:
      candidate function not viable: no known conversion from 'unique_ptr<int>' to
      'nullptr_t' for 1st argument
      operator=(nullptr_t) noexcept
      ^
2 errors generated.
```

