#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int is_no_print(int c)
{
	return !isprint(c);
}
static int(*func[])(int)={
	iscntrl,
	isspace,
	isdigit,
	islower,
	isupper,
	ispunct,
	is_no_print,
};
char *label[]={
	"control",
	"whitespace",
	"digit",
	"lower case",
	"upper case",
	"punctuation",
	"no_print",
};
#define N_CATEGORY \
	(sizeof(func)/sizeof(func[0]))
int count[N_CATEGORY];
int total;
int main(int argc,char *argv[])
{
int ch;
int category;
while((ch=getchar())!=EOF)
{
	total+=1;
	for(category=0;category<N_CATEGORY;category++)
	{
		if((func[category])(ch))
		{
			count[category]+=1;
			break;
		}
	}
	if(ch=='q')
		break;
	getchar();
}
	for(category=0;category<N_CATEGORY;category++)
	{
		printf("%2.1f%% %s\n",count[category]*100.0/total,label[category]);
	}
	printf("total is:%d\n",total);
}
