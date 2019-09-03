##Dart基础

## 多重继承Mixins
 因为dart是一个单继承的模式并不具备多继承的功能，而Mixins可以使它能类似多继承一样
 作为Mixins的类只能继承自**Object** 并且不能有显示声明构造方法

 #### 简化写法
 如果继承类只是想继承多重类的方法 写法可以简化
 相当于多模块组合
 例：
 ```
 class A extends B with C{}
 ==
 class A = B with C;
```

## 操作符覆盖
类似 c/c++里的操作符覆盖 通过**operator**
在类里面重定义操作符
```
    bool operator <(int a){
        return this.a < a;
    }
```

## 枚举 enum
在Dart中 index是从**0**开始 并且不能指定原始值,不能添加方法，只是一个纯粹的枚举
```
    enum Seanson{
        spring,
        summer
    }
```

## 方法
