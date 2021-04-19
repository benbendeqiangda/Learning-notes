springboot静态资源访问路径在pom中的父依赖配置

###### RestController

@RestController是@Controller和@ResponseBody的结合体，两个标注合并起来的作用。

@responseBody注解的作用是将controller的方法返回的对象通过适当的转换器转换为指定的格式之后，写入到response对象的body区，通常用来返回JSON数据或者是XML数据。在使用此注解之后不会再走视图处理器（在使用 @RequestMapping后，返回值通常解析为跳转路径），加上 @ResponseBody 后返回结果不会被解析为跳转路径，而是直接写入 HTTP response body 中，通过response对象输出指定格式的数据。