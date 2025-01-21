#include <stdio.h>
#include <dirent.h>

int main(){
	
	char dirName[256];
	DIR*dirp;
	struct  dirent*entry;
	
	printf("Enter directory name: ");
	scanf("%s",dirName);
	
	dirp =opendir(dirName);
	
	if(dirp==NULL){
		printf("Error oprning directory ,\n");
		return 1;
		}
	while((entry =readdir(dirp)) != NULL){
		printf("%s\n",entry->d_name);
		}
	closedir(dirp);
	return 0;
	}
