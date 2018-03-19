#Activity


-----------------------------------

1, 开始运行 activity 从 onCreate() -> onStart() -> onResume() 进入运行状态  
当关闭 Activity 时（完全关闭） 从 onPasue() -> onStop() -> onDestory()  
当Activity进入后台（非消除activity）从 onPasue() -> onStop() 进入后台（处于停滞状态）  
当Activity 处于前台但是 在activity 之上有覆盖 进入 onPasue()状态 
------------------------------------------------------------------
2, 当acitivity 处于 onStop()时 再回退到 activity 进入 onResume();  
当activity 从后台出来 onReStart() -> onStart() -> onResume();  
但是在后台期间因内存不足导致activity清楚要重新从 onCreate() -> onStart() ->onResume()

3, 在onStart()阶段还不能进行交互,因为此时还存在与后台，所以一般base类没有在onStart()中添加更多的东西  
在onPasue()中可以进行耗时较少的操作 如一些页面数据的保存 但是不能进行耗时过多的操作 因为会影响之后的activity
 当onPasue()未结束下一个activity的onResume()不会执行
 
4, 在activity出现意外被销毁时 acitivity会调用 onSaveInstanceState() 然后在重启该activity时
在onCreate()之后调用 onRestoreInstanceState() 我们可以在onSave() 中保存当前页面的数据然后在
onRestore()中重新恢复， 在这其中数据都是用 Bundle 传递 在onSave() 中创建 Bundle传递到onRestore()

5, 在页面横竖切换的时候 如果不想让activity重建 可以在该activity的 configChanges 参数 设置
`
android : configChanges = "orientation"
`

6, activity 启动模式
> standard 模式 ：在这种模式 activity会进入默认的 任务栈  
在非activity类型的context（如ApplicationContext）并没有所谓的任务栈，所以不能通过ApplicationContext去启动standard模式的activity

>singleTop 模式 ：栈顶复用模式 只要新的activity 有同一个Activity在任务栈的栈顶时 该activity不会被重新创建 只会调用 onNewIntent()
因为没有创建新的activity 所以 onCreate() onStart() onResume() 不执行

>singleTask模式 ：栈内复用模式 只要要启用的activity在栈中存在 就把该activity 调到栈顶 并且调用该activity的
onNewIntent()

>

>>