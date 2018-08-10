#GC

#
对象在虚拟机中的生命周期

Created -> InUse -> Invisible -> Unreachable -> Collected -> Finalized -> Deallocated  
 创建       应用      不可见      不可达阶段        收集阶段      终结         重分配  

(在创建对象的时候在确定不需要使用该对象 使对象质控 更符合垃圾回收标准 减少深层的引用)

ActivityManager.getMemoryClass() 可以用来查询当前应用的 Heap Size

###内存回收机制
在内存空间分成三个区域 : Young Generation 、Old Generation 、Permanent Generation

||Young      ||  Old    ||  Permanent  ||  
||eden s0 s1 || Tenured || Permanent   ||

####处于Young
大部分新生成的 对象都储存在 eden区 当 Eden区满之后 **还存活的对象** 再copy到 s0区域 然后 当s0也满了之后 **还存活的对象**
从 s0 copy到 s1，s0 清空，之后 当s1满载 s1 将**还存活的对象** copy到s0， 以这种模式 辗转 多次 （这里的多次根据
系统来定）  (copying 算法  复制直接保存)  
####处于Old
当辗转次数到达后 **还存活的对象** 将 copy到Tenured区 也就是 Old Generation （Mark算法  标记存活对象 回收未
标记对象 然后回收后对空出空间合并 或者标记下次分配  以减少内存碎片带来的损耗）  
####处于Permanent
 当对象在Old区域存活时间达到一定时间就会移动到Permanent Generation

###内存泄漏 OOM

1. 资源对象未关闭 
比如读取了一些 Curosr、File文件 形成缓存 在不使用时关闭   
 在Activity中创建一个外部类 和创建一个内部临时类是不同的 外部类会长时间持有 而内部类是 gc
2. 注册对象未注销
 在注册广播接收器 观察者时 当Activity 释放后 因为没有取消之前注册的观察者 导致 Activity无法被GC回收
3. 静态变量长期维持大数据对象


###使用最优数据类型 

1. 注解枚举
IntDefault、 StringDef



http://steamcommunity.com/id/phantom34
752049635@qq.com	cjphantom123	phantom
