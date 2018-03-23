#context 

1,context 一共有三种类型 Activity 、service、Application

2,Context 的功能很多 并且三种类型的 context的功能都通用，但是在启动Activity和dialog上必须
使用Activity类型的context 因为 Activity的启动是建立在上一个Activity的基础上启动 而Dialog
也只能在一个已有的页面上 show (除了system alert的dialog）
