工作区的内容最新，暂存区次之（工作区add之后两人相同），分支再次之（暂存区commit之后两人相同）

git命令不区分大小写、

`git check-ignore -v 文件名`命令检查哪个规则使得文件没有被add

###### 随时工作

git 文件夹下还未被track的文件在切换分支的时候不会变动

分支共享工作区和暂存区，只是指针指向的分支版本不一样

##### 配置别名

```
git config --global alias.别名 命令原名
```

配置Git的时候，加上`--global`是针对当前用户起作用的，如果不加，那只针对当前的仓库起作用。

每个仓库的Git配置文件都放在`.git/config`文件中：别名就在`[alias]`后面，要删除别名，直接把对应的行删掉即可。

当前用户的Git配置文件放在用户主目录下的一个隐藏文件`.gitconfig`中：配置别名也可以直接修改这个文件，如果改错了，可以删掉文件重新通过命令配置。

##### 配置.gitignore

- 以”#”号开头表示注释；
- 以斜杠“/”开头表示目录；
- 以星号“*”通配多个字符；
- 以问号“?”通配单个字符
- 以方括号“[]”包含单个字符的匹配列表；
- 以叹号“!”表示不忽略(跟踪)匹配到的文件或目录；

- `*.后缀名`：忽略所有后缀名相同的

- `文件夹名/`：忽略对应目录下的全部内容；不管是根目录下的/对应目录/，还是某个子目录/balabala/对应目录/，都会被忽略。

  `/文件夹名/`：写全路径，忽略全路径名下的全部内容

- `某个文件名`：忽略对应文件

  `!某个文件名`：不忽略这个文件

- ```
  bin/: 忽略当前路径下的bin文件夹，该文件夹下的所有内容都会被忽略，不忽略 bin 文件
  
  /bin: 忽略根目录下的bin文件
  
  /*.c: 忽略 cat.c，不忽略 build/cat.c
  
  debug/*.obj: 忽略 debug/io.obj，不忽略 debug/common/io.obj 和 tools/debug/io.obj
  
  **/foo: 忽略/foo, a/foo, a/b/foo等
  
  a/**/b: 忽略a/b, a/x/b, a/x/y/b等
  
  !/bin/run.sh: 不忽略 bin 目录下的 run.sh 文件
  
  *.log: 忽略所有 .log 文件
  
  config.php: 忽略当前路径的 config.php 文件
  ```

###### 忽略未生效

gitignore只能忽略那些原来没有被track的文件，如果某些文件已经被纳入了版本管理中，则修改.gitignore是无效的。

解决方法就是先把本地缓存删除（改变成未track状态），然后再提交:

```
git rm -r --cached .
git add .
git commit -m 'update .gitignore'
```

可能是`.gitignore`写得有问题，需要找出来到底哪个规则写错了，可以用`git check-ignore`命令检查：

```
$ git check-ignore -v App.class
.gitignore:3:*.class    App.class
```

#### gitadd

- `cherry-pick`命令，让我们能复制一个特定的提交到**当前分支**
- git add -f 文件名：忽略.gitignore中的规则，强制add文件

#### git标签

- `git tag <tagname>`用于新建一个标签，默认为最新一次commit，也可以指定一个commit id；

  `git tag -a <tagname> -m "blablabla..."`可以指定标签信息；

- `git tag`可以查看所有标签。

- `git show <tagname>`可以看到说明文字：

- `git push 远程主机名 <tagname>`可以推送一个本地标签；

- `git push origin --tags`可以推送全部未推送过的本地标签；

- `git tag -d <tagname>`可以删除一个本地标签；

- `git push origin :refs/tags/<tagname>`可以删除一个远程标签。

#### git恢复

- `git log`命令查看commit的历史记录，多行按q退出

- `git status`命令可以让我们时刻掌握仓库当前的状态

- `git diff`

  - 尚未缓存的改动（查看工作区与暂存区的不同）：**git diff**
  - 查看已缓存的改动（暂存区与分支之间的不同）： **git diff --cached**
  - 查看已缓存的与未缓存的所有改动（查看工作区和分支的不同）：**git diff HEAD**
  - 显示摘要而非整个 diff：**git diff --stat**

- `git restore <file>`可以丢弃工作区的修改：

  一种是文件自修改后还没有被add到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

  一种是文件已经add到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。

- `git reset`命令回退版本：在Git中，用`HEAD`表示当前版本，上一个版本就是`HEAD^`，上上一个版本就是`HEAD^^`，当然往上100个版本写100个`^`比较容易数不过来，所以写成`HEAD~100`。

  - git reset --mixed：默认参数(--之后不写参数默认mixed，不写head默认head)，移动分支HEAD指针，改变暂存区和分支一样，不改变工作区
  - git reset --soft：倒退指针的同时，不改变暂存区和工作区
  - git reset --hard：倒退指针的同时，改变暂存区和工作区和分支一样

  不带任何参数相当于 git reset --mixed head（用于撤销已经add到暂存区的内容）

#### git远程

###### 主机名称

- `git remote`命令列出所有远程主机。

  使用`-v`选项，可以显示更详细的信息：

  ```
  $ git remote -v
  origin  git@github.com:michaelliao/learngit.git (fetch)
  origin  git@github.com:michaelliao/learngit.git (push)
  ```

  上面显示了可以抓取和推送的`origin`的地址。如果没有推送权限，就看不到push的地址。

- `git remote add <主机名> <网址>`命令用于添加远程主机。

- `git remote rm <主机名>`命令用于删除远程主机。

- `git remote show <主机名>`命令加上主机名，可以查看该主机的详细信息。

- `git remote rename <原主机名> <新主机名>`命令用于远程主机的改名。

##### 协作

- `git clone <版本库的网址>`

  克隆版本库的时候，所使用的远程主机自动被Git命名为`origin`。如果想用其他的主机名，需要用`git clone`命令的`-o`选项指定。

  git clone顾名思义就是将其他仓库克隆到本地，**包括被clone仓库的版本变化**。下载远程仓库，本地无需**git init**，直接git clone url。执行git clone等待clone结束，目录下自动会有一个.git的隐藏文件夹，因为是clone来的，所以.git文件夹里存放着与远程仓库一模一样的git log记录。clone操作是一个从无到有的**克隆**操作，不需要`git init`初始化。

- 建立本地分支与远程分支关系：git branch --set-upstream origin/branch-name branch-name 

  如果远程还没有创建origin/branch-name，直接写origin主机名即可，远程会自动创建相应的分支（或者直接git push 远程主机名 本地分支名）

- git pull 远程主机名（需要建立分支关系）

- git push 远程主机名 本地分支名

#### git分支

分支共享工作区和暂存区，只是指针指向的分支版本不一样

- 创建分支：`git branch <name>`

  创建分支跟踪远程已有的分支：git branch 本地分支名 远程主机名/远程分支名

  切换分支：`git checkout <name>`或者`git switch <name>`

  创建+切换分支：`git checkout -b <name>`或者`git switch -c <name>`

- `git branch`命令查看当前分支：

  ```
    git branch
  * dev
    master
  ```

  `git branch`命令会列出所有分支，当前分支前面会标一个`*`号。

- 删除分支：`git branch -d <name>`

  强行删除分支：`git branch -D <name>`

  当一个分支被推送并合并到远程分支后，`-d` 才会本地删除该分支。如果一个分支还没有被推送或者合并，那么可以使用`-D`强制删除它。

  删除远程分支：`git push <remotename> --delete <branchname>`。

- 合并某分支到**当前分支**：`git merge <name>`

  合并问题

  - git merge请输入一个提交信息以解释此合并的必要性：（可以直接git merge -m " "添加信息）

    1. 键盘输入i，进入insert状态，在该状态下你可以修改控制台中的文字，填你想填写的内容
    2. 输入完之后，按esc退出insert状态
    3. 按shift + :（注意：当前应处于英文输入法状态），当底部出现冒号之后，再输入wq，回车即可，如图所示

  - 合并分支时，如果可能，Git会用`Fast forward`模式，如果要强制禁用`Fast forward`模式，Git就会在merge时生成一个新的commit，这样，能看出来曾经做过合并，

    `git merge --no-ff -m "merge with no-ff" <name>`：--no-ff`参数，表示禁用`Fast forward，因为本次合并要创建一个新的commit，所以加上`-m`参数，把commit描述写进去。

###### 保存暂存区

- `git stash`：可以保存暂存区
- `git stash list`：查看保存的暂存区
- `git stash apply`：恢复暂存区，但是恢复后，stash内容并不删除，你需要用`git stash drop`来删除；
  - 恢复指定的stash，用命令：git stash apply stash@{0}
- `git stash pop`：恢复的同时把stash内容也删了

