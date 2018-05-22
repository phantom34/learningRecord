#WebView


简单调用
```androiddatabinding
        //声明WebSettings子类
        WebSettings webSettings = wbSeed.getSettings();
       //如果访问的页面中要与Javascript交互，则webview必须设置支持Javascript
        webSettings.setJavaScriptEnabled(true);
        //设置自适应屏幕，两者合用
        webSettings.setUseWideViewPort(true); 
        //将图片调整到适合webview的大小
        webSettings.setLoadWithOverviewMode(true); 
        // 缩放至屏幕的大小

//缩放操作
        webSettings.setSupportZoom(true); 
        //支持缩放，默认为true。是下面那个的前提。
        webSettings.setBuiltInZoomControls(true); 
        //设置内置的缩放控件。若为false，则该WebView不可缩放
        webSettings.setDisplayZoomControls(false); 
        //隐藏原生的缩放控件

//其他细节操作
        webSettings.setCacheMode(WebSettings.LOAD_CACHE_ELSE_NETWORK); 
        //如果页面需要实时更新 选择 WebSetting.LOAD_NO_CACHE
        //关闭webview中缓存
        webSettings.setLoadsImagesAutomatically(true); 
        //支持自动加载图片
        webSettings.setDefaultTextEncodingName("utf-8");
        //设置编码格式
        wbSeed.setWebViewClient(new WebViewClient() {
            @Override
            public boolean shouldOverrideUrlLoading(WebView view, String url) {
                view.loadUrl(url);
                return true;
            }
        });
```
同时 因为webview 的滑动监听是 protected 外部无法调用 所以如果要监听 webview的滑动状态
需要自己重写webview 在其中添加可以外部调用的监听

如果 在webview和srcollview 一起用的时候要注意  点击监听 