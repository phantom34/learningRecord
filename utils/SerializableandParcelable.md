##Serializable & Parcelable


###序列化 

|| 通过序列化 把Java对象 转换成字节码 存储进存储中介的 过程

|| 反序列化  把字节码恢复成 对象的 过程

###Serializable

Java原有的接口 
可以在网络上传输 也可以保存在本地  
可以很好的保证数据的持续性  
但是在使用时会产生 临时变量 可能会大致 gc  
Serializable 使用I/O读写  
使用时只用 implements Serializable 就好了


###Pracelable

Android 独有接口  
在内存中读写  
在效率上远远超过Serializable的使用  
但是在编写上 代码量要比 Serializable 多很多  
pracelable的方法
>describeContents()  
>>用来描述接口内容  

>writeToParcel(Parcel dest, int flags)  
createFromParcel(Parcel source)
>> 用write序列化对象 写入Parcel中  
```
    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(this.tmid);
        dest.writeString(this.tmname);
        dest.writeByte(this.selected ? (byte) 1 : (byte) 0);
        dest.writeList(this.contacts);
    }

```
>然后用create 从Parcel中写入对象
create方法 会生成 xxBean(Pracel in)
类似
```
   protected DepartmentBean(Parcel in) {
        this.tmid = in.readInt();
        this.tmname = in.readString();
        this.selected = in.readByte() != 0;
        this.contacts = new ArrayList<ContactBean>();
        in.readList(this.contacts, ContactBean.class.getClassLoader());
    }

```
 *在这两个方法中参数顺序必须一致不然会导致数据混乱* 
 
 
