
1 什么情况下 会内存泄漏

  打开一个 inputstream 然后当activity 结束时没有关闭
 长时间持有一个 无用的对象 导致 内存泄漏

2 广播的调用方式
 一种是静态注册 在mainifest 中 注册好广播
一种是 标准的发送广播
 ```
        <receiver android:name=".NormalReceiver">
            <intent-filter>
                <action android:name="com.example.normal.receiver" />
            </intent-filter>
        </receiver>
 ```
 创建广播
 ```
 public class NormalReceiver extends BroadcastReceiver {

    private static final String TAG = "NormalReceiver";

    public NormalReceiver() {
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        String msg = intent.getStringExtra("Msg");
        Log.e(TAG, msg);
    }

}
 ```
发送广播
 ```
 Intent intent = new Intent(NORMAL_ACTION);
      intent.putExtra("Msg", "Hi");
      sendBroadcast(intent);
 ```

 静态注册还有一个 发送有序广播
 在mainifest中的 **intent-fiter** 设置 优先级
 ```
    android:priority="99"
 ```
动态 注册广播  可以在 Service 中注册广播接收器  然后在oncreate 注册广播
在 onDestory 反注册广播

在activity 中 可以 启动服务 来打开广播 然后在关闭服务 反注册广播  通过 **sendBroadcast(Intent);** 发送广播


3 rxjava
 核心是 异步
 总的流程是 事件源发起 通过 操作符 转换成 新的事件流 然后 传递给下游 最后在
 将结果传递给  subscribe() 中 实现订阅代码


4 要回收对象 放在哪个周期
onpause ondestory

5 application
 和 activity 以及 service 一样是 app的组件之一  并且 application在 app中是唯一的 也就是 是一个全局单例类
 同是 application 也可以通过 类似 hashmap  实现 数据 交换


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

aidl 接口定义语言   本质是生成 binder文件的 ontransact  给 客户端调用  可以自动 生成 binder 文件

10 什么情况会导致崩溃
  空指针 oom anr 内存泄漏

  11 ANR  
   本质是主线程阻塞导致
  输入分发事件响应超过 5s
  前台广播 10s  后台广播 20s
  前台服务 20s  后台服务200s
  contentprovider 在 pulish 过程超时 10s


12 gilde Picasso
 两者方法度很多

 但是 gilde 在加载图片是先 根据imageview大小决定下载图片大小

 13 parcelable 和serialable
  s 是 java自带的  p则是Android的
  p 比 s 在效率上高 很多 但是如果是把数据保存在 本地磁盘 推荐用 s
  应为 p 不能保证外部有变化的情况下  自身不变 而 s 可以
  s 使用的时候代码量少 只有一个 uid
  而 p 则需要 实现 打包 和 解包

14 点击launcher 到打开页面
首先 launcher 向 system_server 发送请求 然后ss向zygote
发送信息  fork 出一个 子线程 也就是 app线程  然后app线程
然后app线程再向ss 请求 然后 ss向 app 发送 scheduleLaunchActivity
然后 app 在 application thread 接收到之后 使用handle 发送 launchactivity
消息 然后 app在主线程 接收到 之后 创建 activity


15 事件 分发
  从 父层到 子层
  如果 父层 不拦截 运行 子层 dispatch

16 消息处理机制

就是 handle 创建 looper 然后 looper中 有 messagequeue
在looper 中通过死循环读取 messagequeue中的msg 然后 handlemessage

17 okhttp 拦截器
  实际上是一个责任链模式 okhttp 在执行请求的时候 RealCall.execute 获取了这一责任链  **getResponseWithInterceptorChain**  然后 在没个阶段都会有一个拦截器 进行判断 然后 修改参数 或者保存参数

18 rxjava 实现原理

19 asynactack
  也是和handle 一样 是Android 的异步任务机制  不过比较简化
  ```
  public abstract class AsyncTask<Params, Progress, Result>
  ```
  主要方法是继承 这个 类

  **execute(Params... params)** 开启 异步方法  
  **onPreExecute()** 在execute  之后调用 可以做一些开始标记 在ui线程
  **doInBackground(Params... params)** 在onpreExecute()完成 开始可以在后台完成比较耗时的操作 同时可以通过 **publishProgress(Progress... values)** 方法传递 状态进度  
  **onProgressUpdate(Progress... values)** 在 publishProgress() 方法调用后 启动  可以更新 ui线程  
  **onPostExecute(Result result)** 当后台操作完成时调用 并返回值
  并且一个 任务进程 只能执行一次


20 java 继承 封装 多态
      封装是 把 方法内 参数 不被外界获取 只给出调用方法
      继承是 类的可以 拥有 父类的方法 同时子类也可以 重写 父类 protect的方法
      多态 就是把方法接口化 让多个子类 有多个同样方法名但是实现不一样



21 final static 能否修改
  final 定义常量的时候不能修改  如果是对象是可以修改的
  static 表示类变量 可以修改
  static final 对象也可以修改


22 类加载机制
加载 验证 准备 解析 初始化 使用 卸载  

23 jvm 模型


24 uml类图
  头 显示 函数类名
  第二层 显示 类内的  属性  + - # 显示 public private protect
  以及属性的 类别

第三层 显示 类的 操作方法


25 arraylist  linkedlist  vector
 三个都是实现了 List 接口
 但是在这其中 arraylist 和 linkedlist 不是线程安全的  vector是安全的
 arraylist 相对于 linkedlist  在get/set 比较快 但是  remove 和add 相对比较慢 （除了头尾元素） 而 vector和arraylist 很相像这操作上 但是 在 加入大量数据时 vector会申请两倍空间大小 而 arraylist 只多一半


26 http tcp/ic 协议

27 dns 解析

28 http 三次握手 4次挥手
    主要为了 安全 以及 两边当结束时 两边度可以确认 关闭了连接


29 设计模式  6大原则
  单一 开闭 接口隔离 可扩展性 依赖倒置

30 检测内存泄漏 leakcanary as
 as  allocation tracker

31 线程安全相关

32 concurrentHashMap

33 hashmap 实现

34 快排
  以一基数 通过交换 使得 在基数前的数小于 后的数 大于
  然后再在 前数列  和后数列进行同样的操作 直至完成


35 单例  饿汉  懒汉的区别


    ````
      public class Singleton {  
        private static Singleton instance = new Singleton();  
        private Singleton (){
       }
       public static Singleton getInstance() {  
       return instance;  
       }  
     }
   ````
  饿汉是在类加载完时就完成初始化 所以类加载比较慢 而且可能被其他方法导致类加载
  不符合懒加载效果
    ```
    懒汉
    class singleton{
        private static singleton instance;
        private singleton(){}
          public static synchronized singleton getInstance(){
            if(instance == null) {
              instance= new singleton();
            }
          }
      return instance;
    }

    ```
    第一次调用的时候初始化 但是 因为要线程同步导致 同步开销比较大 耗时
    ````
    public class Singleton{
      private Singleton(){}
      private static Singleton getInstance(){
        return SingletonHolder.sInstance;
      }

      private static class SingletonHolder{
        private static final Singleton sInstance = new Singleton();
      }

    }


    ````
   加载singleton 不会初始化 sinstance 在 第一 getInstance 才会记载 singletonHolder 这样保证了单例对象的唯一性 实现了懒加载 确保线程安全


36 中断 一个线程
  interrupt() 中断

37 优化

38 非ui线程 是否可以更新 UI
  该线程拥有自己的 viewroot 后再 checkThread之前（ 在onresume 之后创建）
