#LogUtil 


工具类设置Log打印  在线上线下做开关判断
同时可以手动设置

```java

public class LogUtil {
    private static final String TAG = "LogUtil";
    private static boolean isShow = true;

    public static boolean isShow() {
        if (BuildConfig.DEBUG) {
            return isShow;
        } else {
            return false;
        }
    }

    public static void setShow(boolean show) {
        isShow = show;
    }

    public static void i(String tag, String msg) {
        if (isShow) {
            Log.i(tag, msg);
        }
    }

    public static void w(String tag, String msg) {
        if (isShow) {
            Log.w(tag, msg);
        }
    }

    public static void e(String tag, String msg) {
        if (isShow) {
            Log.e(tag, msg);
        }
    }

    public static void all(String msg) {
        if (isShow) {
            Log.e("all", msg);
        }
    }

    public static void i(String msg) {
        if (isShow) {
            Log.i(TAG, msg);
        }
    }

    public static void w(String msg) {
        if (isShow) {
            Log.w(TAG, msg);
        }
    }

    public static void e(String msg) {
        if (isShow) {
            Log.e(TAG, msg);
        }
    }

    public static void v(String msg) {
        e(msg);
    }

    public static void d(String msg) {
        v(msg);
    }
}

```