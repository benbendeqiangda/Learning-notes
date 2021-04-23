springboot静态资源访问路径在pom中的父依赖配置

###### RestController

@RestController是@Controller和@ResponseBody的结合体，两个标注合并起来的作用。

@responseBody注解的作用是将controller的方法返回的对象通过适当的转换器转换为指定的格式之后，写入到response对象的body区，通常用来返回JSON数据或者是XML数据。在使用此注解之后不会再走视图处理器（在使用 @RequestMapping后，返回值通常解析为跳转路径），加上 @ResponseBody 后返回结果不会被解析为跳转路径，而是直接写入 HTTP response body 中，通过response对象输出指定格式的数据。

#### 自动配置

parent依赖的传递

##### 自动配置类

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
2. 自动配置类上的@ConditionalOnMissingBean会去判断是否满足条件，满足就将自动配置类导入容器 ， 自动配置类就生效 ， 帮我们进行自动配置工作；