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
#define STUDENTMAX 1000 //学生最大人数  
#define PASSWORD "19960224" //系统登录密码  
/************************学生信息结构体**********************/  
struct studentinfo //学生个人信息结构 
{ char name [NAME]; //学生姓名 
 char sex [SEX]; //学生性别 
 char kdays [KDAYS]; //旷课日期 
 char addr [ADDR]; //旷课科目 
 char number [NUMBER]; //学生学号 
 char dak [DAK]; //旷课数目 
 char school[SCHOOL]; }; //所在学校班级  
struct allstudentinfo //学生全部结构  
{ struct studentinfo student; };  
FILE *infofile=NULL; //存学生个人信息数据文件 
char filename[]="c:\\学生个人信息登记.dat"; //记录个人信息登记 
/************************函数块声明****************************/  
void password(); //密码验证 
int showmeun(); //系统主菜单显示 
int submeun(); //子菜单显示  
void submain(struct allstudentinfo *); //子系统  
void inputinfo(struct allstudentinfo *); //输入学生个人信息 
void modinfo(struct allstudentinfo *); //修改个人信息 
void aboutinfo(struct allstudentinfo *); //查询个人信息 
void allabout(struct allstudentinfo *); //查询所有信息  
void delinfo(struct allstudentinfo *); //删除个人信息 
void mofname(struct allstudentinfo *); //修改姓名 
void mofsex(struct allstudentinfo *); //修改性别 
void mofbirth(struct allstudentinfo *); //修改旷课日期 
void mofaddr(struct allstudentinfo *); //修改旷课科目 
void moftel(struct allstudentinfo *); //修改学生学号 
void mofdak(struct allstudentinfo *); //修改旷课数目 
void mofschool(struct allstudentinfo *); //修改所在班级 
int datfile(struct allstudentinfo *); //处理修改个人信息的文件 
void systemhelp(); //系统帮助信息 
void logout(); //退出系统 
void main() 
{ struct allstudentinfo studentmax[STUDENTMAX]; //最大学生人数 
 struct allstudentinfo *p_student; //指向结构指针 
 int in; 
 time_t start,end; 
 p_student=studentmax; //指向结构体  
 password(); //获取学生密码验证 
 do 
 { system("cls"); 
 in=showmeun(); //系统主菜单显示  
 switch(in) 
 { case 1 : submain(p_student);  
 break;  
 case 2 : systemhelp(); 
 break; 
 case 3 : logout(); 
 break; 
 default: printf("没有此选项，请按任意键返回重新选择!"); 
 getch(); 
 system("cls"); 
 break; } 
 }while(in!=4); 
} 
/************************子系统*******************************/ 
void submain(struct allstudentinfo *p_student) 
{ int in; 
 do 
 { system("cls"); 
 in=submeun(); //子菜单显示  
 switch(in) 
 { case 1 : inputinfo(p_student); //输入个人信息 
 break; 
 case 2 : modinfo(p_student); //修改个人信息 
 break; 
 case 3 : aboutinfo(p_student); //查询个人信息 
 break; 
 case 4 : allabout(p_student); //查询所有信息 
 break; 
 case 5 : delinfo(p_student); //删除个人信息 
 break; 
 case 6 : break; 
 default: printf("没有此选项。请您重新输入(1-5)"); 
 getch(); 
 system("cls"); 
 break; 
 } 
 } while(in!=6); 
 system("cls"); 
}  
/************************密码验证*****************************/ 
void password() 
{ char *pass=NULL; //初始化指针  
 int count; 
 time_t start,end; //时间函数 
 pass=(char *)malloc(255*sizeof(char)); //分配内存  
 while(1) 
 { count=0;  
 printf("\n\n\n\n\n\t\t 学生信息管理系统 \n\n\n\n"); 
 printf("\n\t\t 学生名:王锴 \n"); 
 printf("\n\t\t 密 码:"); 
 while((count>=0)&&(pass[count++]=getch())!=13) //密码输入  
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
 if(!strcmp(pass,PASSWORD)) //开始验证  
 { system("cls"); 
 printf("\n\n\n\n\n\n\n\n\n\t\t\t"); 
 printf(" 欢 迎 登 陆 学 生 信 息 管 理 系 统 !"); 
 start=time(NULL); 
 end=time(NULL); 
 while(end-start<1) //延时1秒执行以下程序  
 { end=time(NULL); } 
 system("cls"); 
 free(pass); //释放储存密码的内存  
 return ; 
 } 
 free(pass); //释放密码错误的那块内存  
 pass=(char *)malloc(255*sizeof(char)); //重新分配储存密码内存  
 system("cls"); 
 printf("\a\n\n\n\n\n\n\n\n\t\t\t\t密 码 错 误 !"); 
 getch(); 
 system("cls"); 
 } 
}  
/***********************系统主菜单************************/ 
int showmeun() 
{ int in; 
 char ch; 
 printf("\n\n\n\n"); 
 printf("\t　╭————————————————————————————╮\n"); 
 printf("\t　∣ 『学生个人旷课信息管理系统』 ∣\n"); 
 printf("\t　｜--------------------------------------------------------｜\n"); 
 printf("\t　｜　　　　　 1. 学生个人信息管理　　　　　　　　 ｜\n"); 
 printf("\t　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜\n"); 
 printf("\t　｜　　　　　 2.　关于本系统帮助　　　　　　　　　　　 ｜\n"); 
 printf("\t　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t　｜　　　　　 3.　退　出　系　统　　　　　　　　　 　　｜\n"); 
 printf("\t　｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　｜\n");  
 printf("\t ╰————————————————————————————╯\n"); 
 printf("\t 请您正确选择:"); 
 while(scanf("%d",&in)!=1) 
 {while((ch=getchar())!='\n') 
 putchar(ch); 
 return in;} 
 fflush(stdin); 
 return in; 
} 
/***********************个人信息子菜单*************************/ 
int submeun() 
{ int in; 
 char ch; 
 system("cls"); 
 printf("\n\n\n"); 
 printf("\t\t╭————————————————————————————╮\n"); 
 printf("\t\t｜　　　　　　 『学生个人信息管理系统』　　　 　　 ｜\n"); 
 printf("\t\t｜--------------------------------------------------------｜\n"); 
 printf("\t\t｜　　　　　　　 1.录入旷课信息　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 2.修改旷课信息　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 3.查询旷课信息　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 4.浏览所有信息　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n");  
 printf("\t\t｜　　　　　　　 5.删除旷课信息　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n");
 printf("\t\t｜　　　　　　　 6.退出系统　　　　　　　　　 ｜\n"); 
 printf("\t\t╰————————————————————————————╯\n"); 
 printf("\t\t 请您正确选择:"); 
 while(scanf("%d",&in)!=1) 
 { while((ch=getchar())!='\n') 
 putchar(ch); 
 return 0; } 
 fflush(stdin); 
 return in; 
} 
/***************************修改个人信息子菜单************************/ 
void modinfo(struct allstudentinfo *p_student) 
{ int in; 
 char ch; 
 do 
 { system("cls"); 
 printf("\n\n\n"); 
 printf("\t\t╭————————————————————————————╮\n"); 
 printf("\t\t｜　　　　　　　　 『个人信息修改管理』　　　　 　 ｜\n"); 
 printf("\t\t｜--------------------------------------------------------｜\n"); 
 printf("\t\t｜　　　　　　　 1.修改学生姓名　　 　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 2.修改学生性别　　 　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 3.修改旷课日期　 　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 4.修改旷课科目　 　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 5.修改学生学号　 　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 6.修改旷课节数　 　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 7.修改所在班级　 　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　　　　　　　　　　　　　　　　　 ｜\n"); 
 printf("\t\t｜　　　　　　　 8.退出系统 　　　　　　　　　　　 ｜\n"); 
 printf("\t\t╰————————————————————————————╯\n"); 
 printf("\t\t 请您正确选择:"); 
 while(scanf("%d",&in)!=1) 
 { 
 while((ch=getchar())!='\n') 
 putchar(ch); 
 printf(" 没有此选项，请重新选择!"); 
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
 default: printf("没有此选项，请重新选择!"); 
 break; 
 } 
 }while(1); 
}  
/*************************个人信息录入*************************/ 
void inputinfo(struct allstudentinfo *p_student) 
{ int count; 
 char ch; 
 system("cls"); 
 if((infofile=fopen(filename,"a+b"))==NULL) 
 { printf("不能打开文件，请确认磁盘已满或c:\\学生个人信息登记.dat文件没有损坏"); 
 getch(); 
 exit(1); } 
 rewind(infofile); //定位文件头开始读取  
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 continue;  
 printf("\n\n 个人信息登记表\n"); 
 printf("\n请正确填写以下信息(系统可以支持英文、汉字或拼音\n");  
 printf("---------------------------------------------------------\n\n"); 
 printf("姓 名:"); 
 while(count<STUDENTMAX&&gets(p_student[count].student.name)!=NULL //输入姓名  
 &&p_student[count].student.name[0]!='\0') 
 { 
 printf("\n性 别:"); //输入性别 
 gets(p_student[count].student.sex);  
 printf("\n旷课日期:"); //输入旷课日期 
 gets(p_student[count].student.kdays);  
 printf("\n旷课科目:"); //输入旷课科目 
 gets(p_student[count].student.addr);  
 printf("\n学生学号:"); //输入学号 
 gets(p_student[count].student.number);  
 printf("\n旷课数目:"); //输入旷课数目 
 gets(p_student[count].student.dak);  
 printf("\n所属班级:"); //输入所在班级 
 gets(p_student[count].student.school);  
  
 fwrite(&p_student[count++].student,sizeof(struct studentinfo),1,infofile); //将信息写入文件 
 printf("是否录入下一个学生旷课信息(y/n)"); 
 ch=getch();  
 if(ch=='y'||ch=='Y') 
 { system("cls"); 
 printf("\n请输入下一个学生的个人信息\n"); 
 printf("\n姓 名:");  
 continue; } //继续输入下一个学生信息 
 else 
 { printf("\n\n个人信息录入结束，返回!"); 
 fclose(infofile); //关闭文件  
 getch(); //返回子菜单 
 system("cls"); 
 return ; } 
 } 
 printf("输入有误，终止个人信息录入，返回!"); 
 getch(); 
 system("cls"); 
 return ; //返回  
} 
/***********************查询个人信息****************************/ 
void aboutinfo(struct allstudentinfo *p_student) 
{ int i; 
 int count; //学生计数器  
 char ch; 
 char *temp=NULL; //临时存储要查询的学生姓名  
 system("cls"); 
 if((infofile=fopen(filename,"rb"))==NULL) 
 { printf("不能打开文件，请确认磁盘已满或文件是否存在"); 
 getch(); 
 exit(1); } 
 rewind(infofile); //指向文件头 
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 { continue; } 
 fclose(infofile); //关闭文件 
 if(!count) 
 { printf("找不到个人数据，请确认已经成功录入或文件是否存在!"); 
 getch(); 
 system("cls"); 
 return ; } 
 temp=(char *)malloc(20*sizeof(char)); //分配内存 
 printf("请输入要查询的学生姓名:");  
 while(gets(temp)!=NULL&&temp[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(!strcmp(temp,p_student[i].student.name)) 
 { system("cls"); 
 printf("以下是你要查询%s的个人信息\n",p_student[i].student.name); 
 printf("\n 个人信息查询表\n"); 
 printf("-----------------------------------------------------------------\n"); 
 printf("\n姓 名: %s\n",p_student[i].student.name); 
 printf("\n性 别: %s\n",p_student[i].student.sex); 
 printf("\n旷课日期: %s\n",p_student[i].student.kdays); 
 printf("\n旷课科目: %s\n",p_student[i].student.addr); 
 printf("\n学生学号: %s\n",p_student[i].student.number); 
 printf("\n旷课数目: %s\n",p_student[i].student.dak); 
 printf("\n所在班级: %s\n",p_student[i].student.school); 
 printf("-----------------------------------------------------------------\n"); 
 break; } 
 } 
 free(temp); //释放空间  
 printf("\n查询下一个学生的个人信息(y/n)"); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { system("cls"); 
 temp=(char *)malloc(20*sizeof(char)); //重新分配内存  
 printf("请输入要查询的学生姓名:"); 
 continue; } 
 else 
 { printf("\n查询结束，返回!"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 free(temp); //释放已经分配的内存空间  
 printf("\n输入有误，请按任意键返回子菜单!"); 
 getch(); 
 system("cls");  
}  
/****************************查询所有信息*******************************/ 
void allabout(struct allstudentinfo *p_student) 
{ int i; 
 int count; 
 system("cls"); 
 if((infofile=fopen(filename,"rb"))==NULL) 
 { printf("不能打开文件，请确认文件是否存在或是否损坏!"); 
 getch(); 
 exit(1); } 
 rewind(infofile); //定位到文件头 
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 { continue; } 
 fclose(infofile); //读完后关闭文件 
 if(!count) 
 { printf("不能读取数据，请确定文件是否存在或已经成功录入数据!"); 
 getch(); 
 system("cls"); 
 return ; } //反回重新操作  
 printf("\n\t\t\t 学生个人信息查询表\n\n"); 
 printf("\t 以下是本系统所查询到的所有学生个人信息,如果表中找不到数据\n"); 
 printf(" 请确认是否已经成功录入本系统!\n"); 
 printf("----------------------------------------"); 
 printf("----------------------------------------\n"); 
 for(i=0;i<count;i++) 
 { printf("您正在查看第[%d]个学生的个人信息\n",i+1);  
 printf("\n姓 名: %s\n",p_student[i].student.name); 
 printf("\n性 别: %s\n",p_student[i].student.sex); 
 printf("\n旷课日期: %s\n",p_student[i].student.kdays); 
 printf("\n旷课科目: %s\n",p_student[i].student.addr); 
 printf("\n学生学号: %s\n",p_student[i].student.number); 
 printf("\n旷课数目: %s\n",p_student[i].student.dak); 
 printf("\n所在班级: %s\n",p_student[i].student.school); 
 printf("------------------------------------");  
 printf("------------------------------------\n"); 
 printf("请按任意键继续查看信息........!"); 
 getch(); 
 system("cls");  
 } 
 printf("\n查询结束...");  
 printf("请按任意键返回!"); 
 getch(); 
 system("cls"); 
 return ; 
}  
/****************************删除个人信息*******************************/ 
void delinfo(struct allstudentinfo *p_student) 
{ int i; 
 int count; 
 char ch; 
 char *temp=NULL; //初始化临时数组 
 system("cls"); //清屏  
 if((infofile=fopen(filename,"rb"))==NULL) 
 { printf("不能打开文件，请确认磁盘已满或文件是否存在"); 
 getch();  
 exit(1); } 
 rewind(infofile); //指向文件头  
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 { continue; }  
 fclose(infofile); //关闭文件 
 if(!count) 
 { printf("不能读取数据，请确认已经正确录入或数据是否存在"); 
 getch(); 
 return ; } 
 temp=(char *)malloc(20*sizeof(char)); //分配内存 
 printf("请输入你要删除的学生姓名:"); 
 while(gets(temp)!=NULL&&temp[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(!strcmp(temp,p_student[i].student.name)) 
 { system("cls"); 
 printf("\a\n\n\n\n\n\n\t\t 确定要删除%s的个人旷课信息吗?(y/n)",p_student[i].student.name); 
 ch=getch(); 
 if(ch=='n'||ch=='N') 
 { free(temp); 
 system("cls"); 
 printf("\n\n\n\n\n\n\t\t 该操作已取消.请按任意键返回!"); 
 getch(); 
 system("cls"); 
 return ; }  
 for(;i<count;i++) 
 { p_student[i].student=p_student[i+1].student; } 
 count--; //删除一个学生信息  
 if((infofile=fopen(filename,"w+b"))==NULL) //重新打开文件更新  
 { free(temp); 
 printf("不能打开文件，请确认磁盘已满或文件是否存在"); 
 getch(); 
 exit(1); } 
 for(i=0;i<count;i++) 
 { //更新文件  
 if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)!=1) 
 break; } 
 free(temp); //释放内存  
 system("cls");  
 printf("\n\n\n\n\n\n\t\t 已成功删除该学生的个人旷课信息.....\n"); 
 printf("\n\t\t确定要删除下一个学生个人信息(y/n)"); 
 ch=getch(); 
 if(ch=='n'||ch=='N') 
 { fclose(infofile); 
 system("cls"); 
 return ; } 
 else 
 { system("cls"); 
 temp=(char *)malloc(20*sizeof(char)); //重新分配内存以删除下一个信息  
 printf("请输入你想要删除的学生姓名:");  
 break; }  
 }  
 } 
 printf("找不到%s的个人信息.",temp); 
 printf("请重新输入(y/n)"); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { free(temp); 
 temp=(char *)malloc(sizeof(char)); //重新分配  
 system("cls"); 
 printf("请输入你要删除的学生姓名:");  
 continue; } 
 else 
 { free(temp); 
 system("cls"); 
 return ; } 
 } 
 free(temp); //释放内存  
 printf("输入有误，请按任意键返回子菜单，重新选择"); 
 getch(); 
 system("cls"); }  
/**********************修改学生姓名***************************/ 
void mofname(struct allstudentinfo *p_student) 
{ char ch; 
 char *temp; 
 char *newtemp;  
 int count; 
 int i; 
 system("cls"); 
 count=datfile(p_student); //处理文件  
 if(!count) 
 { printf("读取数据失败，请确认已成功录入或文件数据是否损害!"); 
 getch(); 
 return ; } 
 newtemp=(char *)malloc(20*sizeof(char)); //分配内存  
 temp= (char *)malloc(20*sizeof(char)); //分配内存 
 printf("请输入您要修改的学生姓名:"); 
 while(gets(temp)!=NULL&&temp[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(temp,p_student[i].student.name)) 
 { continue; } 
 else 
 { printf("请您输入该学生的新姓名:"); 
 gets(newtemp); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\t确定要把姓名为%s的学生修改为%s码?(y/n)",temp,newtemp); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.name,newtemp); //修改姓名 
 infofile=fopen(filename,"w+b"); //重新写入文件 
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 printf("修改失败，返回重新操作....."); 
 getch(); 
 free(temp); 
 free(newtemp); 
 system("cls"); 
 return ; }  
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t已成功把%s修改为%s返回!",temp,newtemp); 
 getch(); 
 free(temp); 
 free(newtemp);  
 system("cls"); 
 return ; } 
 } 
 } 
 printf("找不到%s的个人信息,返回重新操作!",temp); 
 free(temp); 
 free(newtemp); 
 getch(); 
 system("cls"); 
 return ; }  
 printf("\n\n\n\n\t\t\t输入有误，请返回重新操作!"); 
 getch(); 
 free(temp); 
 free(newtemp); 
 system("cls"); 
 return ; 
} 
/************************修改个人性别*********************/ 
void mofsex(struct allstudentinfo *p_student) 
{ char *tempname; //要修改的学生的名字 
 char *tempsex; //要修改的学生的性别 
 char ch; 
 int count; 
 int i; 
 system("cls"); 
 count=datfile(p_student); //处理文件 
 if(!count) 
 { printf("读取数据失败，请确认已成功录入数据或文件是否损坏!"); 
 getch(); 
 return ; } 
 tempname=(char *)malloc(10*sizeof(char)); //分配内存 
 tempsex=(char *)malloc(10*sizeof(char)); //分配内存 
 printf("请输入要修改的学生姓名:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { 
 for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("请输入该学生的新性别:"); 
 gets(tempsex); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\t确定要修改该学生的性别吗?(y/n)"); 
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
 printf("\n\n\n\n\t\t\t修改失败，请返回....."); 
 getch(); 
 free(tempname); 
 free(tempsex); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t已成功修改%s的性别，返回!",tempname); 
 getch(); 
 free(tempname); 
 free(tempsex); 
 system("cls"); 
 return ; } 
 printf("该操作已衩取消,返回....."); 
 free(tempname); 
 free(tempsex); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 printf("找不到%s的个人信息，返回......",tempname); 
 free(tempname); 
 free(tempsex); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("输入有误，请返回重新输入!"); 
 free(tempname); 
 free(tempsex); 
 getch(); 
 system("cls"); 
 return ;}  
/**************************修改旷课日期***************************/ 
void mofbirth(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *tempbirth; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //处理文件 
 if(!count) 
 { printf("读取数据失败，请确认已成功录入或数据是否损坏!"); 
 getch(); 
 return ; } 
 tempname=(char *)malloc(20*sizeof(char)); 
 tempbirth=(char *)malloc(20*sizeof(char)); //分配内存 
 printf("请输入要修改的学生姓名:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("请重新输入该学生的旷课日期:"); 
 gets(tempbirth); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\t确定要修改%s的旷课日期吗?(y/n)",tempname); 
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
 printf("\n\n\n\n\t\t\t修改失败,返回......"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t成功修改%s的旷课日期,返回!,",tempname); 
 free(tempname); 
 free(tempbirth); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("\n\n\n\n\t\t\t该操作已被取消，返回!"); 
 free(tempname); 
 free(tempbirth); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 } 
 printf("\n\n\n\n\t\t\t找不到%s的个人信息，返回!",tempname); 
 free(tempname); 
 free(tempbirth); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("输入有误，请返回重新选择!"); 
 free(tempname); 
 free(tempbirth); 
 getch(); 
 system("cls"); 
 return ; 
} 
/***********************修改旷课科目*********************/ 
void mofaddr(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *tempaddr; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //处理文件 
 if(!count) 
 { printf("读取数据失败，请确认已成功录入或数据是否损坏!"); 
 getch(); 
 return ; } 
 tempname=(char *)malloc(20*sizeof(char)); 
 tempaddr=(char *)malloc(20*sizeof(char)); //分配内存 
 printf("请输入要修改的学生姓名:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("请重新输入该学生的旷课科目:"); 
 gets(tempaddr); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\t确定要修改%s的旷课科目吗?(y/n)",tempname); 
 ch=getch(); 
 if(ch=='y'||ch=='Y') 
 { strcpy(p_student[i].student.addr,tempaddr); 
 infofile=fopen(filename,"w+b"); //重新写入数据库  
 for(i=0;i<count;i++) 
 { if(fwrite(&p_student[i].student,sizeof(struct studentinfo),1,infofile)==1) 
 continue; 
 else 
 { fclose(infofile); 
 free(tempname); 
 free(tempaddr); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t修改失败,返回......!"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t成功修改%s的旷课科目,返回......!,",tempname); 
 free(tempname); 
 free(tempaddr); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("\n\n\n\n\t\t\t该操作已被取消，返回.......!"); 
 free(tempname); 
 free(tempaddr); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 } 
 printf("\n\n\n\n\t\t\t找不到%s的个人信息，返回.......!",tempname); 
 free(tempname); 
 free(tempaddr); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("输入有误，请返回重新选择.......!"); 
 free(tempname); 
 free(tempaddr); 
 getch(); 
 system("cls"); 
 return ; 
} 
/*****************************修改学生学号********************************/ 
void moftel(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *temptel; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //处理文件 
 if(!count) 
 { printf("读取数据失败，请确认已成功录入或数据是否损坏!"); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 tempname=(char *)malloc(20*sizeof(char)); 
 temptel=(char *)malloc(20*sizeof(char)); //分配内存 
 printf("请输入要修改的学生姓名:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { 
 if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("请重新输入该学生的学生学号:"); 
 gets(temptel); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\t确定要修改%s的学生学号吗?(y/n)",tempname); 
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
 printf("\n\n\n\n\t\t\t修改失败,返回.......!"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t成功修改%s的学生学号,返回.......!,",tempname); 
 free(tempname); 
 free(temptel); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("\n\n\n\n\t\t\t该操作已被取消，返回.......!"); 
 free(tempname); 
 free(temptel); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 } 
 printf("\n\n\n\n\t\t\t找不到%s的个人信息，返回.......!",tempname); 
 free(tempname); 
 free(temptel); 
 getch(); 
 system("cls"); 
 return ; 
 } 
 printf("输入有误，请返回重新选择.......!"); 
 free(tempname); 
 free(temptel); 
 getch(); 
 system("cls"); 
 return ; 
} 
/**************************修改旷课数目*************************/ 
void mofdak(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *tempdak; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //处理文件  
 if(!count) 
 { printf("读取数据失败，请确认已成功录入或数据是否损坏!"); 
 getch(); 
 system("cls"); 
 return ; } 
 tempname=(char *)malloc(20*sizeof(char)); 
 tempdak =(char *)malloc(20*sizeof(char)); //分配内存 
 printf("请输入要修改的学生姓名:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("请重新输入该学生的旷课数目:"); 
 gets(tempdak); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\t确定要修改%s的旷课数目吗?(y/n)",tempname); 
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
 printf("\n\n\n\n\t\t\t修改失败,返回.......!"); 
 getch(); 
 system("cls"); 
 return ; } 
 } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t成功修改%s的旷课数目,返回.......!",tempname); 
 free(tempname); 
 free(tempdak); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("\n\n\n\n\t\t\t该操作已取消，返回.......!"); 
 free(tempname); 
 free(tempdak); 
 getch(); 
 system("cls"); 
 return ; } } 
 printf("\n\n\n\n\t\t\t找不到%s的个人信息，返回.......!",tempname); 
 free(tempname); 
 free(tempdak); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("输入有误，请返回重新选择.......!"); 
 free(tempname); 
 free(tempdak); 
 getch(); 
 system("cls"); 
 return ; } 
/*************************修改所在班级******************************/ 
void mofschool(struct allstudentinfo *p_student) 
{ char *tempname; 
 char *tempschool; 
 char ch; 
 int i,count; 
 system("cls"); 
 count=datfile(p_student); //文件处理  
 if(!count) 
 { printf("读取数据失败，请确认已成功录入或数据是否损坏!"); 
 getch(); 
 system("cls"); 
 return ; 
 }  
 tempname=(char *)malloc(20*sizeof(char)); 
 tempschool=(char *)malloc(20*sizeof(char)); //分配内存 
 printf("请输入要修改的学生姓名:"); 
 while(gets(tempname)!=NULL&&tempname[0]!='\0') 
 { for(i=0;i<count;i++) 
 { if(strcmp(tempname,p_student[i].student.name)) 
 continue; 
 else 
 { printf("请重新输入该学生的所在班级:"); 
 gets(tempschool); 
 system("cls"); 
 printf("\a\n\n\n\n\t\t\t确定要修改%s的所在班级吗?(y/n)",tempname); 
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
 printf("\n\n\n\n\t\t\t修改失败,返回.......!"); 
 getch(); 
 system("cls"); 
 return ; } } 
 fclose(infofile); 
 system("cls"); 
 printf("\n\n\n\n\t\t\t成功修改%s的所在班级,返回.......!",tempname); 
 free(tempname); 
 free(tempschool); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("\n\n\n\n\t\t\t该操作已取消，返回.......!"); 
 free(tempname); 
 free(tempschool); 
 getch(); 
 system("cls"); 
 return ; } } 
 printf("\n\n\n\n\t\t\t找不到%s的个人信息，返回.......!",tempname); 
 free(tempname); 
 free(tempschool); 
 getch(); 
 system("cls"); 
 return ; } 
 printf("输入有误，请返回重新选择.......!"); 
 free(tempname); 
 free(tempschool); 
 getch(); 
 system("cls"); 
 return ; } 
/**************************修改个人信息的主要操作文件**************************/ 
int datfile(struct allstudentinfo *p_student) 
{ int count; 
  
 system("cls"); 
 if((infofile=fopen(filename,"rb"))==NULL) 
 { printf("不能找开文件，请确认磁盘已满或文件是否存在!"); 
 getch(); 
 exit(1); } 
 rewind(infofile); //指向文件头读取数据  
 for(count=0;fread(&p_student[count].student,sizeof(struct studentinfo),1,infofile)==1;count++) 
 { continue; } 
 fclose(infofile); 
 return count; //返回读到的结构块数  
}  
/*****************************系统帮助信息*******************************/ 
void systemhelp() 
{ system("cls"); 
 printf("\n\n\n\t\t\t\t系统帮助\n"); 
 printf("\t****************------------------------------******************\n"); 
 printf("\t 本系统支持汉字、英语、拼音或其它助记方式录入，为了能正常使用\n"); 
 printf("\t本系统，如要使用修改和删除功能请谨慎使用，或先将资料做好备份以免\n"); 
 printf("\t因系统出错造成数据丢失! 请按任意键退出!\n"); 
 printf("\t****************------------------------------******************\n"); 
 getch(); 
 system("cls"); 
 return ; }  
/***********退出*********************************/ 
void logout() 
{ time_t start,end; //时间函数 
 system("cls"); 
 printf("\n\n\n\n\n\n\n\n\t\t\t"); 
 printf("谢 谢 使 用 本 系 统 !");  
 start=time(NULL); 
 end=time(NULL); 
 while(end-start<2) //延时2秒执行以下程序  
 end=time(NULL); 
 exit(0); 
}
