#include<stdio.h>
#include<windows.h>
#include <time.h> 
 /*********************************************************
��������MessageBox_Fcn
��  ������ 
����ֵ���� 
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
	
		//9�㵯����Ϣ�� 
		if((p->tm_hour)==9&&(p->tm_min)==0)
		{
			MessageBox(NULL , "���Ϻã�","�������",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);
		} 

		//10�㵯����Ϣ��	
		if((p->tm_hour)==10&&(p->tm_min)==0)
		{
			MessageBox(NULL , "���Ϻã�","�������",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);

		} 
    	
    //11��뵯����Ϣ��	
    
    	if((p->tm_hour)==11&&(p->tm_min)==0)
		{
			MessageBox(NULL , "���Ϻã�","�������",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);

		} 
    
	//13�㵯����Ϣ�� 
		if((p->tm_hour)==13&&(p->tm_min)==0)
		{
			MessageBox(NULL , "���Ϻã�","�������",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);

		} 

	//14�㵯����Ϣ��	
		if((p->tm_hour)==14&&(p->tm_min)==0)
		{
			MessageBox(NULL , "���Ϻã�","�������",MB_YESNO);
			ShellExecute(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MAXIMIZE);
		} 
    	
    //16��뵯����Ϣ��	
    	if((p->tm_hour)==21&&(p->tm_min)==0&&(p->tm_sec)==0)
		{
			MessageBox(NULL , "�ۣ�������ѧ��2��Сʱ�������׸������Ŷ���㡾ȷ�������Զ���Ϊ�������Ŷ","�������",MB_YESNO);
			ShellExecute(NULL, "open", "https://y.qq.com/n/yqq/song/003OUlho2HcRHC.html?ADTAG=baiduald&play=1", NULL, NULL, SW_MAXIMIZE);
		} 	
	
	//18�㵯����Ϣ��	
    	if((p->tm_hour)==21&&(p->tm_min)==2&&(p->tm_sec)==0)
		{
			MessageBox(NULL , "С���㣬���Է��ĵ��ˣ��㡾ȷ���������ں�����ȥ�η���","һ��һ��ֻ������",MB_YESNO);
			ShellExecute(NULL, "open", "http://neihanshequ.com/", NULL, NULL, SW_MAXIMIZE);
	
        } 
}
 /*********************************************************
��������Welcome()
��  ������ 
����ֵ���� 
*********************************************************/  
void Welcome()
{
		//����������ӭ��Ϣ��	
		MessageBox(NULL , "æµ���������һ��","��������",MB_OK);      		
} 
/*********************************************************
��������SetAutoRun()
��  ������ 
����ֵ��int 
*********************************************************/  

int   SetAutoRun()//�����Զ�����    
{    
    //д��ע�������������  
    HKEY hKey;  
  
    //�ҵ�ϵͳ��������  
    LPCTSTR lpRun="Software\\Microsoft\\Windows\\CurrentVersion\\Run";  
  
     DWORD dwDisposition;  
  
    //��������Key  
    long lRet=RegCreateKeyEx(HKEY_LOCAL_MACHINE,lpRun,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKey,&dwDisposition);  
      
    if (lRet==ERROR_SUCCESS)  
    {  
        char pFileName[MAX_PATH]={0};  
  
        //�õ����������ȫ·��  
        DWORD dwRet=GetModuleFileName(NULL,pFileName,MAX_PATH);  
  
        //���һ����key��������ֵ  
        lRet=RegSetValueEx(hKey,"Ϊ������",0,REG_SZ,(BYTE*)pFileName,dwRet);  
  
        //�ر�ע���  
        RegCloseKey(hKey);  
        return TRUE;  
    }  
}
//������ 
int main()
{   
	int i = 1; 
	SetAutoRun();
	i++; 
	Welcome();
	while(1)
	{
		MessageBox_Fcn();//��Ϣ������ 
	}
	MessageBox(NULL , "������������Ŷ","�������",MB_YESNO);	    
   return 0;
}
