//zombie_process.c
//演示僵尸进程的生成
//编译命令：$ gcc -o zombie_process  zombie_process.c
//运行命令：$ ./zombie_process
//子进程退出后，父进程需要调用wait来处理其遗留的task_struct
//如果父进程未调用wait，那么就会产生僵尸进程。
//在ps命令中，标记为defunct的进程，就是僵尸进程。
//defunct 进程可能会一直留在系统中直到系统重新启动
//“僵尸”进程是一个早已死亡的进程，但在进程表（processs table）中仍占了一个位置（slot）。
//由于进程表的容量是有限的，所以，defunct进程不仅占用系统的内存资源，影响系统的性能，而且如果其数目太多，还会导致系统瘫痪。

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
        pid_t pid;
        if((pid=fork())==-1)
                perror("fork");
        else if(pid==0)
        {
                printf("child_pid pid=%d\n",getpid());
                exit(0);
        }
        sleep(5);
        system("ps");//等待5秒后，子进程肯定已经退出，但是父进程一直未调用wait
        exit(0);
}
