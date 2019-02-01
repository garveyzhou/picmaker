#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int file =  open("pic.ppm",O_WRONLY | O_CREAT | O_TRUNC,0644);
	char * line = "P3 500 500 255\n";
	write(file,line,strlen(line));
	int r,g,b;
	char * buffer = malloc(20*sizeof(char));
	for(int i = 0; i < 500; i++){
		for(int j = 0;j<500;j++){
			r = i % 256;
			g = j % 256;
			b = (i + j) % 256;
			sprintf(buffer,"%d %d %d ",r,g,b);
			write(file,buffer,strlen(buffer));
		}
	}
	close(file);
}

