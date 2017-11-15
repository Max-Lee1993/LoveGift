#include<stdio.h>
#include<windows.h>
#include <time.h> 
 /*********************************************************
函数名：MessageBox_Fcn
参  数：无 
返回值：无 
*********************************************************/  
void MessageBox_Fcn()
{

		char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
		time_t timep;
		struct tm *p;
		time(&timep);
		p=localtime(&timep);
		//printf("%d %d %d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday);
		//printf("%s%d:%d:%d\n",wday[p->tm_wday],p->tm_hour, p->tm_min, p->tm_sec);
	
		//9点弹出消息框 
		if((p->tm_hour)==9&&(p->tm_min)==0)
		{
			MessageBox(NULL , "早上好，","香香最棒",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);
		} 

		//10点弹出消息框	
		if((p->tm_hour)==10&&(p->tm_min)==0)
		{
			MessageBox(NULL , "早上好，","香香最棒",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);

		} 
    	
    //11点半弹出消息框	
    
    	if((p->tm_hour)==11&&(p->tm_min)==0)
		{
			MessageBox(NULL , "早上好，","香香最棒",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);

		} 
    
	//13点弹出消息框 
		if((p->tm_hour)==13&&(p->tm_min)==0)
		{
			MessageBox(NULL , "早上好，","香香最棒",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);

		} 

	//14点弹出消息框	
		if((p->tm_hour)==14&&(p->tm_min)==0)
		{
			MessageBox(NULL , "早上好，","香香最棒",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);
		} 
    	
    //16点半弹出消息框	
    	if((p->tm_hour)==21&&(p->tm_min)==0&&(p->tm_sec)==0)
		{
			MessageBox(NULL , "哇，香香又学了2个小时啦，听首歌放松下哦，点【确定】将自动给为你打开音乐哦","香香最棒",MB_YESNO);
			ShellExecute(NULL, "open", "https://y.qq.com/n/yqq/song/003OUlho2HcRHC.html?ADTAG=baiduald&play=1", NULL, NULL, SW_MAXIMIZE);
		} 	
	
	//18点弹出消息框	
    	if((p->tm_hour)==21&&(p->tm_min)==2&&(p->tm_sec)==0)
		{
			MessageBox(NULL , "小香香，到吃饭的点了，点【确定】看个内涵段子去次饭啦","一生一世只爱香香",MB_YESNO);
			ShellExecute(NULL, "open", "http://neihanshequ.com/", NULL, NULL, SW_MAXIMIZE);
	
        } 
}
 /*********************************************************
函数名：Welcome()
参  数：无 
返回值：无 
*********************************************************/  
void Welcome()
{
		//开机弹出欢迎消息框	
		MessageBox(NULL , "忙碌而有意义的一天","香香最胖",MB_OK);      		
} 
/*********************************************************
函数名：SetAutoRun()
参  数：无 
返回值：int 
*********************************************************/  

int   SetAutoRun()//开机自动运行    
{    
    //写入注册表，开机自启动  
    HKEY hKey;  
  
    //找到系统的启动项  
    LPCTSTR lpRun="Software\\Microsoft\\Windows\\CurrentVersion\\Run";  
  
     DWORD dwDisposition;  
  
    //打开启动项Key  
    long lRet=RegCreateKeyEx(HKEY_LOCAL_MACHINE,lpRun,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKey,&dwDisposition);  
      
    if (lRet==ERROR_SUCCESS)  
    {  
        char pFileName[MAX_PATH]={0};  
  
        //得到程序自身的全路径  
        DWORD dwRet=GetModuleFileName(NULL,pFileName,MAX_PATH);  
  
        //添加一个子key，并设置值  
        lRet=RegSetValueEx(hKey,"为爱启动",0,REG_SZ,(BYTE*)pFileName,dwRet);  
  
        //关闭注册表  
        RegCloseKey(hKey);  
        return TRUE;  
    }  
}
//主程序 
int main()
{   
	int i = 1; 
	SetAutoRun();
	i++; 
	Welcome();
	while(1)
	{
		MessageBox_Fcn();//消息弹框函数 
	}
	MessageBox(NULL , "明天继续陪伴你哦","香香最棒",MB_YESNO);	    
   return 0;
}
