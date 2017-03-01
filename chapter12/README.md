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