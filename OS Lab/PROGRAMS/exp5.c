#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main()
{
/* ftok function is used to generate unique key which is for System V IPC functions */
key_t key = ftok("shmfile",65);
/* shmget function returns the shared memory identifier associated with key in shmid */
int shmid = shmget(key,1024,0666|IPC_CREAT);
/* shmat function is used to attach to the shared memory segment associated with the shared
memory identifier, shmid, to the address space of the calling process. */
char *str = (char*) shmat(shmid,(void*)0,0);
printf("Write Data: ");
//scanf("%s", str);
//gets(str);
fgets(str, 25, stdin);
printf("\n Data written in memory: %s\n",str);
/* shmdt function detaches the shared memory segment located at the specified address from
the address space of the calling process */
shmdt(str);
return 0;
}

