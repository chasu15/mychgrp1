#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
	gid_t gid;
	struct passwd *pwd;
	char *endptr;

	if(argc == 3){
			if(argv[0] == '\0'){
				if(argv[1] == '\0'){
				fprintf(stderr, "%s <group> <file>\n", argv[0]);
				exit(EXIT_FAILURE);
			}
		}
	
	gid = strtol(argv[1], &endptr, 10);

	if(*endptr != '\0'){
		pwd = getpwnam(argv[1]);
		if(pwd == NULL){
			perror("getpwnam");
			exit(EXIT_FAILURE);
		}

	gid = pwd->pw_gid;
	}
	
	if(chown(argv[2], -1,gid) == -1){
		perror("chown");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_FAILURE);
	}else if(argc == 4){
		if(argv[0] == '\0'){
			if(argv[1] == '\0'){
				fprintf(stderr, "%s <option> <group> <file> \n",argv[0]);
				exit(EXIT_FAILURE);
			}
		}

	if(strcmp(argv[1],"-c") == 0)
	{
		printf("changed group of '%s' from %s to %s\n",argv[3],pwd,argv[2]);
	}
	if(strcmp(argv[1],"-v") == 0)
	{
		printf("changed group of '%s' from %s to %s\n",argv[3],pwd,argv[2]);
	}
	if(strcmp(argv[1],"-f") == 0)
	{
	}
	if(strcmp(argv[1],"-R") == 0)
	{
		
	}

	gid = strtol(argv[2], &endptr, 10);

	if(*endptr != '\0'){
		pwd = getpwnam(argv[2]);
		if(pwd == NULL){
			perror("getpwnam");
			exit(EXIT_FAILURE);
		}

	gid = pwd->pw_gid;
	}

	if(chown(argv[3], -1, gid) == -1){
		perror("chown");
		exit(EXIT_FAILURE);
	}
	
	return 0;
	exit(EXIT_FAILURE);
	}else{
		perror("error\n");
	}
}
