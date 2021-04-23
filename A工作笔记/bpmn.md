bpmn：业务流程建模符号(BPMN - Business Process Modeling Notation)

BPMN定义了一个[业务流程图](https://baike.baidu.com/item/业务流程图)（Business Process Diagram）

activiti是一个业务流程管理引擎，会沿着设计者设计好的流程，一步一步的执行下去，直到终点。

#### bpmn

Sequence：（After an element is visited during process execution, **all outgoing sequence flow will be followed**. ）

exclusive gateway：在使用独占网关时，只选择一个序列流。如果多序列流具有计算结果为 true 的条件，则为 XML 中定义的第一个条件(并且只有那个条件!)被选中来继续这个过程。如果无法选择序列流，则将引发异常。

usertask：如果没有给出给定文本字符串是用户还是组的具体信息，则引擎默认为 group。

Receive Task：当流程执行到达接收任务时，流程状态将被持久性存储。这意味着流程将保持这种等待状态，直到引擎接收到特定的消息，这将触发接收任务之后流程的继续。

要继续当前正在接收任务上等待的流程实例，必须使用到达接收任务的执行的 id 调用 runtimeService.signal (executionId)。下面的代码片段展示了这在实践中是如何工作的:

```java
ProcessInstance pi = runtimeService.startProcessInstanceByKey("receiveTask");
Execution execution = runtimeService.createExecutionQuery()
  .processInstanceId(pi.getId())
  .activityId("waitState")
  .singleResult();
assertNotNull(execution);

runtimeService.signal(execution.getId());
```

```
List<Task> tasks = taskService.createTaskQuery().taskAssignee("kermit").list();
List<Task> tasks = taskService.createTaskQuery().taskCandidateUser("kermit");
```

#### activiti的7大马车

- RepositoryService：提供一系列管理流程部署和流程定义的API。
- RuntimeService：在流程运行时对流程实例进行管理与控制。
- TaskService：对流程任务进行管理，例如任务提醒、任务完成和创建任务等。
- IdentityService：提供对流程角色数据进行管理的API，这些角色数据包括用户组、用户及它们之间的关系。
- ManagementService：提供对流程引擎进行管理和维护的服务。
- HistoryService：对流程的历史数据进行操作，包括查询、删除这些历史数据。
- FormService：表单服务。
- ProcessEngine（流程引擎对象）

| 表分类       | 表名称                | 表含义                        |
| ------------ | --------------------- | ----------------------------- |
|              | act_evt_log           | 事件处理日志表                |
| 一般数据     | act_ge_bytearray      | 通用的流程定义和流程资源      |
|              | act_ge_property       | 系统相关属性                  |
| 流程历史记录 | act_hi_actinst        | 历史的流程实例                |
|              | act_hi_attachment     | 历史的流程附件                |
|              | act_hi_comment        | 历史的说明性信息              |
|              | act_hi_detail         | 历史的流程运行中的细节信息    |
|              | act_hi_identitylink   | 历史的流程运行过程中用户关系  |
|              | act_hi_procinst       | 历史的流程实例                |
|              | act_hi_taskinst       | 历史的任务实例                |
|              | act_hi_varinst        | 历史的流程运行中的变量信息    |
| 用户用户组表 | act_id_group          | 身份信息-组信息               |
|              | act_id_info           | 身份信息-组信息               |
|              | act_id_membership     | 身份信息-用户和组关系的中间表 |
|              | act_id_user           | 身份信息-用户信息             |
|              | act_procdef_info      | 死信任务                      |
| 流程定义表   | act_re_deployment     | 部署单元信息                  |
|              | act_re_model          | 模型信息                      |
|              | act_re_procdef        | 已部署的流程定义              |
| 运行实例表   | act_ru_deadletter_job | 执行失败任务表                |
|              | act_ru_event_subscr   | 运行时事件                    |
|              | act_ru_execution      | 运行时流程执行实例            |
|              | act_ru_identitylink   | 运行时用户关系信息            |
|              | act_ru_job            | 运行时作业                    |
|              | act_ru_suspended_job  | 运行时暂停任务                |
|              | act_ru_task           | 运行时任务                    |
|              | act_ru_timer_job      | 运行时定时任务                |
|              | act_ru_variable       | 运行时变量表                  |

具体的表结构及详细介绍可参考[Activiti数据库表结构](https://links.jianshu.com/go?to=https%3A%2F%2Fblog.csdn.net%2Fhj7jay%2Farticle%2Fdetails%2F51302829) 里面有详细的每个表介绍。

```
Activiti的后台是有数据库的支持，所有的表都以ACT_开头。 第二部分是表示表的用途的两个字母标识。 用途也和服务的API对应。
ACT_RE_*: 'RE'表示repository。 这个前缀的表包含了流程定义和流程静态资源 （图片，规则，等等）。
ACT_RU_*: 'RU'表示runtime。 这些运行时的表，包含流程实例，任务，变量，异步任务，等运行中的数据。 Activiti只在流程实例执行过程中保存这些数据， 在流程结束时就会删除这些记录。 这样运行时表可以一直很小速度很快。
ACT_ID_*: 'ID'表示identity。 这些表包含身份信息，比如用户，组等等。
ACT_HI_*: 'HI'表示history。 这些表包含历史数据，比如历史流程实例， 变量，任务等等。
ACT_GE_*: 通用数据， 用于不同场景下，如存放资源文件。
```

