#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 
#include <time.h> 
#define NAME 20 
#define SEX 10 
#define KDAYS 20 
#define ADDR 30 
#define NUMBER 12 
#define DAK 10 
#define SCHOOL 30 
#define STUDENTMAX 1000 //ѧ���������  
#define PASSWORD "19960224" //ϵͳ��¼����  
/************************ѧ����Ϣ�ṹ��**********************/  
struct studentinfo //ѧ��������Ϣ�ṹ 
{ char name [NAME]; //ѧ������ 
 char sex [SEX]; //ѧ���Ա� 
 char kdays [KDAYS]; //�������� 
 char addr [ADDR]; //���ο�Ŀ 
 char number [NUMBER]; //ѧ��ѧ�� 
 char dak [DAK]; //������Ŀ 
 char school[SCHOOL]; }; //����ѧУ�༶  
struct allstudentinfo //ѧ��ȫ���ṹ  
{ struct studentinfo student; };  
FILE *infofile=NULL; //��ѧ��������Ϣ�����ļ� 
char filename[]="c:\\ѧ��������Ϣ�Ǽ�.dat"; //��¼������Ϣ�Ǽ� 
/************************����������****************************/  
void password(); //������֤ 
int showmeun(); //ϵͳ���˵���ʾ 
int submeun(); //�Ӳ˵���ʾ  
void submain(struct allstudentinfo *); //��ϵͳ  
void inputinfo(struct allstudentinfo *); //����ѧ��������Ϣ 
void modinfo(struct allstudentinfo *); //�޸ĸ�����Ϣ 
void aboutinfo(struct allstudentinfo *); //��ѯ������Ϣ 
void allabout(struct allstudentinfo *); //��ѯ������Ϣ  
void delinfo(struct allstudentinfo *); //ɾ��������Ϣ 
void mofname(struct allstudentinfo *); //�޸����� 
void mofsex(struct allstudentinfo *); //�޸��Ա� 
void mofbirth(struct allstudentinfo *); //�޸Ŀ������� 
void mofaddr(struct allstudentinfo *); //�޸Ŀ��ο�Ŀ 
void moftel(struct allstudentinfo *); //�޸�ѧ��ѧ�� 
void mofdak(struct allstudentinfo *); //�޸Ŀ�����Ŀ 
void mofschool(struct allstudentinfo *); //�޸����ڰ༶ 
int datfile(struct allstudentinfo *); //�����޸ĸ�����Ϣ���ļ� 
void systemhelp(); //ϵͳ������Ϣ 
void logout(); //�˳�ϵͳ 
void main() 
{ struct allstudentinfo studentmax[STUDENTMAX]; //���ѧ������ 
 struct allstudentinfo *p_student; //ָ��ṹָ�� 
 int in; 
 time_t start,end; 
 p_student=studentmax; //ָ��ṹ��  
 password(); //��ȡѧ��������֤ 
 do 
 { system("cls"); 
 in=showmeun(); //ϵͳ���˵���ʾ  
 switch(in) 
 { case 1 : submain(p_student);  
 break;  
 case 2 : systemhelp(); 
 break; 
 case 3 : logout(); 
 break; 
 default: printf("û�д�ѡ��밴�������������ѡ��!"); 
 getch(); 
 system("cls"); 
 break; } 
 }while(in!=4); 
} 
/************************��ϵͳ*******************************/ 
void submain(struct allstudentinfo *p_student) 
{ int in; 
 do 
 { system("cls"); 
 in=submeun(); //�Ӳ˵���ʾ  
 switch(in) 
 { case 1 : inputinfo(p_student); //���������Ϣ 
 break; 
 case 2 : modinfo(p_student); //�޸ĸ�����Ϣ 
 break; 
 case 3 : aboutinfo(p_student); //��ѯ������Ϣ 
 break; 
 case 4 : allabout(p_student); //��ѯ������Ϣ 
 break; 
 case 5 : delinfo(p_student); //ɾ��������Ϣ 
 break; 
 case 6 : break; 
 default: printf("û�д�ѡ�������������(1-5)"); 
 getch(); 
 system("cls"); 
 break; 
 } 
 } while(in!=6); 
 system("cls"); 
}  
/************************������֤*****************************/ 
void password() 
{ char *pass=NULL; //��ʼ��ָ��  
 int count; 
 time_t start,end; //ʱ�亯�� 
 pass=(char *)malloc(255*sizeof(char)); //�����ڴ�  
 while(1) 
 { count=0;  
 printf("\n\n\n\n\n\t\t ѧ����Ϣ����ϵͳ \n\n\n\n"); 
 printf("\n\t\t ѧ����:���� \n"); 
 printf("\n\t\t �� ��:"); 
 while((count>=0)&&(pass[count++]=getch())!=13) //��������  
 { if(pass[0]=='\b') 
 { count=0; 
 continue; } 
 else if(pass[count-1]=='\b') 
 { printf("%c%c%c",'\b','\0','\b'); 
 count-=2; } 
 else 
 putchar('*'); 
 } 
 pass[--count]='\0'; 
 if(!strcmp(pass,PASSWORD)) //��ʼ��֤  
 { system("cls"); 
 printf("\n\n\n\n\n\n\n\n\n\t\t\t"); 
 printf(" �� ӭ �� ½ ѧ �� �� Ϣ �� �� ϵ ͳ !"); 
 start=time(NULL); 
 end=time(NULL); 
 while(end-start<1) //��ʱ1��ִ�����³���  
 { end=time(NULL); } 
 system("cls"); 
 free(pass); //�ͷŴ���������ڴ�  
 return ; 
 } 
 free(pass); //�ͷ����������ǿ��ڴ�  
 pass=(char *)malloc(255*sizeof(char)); //���·��䴢�������ڴ�  
 system("cls"); 
 printf("\a\n\n\n\n\n\n\n\n\t\t\t\t�� �� �� �� !"); 
 getch(); 
 system("cls"); 
 } 
}  
/***********************ϵͳ���˵�************************/ 
int showmeun() 
{ int in; 
 char ch; 
 printf("\n\n\n\n"); 
 printf("\t���q���������������������������������������������������������r\n"); 
 printf("\t���O ��ѧ�����˿�����Ϣ����ϵͳ�� �O\n"); 
 printf("\t����--------------------------------------------------------��\n"); 
 printf("\t�������������� 1. ѧ��������Ϣ������������������ ��\n"); 
 printf("\t��������������������������������������������������������������\n"); 
 printf("\t�������������� 2.�����ڱ�ϵͳ�������������������������� ��\n"); 
 printf("\t���������������������������������������������������������� ��\n"); 
 printf("\t�������������� 3.���ˡ�����ϵ��ͳ������������������ ������\n"); 
 printf("\t��������������������������������������������������������������\n");  
 printf("\t �t���������������������������������������������������������s\n"); 
 printf("\t ������ȷѡ��:"); 
 while(scanf("%d",&in)!=1) 
 {while((ch=getchar())!='\n') 
 putchar(ch); 
 return in;} 
 fflush(stdin); 
 return in; 
} 
/***********************������Ϣ�Ӳ˵�*************************/ 
int submeun() 
{ int in; 
 char ch; 
 system("cls"); 
 printf("\n\n\n"); 
 printf("\t\t�q���������������������������������������������������������r\n"); 
 printf("\t\t�������������� ��ѧ��������Ϣ����ϵͳ�������� ���� ��\n"); 
 printf("\t\t��--------------------------------------------------------��\n"); 
 printf("\t\t���������������� 1.¼�������Ϣ������������������ ��\n"); 
 printf("\t\t�������������������������������������������� ��\n"); 
 printf("\t\t���������������� 2.�޸Ŀ�����Ϣ�������� ��\n"); 
 printf("\t\t�������������������������������������������� ��\n"); 
 printf("\t\t���������������� 3.��ѯ������Ϣ������������ ��\n"); 
 printf("\t\t������������������������������������������������ ��\n"); 
 printf("\t\t���������������� 4.���������Ϣ�������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n");  
 printf("\t\t���������������� 5.ɾ��������Ϣ�������������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n");
 printf("\t\t���������������� 6.�˳�ϵͳ������������������ ��\n"); 
 printf("\t\t�t���������������������������������������������������������s\n"); 
 printf("\t\t ������ȷѡ��:"); 
 while(scanf("%d",&in)!=1) 
 { while((ch=getchar())!='\n') 
 putchar(ch); 
 return 0; } 
 fflush(stdin); 
 return in; 
} 
/***************************�޸ĸ�����Ϣ�Ӳ˵�************************/ 
void modinfo(struct allstudentinfo *p_student) 
{ int in; 
 char ch; 
 do 
 { system("cls"); 
 printf("\n\n\n"); 
 printf("\t\t�q���������������������������������������������������������r\n"); 
 printf("\t\t������������������ ��������Ϣ�޸Ĺ����������� �� ��\n"); 
 printf("\t\t��--------------------------------------------------------��\n"); 
 printf("\t\t���������������� 1.�޸�ѧ���������� �������������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n"); 
 printf("\t\t���������������� 2.�޸�ѧ���Ա𡡡� �������������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n"); 
 printf("\t\t���������������� 3.�޸Ŀ������ڡ� ���������������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n"); 
 printf("\t\t���������������� 4.�޸Ŀ��ο�Ŀ�� ���������������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n"); 
 printf("\t\t���������������� 5.�޸�ѧ��ѧ�š� ���������������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n"); 
 printf("\t\t���������������� 6.�޸Ŀ��ν����� ���������������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n"); 
 printf("\t\t���������������� 7.�޸����ڰ༶�� ���������������� ��\n"); 
 printf("\t\t������������������������������������������������ ��\n"); 
 printf("\t\t���������������� 8.�˳�ϵͳ ���������������������� ��\n"); 
 printf("\t\t�t���������������������������������������������������������s\n"); 
 printf("\t\t ������ȷѡ��:"); 
 while(scanf("%d",&in)!=1) 
 { 
 while((ch=getchar())!='\n') 
 putchar(ch); 
 printf(" û�д�ѡ�������ѡ��!"); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 fflush(stdin); 
 switch(in) 
 { case 1 : mofname(p_student); 
 break; 
 case 2 : mofsex(p_student); 
 break; 
 case 3 : mofbirth(p_student); 
 break; 
 case 4 : mofaddr(p_student); 
 break; 
 case 5 : moftel(p_student); 
 break; 
 case 6 : mofdak(p_student); 
 break; 
 case 7 : mofschool(p_student); 
 break; 
 case 8 : return ; 
 default: printf("û�д�ѡ�������ѡ��!"); 
 break; 
 } 
 }while(1); 
}  
/*************************������Ϣ¼��*************************/ 
void inputinfo(struct allstudentinfo *p_student) 
{ int count; 
 char ch; 
 system("cls"); 
 if((infofile=fopen(filename,"a+b"))==NULL) 
 { printf("���ܴ��ļ�����ȷ�ϴ���������c:\\ѧ��������Ϣ�Ǽ�.dat�ļ�û����"); 
 getch(); 
 exit(1); } 
 rewind(infofile); //��λ�ļ�ͷ��ʼ��ȡ  
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 continue;  
 printf("\n\n ������Ϣ�ǼǱ�\n"); 
 printf("\n����ȷ��д������Ϣ(ϵͳ����֧��Ӣ�ġ����ֻ�ƴ��\n");  
 printf("---------------------------------------------------------\n\n"); 
 printf("�� ��:"); 
 while(count<STUDENTMAX&&gets(p_student[count].student.name)!=NULL //��������  
 &&p_student[count].student.name[0]!='\0') 
 { 
 printf("\n�� ��:"); //�����Ա� 
 gets(p_student[count].student.sex);  
 printf("\n��������:"); //����������� 
 gets(p_student[count].student.kdays);  
 printf("\n���ο�Ŀ:"); //������ο�Ŀ 
 gets(p_student[count].student.addr);  
 printf("\nѧ��ѧ��:"); //����ѧ�� 
 gets(p_student[count].student.number);  
 printf("\n������Ŀ:"); //���������Ŀ 
 gets(p_student[count].student.dak);  
 printf("\n�����༶:"); //�������ڰ༶ 
 gets(p_student[count].student.school);  
  
 fwrite(&p_student[count++].student,sizeof(struct studentinfo),1,infofile); //����Ϣд���ļ� 
 printf("�Ƿ�¼����һ��ѧ��������Ϣ(y/n)"); 
 ch=getch();  
 if(ch=='y'||ch=='Y') 
 { system("cls"); 
 printf("\n��������һ��ѧ���ĸ�����Ϣ\n"); 
 printf("\n�� ��:");  
 continue; } //����������һ��ѧ����Ϣ 
 else 
 { printf("\n\n������Ϣ¼�����������!"); 
 fclose(infofile); //�ر��ļ�  
 getch(); //�����Ӳ˵� 
 system("cls"); 
 return ; } 
 } 
 printf("����������ֹ������Ϣ¼�룬����!"); 
 getch(); 
 system("cls"); 
 return ; //����  
} 
/***********************��ѯ������Ϣ****************************/ 
void aboutinfo(struct allstudentinfo *p_student) 
{ int i; 
 int count; //ѧ��������  
 char ch; 
 char *temp=NULL; //��ʱ�洢Ҫ��ѯ��ѧ������  
 system("cls"); 
 if((infofile=fopen(filename,"rb"))==NULL) 
 { printf("���ܴ��ļ�����ȷ�ϴ����������ļ��Ƿ����"); 
 getch(); 
 exit(1); } 
 rewind(infofile); //ָ���ļ�ͷ 
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 { continue; } 
 fclose(infofile); //�ر��ļ� 
 if(!count) 
 { printf("�Ҳ����������ݣ���ȷ���Ѿ��ɹ�¼����ļ��Ƿ����!"); 
 getch(); 
 system("cls"); 
 return ; } 
 temp=(char *)malloc(20*sizeof(char)); //�����ڴ� 
 printf("������Ҫ��ѯ��ѧ������:");  
 while(gets(temp)!=NULL&&temp[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(!strcmp(temp,p_student[i].student.name)) 
 { system("cls"); 
 printf("��������Ҫ��ѯ%s�ĸ�����Ϣ\n",p_student[i].student.name); 
 printf("\n ������Ϣ��ѯ��\n"); 
 printf("-----------------------------------------------------------------\n"); 
 printf("\n�� ��: %s\n",p_student[i].student.name); 
 printf("\n�� ��: %s\n",p_student[i].student.sex); 
 printf("\n��������: %s\n",p_student[i].student.kdays); 
 printf("\n���ο�Ŀ: %s\n",p_student[i].student.addr); 
 printf("\nѧ��ѧ��: %s\n",p_student[i].student.number); 
 printf("\n������Ŀ: %s\n",p_student[i].student.dak); 
 printf("\n���ڰ༶: %s\n",p_student[i].student.school); 
 printf("-----------------------------------------------------------------\n"); 
 break; } 
 } 
 free(temp); //�ͷſռ�  
 printf("\n��ѯ��һ��ѧ���ĸ�����Ϣ(y/n)"); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { system("cls"); 
 temp=(char *)malloc(20*sizeof(char)); //���·����ڴ�  
 printf("������Ҫ��ѯ��ѧ������:"); 
 continue; } 
 else 
 { printf("\n��ѯ����������!"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 free(temp); //�ͷ��Ѿ�������ڴ�ռ�  
 printf("\n���������밴����������Ӳ˵�!"); 
 getch(); 
 system("cls");  
}  
/****************************��ѯ������Ϣ*******************************/ 
void allabout(struct allstudentinfo *p_student) 
{ int i; 
 int count; 
 system("cls"); 
 if((infofile=fopen(filename,"rb"))==NULL) 
 { printf("���ܴ��ļ�����ȷ���ļ��Ƿ���ڻ��Ƿ���!"); 
 getch(); 
 exit(1); } 
 rewind(infofile); //��λ���ļ�ͷ 
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 { continue; } 
 fclose(infofile); //�����ر��ļ� 
 if(!count) 
 { printf("���ܶ�ȡ���ݣ���ȷ���ļ��Ƿ���ڻ��Ѿ��ɹ�¼������!"); 
 getch(); 
 system("cls"); 
 return ; } //�������²���  
 printf("\n\t\t\t ѧ��������Ϣ��ѯ��\n\n"); 
 printf("\t �����Ǳ�ϵͳ����ѯ��������ѧ��������Ϣ,��������Ҳ�������\n"); 
 printf(" ��ȷ���Ƿ��Ѿ��ɹ�¼�뱾ϵͳ!\n"); 
 printf("----------------------------------------"); 
 printf("----------------------------------------\n"); 
 for(i=0;i<count;i++) 
 { printf("�����ڲ鿴��[%d]��ѧ���ĸ�����Ϣ\n",i+1);  
 printf("\n�� ��: %s\n",p_student[i].student.name); 
 printf("\n�� ��: %s\n",p_student[i].student.sex); 
 printf("\n��������: %s\n",p_student[i].student.kdays); 
 printf("\n���ο�Ŀ: %s\n",p_student[i].student.addr); 
 printf("\nѧ��ѧ��: %s\n",p_student[i].student.number); 
 printf("\n������Ŀ: %s\n",p_student[i].student.dak); 
 printf("\n���ڰ༶: %s\n",p_student[i].student.school); 
 printf("------------------------------------");  
 printf("------------------------------------\n"); 
 printf("�밴����������鿴��Ϣ........!"); 
 getch(); 
 system("cls");  
 } 
 printf("\n��ѯ����...");  
 printf("�밴���������!"); 
 getch(); 
 system("cls"); 
 return ; 
}  
/****************************ɾ��������Ϣ*******************************/ 
void delinfo(struct allstudentinfo *p_student) 
{ int i; 
 int count; 
 char ch; 
 char *temp=NULL; //��ʼ����ʱ���� 
 system("cls"); //����  
 if((infofile=fopen(filename,"rb"))==NULL) 
 { printf("���ܴ��ļ�����ȷ�ϴ����������ļ��Ƿ����"); 
 getch();  
 exit(1); } 
 rewind(infofile); //ָ���ļ�ͷ  
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 { continue; }  
 fclose(infofile); //�ر��ļ� 
 if(!count) 
 { printf("���ܶ�ȡ���ݣ���ȷ���Ѿ���ȷ¼��������Ƿ����"); 
 getch(); 
 return ; } 
 temp=(char *)malloc(20*sizeof(char)); //�����ڴ� 
 printf("��������Ҫɾ����ѧ������:"); 
 while(gets(temp)!=NULL&&temp[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(!strcmp(temp,p_student[i].student.name)) 
 { system("cls"); 
 printf("\a\n\n\n\n\n\n\t\t ȷ��Ҫɾ��%s�ĸ��˿�����Ϣ��?(y/n)",p_student[i].student.name); 
 ch=getch(); 
 if(ch=='n'||ch=='N') 
 { free(temp); 
 system("cls"); 
 printf("\n\n\n\n\n\n\t\t �ò�����ȡ��.�밴���������!"); 
 getch(); 
 system("cls"); 
 return ; }  
 for(;i<count;i++) 
 { p_student[i].student=p_student[i+1].student; } 
 count--; //ɾ��һ��ѧ����Ϣ  
 if((infofile=fopen(filename,"w+b"))==NULL) //���´��ļ�����  
 { free(temp); 
 printf("���ܴ��ļ�����ȷ�ϴ����������ļ��Ƿ����"); 
 getch(); 
 exit(1); } 
 for(i=0;i<count;i++) 
 { //�����ļ�  
 if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)!=1) 
 break; } 
 free(temp); //�ͷ��ڴ�  
 system("cls");  
 printf("\n\n\n\n\n\n\t\t �ѳɹ�ɾ����ѧ���ĸ��˿�����Ϣ.....\n"); 
 printf("\n\t\tȷ��Ҫɾ����һ��ѧ��������Ϣ(y/n)"); 
 ch=getch(); 
 if(ch=='n'||ch=='N') 
 { fclose(infofile); 
 system("cls"); 
 return ; } 
 else 
 { system("cls"); 
 temp=(char *)malloc(20*sizeof(char)); //���·����ڴ���ɾ����һ����Ϣ  
 printf("����������Ҫɾ����ѧ������:");  
 break; }  
 }  
 } 
 printf("�Ҳ���%s�ĸ�����Ϣ.",temp); 
 printf("����������(y/n)"); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { free(temp); 
 temp=(char *)malloc(sizeof(char)); //���·���  
 system("cls"); 
 printf("��������Ҫɾ����ѧ������:");  
 continue; } 
 else 
 { free(temp); 
 system("cls"); 
 return ; } 
 } 
 free(temp); //�ͷ��ڴ�  
 printf("���������밴����������Ӳ˵�������ѡ��"); 
 getch(); 
 system("cls"); }  
/**********************�޸�ѧ������***************************/ 
void mofname(struct allstudentinfo *p_student) 
{ char ch; 
 char *temp; 
 char *newtemp;  
 int count; 
 int i; 
 system("cls"); 
 count=datfile(p_student); //�����ļ�  
 if(!count) 
 { printf("��ȡ����ʧ�ܣ���ȷ���ѳɹ�¼����ļ������Ƿ���!"); 
 getch(); 
 return ; } 
 newtemp=(char *)malloc(20*sizeof(char)); //�����ڴ�  
 temp= (char *)malloc(20*sizeof(char)); //�����ڴ� 
 printf("��������Ҫ�޸ĵ�ѧ������:"); 
 while(gets(temp)!=NULL&&temp[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(temp,p_student[i].student.name)) 
 { continue; } 
 else 
 { printf("���������ѧ����������:"); 
 gets(newtemp); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\tȷ��Ҫ������Ϊ%s��ѧ���޸�Ϊ%s��?(y/n)",temp,newtemp); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.name,newtemp); //�޸����� 
 infofile=fopen(filename,"w+b"); //����д���ļ� 
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 printf("�޸�ʧ�ܣ��������²���....."); 
 getch(); 
 free(temp); 
 free(newtemp); 
 system("cls"); 
 return ; }  
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�ѳɹ���%s�޸�Ϊ%s����!",temp,newtemp); 
 getch(); 
 free(temp); 
 free(newtemp);  
 system("cls"); 
 return ; } 
 } 
 } 
 printf("�Ҳ���%s�ĸ�����Ϣ,�������²���!",temp); 
 free(temp); 
 free(newtemp); 
 getch(); 
 system("cls"); 
 return ; }  
 printf("\n\n\n\n\t\t\t���������뷵�����²���!"); 
 getch(); 
 free(temp); 
 free(newtemp); 
 system("cls"); 
 return ; 
} 
/************************�޸ĸ����Ա�*********************/ 
void mofsex(struct allstudentinfo *p_student) 
{ char *tempname; //Ҫ�޸ĵ�ѧ�������� 
 char *tempsex; //Ҫ�޸ĵ�ѧ�����Ա� 
 char ch; 
 int count; 
 int i; 
 system("cls"); 
 count=datfile(p_student); //�����ļ� 
 if(!count) 
 { printf("��ȡ����ʧ�ܣ���ȷ���ѳɹ�¼�����ݻ��ļ��Ƿ���!"); 
 getch(); 
 return ; } 
 tempname=(char *)malloc(10*sizeof(char)); //�����ڴ� 
 tempsex=(char *)malloc(10*sizeof(char)); //�����ڴ� 
 printf("������Ҫ�޸ĵ�ѧ������:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { 
 for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("�������ѧ�������Ա�:"); 
 gets(tempsex); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\tȷ��Ҫ�޸ĸ�ѧ�����Ա���?(y/n)"); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.sex,tempsex); 
 infofile=fopen(filename,"w+b"); 
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�޸�ʧ�ܣ��뷵��....."); 
 getch(); 
 free(tempname); 
 free(tempsex); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�ѳɹ��޸�%s���Ա𣬷���!",tempname); 
 getch(); 
 free(tempname); 
 free(tempsex); 
 system("cls"); 
 return ; } 
 printf("�ò�������ȡ��,����....."); 
 free(tempname); 
 free(tempsex); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 printf("�Ҳ���%s�ĸ�����Ϣ������......",tempname); 
 free(tempname); 
 free(tempsex); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("���������뷵����������!"); 
 free(tempname); 
 free(tempsex); 
 getch(); 
 system("cls"); 
 return ;}  
/**************************�޸Ŀ�������***************************/ 
void mofbirth(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *tempbirth; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //�����ļ� 
 if(!count) 
 { printf("��ȡ����ʧ�ܣ���ȷ���ѳɹ�¼��������Ƿ���!"); 
 getch(); 
 return ; } 
 tempname=(char *)malloc(20*sizeof(char)); 
 tempbirth=(char *)malloc(20*sizeof(char)); //�����ڴ� 
 printf("������Ҫ�޸ĵ�ѧ������:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("�����������ѧ���Ŀ�������:"); 
 gets(tempbirth); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\tȷ��Ҫ�޸�%s�Ŀ���������?(y/n)",tempname); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.kdays,tempbirth); 
 infofile=fopen(filename,"w+b"); 
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 free(tempname); 
 free(tempbirth); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�޸�ʧ��,����......"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�ɹ��޸�%s�Ŀ�������,����!,",tempname); 
 free(tempname); 
 free(tempbirth); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("\n\n\n\n\t\t\t�ò����ѱ�ȡ��������!"); 
 free(tempname); 
 free(tempbirth); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 } 
 printf("\n\n\n\n\t\t\t�Ҳ���%s�ĸ�����Ϣ������!",tempname); 
 free(tempname); 
 free(tempbirth); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("���������뷵������ѡ��!"); 
 free(tempname); 
 free(tempbirth); 
 getch(); 
 system("cls"); 
 return ; 
} 
/***********************�޸Ŀ��ο�Ŀ*********************/ 
void mofaddr(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *tempaddr; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //�����ļ� 
 if(!count) 
 { printf("��ȡ����ʧ�ܣ���ȷ���ѳɹ�¼��������Ƿ���!"); 
 getch(); 
 return ; } 
 tempname=(char *)malloc(20*sizeof(char)); 
 tempaddr=(char *)malloc(20*sizeof(char)); //�����ڴ� 
 printf("������Ҫ�޸ĵ�ѧ������:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("�����������ѧ���Ŀ��ο�Ŀ:"); 
 gets(tempaddr); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\tȷ��Ҫ�޸�%s�Ŀ��ο�Ŀ��?(y/n)",tempname); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.addr,tempaddr); 
 infofile=fopen(filename,"w+b"); //����д�����ݿ�  
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 free(tempname); 
 free(tempaddr); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�޸�ʧ��,����......!"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�ɹ��޸�%s�Ŀ��ο�Ŀ,����......!,",tempname); 
 free(tempname); 
 free(tempaddr); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("\n\n\n\n\t\t\t�ò����ѱ�ȡ��������.......!"); 
 free(tempname); 
 free(tempaddr); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 } 
 printf("\n\n\n\n\t\t\t�Ҳ���%s�ĸ�����Ϣ������.......!",tempname); 
 free(tempname); 
 free(tempaddr); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("���������뷵������ѡ��.......!"); 
 free(tempname); 
 free(tempaddr); 
 getch(); 
 system("cls"); 
 return ; 
} 
/*****************************�޸�ѧ��ѧ��********************************/ 
void moftel(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *temptel; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //�����ļ� 
 if(!count) 
 { printf("��ȡ����ʧ�ܣ���ȷ���ѳɹ�¼��������Ƿ���!"); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 tempname=(char *)malloc(20*sizeof(char)); 
 temptel=(char *)malloc(20*sizeof(char)); //�����ڴ� 
 printf("������Ҫ�޸ĵ�ѧ������:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { 
 if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("�����������ѧ����ѧ��ѧ��:"); 
 gets(temptel); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\tȷ��Ҫ�޸�%s��ѧ��ѧ����?(y/n)",tempname); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.number,temptel); 
 infofile=fopen(filename,"w+b"); 
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 free(tempname); 
 free(temptel); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�޸�ʧ��,����.......!"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�ɹ��޸�%s��ѧ��ѧ��,����.......!,",tempname); 
 free(tempname); 
 free(temptel); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("\n\n\n\n\t\t\t�ò����ѱ�ȡ��������.......!"); 
 free(tempname); 
 free(temptel); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 } 
 printf("\n\n\n\n\t\t\t�Ҳ���%s�ĸ�����Ϣ������.......!",tempname); 
 free(tempname); 
 free(temptel); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("���������뷵������ѡ��.......!"); 
 free(tempname); 
 free(temptel); 
 getch(); 
 system("cls"); 
 return ; 
} 
/**************************�޸Ŀ�����Ŀ*************************/ 
void mofdak(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *tempdak; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //�����ļ�  
 if(!count) 
 { printf("��ȡ����ʧ�ܣ���ȷ���ѳɹ�¼��������Ƿ���!"); 
 getch(); 
 system("cls"); 
 return ; } 
 tempname=(char *)malloc(20*sizeof(char)); 
 tempdak =(char *)malloc(20*sizeof(char)); //�����ڴ� 
 printf("������Ҫ�޸ĵ�ѧ������:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("�����������ѧ���Ŀ�����Ŀ:"); 
 gets(tempdak); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\tȷ��Ҫ�޸�%s�Ŀ�����Ŀ��?(y/n)",tempname); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.dak,tempdak); 
 infofile=fopen(filename,"w+b"); 
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 free(tempname); 
 free(tempdak); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�޸�ʧ��,����.......!"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�ɹ��޸�%s�Ŀ�����Ŀ,����.......!",tempname); 
 free(tempname); 
 free(tempdak); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("\n\n\n\n\t\t\t�ò�����ȡ��������.......!"); 
 free(tempname); 
 free(tempdak); 
 getch(); 
 system("cls"); 
 return ; } } 
 printf("\n\n\n\n\t\t\t�Ҳ���%s�ĸ�����Ϣ������.......!",tempname); 
 free(tempname); 
 free(tempdak); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("���������뷵������ѡ��.......!"); 
 free(tempname); 
 free(tempdak); 
 getch(); 
 system("cls"); 
 return ; } 
/*************************�޸����ڰ༶******************************/ 
void mofschool(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *tempschool; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //�ļ�����  
 if(!count) 
 { printf("��ȡ����ʧ�ܣ���ȷ���ѳɹ�¼��������Ƿ���!"); 
 getch(); 
 system("cls"); 
 return ; 
 }  
 tempname=(char *)malloc(20*sizeof(char)); 
 tempschool=(char *)malloc(20*sizeof(char)); //�����ڴ� 
 printf("������Ҫ�޸ĵ�ѧ������:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("�����������ѧ�������ڰ༶:"); 
 gets(tempschool); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\tȷ��Ҫ�޸�%s�����ڰ༶��?(y/n)",tempname); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.school,tempschool); 
 infofile=fopen(filename,"w+b"); 
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 free(tempname); 
 free(tempschool); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�޸�ʧ��,����.......!"); 
 getch(); 
 system("cls"); 
 return ; } } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t�ɹ��޸�%s�����ڰ༶,����.......!",tempname); 
 free(tempname); 
 free(tempschool); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("\n\n\n\n\t\t\t�ò�����ȡ��������.......!"); 
 free(tempname); 
 free(tempschool); 
 getch(); 
 system("cls"); 
 return ; } } 
 printf("\n\n\n\n\t\t\t�Ҳ���%s�ĸ�����Ϣ������.......!",tempname); 
 free(tempname); 
 free(tempschool); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("���������뷵������ѡ��.......!"); 
 free(tempname); 
 free(tempschool); 
 getch(); 
 system("cls"); 
 return ; } 
/**************************�޸ĸ�����Ϣ����Ҫ�����ļ�**************************/ 
int datfile(struct allstudentinfo *p_student) 
{ int count; 
  
 system("cls"); 
 if((infofile=fopen(filename,"rb"))==NULL) 
 { printf("�����ҿ��ļ�����ȷ�ϴ����������ļ��Ƿ����!"); 
 getch(); 
 exit(1); } 
 rewind(infofile); //ָ���ļ�ͷ��ȡ����  
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 { continue; } 
 fclose(infofile); 
 return count; //���ض����Ľṹ����  
}  
/*****************************ϵͳ������Ϣ*******************************/ 
void systemhelp() 
{ system("cls"); 
 printf("\n\n\n\t\t\t\tϵͳ����\n"); 
 printf("\t****************------------------------------******************\n"); 
 printf("\t ��ϵͳ֧�ֺ��֡�Ӣ�ƴ�����������Ƿ�ʽ¼�룬Ϊ��������ʹ��\n"); 
 printf("\t��ϵͳ����Ҫʹ���޸ĺ�ɾ�����������ʹ�ã����Ƚ��������ñ�������\n"); 
 printf("\t��ϵͳ����������ݶ�ʧ! �밴������˳�!\n"); 
 printf("\t****************------------------------------******************\n"); 
 getch(); 
 system("cls"); 
 return ; }  
/***********�˳�*********************************/ 
void logout() 
{ time_t start,end; //ʱ�亯�� 
 system("cls"); 
 printf("\n\n\n\n\n\n\n\n\t\t\t"); 
 printf("л л ʹ �� �� ϵ ͳ !");  
 start=time(NULL); 
 end=time(NULL); 
 while(end-start<2) //��ʱ2��ִ�����³���  
 end=time(NULL); 
 exit(0); 
}
