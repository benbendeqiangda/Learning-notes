| 常用HTML标签的英文全称及简单描述 |                           |                                |
| -------------------------------- | ------------------------- | ------------------------------ |
| HTML标签                         | 英文全称                  | 中文释义                       |
| a                                | Anchor                    | 锚                             |
| abbr                             | Abbreviation              | 缩写词                         |
| acronym                          | Acronym                   | 取首字母的缩写词               |
| address                          | Address                   | 地址                           |
| alt                              | alter                     | 替用(一般是图片显示不出的提示) |
| b                                | Bold                      | 粗体（文本）                   |
| bdo                              | Direction of Text Display | 文本显示方向                   |
| big                              | Big                       | 变大（文本）                   |
| blockquote                       | Block Quotation           | 区块引用语                     |
| br                               | Break                     | 换行                           |
| cell                             | cell                      | 巢                             |
| cellpadding                      | cellpadding               | 巢补白                         |
| cellspacing                      | cellspacing               | 巢空间                         |
| center                           | Centered                  | 居中（文本）                   |
| cite                             | Citation                  | 引用                           |
| code                             | Code                      | 源代码（文本）                 |
| dd                               | Definition Description    | 定义描述                       |
| del                              | Deleted                   | 删除（的文本）                 |
| dfn                              | Defines a Definition Term | 定义定义条目                   |
| div                              | Division                  | 分隔                           |
| dl                               | Definition List           | 定义列表                       |
| dt                               | Definition Term           | 定义术语                       |
| em                               | Emphasized                | 加重（文本）                   |
| font                             | Font                      | 字体                           |
| h1~h6                            | Header 1 to Header 6      | 标题1到标题6                   |
| hr                               | Horizontal Rule           | 水平尺                         |
| href                             | hypertext reference       | 超文本引用                     |
| i                                | Italic                    | 斜体（文本）                   |
| iframe                           | Inline frame              | 定义内联框架                   |
| ins                              | Inserted                  | 插入（的文本）                 |
| kbd                              | Keyboard                  | 键盘（文本）                   |
| li                               | List Item                 | 列表项目                       |
| nl                               | navigation lists          | 导航列表                       |
| ol                               | Ordered List              | 排序列表                       |
| optgroup                         | Option group              | 定义选项组                     |
| p                                | Paragraph                 | 段落                           |
| pre                              | Preformatted              | 预定义格式（文本 ）            |
| q                                | Quotation                 | 引用语                         |
| rel                              | Reload                    | 加载                           |
| s/ strike                        | Strikethrough             | 删除线                         |
| samp                             | Sample                    | 示例（文本                     |
| small                            | Small                     | 变小（文本）                   |
| span                             | Span                      | 范围                           |
| src                              | Source                    | 源文件链接                     |
| strong                           | Strong                    | 加重（文本）                   |
| sub                              | Subscripted               | 下标（文本）                   |
| sup                              | Superscripted             | 上标（文本）                   |
| td                               | table data cell           | 表格中的一个单元格             |
| th                               | table header cell         | 表格中的表头                   |
| tr                               | table row                 | 表格中的一行                   |
| tt                               | Teletype                  | 打印机（文本）                 |
| u                                | Underlined                | 下划线（文本）                 |
| ul                               | Unordered List            | 不排序列表                     |
| var                              | Variable                  | 变量（文本）                   |

#### html ####

1. 概念：是最基础的网页开发语言
  * Hyper Text Markup Language 超文本标记语言
  	* 超文本:
        		* 超文本是用超链接的方法，将各种不同空间的文字信息组织在一起的网状文本.
  	* 标记语言:
        		* 由标签构成的语言。<标签名称> 如 html，xml
2. 快速入门：
  * 语法：
  	1. html文档后缀名 .html 或者 .htm
  	2. 标签分为
        		1. 围堵标签：有开始标签和结束标签。如 `<html> </html>`
                 		2. 自闭和标签：开始标签和结束标签在一起。如 `<br/>`
  3. 标签可以嵌套：

    		需要正确嵌套，不能你中有我，我中有你
    		错误：`<a><b></a></b>`
    		正确：`<a><b></b></a>`
  	4. 在开始标签中可以定义属性。属性是由键值对构成，值需要用引号(单双都可)引起来
  5. html的标签不区分大小写，但是建议使用小写。

##### 表单 #####

form：用于定义表单（定义一个范围，范围代表采集用户数据的范围）

属性：
* action：指定提交数据的URL
* method:指定提交方式
    * 分类：一共7种，2种比较常用
       * get：
            1. 请求参数会在地址栏中显示。会封装到请求行中(HTTP协议后讲解)。
            2. 请求参数大小是有限制的。
            3. 不太安全。
       * post：
            2. 请求参数不会再地址栏中显示。会封装在请求体中(HTTP协议后讲解)
            2. 请求参数的大小没有限制。
            3. 较为安全。

* 表单项中的数据要想被提交：必须指定其name属性

##### 表单项标签： #####

###### input ######

可以通过type属性值，改变元素展示的样式

type属性：
* text：文本输入框，默认值
	* placeholder：指定输入框的提示信息，当输入框的内容发生变化，会自动清空提示信息	
* password：密码输入框
* radio:单选框
	* 注意：
		1. 要想让多个单选框实现单选的效果，则多个单选框的name属性值必须一样。
		2. 一般会给每一个单选框提供value属性，指定其被选中后提交的值
		3. checked属性，可以指定默认值
* checkbox：复选框
	* 注意：
		1. 一般会给每一个单选框提供value属性，指定其被选中后提交的值
		2. checked属性，可以指定默认值

* file：文件选择框
* hidden：隐藏域，用于提交一些信息。
* 按钮：
	* submit：提交按钮。可以提交表单
	* button：普通按钮
	* image：图片提交按钮
		* src属性指定图片的路径	

 * label：指定输入项的文字描述信息
   * 注意：
	   * label的for属性一般会和input 的id属性值 对应。如果对应了，则点击label区域，会让input输入框获取焦点。

###### select: 下拉列表 ######

* 子元素：option，指定列表项

###### textarea：文本域 ######

* cols：指定列数，每一行有多少个字符
* rows：默认多少行。

#### css ####

###### CSS与html结合方式 ######

```html
1. 内联样式
	 * 在标签内使用style属性指定css代码
	 * 如：<div style="color:red;">hello css</div>
2. 内部样式
	* 在head标签内，定义style标签，style标签的标签体内容就是css代码
	* 如：
		<style>
	        div{
	            color:blue;
	        	}
	    </style>
		<div>hello css</div>
3. 外部样式
	1. 定义css资源文件。
	2. 在head标签内，定义link标签，引入外部的资源文件
	* 如：
		* a.css文件：
			div{
			    color:green;
			}
		<link rel="stylesheet" href="css/a.css">
		<div>hello css</div>
		<div>hello css</div>
    3. 外部样式可以写为：
        <style>
            @import "css/a.css";
        </style>
```

###### css语法 ######

* 格式：
	选择器 {
		属性名1:属性值1;
		属性名2:属性值2;
		...
	}
* 选择器:筛选具有相似特征的元素
* 注意：
	* 每一对属性需要使用；隔开，最后一对属性可以不加；

##### 选择器 #####

###### 基础选择器 ######

1. 元素选择器：选择具有相同标签名称的元素
   - 语法： 标签名称{}
   - 注意：id选择器优先级高于元素选择器
2. 类选择器：选择具有相同的class属性值的元素。
   * 语法：.class{}
   * 注意：类选择器选择器优先级高于元素选择器
3. id选择器：选择具体的id属性值的元素.建议在一个html页面中id值唯一
   - 语法：#id{}

###### 扩展选择器 ######

1. 选择所有元素：
	* 语法： *{}
2. 并集选择器：
	* 选择器1,选择器2{}

3. 子选择器：筛选选择器1元素下的选择器2元素
	* 语法：  选择器1 选择器2{}
4. 父选择器：筛选选择器2的父元素选择器1
	* 语法：  选择器1 > 选择器2{}

5. 属性选择器：选择元素名称，属性名=属性值的元素
	* 语法：  元素名称[属性名="属性值"]{}

6. 伪类选择器：选择一些元素具有的状态
	* 语法： 元素:状态{}
	* 如： `<a>`
		* 状态：
			* link：初始化的状态
			* visited：被访问过的状态
			* active：正在访问状态
			* hover：鼠标悬浮状态

##### 属性 #####

1. 字体、文本
	* font-size：字体大小
	* color：文本颜色
	* text-align：对其方式
	* line-height：行高 
2. 背景
	* background：
3. 边框
	* border：设置边框，符合属性
4. 尺寸
	* width：宽度
	* height：高度
5. 盒子模型：控制布局
	* margin：外边距
	* padding：内边距
		* 默认情况下内边距会影响整个盒子的大小
		* box-sizing: border-box;  设置盒子的属性，让width和height就是最终盒子的大小

	* float：浮动
		* left
		* right

