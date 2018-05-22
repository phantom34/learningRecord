#Gradle

基于Groovy的 一种 构造工具  


在Gradle 中分为 project 和 task

在执行时，Gradle并不会一开始便顺序执行build.gradle文件中的内容，  
而是分为两个阶段，第一个阶段是配置阶段，然后才是实际的执行阶段。


在配置阶段 gradle读取所有 bulid.gradle文件去配置project和task 比如设置 project 和 task的配置
处理task之间的 依赖问题


依赖 可以在定义task时直接添加 也可以 在 定义后设置


```groovy
task hello5(dependsOn:hello4) << {
    println 'hello5'
}
```

```groovy
  task hello6 << {
     println 'hello6'
  }
  
  hello6.dependsOn hello5
```
配置task
闭包内添加设置属性
````groovy
task hello8 << {
println description
}

hello8 {
description = "this is hello8"
}
````
通过 configure 方法设置
```groovy
task hello9 << {
   println description
}

hello9.configure {
   description = "this is hello9"
}
```

Groovy的闭包 三个机制 this owner  delegate
其中 delegate 在gradle中  大量使用 
既在闭包中应用其他属性先寻找 this 的 然后 owner 然后 再 delegate
```groovy
class Child {
   private String name
}

class Parent {
   Child child = new Child();

   void configChild(Closure c) {
      c.delegate = child
      c.setResolveStrategy Closure.DELEGATE_FIRST
      c()
   }
}

def parent = new Parent()
parent.configChild {
name = "child name"
}

println parent.child.name
```

allprojects()
subprojects()



```groovy
buildscript {
    ext.kotlin_version = '1.1.60'
    repositories {
        jcenter()
        mavenCentral()
        google()
    }
    dependencies {
        classpath 'com.android.tools.build:gradle:3.0.1'
        // NOTE: Do not place your application dependencies here; they belong
        // in the individual module build.gradle files
        classpath 'org.greenrobot:greendao-gradle-plugin:3.2.1'
        classpath "org.jetbrains.kotlin:kotlin-gradle-plugin:$kotlin_version"
        classpath 'com.github.dcendents:android-maven-gradle-plugin:1.5'
        classpath 'com.jakewharton:butterknife-gradle-plugin:8.4.0'
        // 只需配置tinker-support插件依赖，无需再依赖tinker插件
//        classpath 'com.tencent.bugly:tinker-support:1.0.8'

    }
}

allprojects {
    repositories {
        jcenter()
        mavenCentral()
        maven { url "https://jitpack.io" }
        maven { url 'https://maven.google.com' }
        google()

    }

    apply plugin: 'checkstyle'
    task checkstyle(type: Checkstyle) {
        source 'src'
        include '**/*.java'
        exclude '**/gen/**'
        exclude '**/R.java'
        exclude '**/BuildConfig.java'
        configFile new File(rootDir, "checkstyle.xml")
        // empty classpath
        classpath = files()
    }
}

```
```groovy
apply plugin: 'com.android.library'

android {
    compileSdkVersion rootProject.ext.compileSdkVersion
    defaultConfig {
        minSdkVersion rootProject.ext.minSdkVersion
        targetSdkVersion rootProject.ext.targetSdkVersion
        versionCode 1
        versionName "1.0"

        testInstrumentationRunner "android.support.test.runner.AndroidJUnitRunner"

        multiDexEnabled true

        javaCompileOptions {
            annotationProcessorOptions {
                arguments = [moduleName: project.getName()]
            }
        }

    }
//    buildTypes {
//        release {
//            minifyEnabled false
//            proguardFiles getDefaultProguardFile('proguard-android.txt'), 'proguard-rules.pro'
//        }
//    }
    compileOptions {
        sourceCompatibility JavaVersion.VERSION_1_8
        targetCompatibility JavaVersion.VERSION_1_8
    }

    lintOptions {
        abortOnError false
    }
}

dependencies {
    implementation fileTree(include: ['*.jar'], dir: 'libs')
    implementation("com.android.support.test.espresso:espresso-core:$rootProject.espressoVersion", {
        exclude group: 'com.android.support', module: 'support-annotations'
    })
    implementation "com.android.support.test.espresso:espresso-idling-resource:$rootProject.espressoVersion"
    api files('libs/nineoldandroids.jar')
    implementation "com.android.support:design:$rootProject.supportLibraryVersion"
    api "com.android.support:cardview-v7:$rootProject.supportLibraryVersion"
    implementation "com.android.support:recyclerview-v7:$rootProject.supportLibraryVersion"
    testImplementation "junit:junit:$rootProject.junitVersion"

    //分包
    api 'com.android.support:multidex:1.0.2'
    api 'com.google.code.gson:gson:2.7'

    //网络图片加载与处理（圆形，圆角，阴影等）
    implementation("com.android.support:support-v4:$rootProject.supportLibraryVersion") {
        exclude module: 'support-annotations'
    }
    api "com.squareup.okhttp3:logging-interceptor:$rootProject.okhttpVersion"
    api "com.squareup.okhttp3:okhttp:$rootProject.okhttpVersion"
    api 'com.github.bumptech.glide:glide:3.7.0'
    implementation 'jp.wasabeef:glide-transformations:2.0.1'
    api 'com.orhanobut:logger:1.13'
    api 'com.tencent.mm.opensdk:wechat-sdk-android-with-mta:+'

    /*网络请求retrofit*/
    api "com.squareup.retrofit2:retrofit:$rootProject.retrofitVersion"
    api "com.squareup.retrofit2:converter-gson:$rootProject.retrofitVersion"
    api "com.squareup.retrofit2:adapter-rxjava2:$rootProject.retrofitVersion"
    api "com.squareup.retrofit2:adapter-rxjava:$rootProject.retrofitVersion"

    // cookies
    api 'com.github.franmontiel:PersistentCookieJar:v1.0.1'

    //    rx
    api "io.reactivex.rxjava2:rxjava:$rootProject.rxjavaVersion"
    api "io.reactivex.rxjava2:rxandroid:$rootProject.rxandroidVersion"
    api "com.jakewharton.rxbinding2:rxbinding:$rootProject.rxbindingVersion"

    // bugly

//    api 'com.tencent.bugly:crashreport_upgrade:1.3.1'

    api 'com.tencent.bugly:nativecrashreport:3.1.2'
    api 'com.tencent.bugly:crashreport:2.5.0'

    //其中latest.release指代最新Bugly SDK版本号，也可以指定明确的版本号，例如2.1.9
    //其中latest.release指代最新Bugly NDK版本号，也可以指定明确的版本号，例如3.0

    //其中latest.release指代最新版本号，也可以指定明确的版本号，例如2.2.0


    implementation "junit:junit:$rootProject.junitVersion"
    implementation "org.jetbrains.kotlin:kotlin-stdlib-jre7:$kotlin_version"

    //leakcanary
//    debugApi 'com.squareup.leakcanary:leakcanary-android:1.6-SNAPSHOT'
//    releaseApi 'com.squareup.leakcanary:leakcanary-android-no-op:1.6-SNAPSHOT'

    api 'com.just.agentweb:agentweb:4.0.2'


}
repositories {
    mavenCentral()
}
```


