#### JDBC ####

概念：Java DataBase Connectivity 

JDBC本质：其实是官方（sun公司）定义的一套即接口。各个数据库厂商去实现这套接口，提供数据库驱动jar包。我们可以使用这套接口（JDBC）编程，真正执行的代码是驱动jar包中的实现类。

##### 核心

| 接口或类          | 作用                                                 |
| ----------------- | ---------------------------------------------------- |
| DriverManager     | 管理和注册数据库驱动\|得到数据库连接对象Connection   |
| Connection        | 用于创建 Statement 和 PreparedStatement 对象         |
| Statement         | 一个 SQL 语句对象，用于将 SQL 语句发送给数据库服务器 |
| PreparedStatement | 一个 SQL 语句对象，是 Statement 的子接口             |
| ResultSet         | 用于封装数据库查询的结果集，返回给客户端 Java 程序   |

释放资源

1) 需要释放的对象：ResultSet 结果集，Statement 语句，Connection 连接

2) 释放原则：先开的后关，后开的先关。

3) 放在哪个代码块中：finally 块

##### 细节 #####

```java
1. DriverManager：驱动管理对象
	获取数据库连接：
    * 方法：static Connection getConnection(String url, String user, String password) 
    * 参数：
        * url：指定连接的路径
        * 语法：jdbc:mysql://ip地址(域名):端口号/数据库名称
        * 例子：jdbc:mysql://localhost:3306/db3
    * 细节：如果连接的是本机mysql服务器，并且mysql服务默认端口是3306，则url可以简写为：jdbc:mysql:///数据库名称
        * user：用户名
        * password：密码
2. Connection：数据库连接对象
    1. 获取执行sql 的对象
    * Statement createStatement()
    * PreparedStatement prepareStatement(String sql) ：可以防止SQL注入
    2. 管理事务：
    * 开启事务：setAutoCommit(boolean autoCommit) ：调用该方法设置参数为false，即开启事务
    * 提交事务：commit() 
    * 回滚事务：rollback()
3. Statement：执行sql的对象
    1. boolean execute(String sql) ：可以执行任意的sql
    2. int executeUpdate(String sql) ：执行DML（insert、update、delete）语句、DDL(create，alter、drop)语句
    * 返回值：影响的行数，可以通过这个影响的行数判断DML语句是否执行成功 返回值>0的则执行成功，反之，则失败。
    3. ResultSet executeQuery(String sql)  ：执行DQL（select)语句
4. ResultSet：结果集对象,封装查询结果
    * boolean next(): 游标向下移动一行，判断当前行是否是最后一行末尾(是否有数据)，如果是，则返回false，如果不是则返回true
    * getXxx(参数):获取数据
        * Xxx：代表数据类型   如： int getInt() ,	String getString()
        * 参数：
            1. int：代表列的编号,从1开始   如： getString(1)
            2. String：代表列名称。 如： getDouble("balance") 
5. PreparedStatement：执行sql的对象
	1. SQL注入问题：在拼接sql时，有一些sql的特殊关键字参与字符串的拼接。会造成安全性问题
        1. 输入用户随便，输入密码：a' or 'a' = 'a
        2. sql：select * from user where username = 'fhdsjkf' and password = 'a' or 'a' = 'a' 
    2. 解决sql注入问题：使用PreparedStatement对象来解决
    3. 预编译的SQL：参数使用?作为占位符
	   select * from user where username = ? and password = ?;
       给？赋值：
            * 方法： setXxx(参数1,参数2)
            * 参数1：？的位置编号 从1 开始
            * 参数2：？的值
		我们可以看下mysql的底层的setString()方法，
         其实就是用值代替了？的位置，并且在值的两边加上了单引号，
         然后再把值当中的所有单引号替换成了斜杠单引号，
         说白了就是把值当中的所有单引号给转义了!这就达到了防止sql注入的目的
         参数类型的检查也有一定的防止注入的作用
```

##### 事务 #####

使用Connection对象来管理事务

	* 开启事务：setAutoCommit(boolean autoCommit) ：调用该方法设置参数为false，即开启事务
 * 提交事务：commit() 
 * 回滚事务：rollback() 

#### 数据库连接池 ####

java中的标准接口：DataSource（javax.sql包下的）

方法：
* 获取连接：getConnection()
* 归还连接：Connection.close()。如果连接对象Connection是从连接池中获取的，那么调用Connection.close()方法，则不会再关闭连接了。而是归还连接

###### C3P0 ######

* 步骤：
	1. 导入jar包 (两个) c3p0-0.9.5.2.jar mchange-commons-java-0.2.12.jar ，
		* 不要忘记导入数据库驱动jar包
	2. 定义配置文件：
		* 名称： c3p0.properties 或者 c3p0-config.xml
		* 路径：直接将文件放在src目录下即可。

	3. 创建核心对象：数据库连接池对象 ComboPooledDataSource
	4. 获取连接： getConnection
	
* 代码：

   创建数据库连接池对象

   DataSource ds  = new ComboPooledDataSource();

   获取连接对象

   Connection conn = ds.getConnection();

###### Druid ######

- 步骤：
  1. 导入jar包 druid-1.0.9.jar
  2. 定义配置文件：
  	* 是properties形式的
  	* 可以叫任意名称，可以放在任意目录下
  3. 加载配置文件。Properties
  4. 获取数据库连接池对象：通过工厂来来获取  DruidDataSourceFactory
  5. 获取连接：getConnection
* 代码：
	
   //加载配置文件
   
   Properties pro = new Properties();
   
   InputStream is = DruidDemo.class.getClassLoader().getResourceAsStream("druid.properties");
   
   pro.load(is);
   
   //获取连接池对象
   
   DataSource ds = DruidDataSourceFactory.createDataSource(pro);
   
   //获取连接
   
   Connection conn = ds.getConnection();
