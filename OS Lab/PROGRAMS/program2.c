#include  <stdio.h>
#include  <sys/stat.h>

int main(void){
	char path1[256];
	struct stat nfile;
	
	printf("Enter name of file :");
	scanf("%s",path1);
	
	if(stat(path1,&nfile)==-1){
		perror("Erroe getting file sats");
		return 1;
	}
	printf("User ID :%d \n",nfile.st_uid);
	
	printf("Block size : %ld \n" , nfile.st_blksize);
	
	printf("last acces time: %ld\n ", nfile.st_atime);
	
	printf("Last modification time :%ld\n",nfile.st_mtime);
	
	printf("file permissions and mode :%o\n",nfile.st_mode);
	
	printf("Siz of file  :%ld\n",nfile.st_size);
	
	return 0;
	
	}
