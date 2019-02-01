#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
	int file =  open("pic.ppm",O_WRONLY | O_CREAT | O_TRUNC,0644);
	char * line = "P3 500 500 255\n";
	write(file,line,strlen(line));
	char color[3];
	for(int i = 0; i < 500; i++){
		for(int j = 0;j<500;j++){
			color[0] = i % 256;
			color[1] = j % 256;
			color[2] = (i + j) % 256;
			write(file,color,strlen(color));
		}
	}
	close(file);
}

