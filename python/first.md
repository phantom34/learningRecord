#python - FirstDay

对于对象来说 不需要去定义 类似（var  i  ,String  str）

String 类  'xxxxxxxx  xxxx' == " ssssssssss  ssssssssss 'sss " == ''' sssssss 
ssssssssss
sssss
'''('''可以换行  并  '''可以包含 '' '  ,''可以包含')  

\ 可以来用来 拼接 

sample ： 
```
  print \
  i
```
依旧是输出 i

```markdown
   print 'shshshhsh\
   sssdsd'
```
实际输出结果是 shshshhshsssdsd


名词 自然字符串 : 指示不需要例如转义这样特别处理的字符串
使用方法 字符串前面 + R or r
```markdown
    print r'This is  a kid \n'
```

名词 Unicode 字符串    处理unicode文字字符串
+ U or u
```markdown
  print u'sssssssssssss'
```

 **对于字符串来说 是不可变的** 
 
 **字符串连接**  
 两个字符串 字面意思 放在一起 输出 会直接合在一起 
 
 
##运算符 
```markdown
    ** 幂  a**b= a*a*a*a···a (b次)
    // 整除
    not  布尔型 非 ( x = True  Print not x   -> False) (!x)
    and  布尔 与  (&&)
    or 布尔 或 (||)
    
```



#控制流

###if elif  else
 去掉了 {}（） 之类的 模块闭包 
 用 ：来表示 下一个模块的开始 
  下一行代码如果属于这个模块  开头空格 自动对齐 
  如果 下一行的代码 开头没有空格对齐 表示是上一个模块的 
  ```markdown
      if sss=sss:
          sss
      elif sss:
          s
      else:
      sss
  ``` 
  *：之后模块 必须要有东西* 
 
### while else 
  在while 循环中 可以加一个 else 
  
  ```markdown
    while True:
    
    else:
```
  
  
