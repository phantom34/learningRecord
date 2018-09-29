#Handle


Handle是为了实现线程间通信

当要处理耗时操作时可以建立子线程 然后在子线程里调用 handle.sendMessage()
发送msg到MessageQueue 消息队列里
然后在主线程中有一个 Looper (能不停循环消息队列 取出消息) 当有新消息的时候
handle 会调用 handlemessage()

在Looper中 存在一个 for(;;) 死循环 一直从 MessageQueue 队列中 读取msg

读取msg之后 判断 在系统跟踪缓冲区 是否已经存在过  调用 Trace.traceBegin 和
Trace.traceEnd  其中传入 tag 和  使用的函数名 如果没存过调用dispatchMessage

在messageQueue调取时 判断 当前线程标记 和原有线程标记时 出现不一样 log输出是
log.wtf 哈哈哈哈

当 messagequeue没有msg 是 会退出 for死循环
