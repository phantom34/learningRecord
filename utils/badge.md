#badge
 *对于Android的桌面角标 不像ios一样有统一性 因为有很多不同厂商的不同系统
 导致有的系统可能就没有桌面角标* 
 
对于桌面角标的更新 与调用 系统功能是一种道理，通过广播发送 意图(Intent)，在意图中包含
一些参数能使系统能识别出是在app桌面图标上显示角标  

具体方法
>获取应用启动页启动页 classname
```
    /**
     * 获取当前app 的启动页面activity的classname
     */
    protected static String getLauncherClassName(Context context) {
        PackageManager packageManager = context.getPackageManager();

        Intent intent = new Intent(Intent.ACTION_MAIN);
        intent.setPackage(context.getPackageName());
        intent.addCategory(Intent.CATEGORY_LAUNCHER);
        ResolveInfo info = packageManager
                .resolveActivity(intent, PackageManager.MATCH_DEFAULT_ONLY);
        if (info == null) {
            info = packageManager.resolveActivity(intent, 0);
        }
        return info.activityInfo.name;
    }

```
获取启动页的 classname时需要 匹配启动页的 启动方式既 Intent-filter
同时 一个 intent-filter 必须满足所有的属性才通过这种方式启动

因为本项目需要被web调起 所以新增一个 intent-filter (不然会导致安装失败，但是直接安装
可以进入app，但是回到手机桌面找不到 app图标 但但是 你可以在后台找到这个应用 (我的猜测
是在手机缓存中这个应用已经被写入但是在 物理内存中 app未被写入))
在这里也给出 Web打开app的一种方法
```
   <intent-filter>
        <action android:name="android.intent.action.MAIN"/>
        <category android:name="android.intent.category.LAUNCHER"/>
   </intent-filter>
  
   <intent-filter>
        <action android:name="android.intent.action.VIEW"/>  
        <category android:name="android.intent.category.DEFAULT"/>
        <category android:name="android.intent.category.BROWSABLE"/>
        <data
             android:host="vaneqi.com"
             android:scheme="wqdl"/>
   </intent-filter>
```

只要 web调用 地址路径 *(scheme://host)* 就可以了  

>获取到classname 就可以通过context.sendBroadcast(Intent) 方法刷新角标
```
    private static final String INTENT_ACTION = "android.intent.action.BADGE_COUNT_UPDATE";
    private static final String INTENT_EXTRA_BADGE_COUNT = "badge_count";
    private static final String INTENT_EXTRA_PACKAGENAME = "badge_count_package_name";
    private static final String INTENT_EXTRA_ACTIVITY_NAME = "badge_count_class_name";
      String launcherClassName = getLauncherClassName(context);
      if (launcherClassName == null) {
            return;
      }

      Intent intent = new Intent(INTENT_ACTION);
      intent.putExtra(INTENT_EXTRA_BADGE_COUNT, count);
      intent.putExtra(INTENT_EXTRA_PACKAGENAME, context.getPackageName());
      intent.putExtra(INTENT_EXTRA_ACTIVITY_NAME, launcherClassName);
      context.sendBroadcast(intent);

``` 

 *但是有些手机厂商发售的系统 可能没有角标!! 没有角标!!!  不管你怎么调用都没有 
 碧如 meizu 在Flyme 6.3.0.2A 在这个版本连QQ 微信都是没有角标的!!!!* 

[github上一个badgeUtil](https://github.com/leolin310148/ShortcutBadger)
在项目上已经引用这个