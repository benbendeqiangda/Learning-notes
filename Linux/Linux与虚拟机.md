- wget：wget不是安装方式，它是一种下载工具，类似于迅雷。
  通过HTTP、HTTPS、FTP三个最常见的TCP/IP协议下载，并可以使用HTTP代理，名字是World Wide Web”与“get”的结合。如果要下载一个软件,可以直接运行：wget 下载地址

- 一般来说著名的linux系统基本上分两大类：

      RedHat系列：Redhat、Centos、Fedora等
      Debian系列：Debian、Ubuntu等 

  RedHat 系列

      常见的安装包格式rpm包,安装rpm包的命令是“rpm -参数”
      包管理工具 yum
      支持tar包

  Fedora系统上对rpm的管理：

  ```
  安装：yum install
  卸载：yum remove
  更新：yum update
  ```

  Debian系列

  ```
  常见的安装包格式 deb包,安装deb包的命令是“dpkg -参数”
  包管理工具 apt-get
  支持tar包
  ```

  Ubuntu系统上对deb的管理：

      安装：apt-get install
      卸载：apt-get remove
      更新：apt-get update


- 软件更新：sudo apt-get updater
- apt-key：apt-key is used to manage the list of keys used by apt to authenticate  packages. Packages which have been authenticated using these keys will  be considered trusted.

###### 常见问题 ######
- 虚拟机设置密码不能用小键盘，大小写不必太过在意
- 虚拟机操作系统找不到：选择镜像时上面有连接选项(启动时连接)

- Linux命令有很多空格，要注意

- Linux中输入密码并不会显示


###### 常用命令 ######

- linux命令区分大小写
- 用Tab键可以实现参数的自动补全；
- 命令选项可以组合（-nv），先后顺序可以变化
- 管道命令：命令 |命令  参数：把第一个命令的结果传递给下一个命令
- 上下键可以快速找到之前的命令；
- linux中的命令中参数有两种形式：一种是一条短横线加单个字符（-h）；另一种是两条短横线加完整单词的形式（--help）
- 获取命令的使用手册：man+命令；命令+--help；whatis+命令。
- 连续5次esc键可以显示支持的所有命令；

- ls ：list 打印当前目录下的所有文件（文件夹也被看作文件）
- cd：change directory 改变目录
- pwd：print working directory 打印当前目录。
- tree：显示指定文件的目录结构
- mkdir：创建目录
- nautilus    某个目录：图形化显示某个目录

---

- echo：显示一个字符串

- sudo su：进入root用户

- chsh更改默认的Shell环境

- PS1=%(更改命令提示符为%)

- xrandr --size 1440x900：改变屏幕分辨率

- https://jingyan.baidu.com/article/870c6fc3eb9253f03ee4be40.html

  sudo apt install open-vm-tools

  sudo apt install open-vm-tools-desktop

#### 文件

- 文件位置的查找：locate；find；whereis；which（查看某个命令在哪里）
- 文件内容的查找：grep
- 文件信息的统计：
  - wc -l 文件名：查看文件有多少行
- 查看文本内容：cat；nl；more；less；head；tail；diff；
- 创建文本：gedit；vim；`>,>>`:重定向符号(常用于将命令的结果输入到文件中去),前者覆盖原来的内容，后者追加内容

##### vi

默认情况下，打开vi编辑器后自动进入命令模式。从编辑模式切换到命令模式使用“esc”键，从命令模式切换到编辑模式使用“A”、“a”、“O”、“o”、“I”、“i”键。

查找关键字：输入斜杠`/`，这时屏幕会跳转到底部，输入栏出现`/`。输入你需要查找的关键字，回车。输入n向后查找，输入N向前查找。

#### 退出

- exit：退出当前终端程序

  q命令

  Ctrl+c

  在命令行下起着终止当前执行程序的作用，

  Ctrl+d

  相当于exit命令，退出当前shell

  Ctrl+s

  挂起当前shell（保护作用很明显哦）

  Ctrl+q

  解冻挂起的shell再不行就重新连接打开一个终端，reboot linux 或 kill 相关进程。
  
  Ctrl + Z  放在后端运行
  
  问题：有时遇到命令或程序卡死，上述前四种方法也无法解决时，可以利用第5种方法，Ctrl + Z先把正在执行的命令或程序放在后端运行，然后用ps查看刚才执行的进程号，最后再用kill命令强制杀除掉。

## Linux规则 ##

- Linux区分大小写

- tar和xz是Linux中的的压缩文件格式，xz是一种压缩形式，tar是里面的打包方式

  tar : **t**ape **ar**chive

- “/”代表根目录

  “..”代表上一级目录

  “.” 代表当前目录

  “~”代表HOME目录

  “-”代表前一目录

- GCC：GNU Compiler Collection

- Linux中所有以.英文点号开头的文件或目录都是隐藏文件或隐藏文件夹，在终端命令行需要用ls命令的-a参数才能看到隐藏文件/隐藏文件夹

- 每个命令都是一个可执行文件，可用which命令找到命令文件所在的位置

- swapmemory：用来交换的外存（虚拟内存）

- 所有文件分成四种类型：普通，目录，链接，特殊

