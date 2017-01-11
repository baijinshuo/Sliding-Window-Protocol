#include<stdio.h>
#include<time.h>
#include <unistd.h>
#include<windows.h>
#include<math.h>
#define Max_Size 100
typedef struct frame {
	int count;
	int data[];
	int head,rear;
	boolean flag;
}str;

 str receive(str s){
 	str re;
 	int time1=rand()%5000;
	time_t starTime; 
	struct tm * timeinfo; 		
	int start = time ( &starTime ); 
	Sleep(time1);
	time_t endTime; 
	int end = time ( &endTime );
	re=s;
	re.flag=true;
	if((end-start)>=3)
	{
		re.flag=false;
		printf("Waiting time is too long! Require resend!\n");
	}
	int ran=rand()%10;
	if(ran==1)
	{
		re.flag=false;
		printf("There is something wrong in process! Require resend!\n");
	}
	
 	return re;
 }
 
 boolean send(str s){
	str se;
	boolean flag=false;
	se=receive(s);
	flag=se.flag;
	return flag;
}
 
 int main(){
	boolean flag;
	int i;
	str s[Max_Size];
	while(1){
		flag=send(s[i]);
		if(flag==true)
		{
			printf("No %d signal has been received!",i);
			printf("\n");
			i++;
		}
	}
	return 0;
}
