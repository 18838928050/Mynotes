
* [一.基础概念](#基础概念)
    - [1.c的%d使用代码案例](#1c的%d使用代码案例)
    - [2.sizeof用法](#2sizeof用法)
    - [3.编码风格](#3编码风格)
    - [4.序列化](#4序列化)
    
* [二.基础技术](#二基础技术)
    - [1.Namespace](#1namespace)
        + [1.1 UTS Namespace](#11-uts-namespace)
        + [1.2 IPC Namespace](#12-ipc-namespace)
        + [1.3 PID Namespace](#13-pid-namespace)
        + [1.4 Mount Namespace](#14-mount-namespace)
        + [1.5 User Namesapce](#15-user-namesapce)
        + [1.6 Network Namespace](#16-network-namespace)
    - [2.Cgroups](#2cgroups)
        + [2.1 Cgroups中的3个组件](#21-cgroups中的3个组件)
        + [2.2 Cgroup文件系统](#22-cgroup文件系统)
## c的%d使用代码案例

# 一.基础概念

## 1.c的%d使用代码案例

```
#include <stdio.h>
int main()
{
int s1=290;//攻击力
int s2=90;
printf("%d\n",s1);
printf("%d\n",s2);
return 0;
}
```
</br>
## 2.javadoc

- javadoc是Sun公司提供的一个技术，它从程序源代码中抽取类、方法、成员等注释形成一个和源代码配套的API帮助文档。
<div align="center"> <img src="./png/javadoc.png"/> </div>

<br>

## 3.编码风格



<div align="center"> <img src="./png/编码风格.png"/> </div>

<br>
<br>

## 4.序列化
只要一个类实现Serializable接口，那么这个类就可以序列化了。
最近在阅读JDK源码中的集合，看到很多集合类实现了Serializable接口,Cloneable接口。在阅读了很多关于Serializable接口的博客后，浅谈下我对Serializable接口的理解。
**序列化：**对象的寿命通常随着生成该对象的程序的终止而终止，有时候需要把在内存中的各种对象的状态（也就是实例变量，不是方法）保存下来，并且可以在需要时再将对象恢复。虽然你可以用你自己的各种各样的方法来保存对象的状态，但是Java给你提供一种应该比你自己的好的**保存对象状态的机制**，那就是序列化。
<div align="center"> <img src="./png/Serializable.png"/> </div>
</br>

### serialVersionUID
注意到上面程序中有一个 serialVersionUID ，实现了Serializable接口之后，Eclipse就会提示你增加一个 serialVersionUID，虽然不加的话上述程序依然能够正常运行。</br>

### 序列化 ID 在 Eclipse 下提供了两种生成策略
- 一个是固定的 1L
- 一个是随机生成一个不重复的 long 类型数据（实际上是使用 JDK 工具，根据类名、接口名、成员方法及属性等来生成</br>

### 静态变量序列化
串行化只能保存对象的非静态成员交量，不能保存任何的成员方法和静态的成员变量，而且串行化保存的只是变量的值，对于变量的任何修饰符都不能保存。如果把Person类中的name定义为static类型的话，试图重构，就不能得到原来的值，只能得到null。说明对静态成员变量值是不保存的。这其实比较容易理解，序列化保存的是对象的状态，静态变量属于类的状态，因此 序列化并不保存静态变量。
</br>

### transient关键字
经常在实现了 Serializable接口的类中能看见transient关键字。这个关键字并不常见。 transient关键字的作用是：**阻止实例中那些用此关键字声明的变量持久化；**当对象被反序列化时（从源文件读取字节序列进行重构），这样的实例变量值不会被持久化和恢复。当某些变量不想被序列化，同是又不适合使用static关键字声明，那么此时就需要用transient关键字来声明该变量。例如用 transient关键字 修饰name变量
<div align="center"> <img src="./png/tr.png"/> </div>

- 序列化： 将数据结构或对象转换成二进制串的过程
- 反序列化：将在序列化过程中所生成的二进制串转换成数据结构或者对象的过程

# 二.基础技术

## 1.Namespace

* kernel的一个功能
* 可以隔离一系列系统资源：比如PID(Process ID)，User ID, Network等等

当前Linux一共实现了6种不同类型的Namespace：

| Namespace类型        | 系统调用参数           | 内核版本 |
| :-------------: |:-------------:| :-----:|
| [Mount namespaces](#14-mount-namespace)      | CLONE_NEWNS | 2.4.19 |
| [UTS namespaces](#11-uts-namespace)      | CLONE_NEWUTS   |   2.6.19 |
| [IPC namespaces](#12-ipc-namespace) | CLONE_NEWIPC    |    2.6.19 |
| [PID namespaces](#13-pid-namespace) | CLONE_NEWPID | 2.6.24 |
| [Network namespaces](#16-network-namespace) | CLONE_NEWNET |  2.6.29 |
| [User namespaces](#15-user-namesapce) | CLONE_NEWUSER | 3.8 |

Namesapce 的API主要使用三个系统调用

* **clone()**：创建新进程。根据系统调用参数来判断哪种类型的namespace被创建，而且它们的子进程也会被包含到namespace中
* **unshare()**：将进程**移出**某个namespace
* **setns()**：将进程**加入**到namespace中

### 查看进程的namespace信息
