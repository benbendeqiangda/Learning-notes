springboot静态资源访问路径在pom中的父依赖配置

###### RestController

@RestController是@Controller和@ResponseBody的结合体，两个标注合并起来的作用。

@responseBody注解的作用是将controller的方法返回的对象通过适当的转换器转换为指定的格式之后，写入到response对象的body区，通常用来返回JSON数据或者是XML数据。在使用此注解之后不会再走视图处理器（在使用 @RequestMapping后，返回值通常解析为跳转路径），加上 @ResponseBody 后返回结果不会被解析为跳转路径，而是直接写入 HTTP response body 中，通过response对象输出指定格式的数据。

###### 静态资源访问目录

```
"classpath:/META-INF/resources/"
"classpath:/resources/"
"classpath:/static/"
"classpath:/public/"
```

我们也可以自己通过配置文件指定哪些文件夹是需要我们放静态资源文件的，在application.properties中配置；

```
spring.resources.static-locations=classpath:/test1/,classpath:/test2/
```

一旦自己定义了静态文件夹的路径，原来的自动配置就都会失效了！

#### 自动配置

parent依赖的传递

##### 自动配置类

我们可以通过启用 debug=true属性；来让控制台打印自动配置报告，这样我们就可以很方便的知道哪些自动配置类生效；

- Positive matches:（自动配置类启用的：正匹配）
- Negative matches:（没有启动，没有匹配成功的自动配置类：负匹配）
- Unconditional classes: （没有条件的类）

```java
@SpringBootApplication下的@EnableAutoConfiguration开启自动配置功能
	@AutoConfigurationPackage ：自动配置包
		@Import({AutoConfigurationPackage})public @interface AutoConfigurationPackage {}
	@Import({AutoConfigurationImportSelector.class}) ：给容器导入组件
    // 获得候选的配置
    protected List<String> getCandidateConfigurations(AnnotationMetadata metadata, AnnotationAttributes attributes) 
    {
    	List<String> configurations = SpringFactoriesLoader.loadFactoryNames(
				getSpringFactoriesLoaderFactoryClass(), getBeanClassLoader());
	//SpringFactoriesLoader.loadFactoryNames 方法的作用就是从META-INF/spring.factories文件中读取指定类对应的类名称列表 
		return configurations;
    }
```

1. SpringBoot在启动的时候从类路径下的META-INF/spring.factories中获取EnableAutoConfiguration指定的值
2. 自动配置类上的@ConditionalOn会去判断是否满足条件，满足就将自动配置类导入容器 ， 自动配置类就生效 ， 帮我们进行自动配置工作；

##### 自动配置文件

根据当前不同的条件判断，决定当前配置类是否生效

- 一但这个配置类生效；这个配置类就会给容器中添加各种组件（例如springmvc中的各种组件）；
- 这些组件的属性是从对应的**properties类**中获取的，这些类里面的每一个属性又是和配置文件绑定的；
- 所有在配置文件中能配置的属性都是在**xxxxProperties类**中封装着；
- 配置文件能配置什么就可以参照某个功能对应的这个属性类

```java
//从配置文件中获取指定的值和bean的属性进行绑定
@ConfigurationProperties(prefix = "spring.http") 
public class HttpProperties 
{    
    // .....
}
```

#### 视图解析器

spring boot 在springmvc的视图解析器方面就默认集成了ContentNegotiatingViewResolver和BeanNameViewResolver，在视图引擎上就已经集成自动配置的模版引擎，如下：
1. FreeMarker
2. Groovy
3. Thymeleaf
4. Velocity (deprecated in 1.4)
6. Mustache

JSP技术spring boot 官方是不推荐的，原因有三：
1. 在tomcat上，jsp不能在内置的tomcat容器解析（不能在打包成可执行的jar的情况下解析，只能在打包成war的情况下解析）
2. Jetty 嵌套的容器不支持jsp
3. Undertow

而其他的模版引擎spring boot 都支持，并默认会到classpath的templates里面查找模版引擎

如果想要使用jsp，需要配置springmvc中的属性，并且只能在打包成war包的情况下被解析https://blog.csdn.net/yingxiake/article/details/51288727