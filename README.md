# Banker-s-Algorithm-
用c++简单实现的银行家算法

大致实现效果如下
![](1.png)
代码中的Vector容器中的数据都是已经创建好的，经过测试没有问题。
如果将```available```容器中的可用资源换成{1，2，1},此时序列是不安全的
![](2.png)
自己写的Vector容器动态分配空间好像有点问题。。。就全是默认的初值。