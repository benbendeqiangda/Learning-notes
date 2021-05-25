###### profiles

控制配置文件的选择

###### 依赖冲突

- 在 pom 文件定义依赖，先声明的依赖为准。

- 路径近者优先原则（直接依赖和传递依赖）

  

- 依赖排除：dependency标签下的exclusions标签

- 版本锁定dependencymanagement：只有锁定的作用，没有导入的作用

###### 分模块部署

每个模块拥有单独的坐标（使得每个模块可以复用），引入的parent标签可以使用parent引入的包

###### 分模块启动

maven父工程编译不会报错，用服务器直接启动不会报错

使用启动类所在的模块启动：无法启动，因为他所依赖的jar包模块很可能在本地，而依赖被maven管理之后只能去仓库去找，找不到就报错。可以将相应的jar包安装到仓库中去

###### packaging打包类型

- ### pom

  ```
      <packaging>pom</packaging>    【父类型都为pom类型】
  ```

- ### jar

  ```
      <packaging>jar</packaging>       【内部调用或者是做服务使用】
  ```

- ### war

  ```
      <packaging>war</packaging>     【需要部署的项目】
  ```