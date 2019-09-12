#include <cstdio>

int main (int argc, char** argv){
 
FILE* fr = fopen ("data.txt" , "r");

int value = 0;

while(fscanf(fr, "%d", &value) !=EOF){
	value+=1;
	printf("%d",value);
}
fclose(fr);

FILE* fw = fopen("data.txt","w");
fprintf(fw, "%d", value);

fclose(fw);
}