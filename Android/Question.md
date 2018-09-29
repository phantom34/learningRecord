
1 什么情况下 会内存泄漏

2 广播的调用方式

3 rxjava

4 要回收对象 放在哪个周期

5 application

6 recycleview 生成 80个item 需要多少 view 显示8个  多少缓存

 8个view  8+2+5*viewtype


 7 view的 构造函数  自定义参数类型有哪些
 public CustomView(Context context, AttributeSet attrs, int defStyleAttr)
```
//在AttributeSet中参数有
// reference 医用资源
// string
// color
// boolean
// dimension  尺寸
// float
// integer
// fraction 百分数
// enum
// flag 位或运算
```

view 创建

meassure
layout
draw


8 activity service 生命周期

Service
在使用bindService时 时 oncreate onbind onunbind  ondestroy

正常 oncreate onstart  ondestory

9 aidl binder

aidl 程序间接口 可以自动 生成 binder 文件
