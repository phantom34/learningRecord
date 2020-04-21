#sqlite数据库

###表替换
因为业务需求需要做 数据库工具类 引用同事的简单数据库类之后发现缺少一部分功能， 因为数据库是需要通过 **bean** 来生成表 但是在版本迭代的时候需要 **bean** 可能需要修改 以致需要对当前表的字段与 **bean** 进行对比判断。
> pragma table_info(tableName)

获取表结构 相当于 mysql 的
 **desc table_info(tableName)**
然后通过
```
 Cursor tableCursor = db.rawQuery("pragma table_info( " + tableName + " )", null);
````
此时tableCursor.get

````
private void TableTransfer(Class table, SQLiteDatabase db, String tableName) {
        Cursor tableCursor = db.rawQuery("pragma table_info( " + tableName + " )", null);
        List<String> mStrings = new ArrayList<>();
        List<String> mCursorStrings = new ArrayList<>();
        while (tableCursor.moveToNext()) {
            String name = tableCursor.getString(tableCursor.getColumnIndex("name"));
            mCursorStrings.add(name);
        }
        tableCursor.close();

        for (Field field : table.getDeclaredFields()) {
            mStrings.add(field.getName());
        }
        mStrings.add("_id");
        int index = 0;
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < mCursorStrings.size(); i++) {
            if (mStrings.contains(mCursorStrings.get(i))) {
                if (index != 0) {
                    builder.append(",");
                }
                index++;
                builder.append(mCursorStrings.get(i));
            }
        }

        boolean isOldVersion = index == mStrings.size() && index == mCursorStrings.size();
        if (!isOldVersion) {
            Cursor oldCursor = db.query("sqlite_master", null, "type = 'table' and name = ?",
                    new String[]{tableName + "_old"}, null, null, null);
            if (oldCursor.getCount() > 0) {
                db.execSQL("drop table " + tableName + "_old");
            }
            db.execSQL("alter table " + tableName + " rename to " + tableName + "_old");
            createTableIfNotExists(table);
            db.execSQL("insert into " + tableName + "( " + builder.toString() + " )" + " select " + builder.toString() + " from " + tableName +
                    "_old");
            db.execSQL("drop table " + tableName + "_old");
        }
    }
````
