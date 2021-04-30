一个典型的 Kafka 体系架构包括若干 Producer、若干 Broker、若干Consumer，以及一个ZooKeeper集群

Broker：服务代理节点。对于Kafka而言，Broker可以简单地看作一个独立的Kafka服务节点或Kafka服务实例。大多数情况下也可以将Broker看作一台Kafka服务器，前提是这台服务器上只部署了一个Kafka实例。一个或多个Broker组成了一个Kafka集群。一般而言，我们更习惯使用首字母小写的broker来表示服务代理节点。

在Kafka中还有两个特别重要的概念—主题（Topic）与分区（Partition）。Kafka中的消息以主题为单位进行归类，发送到Kafka集群中的每一条消息都要指定一个主题。主题是一个逻辑上的概念，它可以包含多个分区。一个分区只属于单个主题，同一主题下的不同分区包含的消息是不同的，

broker 端接收的消息必须以字节数组（byte[]）的形式存在。

KafkaProducer是线程安全的，可以在多个线程中共享单个KafkaProducer实例，也可以将KafkaProducer实例进行池化来供其他线程调用。

ProducerRecord类的定义![image-20210429145350669](C:\Users\wangjingyu\AppData\Roaming\Typora\typora-user-images\image-20210429145350669.png)

发送消息主要有三种模式：发后即忘（fire-and-forget）、同步（sync）及异步（async）。