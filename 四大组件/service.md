#Service

----------------------------------------------------------------------------------

1,  service 类 通常长期在后台活动 它是没有界面的Activity 可以应用于 应用保活  后台听歌此类

```java
import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

class MyService extends Service{
  
  public MyService(){}
  
  @Override
  public IBinder onBind(Intent intent) {
    IBinder iBinder = null;
    return iBinder;
  }

  @Override
  public void onCreate() {
    super.onCreate();
    
  }
} 
```

2，应用方式 
> 1， 通过**startService()** 方式进行启动 服务   
>需要在 Mainfest.xml中 先注册好 Service 
 在使用时调用 context 的 startService(service) 方法启用
 在停止使用是使用 stopService(service) 方法
 
 ````
 
 Intent mIntent = new Intent(this,MyService.class);  
 this.startService(mIntent);
 
 ````
> 在此流程中 Service的生命周期为   onCreate() -> onStart() -> onDestory()
 并且 同一个 Service 再次调用时 直接从 onStart()开始   
 
> 2, 使用**bindService()** 启动Service
> 同样需要在 Mainfest.xml注册
  使用context 的bindService()方法
  在停止使用时调用 unbindService()方法  
  生命周期 onCreate() -> onBind() -> onUnbind() -> onDestory()
>> 使用bind绑定后 当 绑定者挂了之后 service 也会跟着挂 
  绑定者也可以直接调用 service 里的方法 
  ```java
   import android.content.ComponentName;
   import android.os.IBinder;
   
   class MyConn implements android.content.ServiceConnection{
   
     @Override
     public void onServiceConnected(ComponentName name, IBinder service) {
       
     }
   
     @Override
     public void onServiceDisconnected(ComponentName name) {
   
     }
   }
   
   Intent intent = new android.content.Intent(this,MyService.class);
   bindService(intent);
  
  ```
 在此中可以 使用 IBinder的 service 调用 MyService的 方法
  
  