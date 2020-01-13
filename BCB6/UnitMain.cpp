//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
#include "process.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#pragma link "sqlite3_bc.lib"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    FThread = INVALID_HANDLE_VALUE;
    OpenDB();
    StartRun();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    if (ComboBox1->ItemIndex == 0)
    {
        Panel1->Visible = true;
        Panel2->Visible = false;
    }
    else
    {
        Panel1->Visible = false;
        Panel2->Visible = true;
    }
}
//---------------------------------------------------------------------------
static unsigned __stdcall threadMain(void *arg)
{
   TForm1 *frm = (TForm1 *)arg;
   frm->ThreadFun();
   return 0;
}


bool __fastcall TForm1::StartRun(void)
{
    hQuitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    bQuitFlag = false;
    unsigned threadId;
    SECURITY_ATTRIBUTES  sa = {
          sizeof(SECURITY_ATTRIBUTES), /* structure size */
          0,      /* No security descriptor */
          TRUE    /* Thread handle is inheritable */
    };

    FThread = (HANDLE)_beginthreadex(
         &sa,          /* Thread security */
         4096,         /* Thread stack size */
         threadMain,   /* Thread starting address */
         (void *)this,    /* Thread start argument */
         0,  /* Create in running state */
         &threadId);   /* Thread ID */
      if(FThread == INVALID_HANDLE_VALUE) {
         MessageBox(0, "Thread Creation Failed", "Error", MB_OK);
         return  false;
      }
      return true;
}

void __fastcall TForm1::StopRun(void)
{
    bQuitFlag = true;
    CloseHandle(FThread);
    SetEvent(hQuitEvent);
    Sleep(100);
    CloseHandle(hQuitEvent);
}

void __fastcall TForm1::ThreadFun(void)
{
    String strSql;
    char * errmsg = NULL;
    char **dbResult;//��char **���ͣ�����*��
    int nRow, nColumn;
    while(1)
    {
        //��ѯ���ݿ�
        if (bQuitFlag)
            break;
        DWORD dwRet = WaitForSingleObject(hQuitEvent,1*1000);
        if (bQuitFlag)
            break;
        strSql.sprintf("slect * from TimerInfo where ReminderTime <= date(\'now\');",);
        int result = sqlite3_get_table( pDB, strSql.c_str(), &dbResult, &nRow, &nColumn, &errmsg );
        if(SQLITE_OK== result )
        {
            int index = nColumn;//ǰ��˵��dbResultǰ���һ���������ֶ����ƣ���nColumn������ʼ��������������
            //printf(���鵽%d����¼/n��, nRow );

            for( int i = 0; i < nRow ; i++ )
            {
                //printf(����%d����¼/n��, i+1 );
                for( int j = 0 ; j < nColumn; j++ )
                {
                     printf("�ֶ���:%s ?>�ֶ�ֵ:%s/n", dbResult[j], dbResult [index] );
                     ++index;// dbResult���ֶ�ֵ�������ģ��ӵ�0��������nColumn - 1���������ֶ����ƣ��ӵ�nColumn������ʼ�����涼���ֶ�ֵ������һ����ά�ı���ͳ�����б�ʾ������һ����ƽ����ʽ����ʾ
                }
                //printf(��-------/n��);
            }
        }

        sqlite3_free_table( dbResult );
    }
}

bool __fastcall TForm1::OpenDB(void)
{
    AnsiString FileName = "./TimerInfo.db";//ChangeFileExt( Application->ExeName, ".db" );
    char * errmsg = NULL;
    int result;
    if( !FileExists(FileName) )
    {
        //�����ļ�
/*        FILE *fp = fopen(FileName.c_str(),"w+b");
        if (fp)
            fclose(fp); 
        else
        {
            Application->MessageBoxA("�������ݿ��ļ�ʧ�ܣ�","����",MB_OK|MB_ICONERROR) ;
            return false;
        }   */
        result = sqlite3_open(FileName.c_str(), &pDB);
        if (SQLITE_OK == result)
        {

            //����
            //������ݣ�����ʱ�䣬��ǰ��������ע��
            int result = sqlite3_exec( pDB,"create table TimerInfo( ReminderTime datetime primary key ASC, ConfigTime datetime, AheadOfSchedule interger, Comments varchar(2048) )", NULL, this, &errmsg );
            return true;
        }
        else
        {
            const char *pszErr = sqlite3_errmsg(pDB);
            ShowMessage(pszErr);
            return false;
        }
    }
    else
    {
        if (SQLITE_OK == sqlite3_open(FileName.c_str(), &pDB))
        {
            int result = sqlite3_exec( pDB,"create table IF NOT EXISTS TimerInfo(  ReminderTime datetime primary key ASC, ConfigTime datetime, AheadOfSchedule interger, Comments varchar(2048) )", NULL, this, &errmsg );
            return true;
        }
    }
    return false;
}

bool __fastcall TForm1::CloseDB(void)
{
    sqlite3_close(pDB);
    return true;
}
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    StopRun();
    CloseDB();
}
//---------------------------------------------------------------------------


bool __fastcall TForm1::AddTimerMode1(TDateTime dt, int aheadofSchedule, AnsiString comment)
{
    TDateTime dtTime = TDateTime(0,0,aheadofSchedule,0);
    String sTimeStamp = dt.FormatString("yyyy:yy:dd hh:mm:ss");
    String sReminderTime = (dt - dtTime).FormatString("yyyy:yy:dd hh:mm:ss");
    String strSql;
    strSql.sprintf("insert toTimerInfo VALUES( \'%s\', \'%s\', %d, \'%s\' )",sReminderTime.c_str() ,sTimeStamp.c_str(), aheadofSchedule, comment.c_str());
    char *errmsg = NULL;
    sqlite3_exec( pDB, strSql.c_str(), NULL, NULL, &errmsg );
}

bool __fastcall TForm1::AddTimerMode2(TDateTime dtDate, TDateTime dtTime, int aheadofSchedule, AnsiString comment)
{
    return AddTimerMode1(dtDate+dtTime, aheadofSchedule, comment);
}
