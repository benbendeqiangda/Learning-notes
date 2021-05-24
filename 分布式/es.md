#### lucene

##### 创建索引

- 收集文档，一个Document文档中包括多个域（Field），域（Field）中存储内容。我们可以将数据库中一条记录当成一个Document，一列当成一个Field。
- 经过分词和语言处理，然后将得到的词(Term)传给索引组件(Indexer)，索引组件(Indexer)主要做以下几件事情：
  - 创建Term字典
  - 对字典按字母顺序进行排序
  - 合并Term字典：合并相同的词(Term)成为文档倒排(Posting List)链表

- 最终的索引结构是一种倒排索引结构也叫反向索引结构，包括索引和文档两部分，索引即词汇表，它的规模较小，
  而文档集合较大。

  相关度：tf和df

  - Term Frequency (tf)：指此Term在此文档中出现了多少次。tf 越大说明越重要（词(Term)在文档中出现的次数越多，说明此词(Term)对该文档越重要）

    如“Lucene”这个词，在文档中出现的次数很多，说明该文档主要就是讲Lucene技术的。

  - Document Frequency (df)：指有多少文档包含此Term。df 越大说明越不重要。

    比如，在一篇英语文档中，this出现的次数更多，就说明越重要吗？不是的，有越多的文档包含此词(Term), 说明此词(Term)太普通，不足以区分这些文档，因而重要性越低。

索引流程代码

```java
class IndexDemo
{
    public static void main(String[] args) throws Exception
    {
		// 1. 数据采集
        ItemDao itemDao = new ItemDaoImpl();
        List<Item> itemList = itemDao.queryItemList();
		// 2. 创建Document文档对象
        List<Document> documents = new ArrayList<>();
        for (Item item : itemList) {
            Document document = new Document();
        // Document文档中添加Field域
        // 商品Id
        // Store.YES:表示存储到文档域中
            document.add(new TextField("id", item.getId().toString(), Store.YES));
        // 商品名称
            document.add(new TextField("name", item.getName().toString(),
                    Store.YES));
        // 商品价格
            document.add(new TextField("price", item.getPrice().toString(),
                    Store.YES));
        // 商品图片地址
            document.add(new TextField("pic", item.getPic().toString(),
                    Store.YES));
        // 商品描述
            document.add(new TextField("description",
                    item.getDescription().toString(), Store.YES));
        // 把Document放到list中
            documents.add(document);
        }
        // 指定分词器：标准分词器（此处可以改为中文分词器）
        // Analyzer analyzer = new StandardAnalyzer();
        Analyzer analyzer = new IKAnalyzer();
        // 配置文件
        IndexWriterConfig iwc = new IndexWriterConfig(analyzer);
        // 指定索引库路径
        String indexPath = "E:\\11-index\\vip01\\";
        // 指定索引库对象
        Directory dir = FSDirectory.open(Paths.get(indexPath));
        // 创建索引写对象
        IndexWriter writer = new IndexWriter(dir, iwc);
        // 3. 分词并创建索引文件
        writer.addDocuments(documents);
        // 释放资源
        writer.close();
    }
}
```



##### 搜索索引

关键字必须大写，否则作为普通单词处理

![image-20210507111252845](C:\Users\wangjingyu\AppData\Roaming\Typora\typora-user-images\image-20210507111252845.png)

搜索流程代码

```java
public class SearchDemo
{
    public static void main(String[] args) throws Exception
    {
        // 指定索引库路径
        String indexPath = "E:\\11-index\\vip01\\";
        // 指定索引库对象
        Directory dir = FSDirectory.open(Paths.get(indexPath));
        // 索引读对象
        IndexReader reader = DirectoryReader.open(dir);
        // 索引搜索器
        IndexSearcher searcher = new IndexSearcher(reader);
        Analyzer analyzer = new StandardAnalyzer();
        // 通过QueryParser解析查询语法，获取Query对象
        QueryParser parser = new QueryParser("description", analyzer);
        // 参数是查询语法
        Query query = parser.parse("lucene");
        TopDocs topDocs = searcher.search(query, 100);
        ScoreDoc[] scoreDocs = topDocs.scoreDocs;
        for (ScoreDoc scoreDoc : scoreDocs) {
            Document document = searcher.doc(scoreDoc.doc);
            System.out.println("name : " + document.get("name"));
        }
        reader.close();
    }
}
```

#### solr

##### schema文件

field标签属性

- name：只有定义了fieldname，才能添加对应域的值
- type：对应fieldtype标签，确定当前域是否分词，以及用什么分词器
- indexed：是否索引
- stored：是否存储
- required：添加document时是否一定需要当前域
- multiValued：当前域的值是单一值还是多个值（以数组存储）

dynamicField：动态匹配域的name（在field标签name没有匹配的情况下）

copyField：

##### 导入数据

