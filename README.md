# TutorialFoCLang

本书是一本介绍C的书,不是语法书而是特定使用场景下的入门参考手册.本文针对的对象是已经熟练使用python的数据科学工作人员.分为3个主要应用场景:

1. 使用C编写数学模型
2. 封装用C编写的模型为python可调用的模块
3. 在嵌入式设备上使用C语言

因为这个场景的限制,本书会涉及的内容只是C.而且许多针对大型程序的方法论以及语法将在这边不适用.本书基本不涉及设计模式,基本不涉及一些数据结构与算法的实现,这本书不适合计算机专业的人看,因为老实说计算机专业的人和数据科学专业的人对于程序,算法的理解有很大不同.

不过作为一本入门书,当然还是会带有语法,只是这些语法会结合例子使用.

这本数的结构大致会和讲python那本一致,内容也偏向实用,希望的是一本书看完就可以在与本书相同的场景下使用C.并且对整个C的基本原理有个大致了解.

## 本书的主要内容

本文的每一章都将以一个完整例子开始,这章的内容就是逐步的完善这个例子.


主要内容主要包括:

1. 工具链
    
    工欲善其事必先利其器,和python一样,我们先从工具入手.C作为一门编译型语言,最终输出的是可执行的二进制文件.因此讲工具链的时候我们顺便就可以了其编译的原理了.本章的例子是一个简单的二维向量的加法乘法预算

2. 数据模型

    C语言恐怕是除了汇编以外最接近硬件底层的编程语言,啥华丽的特性都没有,本章主要是讲解其数据模型,包括类型系统,值,指针,内存分配等比较底层的内容,C语言说到底都是围绕这些展开的.

3. 输入输出和文本处理

    这部分讲系统标准输入输出,文件io操作以及bytes,string,utf-8的处理.

4. 流程控制

    和python一样,C也可以使用单线程,协程,多线程,多进程进行编程.而且C是真正的多线程,没有全局锁,因此多核并行计算多线程更加合适,而多进程更多的是体统调用子进程和系统提供的进程间通信接口了.本章主要讲C提供的多线程工具,以及更加方便的openmp.本例将为我们的简单矩阵

5. 函数与函数指针

6. C语言与面向对象

7. 矩阵运算mkl

    使用现成的矩阵运算库实现一个单线程的多层感知器模型
    
8. opencv编程
9. 社会网络图模型与igraph
10. tensorflow与gpu运算
11. 异构计算opencl与clBLAS
12. 使用为python写扩展
    在python那本中已经有过讲解,这边以C的视角再次讲解如何使用Cython封装一个C库